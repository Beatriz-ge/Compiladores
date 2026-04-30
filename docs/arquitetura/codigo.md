# Arquitetura — Código

O módulo de geração de código é responsável por converter estruturas válidas da linguagem C em código equivalente na linguagem Python.

Essa etapa representa a saída final do compilador e ocorre após as validações léxica, sintática e semântica.

---

# Objetivo

Traduzir estruturas reconhecidas pelo compilador para código Python semanticamente equivalente, mantendo a lógica original do programa de entrada.

---

# Responsabilidades

O gerador de código é responsável por:

- Traduzir declarações de variáveis
- Converter expressões aritméticas
- Traduzir estruturas condicionais
- Traduzir estruturas de repetição
- Adaptar operadores e sintaxe
- Gerar código Python válido
- Produzir o arquivo final de saída

---

# Fluxo de Geração

```text
Código Validado
        ↓
Processamento Semântico
        ↓
Conversão das Estruturas
        ↓
Geração de Código Python
        ↓
Arquivo Final
```

---

# Estruturas Suportadas

## Declaração de Variáveis

### Entrada em C

```c
int x = 10;
```

### Saída em Python

```python
x = 10
```

---

## Operações Aritméticas

### Entrada em C

```c
resultado = a + b;
```

### Saída em Python

```python
resultado = a + b
```

---

## Estruturas Condicionais

### Entrada em C

```c
if (x > 0) {
    x = x + 1;
}
```

### Saída em Python

```python
if x > 0:
    x = x + 1
```

---

## Estruturas de Repetição

### Entrada em C

```c
while (x < 10) {
    x++;
}
```

### Saída em Python

```python
while x < 10:
    x += 1
```

---

# Estratégia de Tradução

O compilador realiza uma tradução direta das estruturas reconhecidas da linguagem C para Python.

A conversão considera:

- Equivalência lógica
- Sintaxe da linguagem alvo
- Indentação obrigatória do Python
- Conversão de blocos
- Conversão de operadores

---

# Organização do Módulo

```text
generator/
├── generator.c
├── generator.h
├── templates.c
└── templates.h
```

---

# Componentes do Gerador

| Componente | Função |
|---|---|
| `generator.c` | Processamento principal da geração |
| `templates.c` | Modelos auxiliares de saída |
| `generator.h` | Declarações compartilhadas |
| `templates.h` | Estruturas auxiliares |

---

# Exemplo Completo

## Código de Entrada (C)

```c
int x = 0;

while (x < 5) {
    x = x + 1;
}
```

---

## Código Gerado (Python)

```python
x = 0

while x < 5:
    x = x + 1
```

---

# Limitações Atuais

A versão atual do gerador de código possui suporte parcial à linguagem C.

Entre as limitações atuais estão:

- Ausência de ponteiros
- Ausência de structs
- Ausência de bibliotecas externas
- Suporte parcial a funções
- Sem otimização de código

---

# Possíveis Evoluções

A arquitetura permite futuras expansões, incluindo:

- Geração de AST
- Código intermediário
- Otimizações
- Suporte a funções avançadas
- Suporte a vetores e matrizes
- Melhor tratamento de erros

---

# Considerações

O módulo de geração de código foi projetado de forma modular, permitindo manutenção simplificada e evolução incremental do compilador.

A separação entre análise e geração facilita futuras melhorias no pipeline de compilação.

---

# Histórico de Versões

| Versão | Data | Descrição | Autor(es) |
|:--:|:--:|:--|:--|
| `1.0` | 30/04/2026 | Criação da documentação do módulo de geração de código | [Arthur Fernandes](https://github.com/arthurfernandesj) |