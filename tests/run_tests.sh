#!/bin/bash
# =================================================================
#  run_tests.sh — Executa testes e exibe cobertura de casos
#
#  Uso normal:        bash tests/run_tests.sh
#  Com coverage:      bash tests/run_tests.sh --coverage
#
#  Modo --coverage:
#    Recompila com gcov, roda todos os cenários da pasta
#    tests/casos/ e ao final exibe % de linhas cobertas.
# =================================================================

# ---- Cores ----
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
NC='\033[0m'

# ---- Caminhos ----
INPUT="tests/teste.c"
OUTPUT="tests/saida.py"
COMPILADOR="./bin/compilador"
CASOS_DIR="tests/casos"
MODO_COVERAGE=0

# ---- Flag --coverage ----
if [[ "$1" == "--coverage" ]]; then
    MODO_COVERAGE=1
fi

# =================================================================
#  FUNÇÃO: rodar um único arquivo de teste
#  $1 = caminho do .c a testar
#  $2 = descrição (opcional)
#  Retorna 0 se passou, 1 se falhou
# =================================================================
rodar_teste() {
    local arquivo="$1"
    local descricao="${2:-$(basename "$arquivo")}"

    local saida_tmp=$(mktemp /tmp/saida_XXXXXX.py)
    local erros_tmp=$(mktemp /tmp/erros_XXXXXX.txt)

    $COMPILADOR "$arquivo" > "$saida_tmp" 2> "$erros_tmp"
    local status=$?
    local erros
    erros=$(cat "$erros_tmp")

    rm -f "$saida_tmp" "$erros_tmp"

    # Verifica se o arquivo esperava ERRO (nome contém "_erro" ou "_fail")
    local espera_erro=0
    if [[ "$arquivo" == *"_erro"* ]] || [[ "$arquivo" == *"_fail"* ]]; then
        espera_erro=1
    fi

    if [[ $espera_erro -eq 1 ]]; then
        # Caso negativo: esperamos que o compilador rejeite
        if [[ "$erros" == *"Erro"* ]] || [[ $status -ne 0 ]]; then
            echo -e "  ${GREEN}✓ PASS${NC}  [esperava erro] $descricao"
            return 0
        else
            echo -e "  ${RED}✗ FAIL${NC}  [esperava erro, mas passou] $descricao"
            return 1
        fi
    else
        # Caso positivo: esperamos compilação sem erros
        if [[ "$erros" == *"Erro sintatico"* ]]; then
            echo -e "  ${RED}✗ FAIL${NC}  [erro léxico/sintático] $descricao"
            [[ $MODO_COVERAGE -eq 1 ]] && echo "         $erros"
            return 1
        elif [[ "$erros" == *"Erro Semantico"* ]]; then
            echo -e "  ${RED}✗ FAIL${NC}  [erro semântico] $descricao"
            [[ $MODO_COVERAGE -eq 1 ]] && echo "         $erros"
            return 1
        else
            echo -e "  ${GREEN}✓ PASS${NC}  $descricao"
            return 0
        fi
    fi
}

# =================================================================
#  MODO NORMAL — comportamento original + resumo de casos
# =================================================================
if [[ $MODO_COVERAGE -eq 0 ]]; then

    echo -e "${YELLOW}Verificando arquivo: $INPUT${NC}"
    echo "------------------------------------------"

    $COMPILADOR "$INPUT" > "$OUTPUT" 2> tmp_erros.txt
    STATUS=$?
    cat tmp_erros.txt
    ERROS=$(cat tmp_erros.txt)

    # 1. TESTE LÉXICO E SINTÁTICO
    if [[ "$ERROS" == *"Erro sintatico"* ]]; then
        echo -e "Léxico/Sintático: ${RED}FALHOU${NC}"
        rm -f "$OUTPUT"
        rm -f tmp_erros.txt
        exit 1
    else
        echo -e "Léxico:           ${GREEN}OK${NC}"
        echo -e "Sintático:        ${GREEN}OK${NC}"
    fi

    # 2. TESTE SEMÂNTICO
    if [[ "$ERROS" == *"Erro Semantico"* ]]; then
        echo -e "Semântico:        ${RED}FALHOU${NC}"
        rm -f "$OUTPUT"
        rm -f tmp_erros.txt
        exit 1
    else
        echo -e "Semântico:        ${GREEN}OK${NC}"
    fi

    echo "===================================="
    echo -e "${GREEN}TUDO OK!${NC}"
    echo -e "Arquivo ${YELLOW}'$OUTPUT'${NC} criado com sucesso."

    # ---- Resumo de casos (se pasta tests/casos/ existir) ----
    if [[ -d "$CASOS_DIR" ]]; then
        TOTAL=0
        PASSOU=0
        FALHOU=0

        echo ""
        echo -e "${CYAN}${BOLD}── Cobertura de Casos ──────────────────────${NC}"

        for f in "$CASOS_DIR"/*.c; do
            [[ -f "$f" ]] || continue
            TOTAL=$((TOTAL + 1))
            if rodar_teste "$f"; then
                PASSOU=$((PASSOU + 1))
            else
                FALHOU=$((FALHOU + 1))
            fi
        done

        if [[ $TOTAL -gt 0 ]]; then
            PCT=$(awk "BEGIN { printf \"%.1f\", ($PASSOU/$TOTAL)*100 }")
            echo -e "${CYAN}────────────────────────────────────────────${NC}"
            echo -e "  Casos:    $TOTAL total  |  ${GREEN}$PASSOU passou${NC}  |  ${RED}$FALHOU falhou${NC}"
            echo -e "  Cobertura de casos: ${BOLD}${PCT}%${NC}"
            echo -e "${CYAN}────────────────────────────────────────────${NC}"
        fi
    fi

    rm -f tmp_erros.txt
    exit 0
fi

# =================================================================
#  MODO --coverage — gcov + cobertura de casos
# =================================================================
echo -e "${CYAN}${BOLD}"
echo "╔══════════════════════════════════════════╗"
echo "║     MODO COVERAGE ATIVADO                ║"
echo "╚══════════════════════════════════════════╝"
echo -e "${NC}"

# Recompila com flags de cobertura
echo -e "${YELLOW}[1/4] Recompilando com gcov...${NC}"
make coverage --no-print-directory
if [[ $? -ne 0 ]]; then
    echo -e "${RED}Falha na compilação. Abortando.${NC}"
    exit 1
fi
echo -e "${GREEN}OK${NC}"

# Cria pasta de casos se não existir
mkdir -p "$CASOS_DIR"

# Verifica se existem casos
CASOS=("$CASOS_DIR"/*.c)
if [[ ! -f "${CASOS[0]}" ]]; then
    echo ""
    echo -e "${YELLOW}Nenhum arquivo em tests/casos/ encontrado.${NC}"
    echo "Crie arquivos .c lá para cobertura automática."
    echo "Dica: arquivos com '_erro' no nome são testados como casos negativos."
    echo ""
    echo "Rodando apenas o teste.c padrão..."
    rodar_teste "$INPUT" "teste.c (padrão)"
    echo ""
fi

# ---- Roda todos os casos ----
echo -e "${YELLOW}[2/4] Rodando casos de teste...${NC}"
echo ""

TOTAL=0
PASSOU=0
FALHOU=0
FALHAS=()

for f in "$CASOS_DIR"/*.c; do
    [[ -f "$f" ]] || continue
    TOTAL=$((TOTAL + 1))
    nome=$(basename "$f")
    if rodar_teste "$f" "$nome"; then
        PASSOU=$((PASSOU + 1))
    else
        FALHOU=$((FALHOU + 1))
        FALHAS+=("$nome")
    fi
done

# Roda também o teste.c principal se existir
if [[ -f "$INPUT" ]]; then
    TOTAL=$((TOTAL + 1))
    if rodar_teste "$INPUT" "teste.c (padrão)"; then
        PASSOU=$((PASSOU + 1))
    else
        FALHOU=$((FALHOU + 1))
        FALHAS+=("teste.c")
    fi
fi

# ---- Gera relatório gcov ----
echo ""
echo -e "${YELLOW}[3/4] Gerando relatório gcov/lcov...${NC}"
make report --no-print-directory
REPORT_STATUS=$?

# ---- Resumo final ----
echo ""
echo -e "${CYAN}${BOLD}"
echo "╔══════════════════════════════════════════╗"
echo "║           RESUMO DE COBERTURA            ║"
echo "╚══════════════════════════════════════════╝"
echo -e "${NC}"

if [[ $TOTAL -gt 0 ]]; then
    PCT_CASOS=$(awk "BEGIN { printf \"%.1f\", ($PASSOU/$TOTAL)*100 }")
    echo -e "  ${BOLD}Casos de Teste${NC}"
    echo -e "  ├─ Total:   $TOTAL"
    echo -e "  ├─ ${GREEN}Passou:  $PASSOU${NC}"
    echo -e "  ├─ ${RED}Falhou:  $FALHOU${NC}"
    echo -e "  └─ Cobertura de casos: ${BOLD}${PCT_CASOS}%${NC}"

    if [[ ${#FALHAS[@]} -gt 0 ]]; then
        echo ""
        echo -e "  ${RED}Casos que falharam:${NC}"
        for f in "${FALHAS[@]}"; do
            echo -e "    ${RED}✗${NC} $f"
        done
    fi
fi

echo ""
if [[ $REPORT_STATUS -ne 0 ]]; then
    echo -e "  ${YELLOW}Aviso: lcov não encontrado. Instale com:${NC}"
    echo -e "  ${YELLOW}  sudo apt install lcov${NC}"
fi

echo ""
echo -e "${CYAN}════════════════════════════════════════════${NC}"