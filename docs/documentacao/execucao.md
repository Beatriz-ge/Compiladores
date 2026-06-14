# Execução

Esta seção descreve o processo de instalação de dependências, compilação, execução e testes do compilador desenvolvido em C utilizando Flex e Bison.

O compilador recebe como entrada um arquivo escrito em um subconjunto da linguagem C e gera como saída um arquivo Python equivalente.

---

# Pré-requisitos

Antes de executar o projeto, é necessário possuir as seguintes ferramentas instaladas no sistema:

* GCC;
* Make;
* Flex;
* Bison;
* Bash;
* lcov, opcional, para geração de cobertura de testes.

---

# Instalação das Dependências

## Linux — Ubuntu/Debian

Para instalar as dependências principais:

```bash
sudo apt update
sudo apt install gcc make flex bison
```

Para também utilizar a funcionalidade de cobertura de testes:

```bash
sudo apt install lcov
```

---

## Windows

No Windows, recomenda-se utilizar WSL ou MSYS2.

A opção mais indicada para manter compatibilidade com os scripts do projeto é utilizar WSL com Ubuntu.

### Opção 1 — WSL com Ubuntu

Após instalar o WSL e abrir o terminal Ubuntu, execute:

```bash
sudo apt update
sudo apt install gcc make flex bison lcov
```

### Opção 2 — MSYS2

1. Instale o MSYS2.
2. Abra o terminal `MSYS2 UCRT64`.
3. Instale as ferramentas necessárias:

```bash
pacman -S mingw-w64-ucrt-x86_64-gcc
pacman -S make
pacman -S flex
pacman -S bison
```

4. Verifique se as ferramentas foram instaladas corretamente:

```bash
gcc --version
make --version
flex --version
bison --version
```

---

# Compilação do Projeto

A compilação do compilador é realizada por meio do `Makefile`.

Para garantir uma compilação limpa, execute:

```bash
make clean
make
```

Durante o processo de compilação:

* O Flex processa o arquivo `src/lexer.l`;
* O Bison processa o arquivo `src/parser.y`;
* O GCC compila os arquivos C do projeto;
* O executável final é gerado no diretório `bin/`.

---

# Estrutura Gerada

Após a compilação, o projeto pode gerar arquivos intermediários no diretório `build/` e o binário final no diretório `bin/`.

```text
build/                  # Arquivos intermediários da compilação
bin/
└── compilador          # Executável final do compilador
```

O executável principal do projeto é:

```text
bin/compilador
```

---

# Execução do Compilador

Para executar o compilador, utilize o binário gerado em `bin/compilador` passando um arquivo `.c` como argumento.

Exemplo:

```bash
./bin/compilador tests/teste.c
```

Caso o código-fonte seja léxica, sintática e semanticamente válido, o compilador gera o arquivo Python equivalente em:

```text
tests/saida.py
```

---

# Exemplo de Execução

## Arquivo de entrada

Exemplo de arquivo `tests/teste.c`:

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

## Comando de execução

```bash
./bin/compilador tests/teste.c
```

## Saída esperada em Python

O arquivo `tests/saida.py` poderá ser gerado com conteúdo semelhante a:

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

# Execução dos Testes

Os testes automatizados são executados por meio do script `tests/run_tests.sh`.

Antes de executar os testes, compile o projeto:

```bash
make clean
make
```

Em seguida, execute:

```bash
bash tests/run_tests.sh
```

O script percorre os casos de teste definidos no diretório `tests/casos/` e valida se o compilador aceita ou rejeita os arquivos conforme esperado.

---

# Execução com Cobertura

O projeto possui suporte à execução dos testes com cobertura.

Para compilar o projeto com suporte à cobertura:

```bash
make coverage
```

Em seguida, execute os testes com a opção de cobertura:

```bash
bash tests/run_tests.sh --coverage
```

Caso o ambiente não possua o `lcov`, instale com:

```bash
sudo apt update
sudo apt install lcov
```

---

# Limpeza dos Arquivos Gerados

Para remover arquivos gerados durante a compilação, utilize:

```bash
make clean
```

Esse comando remove arquivos intermediários e artefatos gerados no processo de build, permitindo uma nova compilação limpa.

---

# Fluxo Geral de Execução

```text
Arquivo C de Entrada
        ↓
Execução do binário bin/compilador
        ↓
Análise Léxica com Flex
        ↓
Análise Sintática com Bison
        ↓
Construção/uso da AST
        ↓
Análise Semântica
        ↓
Tabela de Símbolos e Tabela de Funções
        ↓
Geração de Código Python
        ↓
Arquivo tests/saida.py
```

---

# Comandos Principais

| Comando                              | Finalidade                                       |
| ------------------------------------ | ------------------------------------------------ |
| `make`                               | Compila o projeto                                |
| `make clean`                         | Remove arquivos gerados pela compilação          |
| `make coverage`                      | Compila o projeto com suporte à cobertura        |
| `./bin/compilador tests/teste.c`     | Executa o compilador com um arquivo C de entrada |
| `bash tests/run_tests.sh`            | Executa a suíte de testes                        |
| `bash tests/run_tests.sh --coverage` | Executa os testes considerando cobertura         |

---

# Observações

* O projeto foi desenvolvido com foco principal em ambiente Linux.
* No Windows, recomenda-se utilizar WSL com Ubuntu para maior compatibilidade.
* O executável final não se chama `compiler`; no projeto atual, ele é gerado como `bin/compilador`.
* Os testes não são executados por `make test`; o comando correto é `bash tests/run_tests.sh`.
* O arquivo Python gerado pelo compilador é salvo em `tests/saida.py`.
* Todas as dependências devem estar corretamente instaladas antes da compilação.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                    | Autor(es)                                               |
| :----: | :--------: | :----------------------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 30/04/2025 | Criação e desenvolvimento inicial do documento               | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.1` | 08/06/2026 | Atualização das instruções conforme execução real do projeto | [Arthur Fernandes](https://github.com/arthurfernandesj) |
