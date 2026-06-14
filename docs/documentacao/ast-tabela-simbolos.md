# AST e Tabela de Símbolos

Esta seção documenta dois componentes centrais do compilador: a AST, responsável pela representação interna do programa, e a tabela de símbolos, responsável pelo armazenamento e controle dos identificadores declarados.

Esses componentes são fundamentais para integrar a análise sintática, a análise semântica e a geração de código Python.

---

# AST — Árvore Sintática Abstrata

A AST, ou Árvore Sintática Abstrata, é uma estrutura utilizada para representar internamente o programa após o reconhecimento sintático.

No projeto, a AST está relacionada principalmente aos arquivos:

```text
src/ast/ast.c
src/ast/ast.h
```

Além disso, a geração de código Python e o controle de indentação também estão associados à estrutura da AST.

---

# Objetivo da AST

O objetivo da AST é organizar as estruturas do código-fonte em uma representação hierárquica, facilitando as próximas etapas do compilador.

A AST permite representar:

* Declarações de variáveis;
* Atribuições;
* Expressões aritméticas;
* Expressões relacionais;
* Estruturas condicionais;
* Funções;
* Chamadas de função;
* Comandos de retorno;
* Comentários;
* Comandos básicos de entrada e saída;
* Estruturas básicas relacionadas a ponteiros.

---

# Papel da AST no Compilador

A AST atua como uma ponte entre a análise sintática e a geração de código.

O fluxo pode ser representado da seguinte forma:

```text
Código em C
     ↓
Lexer
     ↓
Parser
     ↓
AST
     ↓
Análise Semântica
     ↓
Geração de Código Python
```

Durante a análise sintática, o parser reconhece as estruturas do programa e pode criar ou organizar nós correspondentes na AST. Depois, essas estruturas são utilizadas para validação e geração da saída equivalente em Python.

---

# Exemplo Conceitual de AST

Considere o seguinte código em C:

```c
int main() {
    int a = 10;
    int b = 20;
    int c;

    c = a + b;

    return c;
}
```

Uma representação conceitual simplificada da AST seria:

```text
programa
└── funcao main
    └── bloco
        ├── declaracao: int a = 10
        ├── declaracao: int b = 20
        ├── declaracao: int c
        ├── atribuicao
        │   ├── identificador: c
        │   └── expressao: a + b
        └── retorno: c
```

Essa representação não corresponde necessariamente à estrutura exata dos nós no código, mas demonstra a organização lógica do programa dentro do compilador.

---

# Exemplos de Nós Representados

## Declaração

```c
int x = 10;
```

Representação conceitual:

```text
declaracao
├── tipo: int
├── identificador: x
└── valor: 10
```

---

## Atribuição

```c
x = a + b;
```

Representação conceitual:

```text
atribuicao
├── identificador: x
└── expressao
    ├── operador: +
    ├── operando esquerdo: a
    └── operando direito: b
```

---

## Condicional

```c
if (x > 0) {
    x += 1;
}
```

Representação conceitual:

```text
condicional
├── condicao: x > 0
└── bloco
    └── atribuicao composta: x += 1
```

---

# Geração de Código a partir da AST

A geração de código Python utiliza as estruturas reconhecidas pelo compilador para produzir uma saída equivalente.

Exemplo de entrada em C:

```c
if (x > 0) {
    x += 1;
}
```

Saída em Python:

```python
if x > 0:
    x += 1
```

Como Python utiliza indentação obrigatória, a geração de código também depende do controle de indentação implementado nos arquivos:

```text
src/ast/indent_manager.c
src/ast/indent_manager.h
```

---

# Tabela de Símbolos

A tabela de símbolos é uma estrutura utilizada para armazenar informações sobre identificadores declarados no programa.

No projeto, a tabela de símbolos está implementada nos arquivos:

```text
src/tabela.c
src/tabela.h
```

---

# Objetivo da Tabela de Símbolos

O objetivo da tabela de símbolos é permitir que o compilador controle informações importantes sobre variáveis e identificadores durante a análise semântica.

Ela é utilizada para verificar:

* Se uma variável foi declarada antes do uso;
* Se uma variável foi redeclarada no mesmo escopo;
* Qual o tipo associado a um identificador;
* Em qual escopo a variável foi declarada;
* Em qual linha a declaração ocorreu.

---

