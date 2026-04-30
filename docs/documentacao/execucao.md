# Execução

Esta seção descreve o processo de compilação e execução do compilador desenvolvido utilizando Flex e Bison.

## Pré-requisitos

Antes de executar o projeto, é necessário possuir as seguintes ferramentas instaladas no sistema:

- GCC
- Make
- Flex
- Bison

---

# Instalação das Dependências

## Linux (Ubuntu/Debian)

```bash
sudo apt update
sudo apt install gcc make flex bison
```

---

## Windows

No Windows, recomenda-se utilizar o ambiente **MSYS2** ou **MinGW**.

### Instalação utilizando MSYS2

1. Instale o MSYS2:
   - https://www.msys2.org/

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

A compilação do compilador é realizada através do `Makefile`.

Execute o comando:

```bash
make
```

Durante o processo de compilação:

- O Flex gera o analisador léxico
- O Bison gera o analisador sintático
- O GCC realiza a compilação final do projeto

---

# Estrutura Gerada

Após a compilação, alguns arquivos são gerados automaticamente:

```text
lex.yy.c        # Código gerado pelo Flex
parser.tab.c    # Código gerado pelo Bison
parser.tab.h    # Definições de tokens
compiler        # Executável final do compilador
```

No Windows, o executável pode ser gerado como:

```text
compiler.exe
```

---

# Execução do Compilador

## Linux

```bash
./compiler
```

Ou utilizando um arquivo de entrada:

```bash
./compiler < arquivo.c
```

---

## Windows

```bash
compiler.exe
```

Ou utilizando um arquivo de entrada:

```bash
compiler.exe < arquivo.c
```

---

# Execução dos Testes

Os testes automatizados podem ser executados através do comando:

```bash
make test
```

Os testes presentes na pasta `tests/` serão executados automaticamente para validar:

- Reconhecimento léxico
- Estrutura sintática
- Tratamento de erros
- Casos válidos e inválidos

---

# Limpeza dos Arquivos Gerados

Para remover os arquivos gerados durante a compilação, utilize:

```bash
make clean
```

Esse comando remove:

```text
lex.yy.c
parser.tab.c
parser.tab.h
compiler
compiler.exe
```

---

# Fluxo Geral de Execução

```text
Código Fonte (.c)
        ↓
Analisador Léxico (Flex)
        ↓
Geração de Tokens
        ↓
Analisador Sintático (Bison)
        ↓
Validação Gramatical
        ↓
Saída do Compilador
```

---

# Observações

- O projeto possui suporte para Linux e Windows.
- Recomenda-se utilizar Ubuntu no Linux e MSYS2 no Windows.
- Todas as dependências devem estar corretamente instaladas antes da compilação.
- Os testes automatizados auxiliam na validação contínua do compilador durante o desenvolvimento.

---

## Histórico de Versões

| Versão | Data       | Descrição               | Autor(es)                                                                 |
|:------:|:----------:|:-----------------------:|:-------------------------------------------------------------------------:| 
| `1.0`  | 30/04/2026 | Criação e texto desenvolvido.    | [Arthur Fernandes](https://github.com/arthurfernandesj)                  |