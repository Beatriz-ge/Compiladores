# Arquitetura — Visão Geral

A arquitetura do compilador foi projetada de forma modular, permitindo a separação das responsabilidades de cada etapa do processo de compilação.

O sistema é organizado em componentes independentes responsáveis pela análise do código-fonte, validação estrutural e geração do código equivalente em Python.

---

# Objetivo da Arquitetura

A arquitetura tem como finalidade:

- Facilitar manutenção e evolução do projeto
- Separar responsabilidades entre os módulos
- Permitir escalabilidade futura
- Melhorar organização do código
- Simplificar testes e depuração

---

# Visão Geral do Fluxo

O compilador segue o fluxo clássico de processamento utilizado em compiladores tradicionais.

```text
Código Fonte em C
        ↓
Análise Léxica
        ↓
Geração de Tokens
        ↓
Análise Sintática
        ↓
Árvore/Validação Gramatical
        ↓
Análise Semântica
        ↓
Validação Semântica
        ↓
Geração de Código
        ↓
Código Python
```

---

# Componentes da Arquitetura

## Analisador Léxico

Responsável por realizar a leitura do código-fonte caractere por caractere, identificando os elementos léxicos da linguagem.

### Principais responsabilidades

- Reconhecimento de tokens
- Remoção de espaços e comentários
- Identificação de palavras-chave
- Identificação de operadores e delimitadores
- Reconhecimento de identificadores e literais

### Ferramenta utilizada

- Flex

---

## Analisador Sintático

Responsável por validar a estrutura gramatical do programa com base nas regras definidas para o subconjunto da linguagem C suportado pelo compilador.

### Principais responsabilidades

- Validação da gramática
- Organização hierárquica das estruturas
- Verificação de comandos válidos
- Tratamento de erros sintáticos

### Ferramenta utilizada

- Bison

---

## Análise Semântica

Responsável por validar regras semânticas relacionadas ao significado do programa.

### Principais responsabilidades

- Verificação de tipos
- Controle de escopo
- Validação de declarações
- Verificação de uso correto de variáveis

---

## Geração de Código

Responsável pela tradução das estruturas válidas da linguagem C para código equivalente em Python.

### Principais responsabilidades

- Conversão de comandos
- Tradução de expressões
- Adaptação de estruturas da linguagem
- Geração do código final em Python

---

# Organização dos Módulos

```text
src/
├── lexer/        # Analisador léxico
├── parser/       # Analisador sintático
├── semantic/     # Regras semânticas
├── generator/    # Geração de código Python
├── include/      # Headers e estruturas compartilhadas
└── main.c        # Inicialização do compilador
```

---

# Tecnologias Utilizadas

| Tecnologia | Finalidade |
|---|---|
| C | Linguagem principal do compilador |
| Flex | Geração do analisador léxico |
| Bison | Geração do analisador sintático |
| Make | Automação de compilação |
| Git/GitHub | Versionamento e colaboração |
| GitHub Pages | Hospedagem da documentação |

---

# Modelo Arquitetural

O projeto segue uma arquitetura em pipeline, onde cada etapa do compilador processa a saída da etapa anterior.

Esse modelo facilita:

- Modularização
- Isolamento de responsabilidades
- Evolução incremental
- Testabilidade
- Manutenção

---

# Considerações Arquiteturais

A arquitetura foi planejada visando simplicidade e clareza didática, permitindo que cada etapa do processo de compilação possa ser compreendida e evoluída separadamente.

Além disso, o modelo adotado permite futuras expansões, incluindo:

- Árvore Sintática Abstrata (AST)
- Tabela de símbolos
- Otimizações
- Código intermediário
- Suporte a novos elementos da linguagem C

---

# Histórico de Versões

| Versão | Data | Descrição | Autor(es) |
|:--:|:--:|:--|:--|
| `1.0` | 30/04/2026 | Criação da documentação de arquitetura | [Arthur Fernandes](https://github.com/arthurfernandesj) |