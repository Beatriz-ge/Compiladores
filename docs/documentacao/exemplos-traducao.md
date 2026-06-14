# Exemplos de Tradução

Esta seção apresenta exemplos de tradução realizados pelo compilador, demonstrando como estruturas escritas em um subconjunto da linguagem C são convertidas para código equivalente em Python.

Os exemplos têm como objetivo facilitar a compreensão do funcionamento do compilador e evidenciar as principais funcionalidades implementadas.

---

# Visão Geral

O compilador recebe como entrada um arquivo `.c`, realiza as etapas de análise léxica, análise sintática, análise semântica e geração de código, e produz como saída um arquivo Python equivalente.

Fluxo resumido:

```text
Código em C
     ↓
Análise Léxica
     ↓
Análise Sintática
     ↓
Análise Semântica
     ↓
Geração de Código
     ↓
Código em Python
```

---

# Exemplo 1 — Declaração de Variáveis

## Entrada em C

```c
int main() {
    int x = 10;
    int y;
    return x;
}
```

## Saída em Python

```python
x = 10
y = None

return x
```

## Observação

Variáveis declaradas sem valor inicial em C são traduzidas para `None` em Python.

---

# Exemplo 2 — Atribuição e Expressão Aritmética

## Entrada em C

```c
int main() {
    int a = 10;
    int b = 20;
    int resultado;

    resultado = a + b;

    return resultado;
}
```

## Saída em Python

```python
a = 10
b = 20
resultado = None

resultado = a + b

return resultado
```

## Observação

Expressões aritméticas simples são preservadas na saída Python, mantendo a equivalência lógica do código original.

---

# Exemplo 3 — Operadores Compostos

## Entrada em C

```c
int main() {
    int x = 10;

    x += 1;
    x -= 1;

    return x;
}
```

## Saída em Python

```python
x = 10

x += 1
x -= 1

return x
```

## Observação

Operadores compostos como `+=` e `-=` possuem equivalência direta em Python.

---

# Exemplo 4 — Estrutura Condicional com `if`

## Entrada em C

```c
int main() {
    int x = 10;

    if (x > 0) {
        x += 1;
    }

    return x;
}
```

## Saída em Python

```python
x = 10

if x > 0:
    x += 1

return x
```

## Observação

A estrutura com chaves `{}` da linguagem C é convertida para bloco indentado em Python.

---

# Exemplo 5 — Estrutura Condicional com `if` e `else`

## Entrada em C

```c
int main() {
    int x = 10;

    if (x > 0) {
        x += 1;
    } else {
        x -= 1;
    }

    return x;
}
```

## Saída em Python

```python
x = 10

if x > 0:
    x += 1
else:
    x -= 1

return x
```

## Observação

O compilador remove as chaves da linguagem C e utiliza indentação para representar os blocos em Python.

---

# Exemplo 6 — Condicional Encadeada

## Entrada em C

```c
int main() {
    int x = 10;

    if (x > 10) {
        x += 1;
    } else if (x == 10) {
        x = 0;
    } else {
        x -= 1;
    }

    return x;
}
```

## Saída em Python

```python
x = 10

if x > 10:
    x += 1
elif x == 10:
    x = 0
else:
    x -= 1

return x
```

## Observação

A estrutura `else if` da linguagem C pode ser convertida para `elif` em Python, mantendo a lógica condicional.

---

# Exemplo 7 — Função sem Argumentos

## Entrada em C

```c
int obterValor() {
    return 10;
}

int main() {
    int resultado;

    resultado = obterValor();

    return resultado;
}
```

## Saída em Python

```python
def obterValor():
    return 10

resultado = None

resultado = obterValor()

return resultado
```

## Observação

Funções em C são traduzidas para funções Python utilizando `def`. Os tipos de retorno não aparecem na assinatura Python, pois Python utiliza tipagem dinâmica.

---

# Exemplo 8 — Função com Argumentos

## Entrada em C

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

## Saída em Python

```python
def soma(a, b):
    return a + b

resultado = None

resultado = soma(10, 20)

return resultado
```

## Observação

Os tipos dos parâmetros em C são removidos na saída Python, mantendo apenas os nomes dos parâmetros.

---

# Exemplo 9 — Comentário de Linha

## Entrada em C

```c
int main() {
    // soma dois valores
    int a = 10;
    int b = 20;
    int resultado;

    resultado = a + b;

    return resultado;
}
```

## Saída em Python

```python
# soma dois valores
a = 10
b = 20
resultado = None

resultado = a + b

return resultado
```

## Observação

Comentários de linha em C iniciados por `//` são convertidos para comentários Python iniciados por `#`.

---

# Exemplo 10 — Comentário de Bloco

## Entrada em C

```c
int main() {
    /*
      cálculo da soma
      entre dois valores
    */
    int a = 10;
    int b = 20;
    int resultado;

    resultado = a + b;

    return resultado;
}
```

## Saída em Python

```python
# cálculo da soma
# entre dois valores
a = 10
b = 20
resultado = None

resultado = a + b

return resultado
```

## Observação

Comentários de bloco são convertidos linha por linha para comentários Python.

---

# Exemplo 11 — Entrada e Saída Básica

## Entrada em C

```c
int main() {
    int valor;

    scanf("%d", &valor);
    printf("Valor: %d", valor);

    return valor;
}
```

## Saída em Python

```python
valor = None

valor = int(input())
print("Valor:", valor)

return valor
```

## Observação

A tradução de `printf` e `scanf` é simplificada e considera os formatos básicos utilizados nos testes do projeto.

---

# Exemplo 12 — Ponteiro Básico

## Entrada em C

```c
int main() {
    int x = 10;
    int *p;

    p = &x;

    return x;
}
```

## Saída Conceitual em Python

```python
x = 10
p = None

p = x

return x
```

## Observação

Python não possui ponteiros como C. Por isso, a tradução de ponteiros é simplificada e busca representar apenas os casos básicos definidos no subconjunto do projeto.

---

# Exemplo 13 — Erro Semântico: Variável Não Declarada

## Entrada em C

```c
int main() {
    x = 10;
    return x;
}
```

## Resultado Esperado

```text
Erro semântico: variável 'x' não declarada
```

## Observação

Nesse caso, o compilador deve rejeitar o código porque a variável `x` é utilizada sem declaração prévia.

---

# Exemplo 14 — Erro Semântico: Redeclaração

## Entrada em C

```c
int main() {
    int x;
    float x;

    return 0;
}
```

## Resultado Esperado

```text
Erro semântico: variável 'x' já declarada neste escopo
```

## Observação

O compilador deve identificar quando uma variável é declarada mais de uma vez no mesmo escopo.

---

# Exemplo 15 — Erro Semântico: Quantidade Incorreta de Argumentos

## Entrada em C

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

## Resultado Esperado

```text
Erro semântico: quantidade incorreta de argumentos na chamada da função 'soma'
```

## Observação

A tabela de funções permite validar se uma chamada possui a quantidade correta de argumentos.

---

# Como Executar os Exemplos

Para testar qualquer exemplo, coloque o código C no arquivo:

```text
tests/teste.c
```

Depois compile o projeto:

```bash
make clean
make
```

Execute o compilador:

```bash
./bin/compilador tests/teste.c
```

A saída Python será gerada em:

```text
tests/saida.py
```

Para executar todos os testes automatizados:

```bash
bash tests/run_tests.sh
```

---

# Considerações

Os exemplos apresentados demonstram o comportamento esperado do compilador para as principais funcionalidades implementadas.

A tradução gerada pode variar em pequenos detalhes de formatação, mas deve preservar a lógica do programa de entrada dentro do subconjunto da linguagem C suportado pelo projeto.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                 | Autor(es)                                               |
| :----: | :--------: | :---------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 14/06/2026 | Criação da página de exemplos de tradução | [Arthur Fernandes](https://github.com/arthurfernandesj) |
