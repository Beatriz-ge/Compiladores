#!/bin/bash

# Cores
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[1;33m'
NC='\033[0m'

INPUT="tests/teste.c"
OUTPUT="tests/saida.py"
COMPILADOR="./bin/compilador"

echo -e "${YELLOW}Verificando arquivo: $INPUT${NC}"
echo "------------------------------------------"


$COMPILADOR "$INPUT" > "$OUTPUT" 2> tmp_erros.txt
STATUS=$? 
cat tmp_erros.txt

ERROS=$(cat tmp_erros.txt)

# 1. TESTE LÉXICO E SINTÁTICO
if [[ "$ERROS" == *"Erro sintatico"* ]]; then
    echo -e "Léxico/Sintático: ${RED}FALHOU${NC}"
    echo "$ERROS"
    rm -f "$OUTPUT" 
    exit 1
else
    echo -e "Léxico:           ${GREEN}OK${NC}" 
    echo -e "Sintático:        ${GREEN}OK${NC}"
fi

# 2. TESTE SEMÂNTICO
if [[ "$ERROS" == *"Erro Semantico"* ]]; then
    echo -e "Semântico:        ${RED}FALHOU${NC}"
    echo "$ERROS"
    rm -f "$OUTPUT"
    exit 1
else
    echo -e "Semântico:        ${GREEN}OK${NC}"
fi

echo ""====================================""
echo -e "${GREEN}TUDO OK!${NC}"
echo -e "Arquivo ${YELLOW}'$OUTPUT'${NC} criado com sucesso."

# Limpa o lixo
rm -f tmp_erros.txt 