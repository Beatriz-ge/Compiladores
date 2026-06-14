# Demo

Esta seção apresenta uma demonstração prática do funcionamento do compilador desenvolvido no projeto.

O objetivo da demo é mostrar como um programa escrito em um subconjunto da linguagem C é processado pelo compilador e convertido para código equivalente em Python.

---

# Objetivo da Demonstração

Demonstrar o fluxo completo de execução do compilador:

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

# Código de Entrada em C

O exemplo abaixo representa um programa simples em C, contendo declaração de variáveis, atribuição, expressão aritmética, estrutura condicional e retorno.

```c
int main() {
    int a = 10;
    int b = 20;
    int c;

    c = a + b;

    if (c > 20) {
        c += 1;
    } else {
        c -= 1;
    }

    return c;
}
```

---

# Compilação do Projeto

Antes de executar o compilador, é necessário compilar o projeto.

```bash
make clean
make
```

Após a compilação, o binário do compilador será gerado em:

```text
bin/compilador
```

---

# Execução do Compilador

Para executar o compilador com o arquivo de entrada `tests/teste.c`, utilize:

```bash
./bin/compilador tests/teste.c
```

Durante a execução, o compilador realiza as seguintes etapas:

* Leitura do arquivo de entrada;
* Análise léxica;
* Análise sintática;
* Análise semântica;
* Construção/uso da AST;
* Consulta à tabela de símbolos;
* Consulta à tabela de funções, quando necessário;
* Geração do código Python equivalente.

---

# Saída Esperada no Terminal

Caso o código seja válido, o compilador deve indicar que as etapas foram executadas corretamente.

Exemplo de saída esperada:

```text
[SUCESSO] O código é sintaticamente válido.
Léxico:           OK
Sintático:        OK
Semântico:        OK
------------------------------------------
TUDO OK!
Arquivo 'tests/saida.py' criado com sucesso.
```

O compilador também pode exibir a tabela de símbolos durante a execução, mostrando variáveis identificadas, tipos, escopos e linhas de declaração.

---

# Código Python Gerado

Após a execução bem-sucedida, o compilador gera o arquivo:

```text
tests/saida.py
```

A saída Python esperada para o exemplo apresentado é:

```python
a = 10
b = 20
c = None

c = a + b

if c > 20:
    c += 1
else:
    c -= 1

return c
```

---

# Exemplo com Comentários

O compilador também possui suporte à conversão de comentários da linguagem C para comentários em Python.

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

---

# Exemplo com Função

O compilador possui suporte a funções com argumentos, dentro do subconjunto definido no projeto.

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

---

# Exemplo de Erro Semântico

A demo também pode demonstrar o comportamento do compilador diante de um erro semântico.

## Entrada em C inválida

```c
int main() {
    x = 10;
    return x;
}
```

Nesse caso, a variável `x` é utilizada sem ter sido declarada.

## Resultado esperado

```text
Erro semântico: variável 'x' não declarada
```

Esse exemplo demonstra que o compilador não apenas verifica a estrutura sintática do programa, mas também realiza validações semânticas antes da geração de código.

---

# Execução dos Testes

Além da execução manual, o projeto possui uma suíte de testes automatizados.

Para executar os testes:

```bash
bash tests/run_tests.sh
```

Para executar os testes com cobertura:

```bash
make coverage
bash tests/run_tests.sh --coverage
```

---

# Resultado da Demonstração

A demonstração evidencia que o compilador é capaz de:

* Receber um arquivo `.c` como entrada;
* Reconhecer tokens da linguagem C;
* Validar a estrutura sintática do programa;
* Realizar verificações semânticas;
* Utilizar tabela de símbolos;
* Validar funções quando necessário;
* Gerar código Python equivalente;
* Identificar erros em programas inválidos;
* Executar testes automatizados.

---

# Considerações

A demo apresenta um fluxo simplificado, mas suficiente para demonstrar o funcionamento principal do compilador.

O projeto não busca implementar toda a linguagem C, mas sim um subconjunto controlado com foco acadêmico, permitindo aplicar conceitos fundamentais de compiladores, como lexer, parser, AST, análise semântica, tabela de símbolos e geração de código.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                       | Autor(es)                                               |
| :----: | :--------: | :---------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 14/06/2026 | Criação da página de demonstração do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |
