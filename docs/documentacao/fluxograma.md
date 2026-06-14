# Fluxograma da Arquitetura do Compilador

Esta seção apresenta o fluxograma da arquitetura do compilador, demonstrando o fluxo de processamento desde o arquivo de entrada em C até a geração do código Python final.

---

# Fluxo Geral

```mermaid
flowchart TD
    A[Arquivo de entrada .c] --> B[main.c]
    B --> C[Analisador Léxico<br/>src/lexer.l]
    C --> D[Tokens]
    D --> E[Analisador Sintático<br/>src/parser.y]
    E --> F[Construção/uso da AST<br/>src/ast/ast.c]
    F --> G[Análise Semântica<br/>src/semantic.c]
    G --> H[Tabela de Símbolos<br/>src/tabela.c]
    G --> I[Tabela de Funções<br/>src/tabela_funcoes.c]
    H --> J{Código válido?}
    I --> J
    J -- Sim --> K[Geração de Código Python<br/>src/ast/ast.c]
    J -- Não --> L[Exibição de erro]
    K --> M[Controle de Indentação<br/>indent_manager.c]
    M --> N[Arquivo de saída<br/>tests/saida.py]
```

---

# Descrição do Fluxo

| Etapa | Descrição |
|---|---|
| Arquivo de entrada | Código-fonte escrito em um subconjunto da linguagem C |
| `main.c` | Inicializa o compilador e aciona o processo de análise |
| `lexer.l` | Realiza a análise léxica e gera tokens |
| `parser.y` | Valida a estrutura gramatical do código |
| AST | Representa internamente comandos, expressões, declarações e funções |
| Análise semântica | Valida escopo, tipos, declarações e chamadas de função |
| Tabela de símbolos | Armazena variáveis, tipos, escopos e linhas |
| Tabela de funções | Armazena funções declaradas e quantidade de argumentos |
| Geração de código | Converte estruturas válidas de C para Python |
| Controle de indentação | Garante blocos Python corretamente indentados |
| `saida.py` | Arquivo Python final gerado pelo compilador |

---

# Fluxo de Erros

```mermaid
flowchart TD
    A[Entrada em C] --> B[Análise Léxica]
    B --> C{Erro léxico?}
    C -- Sim --> D[Reporta erro léxico]
    C -- Não --> E[Análise Sintática]
    E --> F{Erro sintático?}
    F -- Sim --> G[Reporta erro sintático]
    F -- Não --> H[Análise Semântica]
    H --> I{Erro semântico?}
    I -- Sim --> J[Reporta erro semântico]
    I -- Não --> K[Gera código Python]
```

---

# Observação sobre Mermaid no MkDocs

Caso o Mermaid não renderize automaticamente no MkDocs, é necessário habilitar suporte no `mkdocs.yml`.

Exemplo de configuração:

```yaml
markdown_extensions:
  - pymdownx.superfences
```

Dependendo do tema, também pode ser necessário configurar suporte específico a diagramas Mermaid.

---

# Histórico de Versões

| Versão | Data | Descrição | Autor(es) |
|:--:|:--:|:--|:--|
| `1.0` | 14/06/2026 | Criação da documentação técnica do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |