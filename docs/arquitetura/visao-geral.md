# Arquitetura — Visão Geral

A arquitetura do compilador foi projetada de forma modular, permitindo a separação das responsabilidades de cada etapa do processo de compilação.

O sistema é organizado em componentes responsáveis pela leitura do código-fonte em C, análise léxica, análise sintática, construção da AST, análise semântica, controle de tabelas auxiliares e geração de código equivalente em Python.

---

# Objetivo da Arquitetura

A arquitetura tem como finalidade:

* Facilitar a manutenção e evolução do projeto;
* Separar responsabilidades entre os módulos;
* Organizar o fluxo de compilação em etapas bem definidas;
* Permitir a integração entre lexer, parser, AST, semântica e geração de código;
* Simplificar testes, depuração e validação das funcionalidades;
* Apoiar a evolução incremental do compilador ao longo das sprints.

---

# Visão Geral do Fluxo

O compilador segue o fluxo clássico de processamento utilizado em compiladores tradicionais, adaptado ao objetivo do projeto: traduzir um subconjunto da linguagem C para Python.

```text
Código Fonte em C
        ↓
Análise Léxica
        ↓
Geração de Tokens
        ↓
Análise Sintática
        ↓
Construção da AST
        ↓
Análise Semântica
        ↓
Tabela de Símbolos e Tabela de Funções
        ↓
Geração de Código
        ↓
Código Python
```

---

# Componentes da Arquitetura

## Analisador Léxico

O analisador léxico é responsável por realizar a leitura do código-fonte e identificar os elementos básicos da linguagem, chamados tokens.

No projeto, essa etapa é implementada com Flex, por meio do arquivo `src/lexer.l`.

### Principais responsabilidades

* Reconhecer palavras-chave da linguagem C;
* Identificar tipos como `int`, `float`, `double` e `char`;
* Reconhecer identificadores;
* Reconhecer literais numéricos e caracteres;
* Identificar operadores aritméticos, relacionais e de atribuição;
* Identificar delimitadores, como parênteses, chaves, vírgulas e ponto e vírgula;
* Reconhecer comentários de linha e comentários de bloco;
* Encaminhar tokens para o analisador sintático;
* Reportar erros léxicos quando encontrados.

### Ferramenta utilizada

* Flex

---

## Analisador Sintático

O analisador sintático é responsável por validar se a sequência de tokens recebida do analisador léxico respeita a gramática definida para o subconjunto da linguagem C suportado pelo compilador.

No projeto, essa etapa é implementada com Bison, por meio do arquivo `src/parser.y`.

### Principais responsabilidades

* Validar a estrutura gramatical do programa;
* Reconhecer declarações de variáveis;
* Reconhecer atribuições;
* Reconhecer expressões aritméticas e relacionais;
* Reconhecer estruturas condicionais;
* Reconhecer funções e chamadas de função;
* Reconhecer comandos de entrada e saída básica;
* Integrar a análise sintática com a construção da AST;
* Acionar verificações semânticas quando necessário;
* Reportar erros sintáticos.

### Ferramenta utilizada

* Bison

---

## AST — Árvore Sintática Abstrata

A AST é responsável por representar internamente a estrutura do programa analisado.

No projeto, os arquivos relacionados à AST estão organizados na pasta `src/ast/`.

### Principais responsabilidades

* Representar comandos, expressões, declarações e funções;
* Organizar hierarquicamente as estruturas do programa;
* Auxiliar a análise semântica;
* Servir de base para a geração de código Python;
* Permitir uma separação mais clara entre parsing, validação e geração de código.

### Arquivos relacionados

```text
src/ast/
├── ast.c
├── ast.h
├── indent_manager.c
└── indent_manager.h
```

---

## Análise Semântica

A análise semântica é responsável por validar regras relacionadas ao significado do programa, garantindo que o código seja não apenas sintaticamente correto, mas também consistente em relação a tipos, escopos e declarações.

No projeto, essa etapa é implementada principalmente nos arquivos `src/semantic.c` e `src/semantic.h`.

### Principais responsabilidades

* Verificar se variáveis foram declaradas antes do uso;
* Detectar redeclaração de variáveis no mesmo escopo;
* Validar compatibilidade entre tipos;
* Controlar escopos locais e globais;
* Validar chamadas de função;
* Verificar quantidade de argumentos em chamadas de função;
* Reportar erros semânticos encontrados durante a compilação.

---

## Tabela de Símbolos

A tabela de símbolos é responsável por armazenar informações sobre os identificadores declarados no programa.

No projeto, essa estrutura é implementada nos arquivos `src/tabela.c` e `src/tabela.h`.

### Principais responsabilidades

* Registrar variáveis declaradas;
* Armazenar nome, tipo, escopo e linha de declaração;
* Auxiliar na verificação de variáveis não declaradas;
* Auxiliar na detecção de redeclarações;
* Apoiar a análise semântica.

---

## Tabela de Funções

A tabela de funções é responsável por armazenar informações sobre funções declaradas e utilizadas no programa.

No projeto, essa estrutura é implementada nos arquivos `src/tabela_funcoes.c` e `src/tabela_funcoes.h`.

### Principais responsabilidades

* Registrar funções declaradas;
* Armazenar quantidade de parâmetros;
* Validar chamadas de função;
* Detectar chamadas com argumentos faltando ou em excesso;
* Apoiar a análise semântica.

---

## Controle de Indentação

Como a saída do compilador é Python, a indentação correta dos blocos é essencial para que o código gerado seja válido.

O controle de indentação é implementado nos arquivos `src/ast/indent_manager.c` e `src/ast/indent_manager.h`.

### Principais responsabilidades

* Controlar o nível atual de indentação;
* Gerar blocos Python corretamente indentados;
* Apoiar a tradução de estruturas como condicionais e funções;
* Evitar inconsistências na saída gerada.

---

## Geração de Código

A geração de código é responsável pela tradução das estruturas válidas da linguagem C para código equivalente em Python.

Essa etapa utiliza as estruturas reconhecidas pelo parser e representadas na AST para produzir o arquivo de saída `tests/saida.py`.

### Principais responsabilidades

* Converter declarações de variáveis para Python;
* Traduzir atribuições;
* Traduzir expressões aritméticas e relacionais;
* Traduzir estruturas condicionais;
* Traduzir funções e chamadas de função;
* Converter comentários de C para comentários Python;
* Adaptar comandos de entrada e saída básica;
* Gerar código Python com indentação correta.

---

# Organização dos Módulos

A organização atual do projeto segue uma estrutura simples e voltada à integração entre Flex, Bison, análise semântica, AST e geração de código.

```text
src/
├── lexer.l                 # Analisador léxico implementado com Flex
├── parser.y                # Analisador sintático implementado com Bison
├── main.c                  # Arquivo principal do compilador
├── common.h                # Definições compartilhadas
├── semantic.c              # Implementação da análise semântica
├── semantic.h              # Interface da análise semântica
├── tabela.c                # Implementação da tabela de símbolos
├── tabela.h                # Interface da tabela de símbolos
├── tabela_funcoes.c        # Implementação da tabela de funções
├── tabela_funcoes.h        # Interface da tabela de funções
└── ast/
    ├── ast.c               # Implementação da AST e geração de código
    ├── ast.h               # Definição das estruturas da AST
    ├── indent_manager.c    # Controle de indentação para Python
    └── indent_manager.h    # Interface do controle de indentação
```

Além da pasta `src/`, o projeto também utiliza diretórios auxiliares:

```text
.
├── bin/                    # Binário final gerado
├── build/                  # Arquivos intermediários de compilação
├── tests/                  # Casos de teste e script de execução
├── Makefile                # Automação de build, limpeza e cobertura
└── README.md               # Documentação principal do projeto
```

---

# Tecnologias Utilizadas

| Tecnologia          | Finalidade                                         |
| ------------------- | -------------------------------------------------- |
| C                   | Linguagem principal de implementação do compilador |
| Flex                | Geração do analisador léxico                       |
| Bison               | Geração do analisador sintático                    |
| Make                | Automação do processo de compilação                |
| Python              | Linguagem de saída gerada pelo compilador          |
| Bash                | Execução dos scripts de teste                      |
| gcov/lcov           | Geração de relatório de cobertura                  |
| Git/GitHub          | Versionamento e colaboração                        |
| GitHub Pages/MkDocs | Hospedagem da documentação                         |

---

# Modelo Arquitetural

O projeto segue uma arquitetura em pipeline, na qual cada etapa processa a saída produzida pela etapa anterior.

Esse modelo facilita:

* Modularização;
* Isolamento de responsabilidades;
* Evolução incremental;
* Testabilidade;
* Manutenção;
* Integração progressiva de novas funcionalidades.

O fluxo principal pode ser resumido da seguinte forma:

```text
lexer.l → parser.y → AST → análise semântica → geração de código Python
```

---

# Considerações Arquiteturais

A arquitetura foi planejada visando simplicidade, clareza didática e modularidade.

Durante a evolução do projeto, componentes inicialmente planejados foram implementados e integrados ao compilador, como a AST, a tabela de símbolos, a tabela de funções, o controle de escopo, a validação semântica e o controle de indentação para geração de Python.

A arquitetura atual permite futuras expansões, incluindo:

* Ampliação do subconjunto da linguagem C suportado;
* Melhoria no tratamento de erros;
* Implementação de otimizações;
* Suporte a novas estruturas da linguagem;
* Geração de código intermediário;
* Aprimoramento da análise semântica;
* Aumento da cobertura de testes.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                             | Autor(es)                                               |
| :----: | :--------: | :-------------------------------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 30/04/2025 | Criação da documentação de arquitetura                                | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.1` | 08/06/2026 | Atualização da arquitetura conforme implementação atual do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |
