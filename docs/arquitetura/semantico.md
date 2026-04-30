# Arquitetura — Semântico

O módulo semântico é responsável por validar o significado das estruturas reconhecidas pelo analisador sintático.

Essa etapa garante consistência lógica e semântica durante o processo de compilação.

---

# Objetivo

Realizar verificações relacionadas ao uso correto de variáveis, tipos e escopo dentro do programa.

---

# Responsabilidades

O analisador semântico é responsável por:

- Verificação de tipos
- Controle de escopo
- Validação de declarações
- Verificação de variáveis não declaradas
- Verificação de incompatibilidade de tipos
- Controle de reutilização de identificadores

---

# Verificações Realizadas

## Variáveis Declaradas

```c
int x;
x = 10;
```

---

## Uso Inválido

```c
y = 10;
```

Resultado:

```text
Erro semântico: variável 'y' não declarada
```

---

## Compatibilidade de Tipos

```c
int x;
x = 3.14;
```

Resultado:

```text
Aviso/Erro de incompatibilidade de tipos
```

---

# Fluxo Semântico

```text
Estrutura Sintática
        ↓
Verificações Semânticas
        ↓
Validação de Tipos e Escopo
        ↓
Código Válido
```

---

# Componentes Associados

| Componente | Função |
|---|---|
| Tabela de Símbolos | Armazenamento de variáveis e escopos |
| Regras Semânticas | Validação lógica do programa |
| Controle de Tipos | Compatibilidade entre expressões |

---

# Estrutura Esperada

```text
semantic/
├── semantic.c
├── semantic.h
└── symbol_table.c
```

---

# Tratamento de Erros

O módulo semântico é capaz de identificar inconsistências relacionadas ao significado do programa.

Exemplos:

```text
Variável não declarada
Tipo incompatível
Variável redeclarada
```

---

# Considerações

A análise semântica complementa a validação realizada pelo parser, garantindo maior confiabilidade no processo de geração de código.

A arquitetura permite futuras expansões para verificações mais avançadas.

---

# Histórico de Versões

| Versão | Data | Descrição | Autor(es) |
|:--:|:--:|:--|:--|
| `1.0` | 30/04/2026 | Criação da documentação do módulo semântico | [Arthur Fernandes](https://github.com/arthurfernandesj) |