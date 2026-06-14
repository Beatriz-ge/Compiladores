# Estrutura

A documentação do compilador foi organizada de forma modular para facilitar a navegação, manutenção e evolução do projeto ao longo do desenvolvimento da disciplina.

A estrutura do projeto está dividida em componentes responsáveis pelas diferentes etapas do compilador, incluindo análise léxica, análise sintática, construção de AST, análise semântica, tabela de símbolos, tabela de funções, geração de código, testes automatizados e documentação.

---

# Organização de Diretórios

```text
.
├── src/
│   ├── lexer.l                 # Analisador léxico implementado com Flex
│   ├── parser.y                # Analisador sintático implementado com Bison
│   ├── main.c                  # Arquivo principal do compilador
│   ├── common.h                # Definições compartilhadas entre módulos
│   ├── semantic.c              # Implementação da análise semântica
│   ├── semantic.h              # Interface da análise semântica
│   ├── tabela.c                # Implementação da tabela de símbolos
│   ├── tabela.h                # Interface da tabela de símbolos
│   ├── tabela_funcoes.c        # Implementação da tabela de funções
│   ├── tabela_funcoes.h        # Interface da tabela de funções
│   └── ast/
│       ├── ast.c               # Implementação da AST e geração de código
│       ├── ast.h               # Definição das estruturas da AST
│       ├── indent_manager.c    # Controle de indentação para código Python
│       └── indent_manager.h    # Interface do controle de indentação
│
├── tests/
│   ├── teste.c                 # Arquivo de teste manual
│   ├── saida.py                # Arquivo Python gerado pelo compilador
│   ├── run_tests.sh            # Script de execução dos testes automatizados
│   ├── README.md               # Documentação dos testes
│   └── casos/                  # Casos de teste positivos e negativos
│
├── build/                      # Arquivos intermediários gerados na compilação
├── bin/
│   └── compilador              # Binário final gerado
├── Makefile                    # Automação de build, limpeza, testes e cobertura
├── README.md                   # Documentação principal do projeto
└── .gitignore                  # Arquivos ignorados pelo Git
```

---

# Componentes Principais

## `src/`

Diretório principal do compilador. Contém os arquivos responsáveis pelas etapas de análise léxica, análise sintática, análise semântica, controle de tabelas auxiliares, AST e geração de código Python.

---

## `src/lexer.l`

Arquivo responsável pelo analisador léxico, implementado com Flex.

Suas principais responsabilidades são:

* Reconhecer palavras reservadas;
* Reconhecer tipos como `int`, `float`, `double` e `char`;
* Reconhecer identificadores;
* Reconhecer literais numéricos, caracteres e strings;
* Reconhecer operadores aritméticos, relacionais e de atribuição;
* Reconhecer delimitadores;
* Reconhecer comentários de linha e de bloco;
* Encaminhar tokens para o parser.

---

## `src/parser.y`

Arquivo responsável pelo analisador sintático, implementado com Bison.

Suas principais responsabilidades são:

* Definir a gramática do subconjunto da linguagem C;
* Validar declarações, atribuições, expressões e comandos;
* Reconhecer estruturas condicionais;
* Reconhecer funções e chamadas de função;
* Integrar regras sintáticas com a AST;
* Acionar validações semânticas;
* Reportar erros sintáticos.

---

## `src/main.c`

Arquivo principal do compilador.

É responsável por iniciar o processo de compilação, abrir o arquivo de entrada, acionar o parser e coordenar o fluxo principal de execução do compilador.

---

## `src/common.h`

Arquivo com definições compartilhadas entre diferentes módulos do compilador.

Pode conter constantes, estruturas, tipos auxiliares e declarações utilizadas por mais de uma etapa do projeto.

---

## `src/semantic.c` e `src/semantic.h`

Arquivos responsáveis pela análise semântica.

Suas principais responsabilidades são:

* Verificar variáveis não declaradas;
* Verificar redeclaração de variáveis;
* Validar compatibilidade de tipos;
* Controlar escopos;
* Apoiar validações envolvendo funções;
* Reportar erros semânticos.

---

## `src/tabela.c` e `src/tabela.h`

Arquivos responsáveis pela tabela de símbolos.

A tabela de símbolos armazena informações sobre variáveis declaradas, como:

* Nome;
* Tipo;
* Escopo;
* Linha de declaração.

Essa estrutura é utilizada principalmente para validar declarações, usos de variáveis e regras de escopo.

---

## `src/tabela_funcoes.c` e `src/tabela_funcoes.h`

Arquivos responsáveis pela tabela de funções.

A tabela de funções armazena informações sobre funções declaradas, como:

* Nome da função;
* Tipo de retorno;
* Quantidade de parâmetros;
* Dados necessários para validar chamadas de função.

