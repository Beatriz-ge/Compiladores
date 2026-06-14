# Documentação Técnica do Compilador

Esta seção apresenta a documentação técnica do compilador desenvolvido no projeto, descrevendo sua arquitetura, funcionamento interno, principais módulos e fluxo de execução.

O compilador foi desenvolvido em C, utilizando Flex para a análise léxica e Bison para a análise sintática. A saída gerada é um código equivalente em Python.

---

# Objetivo Técnico

O objetivo técnico do compilador é processar arquivos escritos em um subconjunto da linguagem C, validar sua estrutura léxica, sintática e semântica, e gerar um arquivo Python equivalente.

O compilador executa as seguintes etapas principais:

1. Leitura do arquivo de entrada em C;
2. Análise léxica;
3. Análise sintática;
4. Construção/uso da AST;
5. Análise semântica;
6. Consulta à tabela de símbolos;
7. Consulta à tabela de funções;
8. Geração de código Python;
9. Escrita do arquivo `tests/saida.py`.

---

# Tecnologias Utilizadas

| Tecnologia | Finalidade |
|---|---|
| C | Linguagem principal de implementação |
| Flex | Geração do analisador léxico |
| Bison | Geração do analisador sintático |
| GCC | Compilação dos arquivos C |
| Make | Automação do processo de build |
| Bash | Execução da suíte de testes |
| Python | Linguagem de saída gerada pelo compilador |
| gcov/lcov | Geração de cobertura de testes |

---

# Módulos Principais

## `src/lexer.l`

Responsável pela análise léxica. Reconhece tokens como palavras reservadas, tipos, identificadores, operadores, delimitadores, literais, comentários e símbolos relacionados a ponteiros.

## `src/parser.y`

Responsável pela análise sintática. Define a gramática do subconjunto de C aceito pelo compilador e integra regras sintáticas com ações semânticas e construção/uso da AST.

## `src/semantic.c` e `src/semantic.h`

Responsáveis pela análise semântica. Validam variáveis não declaradas, redeclarações, compatibilidade de tipos, escopos e chamadas de função.

## `src/tabela.c` e `src/tabela.h`

Implementam a tabela de símbolos, utilizada para armazenar variáveis, tipos, escopos e linhas de declaração.

## `src/tabela_funcoes.c` e `src/tabela_funcoes.h`

Implementam a tabela de funções, utilizada para registrar funções declaradas e validar chamadas com quantidade correta de argumentos.

## `src/ast/ast.c` e `src/ast/ast.h`

Responsáveis pela representação interna das estruturas do programa e pela geração de código Python.

## `src/ast/indent_manager.c` e `src/ast/indent_manager.h`

Responsáveis pelo controle de indentação necessário para gerar código Python válido.

---

# Fluxo Técnico de Execução

```text
Arquivo .c de entrada
        ↓
main.c
        ↓
lexer.l
        ↓
parser.y
        ↓
AST
        ↓
semantic.c
        ↓
tabela.c / tabela_funcoes.c
        ↓
ast.c
        ↓
tests/saida.py
```

---

# Entrada e Saída

## Entrada

O compilador recebe como entrada um arquivo `.c`.

Exemplo:

```c
int main() {
    int a = 10;
    int b = 20;
    int c;

    c = a + b;

    return c;
}
```

## Saída

O compilador gera um arquivo Python em `tests/saida.py`.

Exemplo:

```python
a = 10
b = 20
c = None

c = a + b

return c
```

---

# Verificações Realizadas

O compilador realiza verificações em diferentes níveis:

| Etapa | Verificações |
|---|---|
| Léxica | Tokens válidos, palavras reservadas, operadores, delimitadores e literais |
| Sintática | Estrutura gramatical, comandos, expressões, blocos e funções |
| Semântica | Escopo, tipos, variáveis declaradas, redeclarações e chamadas de função |
| Geração | Tradução para Python, indentação e saída final |

---

# Testes

A suíte de testes é executada com:

```bash
bash tests/run_tests.sh
```

Para cobertura:

```bash
make coverage
bash tests/run_tests.sh --coverage
```

---

# Considerações Técnicas

O compilador não busca implementar toda a linguagem C. O foco está em um subconjunto controlado, suficiente para demonstrar as principais etapas de construção de compiladores.

A arquitetura modular facilita a manutenção e permite expansão futura, como melhoria no tratamento de erros, ampliação da gramática, suporte mais completo a ponteiros, arrays e otimizações.

---

# Histórico de Versões

| Versão | Data | Descrição | Autor(es) |
|:--:|:--:|:--|:--|
| `1.0` | 14/06/2026 | Criação da documentação técnica do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |