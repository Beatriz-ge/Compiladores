#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
CYAN='\033[0;36m'
NC='\033[0m'

COMPILADOR="./bin/compilador"

echo "Iniciando testes automatizados..."

TOTAL=0
PASSOU=0
FALHOU=0

for test_file in sintaxe_tests/*.c; do

    expected_file="${test_file%.c}.expected"

    if [ -f "$expected_file" ]; then

        TOTAL=$((TOTAL + 1))

        echo -n "Testando $test_file: "

        $COMPILADOR < "$test_file" > tmp_output.txt 2>&1

        if diff -u "$expected_file" tmp_output.txt > /dev/null; then

            if [[ "$test_file" == *"erro"* || "$test_file" == *"invalida"* ]]; then
                echo -e "${CYAN}PASSOU (erro detectado corretamente)${NC}"
            else
                echo -e "${GREEN}PASSOU${NC}"
            fi

            PASSOU=$((PASSOU + 1))

        else

            echo -e "${RED}FALHOU${NC}"

            FALHOU=$((FALHOU + 1))

            echo "Diferenças encontradas:"
            diff -u "$expected_file" tmp_output.txt
        fi
    fi
done

rm -f tmp_output.txt

echo ""
echo "=============================="
echo "Total:   $TOTAL"
echo -e "${GREEN}Passou:  $PASSOU${NC}"
echo -e "${RED}Falhou: $FALHOU${NC}"
echo "=============================="