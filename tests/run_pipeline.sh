#!/bin/bash
# =================================================================
#  run_pipeline.sh — Pipeline automatizado de tradução C → Python
#
#  Uso:
#    bash tests/run_pipeline.sh                  # traduz tests/casos/
#    bash tests/run_pipeline.sh caminho/dir/     # traduz diretório custom
#    bash tests/run_pipeline.sh arquivo.c        # traduz arquivo único
#    bash tests/run_pipeline.sh --gerar-esperado # (re)gera arquivos .esperado
#    bash tests/run_pipeline.sh --help
#
#  Modos de validação (escolhidos automaticamente):
#    1. Se existe .esperado → compara stdout com ele
#    2. Se não existe       → valida que o .py executa sem exceções Python
#
#  Flags:
#    --gerar-esperado   Roda cada .py gerado e salva stdout como .esperado
#                       (útil para fixar o comportamento atual como baseline)
#    --verbose / -v     Mostra diff completo e stdout de cada caso
#    --parar-no-erro    Para ao primeiro FAIL
#    --saida DIR        Pasta onde os .py gerados serão salvos (padrão: /tmp/pipeline_XXXX)
# =================================================================

set -euo pipefail

GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
CYAN='\033[0;36m'
BOLD='\033[1m'
DIM='\033[2m'
NC='\033[0m'

COMPILADOR="./bin/compilador"
ALVO_PADRAO="tests/casos/benchmark"
ESPERADO_DIR="tests/traducao/casos"
TMP_DIR=$(mktemp -d /tmp/pipeline_XXXXXX)
SAIDA_PADRAO="tests/traducao/saida_py"
VERBOSE=0
PARAR_NO_ERRO=0
GERAR_ESPERADO=0
SAIDA_DIR=""
ALVO=""

uso() {
    echo -e "${BOLD}Uso:${NC}"
    echo "  bash tests/run_pipeline.sh [opções] [alvo]"
    echo ""
    echo -e "${BOLD}Alvo (opcional):${NC}"
    echo "  diretório/   Processa todos os .c dentro dele (padrão: tests/casos/)"
    echo "  arquivo.c    Processa apenas esse arquivo"
    echo ""
    echo -e "${BOLD}Opções:${NC}"
    echo "  --gerar-esperado   Executa os .py gerados e salva como .esperado"
    echo "  --verbose, -v      Exibe diff e stdout detalhados"
    echo "  --parar-no-erro    Para ao primeiro FAIL"
    echo "  --saida DIR        Pasta de destino dos .py gerados"
    echo "  --help, -h         Exibe esta ajuda"
    exit 0
}

while [[ $# -gt 0 ]]; do
    case "$1" in
        --help|-h)         uso ;;
        --verbose|-v)      VERBOSE=1 ; shift ;;
        --parar-no-erro)   PARAR_NO_ERRO=1 ; shift ;;
        --gerar-esperado)  GERAR_ESPERADO=1 ; shift ;;
        --saida)           SAIDA_DIR="$2" ; shift 2 ;;
        *)                 ALVO="$1" ; shift ;;
    esac
done

[[ -z "$ALVO" ]] && ALVO="$ALVO_PADRAO"
[[ -z "$SAIDA_DIR" ]] && SAIDA_DIR="$SAIDA_PADRAO"

if [[ ! -f "$COMPILADOR" ]]; then
    echo -e "${RED}Erro: compilador não encontrado em '$COMPILADOR'${NC}"
    echo -e "Execute ${YELLOW}make${NC} primeiro."
    exit 1
fi

if ! command -v python3 &>/dev/null; then
    echo -e "${RED}Erro: python3 não encontrado.${NC}"
    exit 1
fi

mkdir -p "$SAIDA_DIR"
mkdir -p "$ESPERADO_DIR"

ARQUIVOS=()
if [[ -f "$ALVO" ]]; then
    ARQUIVOS=("$ALVO")
elif [[ -d "$ALVO" ]]; then
    while IFS= read -r -d '' f; do
        ARQUIVOS+=("$f")
    done < <(find "$ALVO" -maxdepth 1 -name "*.c" -print0 | sort -z)
else
    echo -e "${RED}Erro: '$ALVO' não é um arquivo nem diretório válido.${NC}"
    exit 1
fi

