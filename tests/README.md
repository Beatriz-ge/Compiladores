# Testes — Compilador C→Python

## Estrutura

```
tests/
├── teste.c          ← arquivo de teste manual (uso livre durante desenvolvimento)
├── saida.py         ← saída gerada pelo compilador
├── run_tests.sh     ← script principal de testes
└── casos/           ← casos de teste permanentes (suite de regressão)
    ├── basico.c
    ├── redeclaracao_erro.c
    └── var_nao_declarada_erro.c
```

---

## Como usar

### Uso diário
```bash
make clean && make
bash tests/run_tests.sh
```

### Com cobertura completa de linhas
```bash
bash tests/run_tests.sh --coverage
```

---

## Pré-requisito para coverage

```bash
sudo apt install lcov
```

> `gcov` já vem junto com o `gcc`, não precisa instalar separado.

---

## Saída esperada

### Modo normal (`bash tests/run_tests.sh`)
```
Léxico:           OK
Sintático:        OK
Semântico:        OK
TUDO OK!

── Cobertura de Casos ──────────────────────
  ✓ PASS  basico.c
  ✓ PASS  [esperava erro] redeclaracao_erro.c
  ✓ PASS  [esperava erro] var_nao_declarada_erro.c
────────────────────────────────────────────
  Casos:    3 total  |  3 passou  |  0 falhou
  Cobertura de casos: 100,0%
```

### Modo coverage (`bash tests/run_tests.sh --coverage`)
```
RESUMO DE COBERTURA

  Casos de Teste
  ├─ Total:   4
  ├─ Passou:  4
  ├─ Falhou:  0
  └─ Cobertura de casos: 100,0%

  ==================================================
       COBERTURA DE LINHAS (gcov)
  ==================================================
    lines.......: 55.8%
    functions...: 68.3%
  ==================================================
```

---

## Comandos do Makefile

| Comando | O que faz |
|---|---|
| `make` | Build normal do compilador |
| `make clean` | Remove build e binário |
| `make coverage` | Recompila com instrumentação gcov |
| `make report` | Gera relatório de cobertura de linhas |
| `make clean-coverage` | Remove só os arquivos gcov |

---

## Como adicionar novos casos de teste

Crie arquivos `.c` em `tests/casos/` seguindo a convenção:

| Nome do arquivo | Tipo | O teste passa quando... |
|---|---|---|
| `basico.c`, `loops.c` | Positivo | Compilador aceita sem erros |
| `redeclaracao_erro.c` | Negativo | Compilador **rejeita** com erro |
| `tipo_invalido_erro.c` | Negativo | Compilador **rejeita** com erro |

> Arquivos com `_erro` ou `_fail` no nome são tratados como **casos negativos**.

### Exemplo — caso positivo (`tests/casos/loops.c`)
```c
int main() {
    int i = 0;
    while (i < 10) {
        i += 1;
    }
    return 0;
}
```

### Exemplo — caso negativo (`tests/casos/uso_antes_declarar_erro.c`)
```c
int main() {
    x = 5;
    return 0;
}
```

---

## Observações

- O `tests/teste.c` é para experimentos durante o desenvolvimento — edite, apague e reescreva à vontade
- A pasta `coverage_report/` é gerada localmente e está no `.gitignore` — não sobe para o repositório
- Os casos em `tests/casos/` são permanentes — garantem que o que funcionava ontem ainda funciona hoje