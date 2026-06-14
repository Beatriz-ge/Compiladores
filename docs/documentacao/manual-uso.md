# Manual de Uso

Este manual apresenta as instruções necessárias para instalar dependências, compilar, executar e testar o compilador C → Python desenvolvido no projeto.

O compilador recebe como entrada um arquivo escrito em um subconjunto da linguagem C e gera como saída um arquivo Python equivalente.

---

# Pré-requisitos

Antes de utilizar o compilador, é necessário ter as seguintes ferramentas instaladas:

* GCC;
* Make;
* Flex;
* Bison;
* Bash;
* lcov, opcional, para cobertura de testes.

---

# Instalação das Dependências

## Linux — Ubuntu/Debian

Execute:

```bash
sudo apt update
sudo apt install gcc make flex bison
```

Para utilizar cobertura de testes, instale também:

```bash
sudo apt install lcov
```

---

## Windows

No Windows, recomenda-se utilizar WSL com Ubuntu para maior compatibilidade com os comandos e scripts do projeto.

Após instalar o WSL e abrir o terminal Ubuntu, execute:

```bash
sudo apt update
sudo apt install gcc make flex bison lcov
```

Também é possível utilizar MSYS2, mas o WSL é a alternativa mais próxima do ambiente Linux utilizado no desenvolvimento.

---

# Como Compilar o Projeto

Na raiz do projeto, execute:

```bash
make clean
make
```

O comando `make clean` remove arquivos gerados anteriormente, enquanto o comando `make` compila o compilador.

Após a compilação, o binário será gerado em:

```text
bin/compilador
```

---

# Como Executar o Compilador

Para executar o compilador, utilize o seguinte formato:

```bash
./bin/compilador caminho/do/arquivo.c
```

Exemplo:

```bash
./bin/compilador tests/teste.c
```

Se o código de entrada for válido, o compilador irá gerar o arquivo Python de saída em:

```text
tests/saida.py
```

---

# Exemplo de Uso

## 1. Criar ou editar o arquivo de entrada

Edite o arquivo:

```text
tests/teste.c
```

Exemplo de conteúdo:

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

## 2. Compilar o projeto

```bash
make clean
make
```

---

## 3. Executar o compilador

```bash
./bin/compilador tests/teste.c
```

---

## 4. Verificar o arquivo gerado

Após a execução, abra o arquivo:

```text
tests/saida.py
```

Saída esperada:

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

# Saída Esperada no Terminal

Durante a execução, o compilador pode exibir mensagens indicando o resultado das etapas de análise.

Exemplo:

```text
[SUCESSO] O código é sintaticamente válido.
Léxico:           OK
Sintático:        OK
Semântico:        OK
------------------------------------------
TUDO OK!
Arquivo 'tests/saida.py' criado com sucesso.
```

Também pode ser exibida a tabela de símbolos, mostrando variáveis identificadas no programa.

---

# Como Executar os Testes

A suíte de testes automatizados pode ser executada com:

```bash
bash tests/run_tests.sh
```

O script executa os arquivos localizados em:

```text
tests/casos/
```

Os testes incluem casos válidos e inválidos.

---

# Como Executar Testes com Cobertura

Para compilar o projeto com suporte à cobertura:

```bash
make coverage
```

Depois execute:

```bash
bash tests/run_tests.sh --coverage
```

Caso o comando falhe por ausência do `lcov`, instale com:

```bash
sudo apt update
sudo apt install lcov
```

---

# Convenção dos Testes

Os testes seguem uma convenção de nomes.

Arquivos com nomes contendo `_ok` representam casos válidos.

Exemplos:

```text
func_args_correto_ok.c
if_else_ok.c
tipo_int_int_ok.c
```

Arquivos com nomes contendo `_erro` ou `_fail` representam casos inválidos.

Exemplos:

```text
var_nao_declarada_erro.c
redeclaracao_erro.c
tipo_mod_float_erro.c
func_args_faltando_erro.c
```

Nos casos inválidos, o teste é considerado correto quando o compilador rejeita a entrada.

---

# Funcionalidades Suportadas

O compilador possui suporte a um subconjunto controlado da linguagem C, incluindo:

* Declaração de variáveis;
* Atribuições;
* Tipos básicos como `int`, `float`, `double` e `char`;
* Expressões aritméticas;
* Expressões relacionais;
* Estruturas condicionais com `if` e `else`;
* Função `main`;
* Funções com e sem argumentos;
* Chamadas de função;
* Verificação de quantidade de argumentos;
* Comentários de linha e de bloco;
* Conversão de comentários C para comentários Python;
* Entrada e saída básica com `printf` e `scanf`;
* Suporte básico a ponteiros;
* Análise semântica;
* Tabela de símbolos;
* Tabela de funções;
* Geração de código Python.

---

# Funcionalidades Não Suportadas

O projeto não implementa a linguagem C completa.

Entre as funcionalidades fora do escopo atual estão:

* Otimizações avançadas;
* Interface gráfica;
* Geração de código de máquina ou assembly;
* Suporte completo à biblioteca padrão de C;
* Suporte completo a ponteiros avançados;
* Suporte completo a arrays;
* Suporte a `struct`, `union` e `enum`;
* Compilação de múltiplos arquivos;
* Suporte a múltiplas linguagens de entrada ou saída.

---

# Problemas Comuns

## Comando `make` não encontrado

Instale o Make:

```bash
sudo apt install make
```

---

## Erro relacionado ao Flex

Instale o Flex:

```bash
sudo apt install flex
```

---

## Erro relacionado ao Bison

Instale o Bison:

```bash
sudo apt install bison
```

---

## Binário não encontrado

Se o comando abaixo falhar:

```bash
./bin/compilador tests/teste.c
```

compile novamente o projeto:

```bash
make clean
make
```

---

## Permissão negada ao executar script de testes

Execute o script com `bash`:

```bash
bash tests/run_tests.sh
```

Ou conceda permissão de execução:

```bash
chmod +x tests/run_tests.sh
./tests/run_tests.sh
```

---

# Fluxo Resumido de Uso

```text
Instalar dependências
        ↓
Compilar com make
        ↓
Executar bin/compilador
        ↓
Gerar tests/saida.py
        ↓
Executar testes, se necessário
```

---

# Comandos Principais

| Comando                              | Finalidade                            |
| ------------------------------------ | ------------------------------------- |
| `make clean`                         | Remove arquivos gerados anteriormente |
| `make`                               | Compila o projeto                     |
| `./bin/compilador tests/teste.c`     | Executa o compilador com um arquivo C |
| `bash tests/run_tests.sh`            | Executa a suíte de testes             |
| `make coverage`                      | Compila com suporte à cobertura       |
| `bash tests/run_tests.sh --coverage` | Executa os testes com cobertura       |

---

# Considerações

Este manual apresenta o fluxo principal de uso do compilador.

Para melhor compatibilidade, recomenda-se executar o projeto em ambiente Linux ou WSL com Ubuntu. O uso de outros ambientes pode exigir adaptações nas dependências ou nos comandos de execução.

---

# Histórico de Versões

| Versão |    Data    | Descrição                              | Autor(es)                                               |
| :----: | :--------: | :------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 14/06/2026 | Criação do manual de uso do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |
