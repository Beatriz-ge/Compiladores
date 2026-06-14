# Gramática Flex/Bison

Esta seção documenta a gramática utilizada pelo compilador, descrevendo os principais tokens reconhecidos pelo Flex e as principais estruturas sintáticas validadas pelo Bison.

O compilador utiliza:

- `src/lexer.l` para análise léxica;
- `src/parser.y` para análise sintática.

---

# Análise Léxica com Flex

O Flex é responsável por reconhecer padrões no código-fonte e convertê-los em tokens para o parser.

## Arquivo principal

```text
src/lexer.l
```

---

# Tokens Reconhecidos

## Tipos

```text
int
float
double
char
void
```

## Palavras reservadas

```text
if
else
return
main
printf
scanf
```

## Identificadores

Representam nomes de variáveis e funções.

Exemplo:

```c
contador
resultado
soma
calcularMedia
```

## Literais

Exemplos de literais reconhecidos:

```c
10
3.14
'a'
"Resultado: %d"
```

## Operadores aritméticos

```text
+
-
*
/
%
```

## Operadores relacionais

```text
==
!=
<
>
<=
>=
```

## Operadores de atribuição

```text
=
+=
-=
*=
/=
```

## Operadores relacionados a ponteiros

```text
*
&
```

## Delimitadores

```text
;
,
(
)
{
}
[
]
```

## Comentários

Comentários de linha:

```c
// comentário de linha
```

Comentários de bloco:

```c
/*
  comentário de bloco
*/
```

---

# Exemplo de Tokenização

## Entrada

```c
int x = 10;
```

## Tokens

```text
INT
IDENTIFICADOR
ATRIBUICAO
NUMERO
PONTO_VIRGULA
```

---

# Análise Sintática com Bison

O Bison é responsável por validar se a sequência de tokens gerada pelo Flex forma estruturas válidas dentro do subconjunto da linguagem C definido pelo projeto.

## Arquivo principal

```text
src/parser.y
```

---

# Estruturas Sintáticas Suportadas

## Programa

O programa é formado por declarações, funções e comandos reconhecidos pela gramática.

Exemplo conceitual:

```bison
programa:
    lista_funcoes
;
```

---

## Função principal

```c
int main() {
    return 0;
}
```

Representação conceitual:

```bison
funcao_main:
    tipo MAIN '(' ')' bloco
;
```

---

## Declaração de variáveis

```c
int x;
float media;
char letra;
```

Representação conceitual:

```bison
declaracao:
    tipo identificador ';'
;
```

Com inicialização:

```c
int x = 10;
```

Representação conceitual:

```bison
declaracao:
    tipo identificador '=' expressao ';'
;
```

---

## Atribuições

```c
x = 10;
x += 1;
x -= 1;
```

Representação conceitual:

```bison
atribuicao:
    identificador '=' expressao ';'
  | identificador MAIS_IGUAL expressao ';'
  | identificador MENOS_IGUAL expressao ';'
;
```

---

## Expressões aritméticas

```c
a + b
a - b
a * b
a / b
a % b
```

Representação conceitual:

```bison
expressao:
    expressao '+' expressao
  | expressao '-' expressao
  | expressao '*' expressao
  | expressao '/' expressao
  | expressao '%' expressao
  | identificador
  | numero
;
```

---

## Expressões relacionais

```c
a > b
a < b
a >= b
a <= b
a == b
a != b
```

Representação conceitual:

```bison
condicao:
    expressao '>' expressao
  | expressao '<' expressao
  | expressao MAIOR_IGUAL expressao
  | expressao MENOR_IGUAL expressao
  | expressao IGUAL expressao
  | expressao DIFERENTE expressao
;
```

---

## Estruturas condicionais

```c
if (x > 0) {
    x += 1;
}
```

Representação conceitual:

```bison
condicional:
    IF '(' condicao ')' bloco
;
```

Com `else`:

```c
if (x > 0) {
    x += 1;
} else {
    x -= 1;
}
```

Representação conceitual:

```bison
condicional:
    IF '(' condicao ')' bloco ELSE bloco
;
```

---

## Funções

```c
int soma(int a, int b) {
    return a + b;
}
```

Representação conceitual:

```bison
funcao:
    tipo identificador '(' parametros ')' bloco
;
```

---

## Chamadas de função

```c
resultado = soma(10, 20);
```

Representação conceitual:

```bison
chamada_funcao:
    identificador '(' argumentos ')'
;
```

---

## Entrada e saída

```c
printf("Resultado: %d", resultado);
scanf("%d", &valor);
```

Representação conceitual:

```bison
comando_saida:
    PRINTF '(' argumentos ')' ';'
;

comando_entrada:
    SCANF '(' argumentos ')' ';'
;
```

---

## Ponteiros

```c
int *p;
p = &x;
```

Representação conceitual:

```bison
declaracao_ponteiro:
    tipo '*' identificador ';'
;

atribuicao_ponteiro:
    identificador '=' '&' identificador ';'
;
```

---

# Precedência de Operadores

Para evitar ambiguidades na gramática, são definidas regras de precedência e associatividade.

Exemplo conceitual:

```bison
%left '+' '-'
%left '*' '/' '%'
```

Essas regras indicam que multiplicação, divisão e módulo possuem maior precedência que soma e subtração.

---

# Integração entre Flex e Bison

O fluxo entre Flex e Bison ocorre da seguinte forma:

```text
Código em C
     ↓
Flex reconhece padrões
     ↓
Tokens são enviados ao Bison
     ↓
Bison aplica regras gramaticais
     ↓
Estruturas válidas seguem para AST/Semântica/Geração
```

---

# Observação

As regras apresentadas nesta página são representações conceituais da gramática, utilizadas para documentação e entendimento do projeto.

A implementação real pode conter nomes de tokens e regras diferentes, conforme definido nos arquivos `src/lexer.l` e `src/parser.y`.

---

# Histórico de Versões

| Versão | Data | Descrição | Autor(es) |
|:--:|:--:|:--|:--|
| `1.0` | 14/06/2026 | Criação da documentação da gramática Flex/Bison | [Arthur Fernandes](https://github.com/arthurfernandesj) |