# Compiladores — Equipe 11

## Sobre o Projeto

Este projeto tem como objetivo o desenvolvimento de um compilador para um subconjunto da linguagem C, como parte da disciplina de **Compiladores** da Faculdade de Ciência, Tecnologia e Engenharia (FCTE) da Universidade de Brasília (UnB).

O compilador realiza as principais etapas de um pipeline de compilação, incluindo análise léxica, análise sintática, construção da AST, análise semântica e geração de código equivalente em Python.

---

## Visão Geral

O projeto implementa um compilador C → Python utilizando **Flex**, **Bison** e linguagem **C**.

Atualmente, o compilador reconhece e processa um subconjunto da linguagem C, incluindo:

* declaração de variáveis;
* atribuições;
* expressões aritméticas;
* expressões relacionais;
* expressões lógicas;
* comandos condicionais `if`, `else` e `else if`;
* laços `while` e `for`;
* comandos `break` e `continue`;
* funções com e sem parâmetros;
* escopo global e local;
* arrays;
* ponteiros;
* structs;
* `printf`;
* `scanf`;
* suporte parcial à biblioteca `string.h`.

---

## Pipeline do Compilador

O fluxo principal do compilador é composto pelas seguintes etapas:

```text
Código C de entrada
→ Análise léxica
→ Análise sintática
→ Construção da AST
→ Análise semântica
→ Geração de código Python
→ Arquivo de saída
```

### Etapas implementadas

* **Lexer:** responsável por identificar tokens da linguagem C.
* **Parser:** responsável por validar a estrutura sintática do programa.
* **AST:** representa a estrutura abstrata do código de entrada.
* **Análise semântica:** valida escopos, declarações, tipos, funções, arrays, ponteiros e structs.
* **Codegen:** gera código Python equivalente ao subconjunto C suportado.

---

## Tecnologias Utilizadas

* C
* Flex
* Bison
* GCC
* Makefile
* Bash
* Python, como linguagem-alvo da tradução

---

## Estrutura do Projeto

```text
Compiladores/
├── src/
│   ├── lexer.l              # Analisador léxico
│   ├── parser.y             # Analisador sintático e integração semântica
│   ├── main.c               # Ponto de entrada do compilador
│   ├── common.h             # Definições comuns
│   ├── tabela.c             # Tabela de símbolos
│   ├── tabela.h
│   ├── tabela_funcoes.c     # Tabela de funções
│   ├── tabela_funcoes.h
│   ├── semantic.c           # Funções de análise semântica
│   ├── semantic.h
│   ├── diagnostics.c        # Emissão de erros e diagnósticos
│   ├── diagnostics.h
│   └── ast/
│       ├── ast.c            # Construção da AST e geração de Python
│       ├── ast.h
│       ├── indent_manager.c # Controle de indentação do Python gerado
│       └── indent_manager.h
│
├── tests/
│   ├── casos/               # Casos positivos e negativos da suíte principal
│   ├── traducao/            # Testes de tradução C → Python
│   ├── teste.c              # Arquivo principal de teste manual
│   ├── saida.py             # Arquivo Python gerado
│   └── run_tests.sh         # Script da suíte principal
│
├── build/                   # Arquivos gerados durante a compilação
├── bin/                     # Binário final do compilador
├── docs/                    # Documentação do projeto
├── Makefile
└── README.md
```

---

## Requisitos

Para compilar e executar o projeto, é necessário ter instalado:

* GCC
* Flex
* Bison
* Make
* Bash
* Python 3, para executar e validar o código Python gerado

Em sistemas baseados em Debian/Ubuntu, é possível instalar com:

```bash
sudo apt update
sudo apt install gcc flex bison make python3
```

---

## Como Compilar

Na raiz do projeto, execute:

```bash
make clean
make
```

Após a compilação, o binário será gerado em:

```text
bin/compilador
```

---

## Como Executar

Para executar o compilador em um arquivo C:

```bash
./bin/compilador tests/teste.c
```

O compilador realiza as análises léxica, sintática e semântica, exibe a AST e gera o arquivo Python de saída em:

```text
tests/saida.py
```

---

## Exemplo de Entrada

```c
int main() {
    int x = 10;
    int y = 20;

    if (y > x) {
        x = y;
    }

    return x;
}
```

## Exemplo de Saída Python

```python
def main():
    x = 10
    y = 20
    if y > x:
        x = y
    return x
```

---

## Funcionalidades Suportadas

### Tipos básicos

* `int`
* `float`
* `char`
* `double`
* `void`

### Comandos e estruturas

* declaração de variáveis;
* atribuições simples e compostas;
* operadores aritméticos;
* operadores relacionais;
* operadores lógicos;
* `if`;
* `else`;
* `else if`;
* `while`;
* `for`;
* `break`;
* `continue`;
* `return`;
* `printf`;
* `scanf`.

