# Arquitetura — Semântico

O módulo semântico é responsável por validar o significado das estruturas reconhecidas pelo analisador sintático.

Essa etapa garante que o programa não seja apenas sintaticamente correto, mas também semanticamente consistente, verificando regras relacionadas a tipos, escopo, declarações, uso de variáveis e chamadas de função.

No projeto, a análise semântica é implementada principalmente pelos arquivos `src/semantic.c` e `src/semantic.h`, com apoio da tabela de símbolos e da tabela de funções.

---

# Objetivo

O objetivo do módulo semântico é realizar verificações relacionadas ao uso correto de identificadores, tipos, escopos e funções dentro do programa.

Essa etapa atua como uma camada de validação entre a análise sintática e a geração de código, impedindo que programas estruturalmente válidos, mas semanticamente incorretos, sejam traduzidos para Python sem verificação adequada.

---

# Responsabilidades

O analisador semântico é responsável por:

* Verificar se variáveis foram declaradas antes do uso;
* Detectar redeclaração de variáveis no mesmo escopo;
* Controlar escopos locais e globais;
* Validar compatibilidade entre tipos;
* Verificar atribuições entre tipos compatíveis;
* Registrar identificadores na tabela de símbolos;
* Validar chamadas de função;
* Verificar quantidade de argumentos em chamadas de função;
* Integrar informações da tabela de símbolos e da tabela de funções;
* Reportar erros semânticos encontrados durante a compilação.

---

# Verificações Realizadas

## Variáveis Declaradas

O módulo semântico valida se uma variável foi declarada antes de ser utilizada.

### Exemplo válido

```c id="qt6q3i"
int x;
x = 10;
```

Nesse caso, a variável `x` foi declarada antes da atribuição, portanto o uso é considerado válido.

---

## Variável Não Declarada

Quando uma variável é utilizada sem declaração prévia, o compilador deve reportar erro semântico.

### Exemplo inválido

```c id="z6bnh1"
y = 10;
```

### Resultado esperado

```text id="65s52o"
Erro semântico: variável 'y' não declarada
```

---

## Redeclaração de Variáveis

O módulo semântico também verifica se uma variável foi declarada mais de uma vez no mesmo escopo.

### Exemplo inválido

```c id="klbc9q"
int x;
float x;
```

### Resultado esperado

```text id="wmd7m1"
Erro semântico: variável 'x' já declarada neste escopo
```

Esse controle evita ambiguidade na identificação de variáveis durante a análise e geração de código.

---

## Controle de Escopo

A análise semântica controla o escopo em que cada variável foi declarada.

Isso permite diferenciar variáveis globais, variáveis locais e variáveis declaradas em blocos diferentes.

### Exemplo

```c id="58ax4c"
int x;

int main() {
    int y;
    y = x + 1;
    return y;
}
```

Nesse exemplo, `x` pertence ao escopo global, enquanto `y` pertence ao escopo local da função `main`.

---

## Compatibilidade de Tipos

O módulo semântico verifica a compatibilidade entre tipos em declarações, atribuições e expressões.

### Exemplo

```c id="2k0i9f"
int x;
x = 3.14;
```

### Resultado esperado

```text id="1w2idm"
Aviso ou erro de incompatibilidade de tipos
```

A forma exata do tratamento depende das regras definidas no compilador para conversões entre tipos. Em geral, o objetivo é impedir atribuições inválidas ou registrar inconsistências relevantes.

---

## Chamadas de Função

O compilador possui uma tabela de funções para registrar funções declaradas e validar chamadas feitas durante o programa.

### Exemplo válido

```c id="vhlcuy"
int soma(int a, int b) {
    return a + b;
}

int main() {
    int resultado;
    resultado = soma(10, 20);
    return resultado;
}
```

Nesse caso, a função `soma` foi declarada com dois parâmetros e chamada com dois argumentos, portanto a chamada é válida.

---

## Quantidade Incorreta de Argumentos

Quando uma função é chamada com quantidade incorreta de argumentos, o módulo semântico deve reportar erro.

### Exemplo inválido

```c id="cyyydj"
int soma(int a, int b) {
    return a + b;
}

int main() {
    int resultado;
    resultado = soma(10);
    return resultado;
}
```

### Resultado esperado

```text id="n1zafu"
Erro semântico: quantidade incorreta de argumentos na chamada da função 'soma'
```

---

# Fluxo Semântico

```text id="oykqnf"
Estrutura Sintática / AST
        ↓
Verificações Semânticas
        ↓
Consulta à Tabela de Símbolos
        ↓
Consulta à Tabela de Funções
        ↓
Validação de Tipos, Escopos e Chamadas
        ↓
Código Semanticamente Válido
```

---

# Componentes Associados

| Componente         | Função                                                            |
| ------------------ | ----------------------------------------------------------------- |
| `semantic.c`       | Implementa as principais regras e validações semânticas           |
| `semantic.h`       | Define a interface das funções semânticas                         |
| `tabela.c`         | Implementa a tabela de símbolos                                   |
| `tabela.h`         | Define a estrutura e operações da tabela de símbolos              |
| `tabela_funcoes.c` | Implementa o controle de funções declaradas                       |
| `tabela_funcoes.h` | Define a estrutura e operações da tabela de funções               |
| `parser.y`         | Aciona verificações semânticas durante o reconhecimento de regras |
| `ast.c`            | Apoia a representação interna e a geração de código               |

---

# Estrutura dos Arquivos

A estrutura relacionada à análise semântica está distribuída nos seguintes arquivos:

```text id="jbbfyg"
src/
├── semantic.c              # Implementação da análise semântica
├── semantic.h              # Interface da análise semântica
├── tabela.c                # Implementação da tabela de símbolos
├── tabela.h                # Interface da tabela de símbolos
├── tabela_funcoes.c        # Implementação da tabela de funções
├── tabela_funcoes.h        # Interface da tabela de funções
├── parser.y                # Integração com regras sintáticas e ações semânticas
└── ast/
    ├── ast.c               # Apoio à AST e geração de código
    └── ast.h               # Definições da AST
```

---

# Tabela de Símbolos

A tabela de símbolos armazena informações sobre variáveis declaradas no programa.

Entre as informações controladas estão:

* Nome do identificador;
* Tipo declarado;
* Escopo;
* Linha de declaração.

Exemplo conceitual:

```text id="41y8kk"
NOME       | TIPO       | ESCOPO | LINHA
-----------------------------------------
x          | int        | 1      | 3
resultado  | float      | 1      | 4
```

Essa tabela é utilizada para verificar se uma variável já foi declarada, se está sendo usada corretamente e se há conflitos de escopo.

---

# Tabela de Funções

A tabela de funções armazena informações sobre funções declaradas no programa.

Entre as informações controladas estão:

* Nome da função;
* Tipo de retorno;
* Quantidade de parâmetros;
* Informações necessárias para validação de chamadas.

Exemplo conceitual:

```text id="8hso7s"
FUNÇÃO     | RETORNO | PARÂMETROS
----------------------------------
soma       | int     | 2
main       | int     | 0
```

Essa tabela permite validar se uma função foi chamada corretamente e se a quantidade de argumentos informada corresponde à declaração da função.

---

# Tratamento de Erros Semânticos

O módulo semântico é capaz de identificar inconsistências relacionadas ao significado do programa.

Exemplos de erros tratados:

```text id="npu4ff"
Variável não declarada
Variável redeclarada no mesmo escopo
Tipo incompatível em atribuição
Quantidade incorreta de argumentos em chamada de função
Uso incorreto de identificadores
```

Esses erros impedem que o compilador considere válido um programa que, apesar de possuir uma estrutura sintática correta, apresenta inconsistências lógicas ou semânticas.

---

# Exemplo de Erro Semântico

## Entrada

```c id="8470jh"
int main() {
    int x;
    y = 10;
    return x;
}
```

## Resultado esperado

```text id="d75qem"
Erro semântico: variável 'y' não declarada
```

Nesse exemplo, o código possui estrutura sintática válida, mas apresenta erro semântico porque a variável `y` é utilizada sem ter sido declarada.

---

# Integração com Parser e Geração de Código

A análise semântica é integrada ao parser para validar as estruturas reconhecidas durante a análise sintática.

Após a validação semântica, as estruturas consideradas corretas podem seguir para a geração de código Python.

```text id="prc4w5"
lexer.l
   ↓ tokens
parser.y
   ↓ regras sintáticas
semantic.c / tabela.c / tabela_funcoes.c
   ↓ validação
ast.c
   ↓ geração
saida.py
```

---

# Considerações

A análise semântica complementa a validação realizada pelo parser, garantindo maior confiabilidade no processo de geração de código.

Enquanto o parser verifica se a estrutura do programa está correta, o módulo semântico verifica se o significado das construções é consistente dentro das regras do compilador.

A arquitetura atual permite futuras expansões, como:

* Verificações mais detalhadas de tipos;
* Melhor tratamento de conversões implícitas;
* Validação mais avançada de retorno de funções;
* Aprimoramento das mensagens de erro;
* Maior suporte a escopos aninhados;
* Ampliação das regras para ponteiros e arrays.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                                  | Autor(es)                                               |
| :----: | :--------: | :------------------------------------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 30/04/2025 | Criação da documentação do módulo semântico                                | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.1` | 08/06/2026 | Atualização do módulo semântico conforme implementação atual do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |
