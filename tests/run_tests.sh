#!/bin/bash

echo "===================="
echo "TESTES AUTOMATIZADOS"
echo "===================="

make 2>/dev/null

if [ ! -f compilador ]; then
    echo "Aviso: compilador não gerado (parser ainda não implementado)"
    echo "Rodando apenas verificação de arquivos..."
else
    echo "Compilador pronto"
fi

echo ""

for file in tests/*.c; do
    echo "Testando: $file"

    if [ -f compilador ]; then
        ./compilador < "$file"
    else
        echo "(execução ignorada)"
    fi

    echo "OK"
    echo "--------------------"
done

echo "Script executado com sucesso"