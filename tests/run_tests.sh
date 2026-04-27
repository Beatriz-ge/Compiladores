#!/bin/bash

echo "===================="
echo "TESTES AUTOMATIZADOS"
echo "===================="

echo "=== TESTES VALIDOS ==="
for file in tests/valido*.c; do
    echo "Testando: $file"
    
    ./bin/compilador < "$file" > /dev/null 2>&1
    
    if [ $? -eq 0 ]; then
        echo "PASSOU"
    else
        echo "FALHOU (deveria passar)"
    fi
    
    echo "--------------------"
done

echo "=== TESTES INVALIDOS ==="
for file in tests/erro*.c; do
    echo "Testando: $file"
    
    ./bin/compilador < "$file" > /dev/null 2>&1
    
    if [ $? -ne 0 ]; then
        echo "PASSOU (erro detectado)"
    else
        echo "FALHOU (deveria dar erro)"
    fi
    
    echo "--------------------"
done

echo "TESTES CONCLUÍDOS"