# Arquitetura — Sintático

O módulo sintático é responsável por validar a estrutura gramatical do programa a partir dos tokens gerados pelo analisador léxico.

No projeto, o analisador sintático foi desenvolvido utilizando Bison, por meio do arquivo `src/parser.y`.

Essa etapa atua como uma das partes centrais do compilador, pois define quais combinações de tokens formam comandos válidos dentro do subconjunto da linguagem C suportado pelo projeto.

---

# Objetivo

O objetivo do módulo sintático é garantir que o código-fonte siga corretamente as regras gramaticais definidas para o subconjunto da linguagem C aceito pelo compilador.

Além da validação estrutural, o parser também participa da construção da AST, da integração com a análise semântica e do encaminhamento das estruturas reconhecidas para a geração de código Python.

---

# Responsabilidades

O analisador sintático é responsável por:

* Receber tokens gerados pelo analisador léxico;
* Validar a estrutura gramatical do código-fonte;
* Reconhecer declarações de variáveis;
* Reconhecer atribuições;
* Reconhecer expressões aritméticas e relacionais;
* Reconhecer estruturas condicionais;
* Reconhecer funções e chamadas de função;
* Reconhecer comandos de entrada e saída básica;
* Reconhecer construções básicas relacionadas a ponteiros;
* Organizar comandos em estruturas hierárquicas;
* Auxiliar na construção da AST;
* Acionar verificações semânticas quando necessário;
* Detectar e reportar erros sintáticos.

---

# Estruturas Suportadas

O parser reconhece as principais estruturas necessárias para a tradução do subconjunto de C definido no projeto.

## Declaração de Variáveis

```c
int x;
float valor;
double media;
char letra;
```

Também são reconhecidas declarações com inicialização:

```c
int idade = 20;
float nota = 8.5;
char letra = 'A';
```

---

## Atribuições

```c
x = 10;
valor = x + 5;
media = nota / 2;
```

Também há suporte a operadores compostos de atribuição, dentro do subconjunto definido:

```c
x += 1;
x -= 1;
```

---

## Expressões Aritméticas

```c
resultado = a + b;
resultado = a - b;
resultado = a * b;
resultado = a / b;
resultado = a % b;
```

---

## Expressões Relacionais

```c
a > b
a < b
a >= b
a <= b
a == b
a != b
```

Essas expressões são utilizadas principalmente em estruturas condicionais.

---

## Estruturas Condicionais

```c
if (x > 0) {
    x = x + 1;
}
```

Também são suportadas estruturas com `else`:

```c
if (x > 0) {
    x = x + 1;
} else {
    x = x - 1;
}
```

E estruturas condicionais encadeadas, conforme as regras previstas na gramática:

```c
if (x > 10) {
    x = x + 1;
} else if (x == 10) {
    x = 0;
} else {
    x = x - 1;
}
```

---

## Função Principal

O parser reconhece a função principal `main`, utilizada como ponto de entrada dos programas de teste.

```c
int main() {
    int x = 10;
    return x;
}
```

---

## Funções

O compilador possui suporte a funções com e sem argumentos, respeitando o subconjunto definido no projeto.

Exemplo de função sem argumentos:

```c
int obterValor() {
    return 10;
}
```

Exemplo de função com argumentos:

```c
int soma(int a, int b) {
    return a + b;
}
```

---

## Chamadas de Função

O parser reconhece chamadas de função e permite a integração com a tabela de funções para validação semântica da quantidade de argumentos.

```c
resultado = soma(10, 20);
```

---

## Entrada e Saída Básica

O parser reconhece comandos básicos de entrada e saída, como `printf` e `scanf`, dentro das limitações previstas no projeto.

```c
printf("Resultado: %d", resultado);
scanf("%d", &valor);
```

---

## Ponteiros

O compilador possui suporte básico a construções relacionadas a ponteiros, dentro do subconjunto definido.

Exemplos:

```c
int *p;
int x = 10;
p = &x;
```

O suporte a ponteiros é limitado e não contempla todos os comportamentos avançados da linguagem C.

---

## Comentários

Comentários reconhecidos pelo lexer podem ser aceitos dentro de blocos e comandos, permitindo a conversão posterior para comentários em Python.