# Informações Armazenadas

A tabela de símbolos armazena, de forma conceitual, informações como:

| Campo  | Descrição                                   |
| ------ | ------------------------------------------- |
| Nome   | Nome do identificador declarado             |
| Tipo   | Tipo associado ao identificador             |
| Escopo | Escopo em que o identificador foi declarado |
| Linha  | Linha em que a declaração ocorreu           |

Exemplo conceitual:

```text
NOME       | TIPO       | ESCOPO | LINHA
-----------------------------------------
a          | int        | 1      | 3
b          | int        | 1      | 4
c          | int        | 1      | 5
```

---

# Uso na Análise Semântica

A tabela de símbolos é consultada durante a análise semântica para validar o uso correto das variáveis.

## Variável Declarada

```c
int x;
x = 10;
```

Nesse caso, `x` é inserida na tabela de símbolos no momento da declaração e depois consultada durante a atribuição.

---

## Variável Não Declarada

```c
x = 10;
```

Nesse caso, o compilador consulta a tabela de símbolos e não encontra `x`, gerando erro semântico.

Resultado esperado:

```text
Erro semântico: variável 'x' não declarada
```

---

## Redeclaração

```c
int x;
float x;
```

Nesse caso, a tabela de símbolos identifica que `x` já existe no mesmo escopo e o compilador reporta erro semântico.

Resultado esperado:

```text
Erro semântico: variável 'x' já declarada neste escopo
```

---

# Controle de Escopo

A tabela de símbolos também é utilizada para diferenciar variáveis declaradas em escopos diferentes.

Exemplo:

```c
int global;

int main() {
    int local;
    local = global + 1;
    return local;
}
```

Representação conceitual:

```text
NOME       | TIPO       | ESCOPO
-------------------------------
global     | int        | global
local      | int        | main
```

Esse controle permite que o compilador diferencie variáveis globais, locais e variáveis declaradas em blocos específicos.

---

# Tabela de Funções

Além da tabela de símbolos, o projeto também possui uma tabela de funções, implementada nos arquivos:

```text
src/tabela_funcoes.c
src/tabela_funcoes.h
```

Essa tabela é utilizada para armazenar informações sobre funções declaradas e validar chamadas de função.

---

# Objetivo da Tabela de Funções

A tabela de funções permite controlar:

* Nome da função;
* Tipo de retorno;
* Quantidade de parâmetros;
* Validação de chamadas;
* Detecção de argumentos faltando ou em excesso.

Exemplo conceitual:

```text
FUNÇÃO     | RETORNO | PARÂMETROS
----------------------------------
soma       | int     | 2
main       | int     | 0
```

---

# Exemplo de Validação de Função

## Código válido

```c
int soma(int a, int b) {
    return a + b;
}

int main() {
    int resultado;
    resultado = soma(10, 20);
    return resultado;
}
```

A chamada `soma(10, 20)` é válida porque a função foi declarada com dois parâmetros.

---

## Código inválido

```c
int soma(int a, int b) {
    return a + b;
}

int main() {
    int resultado;
    resultado = soma(10);
    return resultado;
}
```

Resultado esperado:

```text
Erro semântico: quantidade incorreta de argumentos na chamada da função 'soma'
```

---

# Integração entre AST, Tabela de Símbolos e Geração

A integração entre esses componentes pode ser resumida da seguinte forma:

```text
Parser
  ↓
AST
  ↓
Análise Semântica
  ↓
Tabela de Símbolos
  ↓
Tabela de Funções
  ↓
Geração de Código Python
```

A AST organiza a estrutura do programa, enquanto as tabelas auxiliam na validação semântica. Após essas validações, o compilador pode gerar código Python equivalente.

---

# Considerações

A AST e as tabelas auxiliares são fundamentais para tornar o compilador mais organizado, modular e extensível.

A AST permite representar o programa internamente de forma hierárquica, enquanto a tabela de símbolos e a tabela de funções garantem maior consistência durante a análise semântica.

Esses componentes também facilitam futuras expansões, como suporte mais avançado a escopos, tipos, funções, arrays, ponteiros e otimizações.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                           | Autor(es)                                               |
| :----: | :--------: | :-------------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 14/06/2026 | Criação da documentação da AST e tabela de símbolos | [Arthur Fernandes](https://github.com/arthurfernandesj) |