Essa estrutura permite detectar chamadas com argumentos faltando ou em excesso.

---

## `src/ast/`

Diretório responsável pela AST e pelo controle de indentação da saída Python.

```text
src/ast/
├── ast.c
├── ast.h
├── indent_manager.c
└── indent_manager.h
```

### `ast.c` e `ast.h`

Responsáveis pela representação interna do programa e por funções relacionadas à geração de código Python.

### `indent_manager.c` e `indent_manager.h`

Responsáveis pelo controle de indentação do código Python gerado.

Esse controle é essencial porque Python utiliza indentação como parte da sintaxe da linguagem.

---

# Diretórios Auxiliares

## `tests/`

Diretório responsável pelos testes do compilador.

Contém arquivos de entrada em C, o script de testes automatizados e o arquivo Python gerado como saída.

```text
tests/
├── teste.c
├── saida.py
├── run_tests.sh
├── README.md
└── casos/
```

Os testes validam:

* Análise léxica;
* Análise sintática;
* Análise semântica;
* Geração de código;
* Controle de escopo;
* Compatibilidade de tipos;
* Funções;
* Ponteiros;
* Comentários;
* Entrada e saída básica;
* Casos válidos;
* Casos inválidos.

---

## `tests/casos/`

Diretório que armazena os casos de teste automatizados.

Exemplos de casos contemplados:

```text
basico.c
func_args_correto_ok.c
func_args_demais_erro.c
func_args_faltando_erro.c
func_sem_args_ok.c
if_apenas_ok.c
if_elif_else_ok.c
if_else_ok.c
ponteiro_01.c
ponteiro_02.c
ponteiro_03.c
ponteiro_04.c
ponteiro_05.c
printf_scanf.c
redeclaracao_erro.c
teste_escopo_global.c
teste_indentacao.c
tipo_char_int_ok.c
tipo_float_double_ok.c
tipo_int_float_ok.c
tipo_int_int_ok.c
tipo_mod_float_erro.c
var_nao_declarada_erro.c
```

Arquivos com nomes contendo `_erro` ou `_fail` representam testes negativos, ou seja, casos em que o compilador deve rejeitar corretamente a entrada.

---

## `build/`

Diretório utilizado para armazenar arquivos intermediários gerados durante a compilação.

Exemplos de arquivos que podem ser gerados nessa etapa:

* Arquivos produzidos pelo Flex;
* Arquivos produzidos pelo Bison;
* Arquivos objeto;
* Artefatos temporários de compilação.

---

## `bin/`

Diretório onde é armazenado o binário final do compilador.

```text
bin/
└── compilador
```

Após a execução do `make`, o compilador pode ser executado a partir desse binário.

---

## `Makefile`

Arquivo responsável pela automação do processo de compilação e limpeza do projeto.

Comandos principais:

```bash
make
make clean
make coverage
```

O comando `make` compila o projeto e gera o binário em:

```text
bin/compilador
```

---

# Execução do Projeto

Para compilar o projeto:

```bash
make clean
make
```

Para executar o compilador com um arquivo C de entrada:

```bash
./bin/compilador tests/teste.c
```

Após a execução, caso o código seja válido, o arquivo Python equivalente será gerado em:

```text
tests/saida.py
```

---

# Execução dos Testes

Para executar a suíte de testes automatizados:

```bash
bash tests/run_tests.sh
```

Para executar com cobertura:

```bash
make coverage
bash tests/run_tests.sh --coverage
```

Caso necessário, instale o `lcov`:

```bash
sudo apt update
sudo apt install lcov
```

---

# Estrutura Evolutiva

A organização do projeto foi construída para permitir crescimento gradual conforme novas etapas do compilador foram implementadas.

Durante a evolução do projeto, foram integrados componentes como:

* AST;
* Análise semântica;
* Tabela de símbolos;
* Tabela de funções;
* Controle de escopo;
* Controle de tipos;
* Geração de código Python;
* Controle de indentação;
* Testes automatizados;
* Cobertura de testes.

---

# Considerações

A estrutura atual do projeto reflete a implementação real do compilador, com arquivos organizados de forma simples e direta.

Diferentemente de uma divisão por pastas como `lexer/`, `parser/` ou `generator/`, o projeto concentra os principais módulos diretamente em `src/`, mantendo apenas a AST e o controle de indentação dentro de `src/ast/`.

Essa organização facilita a integração entre Flex, Bison, análise semântica, tabelas auxiliares e geração de código Python.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                     | Autor(es)                                               |
| :----: | :--------: | :------------------------------------------------------------ | :------------------------------------------------------ |
|  `1.0` | 30/04/2025 | Criação e desenvolvimento inicial do documento                | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.1` | 08/06/2026 | Atualização da estrutura conforme organização real do projeto | [Arthur Fernandes](https://github.com/arthurfernandesj) |