### Estruturas adicionais

* funções com argumentos;
* escopo global e local;
* arrays unidimensionais e multidimensionais;
* ponteiros;
* structs;
* suporte parcial à `string.h`.

---

## Suporte Parcial à `string.h`

O compilador possui suporte parcial às seguintes funções da biblioteca `string.h`:

* `strlen`
* `strcmp`
* `strcpy`
* `strcat`
* `strchr`
* `strstr`

Exemplo:

```c
#include <string.h>

int main() {
    int tamanho = strlen("Arthur");
    int igual = strcmp("Arthur", "Arthur");
    return 0;
}
```

Saída Python equivalente:

```python
def main():
    tamanho = len("Arthur")
    igual = (("Arthur" > "Arthur") - ("Arthur" < "Arthur"))
    return 0
```

---

## Testes

O projeto possui duas suítes principais de teste.

### Suíte principal

Executa testes léxicos, sintáticos e semânticos:

```bash
./tests/run_tests.sh
```

Resultado validado:

```text
Casos: 46 total | 46 passou | 0 falhou
Cobertura de casos: 100,0%
```

### Suíte de tradução C → Python

Executa testes voltados à validação da saída Python gerada:

```bash
./tests/traducao/run_traducao_tests.sh
```

Resultado validado:

```text
Total: 16 | Passou: 16 | Falhou: 0 | Pulou: 0
Cobertura de tradução: 100,0%
```

---

## Casos de Teste Cobertos

A suíte contempla casos como:

* código básico;
* variáveis globais e locais;
* escopo;
* funções com argumentos;
* funções sem argumentos;
* operadores aritméticos;
* operadores relacionais;
* operadores lógicos;
* `if`, `else` e `else if`;
* `while`;
* `for`;
* `break`;
* `continue`;
* arrays;
* ponteiros;
* structs;
* `printf`;
* `scanf`;
* suporte parcial à `string.h`;
* erros semânticos;
* erros sintáticos;
* casos não suportados.

---

## Limitações Conhecidas

O compilador implementa apenas um subconjunto da linguagem C. Algumas funcionalidades ainda não são suportadas ou possuem suporte parcial.

Limitações conhecidas:

* suporte incompleto à linguagem C completa;
* ausência de suporte completo a `switch/case`;
* ausência de suporte completo a `do while`;
* suporte parcial a bibliotecas padrão;
* simulação simplificada de ponteiros em Python;
* suporte parcial a inicializações complexas de strings e arrays de caracteres.

---

## Status Atual

O projeto encontra-se em fase final de validação, com as principais etapas do pipeline implementadas e testadas:

* análise léxica;
* análise sintática;
* construção da AST;
* análise semântica;
* geração de código Python;
* testes automatizados;
* testes de tradução;
* documentação do projeto.

---

## Comandos Úteis

Compilar o projeto:

```bash
make
```

Limpar arquivos gerados:

```bash
make clean
```

Executar o compilador:

```bash
./bin/compilador tests/teste.c
```

Executar suíte principal:

```bash
./tests/run_tests.sh
```

Executar suíte de tradução:

```bash
./tests/traducao/run_traducao_tests.sh
```

Visualizar saída Python gerada:

```bash
cat tests/saida.py
```

---

## Membros da Equipe

| [![](https://avatars.githubusercontent.com/u/90862900?v=4)](https://github.com/arthurfernandesj) | [![](https://avatars.githubusercontent.com/u/129804255?v=4)](https://github.com/Beatriz-ge) | [![](https://avatars.githubusercontent.com/u/165945167?v=4)](https://github.com/BeatrizSants) | [![](https://avatars.githubusercontent.com/u/164348330?v=4)](https://github.com/dudaa28) | [![](https://avatars.githubusercontent.com/u/185298426?v=4)](https://github.com/isabellachoukaira) |
| :----------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------: | :-------------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------------: | :------------------------------------------------------------------------------------------------: |
|                      [Arthur Fernandes](https://github.com/arthurfernandesj)                     |                        [Beatriz Lins](https://github.com/Beatriz-ge)                        |                       [Beatriz Santos](https://github.com/BeatrizSants)                       |                        [Maria Eduarda](https://github.com/dudaa28)                       |                     [Isabella Choukaira](https://github.com/isabellachoukaira)                     |

---

## Objetivo Acadêmico

Aplicar, na prática, os conceitos fundamentais da disciplina de Compiladores, incluindo:

* análise léxica;
* análise sintática;
* gramáticas livres de contexto;
* construção de AST;
* análise semântica;
* tabela de símbolos;
* geração de código;
* testes automatizados;
* organização de um pipeline de compilação.
