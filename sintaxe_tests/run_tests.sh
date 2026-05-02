#!/bin/bash

GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' 

COMPILADOR="./bin/compilador"

echo "Iniciando testes automatizados..."

for test_file in sintaxe_tests/*.c; do
    expected_file="${test_file%.c}.expected"
    
    if [ -f "$expected_file" ]; then
        echo -n "Testando $test_file: "
        
        $COMPILADOR < "$test_file" > tmp_output.py 2>/dev/null
        
        if diff -u "$expected_file" tmp_output.py > /dev/null; then
            echo -e "${GREEN}PASSOU${NC}"
        else
            echo -e "${RED}FALHOU${NC}"
            echo "Diferenças encontradas:"
            diff -u "$expected_file" tmp_output.py
        fi
    fi
done

rm tmp_output.py