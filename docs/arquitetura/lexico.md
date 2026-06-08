# Arquitetura — Léxico

O módulo léxico é responsável pela primeira etapa do processo de compilação. Ele realiza a leitura do código-fonte escrito em C e converte os caracteres de entrada em tokens válidos para as próximas fases do compilador.

No projeto, o analisador léxico foi desenvolvido utilizando a ferramenta Flex, por meio do arquivo `src/lexer.l`.

---

# Objetivo

O objetivo do módulo léxico é identificar padrões pertencentes ao subconjunto da linguagem C suportado pelo compilador e transformá-los em unidades léxicas compreensíveis pelo analisador sintático.

Essas unidades léxicas, chamadas tokens, são enviadas ao parser para que a estrutura gramatical do programa seja validada.

---

# Responsabilidades

O analisador léxico é responsável por:

* Ler o código-fonte de entrada;
* Reconhecer tokens da linguagem;
* Ignorar espaços em branco, tabulações e quebras de linha quando não possuem relevância sintática;
* Identificar palavras reservadas;
* Identificar tipos da linguagem C;
* Identificar operadores e delimitadores;
* Reconhecer identificadores;
* Reconhecer constantes numéricas, caracteres e strings;
* Reconhecer comentários de linha e comentários de bloco;
* Encaminhar os tokens reconhecidos para o analisador sintático;
* Reportar erros léxicos quando caracteres inválidos ou padrões não reconhecidos são encontrados.

---

# Tokens Reconhecidos

O analisador léxico reconhece os principais elementos necessários para o subconjunto da linguagem C utilizado no projeto.

## Tipos

```text
int
float
double
char
void
```

---

## Palavras-chave

```text
if
else
return
main
printf
scanf
```

Dependendo da evolução da gramática, outras palavras reservadas podem ser reconhecidas pelo léxico, mesmo que nem todas sejam completamente suportadas nas etapas sintática, semântica ou de geração de código.

---

## Operadores Aritméticos

```text
+
-
*
/
%
```

---

## Operadores Relacionais

```text
==
!=
<
>
<=
>=
```

---

## Operadores de Atribuição

```text
=
+=
-=
*=
/=
```

---

## Operadores de Ponteiro e Endereço

```text
*
&
```

Esses símbolos podem ser utilizados no suporte básico a ponteiros, dependendo do contexto sintático definido no parser.

---

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

---

## Identificadores

Identificadores representam nomes definidos pelo usuário, como variáveis e funções.

Exemplos:

```c
contador
resultado
valorFinal
soma
calcularMedia
```

---

## Literais

O analisador léxico reconhece literais utilizados em declarações, atribuições, expressões e comandos de entrada/saída.

Exemplos:

```c
10
3.14
'a'
"Resultado: %d\n"
```

---

## Comentários

O compilador reconhece comentários da linguagem C e os utiliza no processo de geração de código Python equivalente.

### Comentário de linha

```c
// este é um comentário de linha
```

### Comentário de bloco

```c
/*
  este é um comentário
  de múltiplas linhas
*/
```

Na geração de código Python, os comentários são convertidos para o formato com `#`.

---

# Fluxo Léxico

```text
Código Fonte em C
      ↓
Leitura dos Caracteres
      ↓
Reconhecimento por Expressões Regulares
      ↓
Geração de Tokens
      ↓
Envio ao Parser
```

---

# Ferramenta Utilizada

| Ferramenta | Finalidade                                                                             |
| ---------- | -------------------------------------------------------------------------------------- |
| Flex       | Geração automática do analisador léxico a partir de expressões regulares e regras em C |

---

# Estrutura do Arquivo Léxico

O arquivo responsável pelo analisador léxico está localizado em:

```text
src/lexer.l
```

Esse arquivo contém:

* Definições auxiliares;
* Inclusão de headers necessários;
* Expressões regulares;
* Regras de reconhecimento de tokens;
* Tratamento de comentários;
* Tratamento de literais;
* Integração com o parser gerado pelo Bison;
* Código auxiliar em C.

---

# Integração com o Parser

O analisador léxico trabalha em conjunto com o analisador sintático.

O lexer identifica os padrões presentes no código-fonte e retorna tokens para o parser. O parser, por sua vez, utiliza esses tokens para validar a estrutura gramatical do programa.

O fluxo de integração pode ser representado da seguinte forma:

```text
lexer.l
   ↓ tokens
parser.y
   ↓ regras gramaticais
AST / Análise Semântica / Geração de Código
```

---

# Exemplo de Funcionamento

## Entrada

```c
int x = 10;
```

## Tokens Gerados

```text
INT
IDENTIFIER(x)
ATRIB
NUMBER(10)
PONTO_VIRGULA
```

---

# Exemplo com Condicional

## Entrada

```c
if (x >= 10) {
    x += 1;
}
```

## Tokens Gerados

```text
IF
ABRE_PARENTESE
IDENTIFIER(x)
MAIOR_IGUAL
NUMBER(10)
FECHA_PARENTESE
ABRE_CHAVE
IDENTIFIER(x)
MAIS_IGUAL
NUMBER(1)
PONTO_VIRGULA
FECHA_CHAVE
```

---

# Exemplo com Comentário

## Entrada

```c
// soma dois valores
int resultado = a + b;
```

## Resultado esperado na geração Python

```python
# soma dois valores
resultado = a + b
```

---

# Tratamento de Erros Léxicos

O analisador léxico é capaz de identificar caracteres inválidos ou padrões que não pertencem ao subconjunto da linguagem reconhecido pelo compilador.

Exemplo:

```text
Erro léxico: caractere inválido '@'
```

Esse tratamento evita que símbolos desconhecidos sejam enviados incorretamente ao parser, facilitando a depuração do código de entrada.

---

# Considerações

A implementação léxica foi desenvolvida visando simplicidade, modularidade e facilidade de integração com o analisador sintático.

Além de reconhecer os tokens básicos da linguagem C, o módulo léxico também foi expandido para lidar com comentários, tipos adicionais, operadores compostos, comandos de entrada e saída básica e símbolos relacionados ao suporte inicial a ponteiros.

Sua estrutura permite expansão futura para novos tokens e novas construções da linguagem C, desde que essas expansões também sejam refletidas no parser, na análise semântica e na geração de código.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                               | Autor(es)                                               |
| :----: | :--------: | :---------------------------------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 30/04/2025 | Criação da documentação do módulo léxico                                | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.1` | 08/06/2026 | Atualização do módulo léxico conforme implementação atual do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |
