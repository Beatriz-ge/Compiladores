# Arquitetura — Código

O módulo de geração de código é responsável por converter estruturas válidas da linguagem C em código equivalente na linguagem Python.

Essa etapa representa a saída final do compilador e ocorre após as validações léxica, sintática e semântica. No projeto atual, a geração de código está integrada principalmente à AST, com apoio do controle de indentação para produzir blocos válidos em Python.

---

# Objetivo

Traduzir estruturas reconhecidas pelo compilador para código Python semanticamente equivalente, preservando a lógica original do programa de entrada dentro do subconjunto da linguagem C suportado pelo projeto.

A geração de código tem como objetivo produzir um arquivo Python final, permitindo visualizar o resultado da tradução feita pelo compilador.

---

# Responsabilidades

O gerador de código é responsável por:

* Traduzir declarações de variáveis;
* Converter atribuições;
* Converter expressões aritméticas e relacionais;
* Traduzir estruturas condicionais;
* Traduzir funções e chamadas de função;
* Adaptar operadores e sintaxe da linguagem C para Python;
* Converter comentários da linguagem C para comentários em Python;
* Adaptar comandos básicos de entrada e saída;
* Tratar construções básicas relacionadas a ponteiros dentro do subconjunto suportado;
* Controlar a indentação dos blocos gerados;
* Gerar código Python válido;
* Produzir o arquivo final de saída `tests/saida.py`.

---

# Fluxo de Geração

```text id="r7zd2t"
Código Validado
        ↓
AST
        ↓
Validação Semântica
        ↓
Conversão das Estruturas
        ↓
Controle de Indentação
        ↓
Geração de Código Python
        ↓
Arquivo Final
```

---

# Estruturas Suportadas

## Declaração de Variáveis

### Entrada em C

```c id="37cfr5"
int x = 10;
```

### Saída em Python

```python id="kef708"
x = 10
```

Quando uma variável é declarada sem valor inicial, a saída pode utilizar `None` como valor inicial equivalente.

### Entrada em C

```c id="uwx24d"
int x;
```

### Saída em Python

```python id="8thofz"
x = None
```

---

## Atribuições

### Entrada em C

```c id="5b0gry"
x = 10;
resultado = x + 5;
```

### Saída em Python

```python id="cjtw7s"
x = 10
resultado = x + 5
```

---

## Operadores Compostos

### Entrada em C

```c id="3dm9x4"
x += 1;
x -= 1;
```

### Saída em Python

```python id="xmpuxx"
x += 1
x -= 1
```

---

## Operações Aritméticas

### Entrada em C

```c id="c6svrl"
resultado = a + b;
media = soma / 2;
```

### Saída em Python

```python id="3ffp0b"
resultado = a + b
media = soma / 2
```

---

## Expressões Relacionais

### Entrada em C

```c id="yxy82r"
if (x >= 10) {
    x += 1;
}
```

### Saída em Python

```python id="mr9uxg"
if x >= 10:
    x += 1
```

---

## Estruturas Condicionais

### Entrada em C

```c id="zr63f0"
if (x > 0) {
    x = x + 1;
}
```

### Saída em Python

```python id="31sd3g"
if x > 0:
    x = x + 1
```

---

## Estruturas Condicionais com `else`

### Entrada em C

```c id="n33z6r"
if (x > 0) {
    x = x + 1;
} else {
    x = x - 1;
}
```

### Saída em Python

```python id="ndcf8z"
if x > 0:
    x = x + 1
else:
    x = x - 1
```

---

## Funções

### Entrada em C

```c id="br4dqj"
int soma(int a, int b) {
    return a + b;
}
```

### Saída em Python

```python id="3kv22o"
def soma(a, b):
    return a + b
```

O tipo de retorno e os tipos dos parâmetros da linguagem C não são mantidos na assinatura Python, pois Python utiliza tipagem dinâmica.

---

## Função Principal

### Entrada em C

```c id="018cnh"
int main() {
    int x = 10;
    return x;
}
```

### Saída em Python

```python id="1ne7gb"
x = 10
return x
```

Dependendo da estratégia de geração adotada, a função `main` pode ser simplificada na saída, mantendo apenas os comandos internos traduzidos.

---

## Chamadas de Função

### Entrada em C

```c id="qskhp0"
resultado = soma(10, 20);
```

### Saída em Python

```python id="4hthlp"
resultado = soma(10, 20)
```

---

## Comentários

O compilador converte comentários da linguagem C para comentários equivalentes em Python.

### Entrada em C

```c id="3v8516"
// soma dois valores
int resultado = a + b;
```

### Saída em Python

```python id="n1ovl3"
# soma dois valores
resultado = a + b
```

### Comentário de bloco em C

```c id="b7k5uo"
/*
  início do cálculo
  soma dos valores
*/
```

### Saída em Python

```python id="4i0lqv"
# início do cálculo
# soma dos valores
```

---

## Entrada e Saída Básica

O compilador possui suporte básico a comandos como `printf` e `scanf`, dentro das limitações definidas no projeto.

### Entrada em C

```c id="i4ip6r"
printf("Resultado: %d", resultado);
```

### Saída esperada em Python

```python id="nz7li1"
print("Resultado:", resultado)
```

### Entrada em C

```c id="mq717b"
scanf("%d", &valor);
```

### Saída esperada em Python

```python id="qhh2zt"
valor = int(input())
```

A tradução de entrada e saída é simplificada e considera os formatos básicos previstos nos casos de teste do projeto.

---

## Ponteiros

O projeto possui suporte básico a ponteiros no subconjunto da linguagem C. Como Python não possui ponteiros da mesma forma que C, a geração de código busca preservar uma representação simplificada da lógica, quando possível.

### Entrada em C

```c id="d03w1a"
int x = 10;
int *p;
p = &x;
```

### Saída conceitual em Python

```python id="0rc3d2"
x = 10
p = None
p = x
```

O suporte a ponteiros é limitado e não representa todos os comportamentos de memória da linguagem C.

---

# Estratégia de Tradução

O compilador realiza uma tradução direta das estruturas reconhecidas da linguagem C para Python.

A conversão considera:

* Equivalência lógica entre as linguagens;
* Sintaxe da linguagem alvo;
* Remoção de ponto e vírgula;
* Conversão de blocos delimitados por `{}` para blocos indentados;
* Conversão de declarações de variáveis;
* Adaptação de tipos de C para a tipagem dinâmica de Python;
* Conversão de comentários;
* Conversão básica de entrada e saída;
* Controle de indentação obrigatório em Python.

---

# Controle de Indentação

Como Python depende de indentação para definir blocos, o compilador utiliza um controle específico para manter a estrutura correta do código gerado.

No projeto, esse controle está relacionado aos arquivos:

```text id="fiklhu"
src/ast/indent_manager.c
src/ast/indent_manager.h
```

Esse componente é responsável por:

* Controlar o nível atual de indentação;
* Aumentar a indentação ao entrar em blocos;
* Reduzir a indentação ao sair de blocos;
* Aplicar espaços corretamente antes de comandos dentro de funções, condicionais e demais estruturas de bloco.

---


# Organização do Módulo

No projeto atual, não há uma pasta separada chamada `generator/`. A geração de código está integrada à AST e ao controle de indentação.

```text
src/
└── ast/
    ├── ast.c               # Implementação da AST e funções de geração de código
    ├── ast.h               # Definições das estruturas da AST
    ├── indent_manager.c    # Controle de indentação do código Python gerado
    └── indent_manager.h    # Interface do controle de indentação

Além disso, a geração de código depende da integração com:

```text id="dru2qn"
src/parser.y                # Reconhecimento das estruturas e ações associadas
src/semantic.c              # Validações antes da geração
src/tabela.c                # Informações de variáveis e escopos
src/tabela_funcoes.c        # Informações de funções e chamadas
```

---

# Componentes do Gerador

| Componente         | Função                                                                |
| ------------------ | --------------------------------------------------------------------- |
| `ast.c`            | Implementa a AST e funções relacionadas à geração do código Python    |
| `ast.h`            | Define as estruturas utilizadas na representação da AST               |
| `indent_manager.c` | Controla os níveis de indentação necessários para gerar Python válido |
| `indent_manager.h` | Define a interface do controle de indentação                          |
| `parser.y`         | Reconhece estruturas sintáticas e integra ações de construção/geração |
| `semantic.c`       | Garante que o código seja semanticamente válido antes da geração      |

---

# Exemplo Completo

## Código de Entrada em C

```c id="c45h6k"
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

## Código Gerado em Python

```python id="yc6ywy"
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

# Limitações Atuais

A versão atual do gerador de código possui suporte parcial à linguagem C, de acordo com o subconjunto definido no projeto.

Entre as limitações atuais estão:

* Ausência de otimizações avançadas de código;
* Ausência de geração de código intermediário;
* Ausência de geração para código de máquina ou assembly;
* Ausência de suporte completo à biblioteca padrão da linguagem C;
* Suporte limitado a ponteiros;
* Suporte limitado a entrada e saída;
* Suporte limitado ou inexistente a estruturas como `struct`, `union`, `enum` e `switch/case`;
* Suporte limitado a arrays e manipulação avançada de memória.

---

# Possíveis Evoluções

A arquitetura permite futuras expansões, incluindo:

* Geração de código intermediário;
* Otimizações de código;
* Suporte mais robusto a funções;
* Suporte mais completo a vetores e matrizes;
* Suporte ampliado a ponteiros;
* Melhor tratamento de entrada e saída;
* Melhor tratamento de erros;
* Geração de código Python mais idiomático;
* Ampliação do subconjunto da linguagem C aceito pelo compilador.

---

# Considerações

O módulo de geração de código foi desenvolvido de forma integrada à AST, permitindo que as estruturas reconhecidas pelo parser e validadas semanticamente sejam traduzidas para Python.

A separação entre análise léxica, análise sintática, análise semântica, AST e geração de código facilita a manutenção do compilador e permite evolução incremental do projeto.

Como a linguagem Python utiliza indentação como parte da sintaxe, o controle de indentação é um componente essencial para garantir que o código gerado seja executável e mantenha a lógica do programa original.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                                             | Autor(es)                                               |
| :----: | :--------: | :------------------------------------------------------------------------------------ | :------------------------------------------------------ |
|  `1.0` | 30/04/2025 | Criação da documentação do módulo de geração de código                                | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.1` | 08/06/2026 | Atualização do módulo de geração de código conforme implementação atual do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |
