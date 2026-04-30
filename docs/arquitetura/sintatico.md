# Arquitetura — Sintático

O módulo sintático é responsável por validar a estrutura gramatical do programa a partir dos tokens gerados pelo analisador léxico.

O analisador sintático foi desenvolvido utilizando Bison.

---

# Objetivo

Garantir que o código-fonte siga corretamente as regras gramaticais definidas para o subconjunto da linguagem C suportado pelo compilador.

---

# Responsabilidades

O analisador sintático é responsável por:

- Validar a estrutura gramatical
- Organizar hierarquicamente os comandos
- Reconhecer expressões válidas
- Validar estruturas condicionais e de repetição
- Detectar erros sintáticos

---

# Estruturas Suportadas

## Declaração de Variáveis

```c
int x;
float valor;
```

---

## Atribuições

```c
x = 10;
```

---

## Estruturas Condicionais

```c
if (x > 0) {
    x = x + 1;
}
```

---

## Estruturas de Repetição

```c
while (x < 10) {
    x++;
}
```

---

# Fluxo Sintático

```text
Tokens
   ↓
Parser (Bison)
   ↓
Validação Gramatical
   ↓
Estrutura Sintática Válida
```

---

# Ferramenta Utilizada

| Ferramenta | Finalidade |
|---|---|
| Bison | Geração automática do parser |

---

# Estrutura do Arquivo Sintático

```text
parser.y
```

O arquivo contém:

- Declaração de tokens
- Regras gramaticais
- Precedência de operadores
- Ações semânticas
- Tratamento de erros

---

# Exemplo de Regra

```bison
program:
    declarations statements
;
```

---

# Tratamento de Erros Sintáticos

O parser identifica estruturas inválidas e informa a linha do erro.

Exemplo:

```text
Erro sintático na linha 5
```

---

# Considerações

A gramática foi construída de forma modular, permitindo expansão gradual das estruturas suportadas pelo compilador.

O módulo sintático atua como núcleo central da validação estrutural do sistema.

---

# Histórico de Versões

| Versão | Data | Descrição | Autor(es) |
|:--:|:--:|:--|:--|
| `1.0` | 30/04/2026 | Criação da documentação do módulo sintático | [Arthur Fernandes](https://github.com/arthurfernandesj) |