#!/bin/bash
# =================================================================
#  run_traducao_tests.sh — Valida a corretude da tradução C → Python
#
#  Uso:   bash tests/traducao/run_traducao_tests.sh
#
#  Para cada caso em tests/traducao/casos/:
#    1. Compila o .c com o compilador gerando um .py
#    2. Executa o .py gerado e captura o stdout
#    3. Compara com o .esperado correspondente
#    4. Exibe PASS ou FAIL com diff legível
# =================================================================

# ---- Cores ----
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m'

# ---- Caminhos ----
COMPILADOR="./bin/compilador"
CASOS_DIR="tests/traducao/casos"
TMP_DIR=$(mktemp -d /tmp/traducao_tests_XXXXXX)

# ---- Verifica compilador ----
if [[ ! -f "$COMPILADOR" ]]; then
    echo -e "${RED}Compilador não encontrado em $COMPILADOR${NC}"
    echo -e "Execute ${YELLOW}make${NC} antes de rodar os testes."
    exit 1
fi

# ---- Verifica Python ----
if ! command -v python3 &> /dev/null; then
    echo -e "${RED}python3 não encontrado. Instale para rodar os testes de tradução.${NC}"
    exit 1
fi

# =================================================================
#  FUNÇÃO: rodar um caso de tradução
#  $1 = caminho do .c
# =================================================================
rodar_caso() {
    local arquivo_c="$1"
    local nome=$(basename "$arquivo_c" .c)
    local esperado="$CASOS_DIR/$nome.esperado"
    local py_gerado="$TMP_DIR/$nome.py"
    local saida_gerada="$TMP_DIR/$nome.saida"
    local erros_compilador="$TMP_DIR/$nome.erros"

    # Verifica se existe o .esperado
    if [[ ! -f "$esperado" ]]; then
        echo -e "  ${YELLOW}? SKIP${NC}  $nome  (sem .esperado)"
        return 2
    fi

    # Compila o .c gerando o .py
    $COMPILADOR "$arquivo_c" > "$py_gerado" 2> "$erros_compilador"
    local status_compilador=$?

    if [[ $status_compilador -ne 0 ]] || grep -qE "Erro sintatico|Erro Semantico" "$erros_compilador"; then
        echo -e "  ${RED}✗ FAIL${NC}  $nome"
        echo -e "         ${RED}Erro na compilação:${NC}"
        sed 's/^/         /' "$erros_compilador"
        return 1
    fi

    # Executa o .py gerado
    echo "" >> "$py_gerado"
    echo "main()" >> "$py_gerado"
    python3 "$py_gerado" > "$saida_gerada" 2>/dev/null
    local status_python=$?

    if [[ $status_python -ne 0 ]]; then
        echo -e "  ${RED}✗ FAIL${NC}  $nome"
        echo -e "         ${RED}Erro ao executar o .py gerado${NC}"
        return 1
    fi

    # Compara saída gerada com esperada
    if diff -q "$saida_gerada" "$esperado" > /dev/null 2>&1; then
        echo -e "  ${GREEN}✓ PASS${NC}  $nome"
        return 0
    else
        echo -e "  ${RED}✗ FAIL${NC}  $nome"
        echo -e "         ${YELLOW}--- esperado${NC}"
        echo -e "         ${YELLOW}+++ gerado${NC}"
        diff "$esperado" "$saida_gerada" | sed 's/^/         /'
        return 1
    fi
}

# =================================================================
#  EXECUÇÃO
# =================================================================
echo -e "${CYAN}${BOLD}"
echo "╔══════════════════════════════════════════╗"
echo "║    TESTES DE TRADUÇÃO  C → Python        ║"
echo "╚══════════════════════════════════════════╝"
echo -e "${NC}"

TOTAL=0
PASSOU=0
FALHOU=0
PULOU=0
FALHAS=()

for f in "$CASOS_DIR"/*.c; do
    [[ -f "$f" ]] || continue
    TOTAL=$((TOTAL + 1))
    nome=$(basename "$f" .c)

    resultado=0
    rodar_caso "$f"
    resultado=$?

    if [[ $resultado -eq 0 ]]; then
        PASSOU=$((PASSOU + 1))
    elif [[ $resultado -eq 2 ]]; then
        PULOU=$((PULOU + 1))
        TOTAL=$((TOTAL - 1))
    else
        FALHOU=$((FALHOU + 1))
        FALHAS+=("$nome")
    fi
done

# ---- Resumo ----
echo ""
echo -e "${CYAN}${BOLD}════════════════════════════════════════════${NC}"

if [[ $TOTAL -gt 0 ]]; then
    PCT=$(awk "BEGIN { printf \"%.1f\", ($PASSOU/$TOTAL)*100 }")
    echo -e "  Total:   $TOTAL  |  ${GREEN}Passou: $PASSOU${NC}  |  ${RED}Falhou: $FALHOU${NC}  |  Pulou: $PULOU"
    echo -e "  Cobertura de tradução: ${BOLD}${PCT}%${NC}"
else
    echo -e "  ${YELLOW}Nenhum caso encontrado em $CASOS_DIR${NC}"
fi

if [[ ${#FALHAS[@]} -gt 0 ]]; then
    echo ""
    echo -e "  ${RED}Casos que falharam:${NC}"
    for f in "${FALHAS[@]}"; do
        echo -e "    ${RED}✗${NC} $f"
    done
fi

echo -e "${CYAN}${BOLD}════════════════════════════════════════════${NC}"

# ---- Limpeza ----
rm -rf "$TMP_DIR"

# ---- Exit code ----
[[ $FALHOU -eq 0 ]] && exit 0 || exit 1