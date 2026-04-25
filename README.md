# Compiladores - Equipe 11

## Sobre

Este projeto tem como objetivo o desenvolvimento de um compilador para um subconjunto da linguagem C, como parte da disciplina de Compiladores da Faculdade de Ciência, Tecnologia e Engenharia (FCTE) da Universidade de Brasília (UnB).

O desenvolvimento está sendo realizado de forma incremental, acompanhando as etapas clássicas de construção de compiladores.

---

## Visão Geral

Atualmente, o projeto implementa as primeiras etapas do compilador:

- **Linguagem de entrada (parcial)**:
  - `int`
  - função `main`
  - declaração de variáveis
  - atribuição
  - operações aritméticas (`+`, `-`, `*`, `/`)
  - `return`

- **Pipeline atual**:
  - Análise léxica (Lexer)
  - Análise sintática (Parser)
  - Construção da AST (Árvore de Sintaxe Abstrata)

- **Tecnologias utilizadas**:
  - Python (implementação inicial de lexer e parser)
  - Estrutura modular (lexer, parser, ast_nodes)

---

## Estrutura do Projeto

    src/
    ├── lexer/        # Análise léxica (tokens e lexer)
    ├── parser/       # Análise sintática
    ├── ast_nodes/    # Definição dos nós da AST
    ├── codegen/      # (em desenvolvimento)
    └── main.py       # Execução principal

    tests/
    ├── basico.c      # Arquivo de teste inicial
    ├── test1.c
    ├── test2.c
    └── run_tests.sh  # Script de testes automatizados

---

## Instalação e Execução

### Requisitos

- Python 3.10 ou superior

### Execução

    cd src
    python main.py

---

## Testes Automatizados

Para executar os testes:

    ./tests/run_tests.sh

O script percorre automaticamente todos os arquivos `.c` presentes na pasta `tests/`.

---

## Status do Projeto

O projeto encontra-se em desenvolvimento inicial, com foco em:

- Estruturação do lexer
- Construção do parser
- Geração da AST
- Implementação de testes automatizados

### Próximas etapas

- Análise semântica
- Geração de código
- Integração com ferramentas como Flex/Bison

---

## Objetivo

Aplicar, na prática, os conceitos fundamentais de compiladores, incluindo:

- Análise léxica
- Análise sintática
- Construção de AST
- Organização de compiladores reais

---

## Membros da Equipe

| [![](https://avatars.githubusercontent.com/u/90862900?v=4)](https://github.com/arthurfernandesj) | [![](https://avatars.githubusercontent.com/u/129804255?v=4)](https://github.com/Beatriz-ge) | [![](https://avatars.githubusercontent.com/u/165945167?v=4)](https://github.com/BeatrizSants) | [![](https://avatars.githubusercontent.com/u/164348330?v=4)](https://github.com/dudaa28) | [![](https://avatars.githubusercontent.com/u/185298426?v=4)](https://github.com/isabellachoukaira) |
|:-:|:-:|:-:|:-:|:-:|
| [Arthur Fernandes](https://github.com/arthurfernandesj) | [Beatriz Lins](https://github.com/Beatriz-ge) | [Beatriz Santos](https://github.com/BeatrizSants) | [Maria Eduarda](https://github.com/dudaa28) | [Isabella Choukaira](https://github.com/isabellachoukaira) |
