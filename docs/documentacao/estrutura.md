# Estrutura

A documentação do compilador foi organizada de forma modular para facilitar a navegação, manutenção e evolução do projeto ao longo do desenvolvimento da disciplina.

A estrutura do projeto está dividida em componentes responsáveis pelas diferentes etapas do compilador, incluindo análise léxica, análise sintática, testes automatizados e documentação.

## Organização de Diretórios

```text
.
├── docs/                 # Documentação do projeto (GitPages)
├── src/                  # Código-fonte principal do compilador
│   ├── lexer/            # Arquivos do analisador léxico (Flex)
│   ├── parser/           # Arquivos do analisador sintático (Bison)
│   ├── include/          # Bibliotecas e headers auxiliares
│   └── main.c            # Arquivo principal do compilador
├── tests/                # Casos de teste automatizados
├── scripts/              # Scripts auxiliares de execução e testes
├── Makefile              # Automação de compilação do projeto
├── README.md             # Documentação principal
└── .gitignore            # Arquivos ignorados pelo Git
```

## Componentes Principais

### `docs/`

Responsável pela documentação do projeto hospedada no GitHub Pages.  
Contém páginas de arquitetura, planejamento, evolução, testes e instruções de execução.

---

### `src/`

Diretório principal do compilador.

#### `lexer/`

Contém os arquivos do analisador léxico desenvolvidos com Flex, responsáveis pela identificação e tokenização dos elementos da linguagem.

#### `parser/`

Contém os arquivos do analisador sintático desenvolvidos com Bison, responsáveis pela validação gramatical da linguagem.

#### `include/`

Armazena bibliotecas auxiliares, definições compartilhadas e estruturas utilizadas pelo compilador.

#### `main.c`

Arquivo responsável pela inicialização e execução do compilador.

---

### `tests/`

Contém os arquivos de entrada utilizados para validar o comportamento do compilador durante o desenvolvimento.

Os testes são organizados para garantir:

- Verificação léxica
- Verificação sintática
- Casos válidos
- Casos inválidos
- Regressão de funcionalidades

---

### `scripts/`

Diretório destinado a scripts auxiliares para:

- Execução automática de testes
- Compilação
- Limpeza de arquivos temporários
- Automação do fluxo de desenvolvimento

---

### `Makefile`

Responsável pela automação da compilação do projeto, permitindo gerar o compilador e executar comandos auxiliares de forma padronizada.

Exemplo:

```bash
make
make test
make clean
```

## Estrutura Evolutiva

A organização do projeto foi planejada para permitir crescimento gradual conforme novas etapas do compilador forem implementadas, incluindo:

- Árvore sintática abstrata (AST)
- Análise semântica
- Tabela de símbolos
- Geração de código intermediário
- Otimizações
- Geração de código final

---


## Histórico de Versões

| Versão | Data       | Descrição               | Autor(es)                                                                 |
|:------:|:----------:|:-----------------------:|:-------------------------------------------------------------------------:| 
| `1.0`  | 30/04/2026 | Criação e texto desenvolvido.    | [Arthur Fernandes](https://github.com/arthurfernandesj)                  |