# Compiladores - Grupo 11

Este projeto consiste no desenvolvimento de um compilador acadêmico para um subconjunto da linguagem C, com geração de código equivalente em Python.

O compilador foi implementado em C utilizando Flex e Bison, seguindo as principais etapas do processo de compilação: análise léxica, análise sintática, construção de AST, análise semântica, tabela de símbolos, tabela de funções e geração de código final em Python.

O projeto possui foco educacional e foi desenvolvido de forma incremental ao longo das sprints da disciplina de Compiladores.

<div class="hero-panel" markdown>

## Objetivo do projeto

Desenvolver um compilador funcional capaz de reconhecer, validar e traduzir programas escritos em um subconjunto da linguagem C para código equivalente em Python.

O projeto busca aplicar, de forma prática, os principais conceitos estudados na disciplina de Compiladores, incluindo:

1. Definição da linguagem de entrada, considerando sintaxe e semântica.
2. Implementação da análise léxica com Flex.
3. Construção do analisador sintático com Bison.
4. Construção e manipulação da AST.
5. Implementação da análise semântica.
6. Gerenciamento de tabela de símbolos e tabela de funções.
7. Geração de código final em Python.
8. Validação do compilador por meio de testes automatizados.

</div>

## Escopo do projeto

O compilador desenvolvido contempla um subconjunto da linguagem C, com suporte a declarações de variáveis, atribuições, expressões aritméticas, estruturas condicionais, funções, chamadas de função, comentários, entrada e saída básica, ponteiros e geração de código Python equivalente.

A implementação cobre as principais fases de um compilador:

| Etapa                | Descrição                                                                                                         | Status           |
| -------------------- | ----------------------------------------------------------------------------------------------------------------- | ---------------- |
| Análise Léxica       | Reconhecimento de tokens, palavras reservadas, identificadores, literais, operadores, delimitadores e comentários | Implementado     |
| Análise Sintática    | Validação da estrutura gramatical do código-fonte utilizando Bison                                                | Implementado     |
| AST                  | Construção de uma árvore sintática abstrata para representar o programa                                           | Implementado     |
| Análise Semântica    | Verificação de escopos, tipos, declarações, redeclarações e uso de identificadores                                | Implementado     |
| Tabela de Símbolos   | Armazenamento de variáveis, tipos, escopos e linhas de declaração                                                 | Implementado     |
| Tabela de Funções    | Registro e validação de funções, parâmetros e chamadas                                                            | Implementado     |
| Geração de Código    | Tradução do código C validado para Python                                                                         | Implementado     |
| Testes Automatizados | Execução de casos de teste positivos e negativos                                                                  | Implementado     |
| Cobertura de Testes  | Suporte à geração de relatório de cobertura com ferramentas como `gcov` e `lcov`                                  | Implementado     |
| Otimização de Código | Otimizações avançadas no código gerado                                                                            | Não implementado |
| Interface Gráfica    | Interface visual para uso do compilador                                                                           | Não implementado |

## Funcionalidades implementadas

Entre as funcionalidades já desenvolvidas no compilador, destacam-se:

* Reconhecimento de tipos como `int`, `float`, `double` e `char`.
* Declaração e atribuição de variáveis.
* Controle de escopo local e global.
* Verificação de variáveis não declaradas.
* Verificação de redeclaração de variáveis.
* Análise de compatibilidade entre tipos.
* Suporte a expressões aritméticas e relacionais.
* Suporte a estruturas condicionais `if`, `else` e encadeamentos.
* Suporte a funções com e sem argumentos.
* Validação da quantidade de argumentos em chamadas de função.
* Suporte a comentários de linha e comentários de bloco.
* Conversão de comentários C para comentários Python.
* Suporte básico a `printf` e `scanf`.
* Suporte a ponteiros dentro do subconjunto definido.
* Controle de indentação para geração correta de blocos em Python.
* Geração de arquivo de saída `saida.py`.
* Execução de testes automatizados por script.

## Tecnologias utilizadas

| Tecnologia          | Finalidade                                         |
| ------------------- | -------------------------------------------------- |
| C                   | Linguagem principal de implementação do compilador |
| Flex                | Geração do analisador léxico                       |
| Bison               | Geração do analisador sintático                    |
| Make                | Automação da compilação                            |
| Python              | Linguagem de saída gerada pelo compilador          |
| Bash                | Execução dos scripts de teste                      |
| gcov/lcov           | Geração de relatório de cobertura                  |
| Git/GitHub          | Versionamento e colaboração                        |
| GitHub Pages/MkDocs | Hospedagem da documentação                         |

## Navegação principal

<div class="grid cards" markdown>

* [Sobre](./sobre/escopo.md)

  ---

  Visão geral, escopo, objetivos e funcionalidades do projeto.

* [Arquitetura](./arquitetura/visao-geral.md)

  ---

  Detalhamento das etapas do compilador e funcionamento interno.

* [Planejamento](./planejamento/backlog.md)

  ---

  Organização das tarefas, backlog e sprints.

* [Evolução](./evolucao.md)

  ---

  Acompanhamento das entregas, incrementos e melhorias realizadas.

* [Testes](./testes/testes.md)

  ---

  Estratégias de teste, validação, casos positivos e negativos.

* [Documentação](./documentacao/estrutura.md)

  ---

  Estrutura do projeto, instruções de compilação e execução.

* [Demo](./demo/demo.md)

  ---

  Demonstração prática do funcionamento do compilador C para Python.

</div>

## Como executar o projeto

Para compilar o compilador:

```bash
make clean
make
```

Para executar o compilador com um arquivo de entrada:

```bash
./bin/compilador tests/teste.c
```

Após a execução, caso o código-fonte seja válido, o arquivo Python equivalente será gerado em:

```bash
tests/saida.py
```

Para executar a suíte de testes:

```bash
bash tests/run_tests.sh
```

## Membros da Equipe

| [![](https://avatars.githubusercontent.com/u/90862900?v=4)](https://github.com/arthurfernandesj) | [![](https://avatars.githubusercontent.com/u/129804255?v=4)](https://github.com/Beatriz-ge) | [![](https://avatars.githubusercontent.com/u/165945167?v=4)](https://github.com/BeatrizSants) | [![](https://avatars.githubusercontent.com/u/164348330?v=4)](https://github.com/dudaa28) | [![](https://avatars.githubusercontent.com/u/185298426?v=4)](https://github.com/isabellachoukaira) |
| :----------------------------------------------------------------------------------------------: | :-----------------------------------------------------------------------------------------: | :-------------------------------------------------------------------------------------------: | :--------------------------------------------------------------------------------------: | :------------------------------------------------------------------------------------------------: |
|                      [Arthur Fernandes](https://github.com/arthurfernandesj)                     |                        [Beatriz Lins](https://github.com/Beatriz-ge)                        |                       [Beatriz Santos](https://github.com/BeatrizSants)                       |                        [Maria Eduarda](https://github.com/dudaa28)                       |                     [Isabella Choukaira](https://github.com/isabellachoukaira)                     |