if [[ ${#ARQUIVOS[@]} -eq 0 ]]; then
    echo -e "${YELLOW}Nenhum arquivo .c encontrado em '$ALVO'.${NC}"
    exit 0
fi

processar() {
    local arquivo_c="$1"
    local nome
    nome=$(basename "$arquivo_c" .c)
    local py_gerado="$SAIDA_DIR/${nome}.py"
    local erros_tmp="$TMP_DIR/${nome}.erros"
    local saida_tmp="$TMP_DIR/${nome}.saida"
    local esperado="$ESPERADO_DIR/${nome}.esperado"

    if ! $COMPILADOR "$arquivo_c" > "$py_gerado" 2> "$erros_tmp"; then
        echo -e "  ${RED}✗ FAIL${NC}  ${BOLD}$nome${NC}  [erro de compilação]"
        if [[ $VERBOSE -eq 1 ]] || grep -qE "Erro" "$erros_tmp"; then
            sed 's/^/         /' "$erros_tmp"
        fi
        return 1
    fi

    if grep -qE "Erro sintatico|Erro Semantico" "$erros_tmp"; then
        echo -e "  ${RED}✗ FAIL${NC}  ${BOLD}$nome${NC}  [erro léxico/sintático/semântico]"
        [[ $VERBOSE -eq 1 ]] && sed 's/^/         /' "$erros_tmp"
        return 1
    fi

    local py_exec="$TMP_DIR/${nome}_exec.py"
    cp "$py_gerado" "$py_exec"
    echo "" >> "$py_exec"
    echo "main()" >> "$py_exec"

    if ! python3 "$py_exec" > "$saida_tmp" 2>"$TMP_DIR/${nome}.py_erros"; then
        echo -e "  ${RED}✗ FAIL${NC}  ${BOLD}$nome${NC}  [exceção Python ao executar]"
        if [[ $VERBOSE -eq 1 ]]; then
            echo -e "         ${RED}--- stderr Python ---${NC}"
            sed 's/^/         /' "$TMP_DIR/${nome}.py_erros"
        fi
        return 1
    fi

    if [[ $GERAR_ESPERADO -eq 1 ]]; then
        cp "$saida_tmp" "$esperado"
        echo -e "  ${CYAN}⊕ SAVED${NC}  ${BOLD}$nome${NC}  → $esperado"
        return 0
    fi

    if [[ -f "$esperado" ]]; then

        if diff -q "$saida_tmp" "$esperado" > /dev/null 2>&1; then
            echo -e "  ${GREEN}✓ PASS${NC}  ${BOLD}$nome${NC}  [saída confere com .esperado]"
            return 0
        else
            echo -e "  ${RED}✗ FAIL${NC}  ${BOLD}$nome${NC}  [saída diverge do .esperado]"
            if [[ $VERBOSE -eq 1 ]]; then
                echo -e "         ${YELLOW}--- esperado   +++ gerado${NC}"
                diff "$esperado" "$saida_tmp" | sed 's/^/         /' || true
            fi
            return 1
        fi
    else
        echo -e "  ${GREEN}✓ PASS${NC}  ${BOLD}$nome${NC}  [executou sem exceções]"
        [[ $VERBOSE -eq 1 ]] && [[ -s "$saida_tmp" ]] && sed 's/^/         /' "$saida_tmp"
        return 0
    fi
}

echo -e "${CYAN}${BOLD}"
echo "╔══════════════════════════════════════════╗"
echo "║   PIPELINE  C → Python  (automático)     ║"
echo "╚══════════════════════════════════════════╝"
echo -e "${NC}"
echo -e "  Compilador : ${YELLOW}$COMPILADOR${NC}"
echo -e "  Alvo       : ${YELLOW}$ALVO${NC}"
echo -e "  Arquivos   : ${BOLD}${#ARQUIVOS[@]}${NC} .c encontrado(s)"
echo -e "  Saída .py  : ${YELLOW}$SAIDA_DIR${NC}  ${DIM}(permanente)${NC}"
[[ $GERAR_ESPERADO -eq 1 ]] && echo -e "  ${CYAN}Modo: gerando arquivos .esperado${NC}"
echo ""

TOTAL=0
PASSOU=0
FALHOU=0
FALHAS=()

for arquivo in "${ARQUIVOS[@]}"; do
    TOTAL=$((TOTAL + 1))
    nome=$(basename "$arquivo" .c)

    if processar "$arquivo"; then
        PASSOU=$((PASSOU + 1))
    else
        FALHOU=$((FALHOU + 1))
        FALHAS+=("$nome")
        if [[ $PARAR_NO_ERRO -eq 1 ]]; then
            echo ""
            echo -e "  ${RED}Parando no primeiro erro (--parar-no-erro).${NC}"
            break
        fi
    fi
done

echo ""
echo -e "${CYAN}${BOLD}════════════════════════════════════════════${NC}"

if [[ $TOTAL -gt 0 ]]; then
    PCT=$(awk "BEGIN { printf \"%.1f\", ($PASSOU/$TOTAL)*100 }")
    echo -e "  Total  : $TOTAL"
    echo -e "  ${GREEN}Passou : $PASSOU${NC}"
    echo -e "  ${RED}Falhou : $FALHOU${NC}"
    echo -e "  Taxa   : ${BOLD}${PCT}%${NC}"
fi

if [[ ${#FALHAS[@]} -gt 0 ]]; then
    echo ""
    echo -e "  ${RED}Casos que falharam:${NC}"
    for f in "${FALHAS[@]}"; do
        echo -e "    ${RED}✗${NC} $f"
    done
fi

echo -e "${CYAN}${BOLD}════════════════════════════════════════════${NC}"
echo ""

rm -rf "$TMP_DIR"

[[ $FALHOU -eq 0 ]] && exit 0 || exit 1