```c
// comentário de linha
int x = 10;

/*
  comentário de bloco
*/
```

---

# Estruturas Fora do Escopo Principal

O projeto não tem como objetivo implementar a gramática completa da linguagem C.

Entre as estruturas que não fazem parte do escopo principal ou possuem suporte limitado, estão:

* `struct`;
* `union`;
* `enum`;
* `switch/case`;
* `goto`;
* macros de pré-processador;
* múltiplos arquivos de entrada;
* uso avançado de ponteiros;
* manipulação completa de arrays;
* biblioteca padrão completa da linguagem C;
* tratamento avançado de erros com recuperação automática.

---

# Fluxo Sintático

```text
Tokens vindos do Lexer
        ↓
Parser gerado pelo Bison
        ↓
Aplicação das Regras Gramaticais
        ↓
Construção da AST
        ↓
Integração com Análise Semântica
        ↓
Estrutura Sintática Válida
```

---

# Ferramenta Utilizada

| Ferramenta | Finalidade                                                            |
| ---------- | --------------------------------------------------------------------- |
| Bison      | Geração automática do parser a partir de regras gramaticais           |
| Flex       | Integração com o analisador léxico responsável por fornecer os tokens |

---

# Estrutura do Arquivo Sintático

O arquivo responsável pelo analisador sintático está localizado em:

```text
src/parser.y
```

Esse arquivo contém:

* Declaração de tokens recebidos do lexer;
* Definição de tipos semânticos;
* Regras gramaticais;
* Precedência de operadores;
* Ações semânticas;
* Integração com a AST;
* Integração com a tabela de símbolos;
* Integração com a tabela de funções;
* Chamadas para validações semânticas;
* Tratamento de erros sintáticos.

---

# Integração com os Demais Módulos

O parser atua como ponto de integração entre diversas partes do compilador.

```text
lexer.l
   ↓ tokens
parser.y
   ↓ regras reconhecidas
AST
   ↓ representação interna
Análise Semântica
   ↓ validação
Geração de Código Python
```

---

# Exemplo de Funcionamento

## Entrada

```c
int main() {
    int x = 10;

    if (x > 0) {
        x += 1;
    }

    return x;
}
```

## Interpretação Sintática

O parser reconhece a seguinte estrutura:

```text
programa
 └── função main
     └── bloco
         ├── declaração de variável
         ├── estrutura condicional
         │   └── atribuição composta
         └── comando de retorno
```

---

# Exemplo de Regra Gramatical

Um exemplo simplificado de regra sintática pode ser representado da seguinte forma:

```bison
programa:
    lista_funcoes
;
```

Outro exemplo simplificado para comandos:

```bison
comando:
      declaracao
    | atribuicao
    | condicional
    | retorno
    | chamada_funcao
;
```

Esses exemplos representam a ideia geral da gramática, não necessariamente a regra exata implementada no arquivo `parser.y`.

---

# Tratamento de Erros Sintáticos

O parser identifica estruturas inválidas e informa a ocorrência de erro sintático durante a compilação.

Exemplo:

```text
Erro sintático na linha 5
```

Esse tipo de erro pode ocorrer quando o código-fonte possui problemas como:

* Ausência de ponto e vírgula;
* Chaves não fechadas;
* Parênteses não fechados;
* Comandos incompletos;
* Sequência inválida de tokens;
* Estrutura fora da gramática suportada.

Exemplo de código inválido:

```c
int main() {
    int x = 10
    return x;
}
```

Nesse caso, o erro ocorre pela ausência de `;` após a declaração/atribuição da variável.

---

# Considerações

A gramática foi construída de forma modular, permitindo expansão gradual das estruturas suportadas pelo compilador.

O módulo sintático atua como núcleo central da validação estrutural do sistema, conectando a etapa léxica às etapas de AST, análise semântica e geração de código.

A implementação atual já contempla as principais estruturas necessárias para a proposta acadêmica do projeto, mantendo o foco em um subconjunto controlado da linguagem C.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                                  | Autor(es)                                               |
| :----: | :--------: | :------------------------------------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 30/04/2025 | Criação da documentação do módulo sintático                                | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.1` | 08/06/2026 | Atualização do módulo sintático conforme implementação atual do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |
