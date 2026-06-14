# Testes

Esta seção apresenta a estratégia de testes utilizada durante o desenvolvimento do compilador, bem como os tipos de validação realizados para garantir o funcionamento correto das etapas do processo de compilação.

Os testes foram organizados para validar o comportamento do compilador C → Python em diferentes cenários, incluindo casos corretos e casos com erros esperados.

---

# Objetivo dos Testes

Os testes possuem como finalidade validar o comportamento do compilador em diferentes cenários, assegurando:

* Reconhecimento correto de tokens;
* Validação sintática adequada;
* Verificações semânticas consistentes;
* Tradução correta para Python;
* Identificação apropriada de erros;
* Funcionamento da tabela de símbolos;
* Funcionamento da tabela de funções;
* Validação de escopo;
* Validação de tipos;
* Geração correta de indentação em Python;
* Prevenção de regressões durante a evolução do projeto.

---

# Estratégia de Testes

O projeto utiliza testes baseados em arquivos de entrada localizados no diretório:

```text
tests/
```

Os testes são executados por meio do script:

```text
tests/run_tests.sh
```

Cada arquivo `.c` representa um cenário específico de validação do compilador.

A suíte contempla:

* Testes positivos, nos quais o código C deve ser aceito pelo compilador;
* Testes negativos, nos quais o código C deve ser rejeitado por conter erro léxico, sintático ou semântico;
* Testes de geração de código, nos quais o compilador deve produzir uma saída Python equivalente;
* Testes de regressão, utilizados para garantir que funcionalidades já implementadas continuem funcionando após novas alterações.

---

# Estrutura dos Testes

A estrutura dos testes é organizada da seguinte forma:

```text
tests/
├── teste.c
├── saida.py
├── run_tests.sh
├── README.md
└── casos/
    ├── basico.c
    ├── func_args_correto_ok.c
    ├── func_args_demais_erro.c
    ├── func_args_faltando_erro.c
    ├── func_sem_args_ok.c
    ├── if_apenas_ok.c
    ├── if_elif_else_ok.c
    ├── if_else_ok.c
    ├── ponteiro_01.c
    ├── ponteiro_02.c
    ├── ponteiro_03.c
    ├── ponteiro_04.c
    ├── ponteiro_05.c
    ├── printf_scanf.c
    ├── redeclaracao_erro.c
    ├── teste_escopo_global.c
    ├── teste_indentacao.c
    ├── tipo_char_int_ok.c
    ├── tipo_float_double_ok.c
    ├── tipo_int_float_ok.c
    ├── tipo_int_int_ok.c
    ├── tipo_mod_float_erro.c
    └── var_nao_declarada_erro.c
```

---

# Categorias de Testes

## Testes Léxicos

Responsáveis por validar o reconhecimento correto dos tokens pelo analisador léxico implementado com Flex.

### Verificações

* Palavras reservadas;
* Tipos básicos;
* Identificadores;
* Operadores aritméticos;
* Operadores relacionais;
* Operadores de atribuição;
* Delimitadores;
* Literais numéricos;
* Literais de caractere;
* Strings;
* Comentários de linha;
* Comentários de bloco;
* Símbolos relacionados a ponteiros.

### Exemplo

```c
int numero = 10;
float media = 8.5;
char letra = 'A';
```

---

## Testes Sintáticos

Responsáveis por validar se a sequência de tokens forma estruturas gramaticais válidas de acordo com o subconjunto da linguagem C suportado pelo compilador.

### Verificações

* Declarações válidas;
* Atribuições;
* Expressões aritméticas;
* Expressões relacionais;
* Blocos de código;
* Estruturas condicionais;
* Função `main`;
* Funções com e sem argumentos;
* Chamadas de função;
* Comandos `return`;
* Comandos básicos de entrada e saída;
* Declarações e usos básicos de ponteiros.

### Exemplo

```c
int main() {
    int x = 10;

    if (x > 0) {
        x += 1;
    }

    return x;
}
```

---

## Testes Semânticos

Responsáveis por validar regras semânticas do compilador, garantindo que o código seja consistente além da estrutura sintática.

### Verificações

* Variáveis não declaradas;
* Redeclaração de variáveis;
* Controle de escopo;
* Compatibilidade de tipos;
* Uso correto de identificadores;
* Registro de funções;
* Chamadas de função com quantidade correta de argumentos;
* Chamadas de função com argumentos faltando;
* Chamadas de função com argumentos em excesso.

### Exemplo de erro semântico

```c
int main() {
    x = 10;
    return x;
}
```

Resultado esperado:

```text
Erro semântico: variável não declarada
```

---

## Testes de Tipos

Responsáveis por validar o comportamento do compilador em operações e atribuições envolvendo diferentes tipos.

### Verificações

* Operações entre inteiros;
* Atribuições envolvendo `int` e `float`;
* Atribuições envolvendo `float` e `double`;
* Compatibilidade envolvendo `char`;
* Erros de operação entre tipos incompatíveis;
* Uso inválido de operadores com determinados tipos.

### Exemplos de arquivos relacionados

```text
tipo_int_int_ok.c
tipo_int_float_ok.c
tipo_float_double_ok.c
tipo_char_int_ok.c
tipo_mod_float_erro.c
```

---

## Testes de Funções

Responsáveis por validar declaração, registro e chamada de funções.

### Verificações

* Funções sem argumentos;
* Funções com argumentos;
* Chamadas com quantidade correta de argumentos;
* Chamadas com argumentos faltando;
* Chamadas com argumentos em excesso;
* Integração com a tabela de funções.

### Exemplos de arquivos relacionados

```text
func_sem_args_ok.c
func_args_correto_ok.c
func_args_faltando_erro.c
func_args_demais_erro.c
```

---

## Testes de Escopo

Responsáveis por validar a separação entre escopos globais e locais.

### Verificações

* Variáveis globais;
* Variáveis locais;
* Uso de variáveis em escopos válidos;
* Identificação de conflitos de declaração;
* Consulta correta à tabela de símbolos.

### Exemplo de arquivo relacionado

```text
teste_escopo_global.c
```

---

## Testes de Condicionais e Indentação

Responsáveis por validar a tradução de estruturas condicionais e a geração correta da indentação no código Python.

### Verificações

* `if` simples;
* `if` com `else`;
* Condicionais encadeadas;
* Blocos internos;
* Indentação obrigatória do Python.

### Exemplos de arquivos relacionados

```text
if_apenas_ok.c
if_else_ok.c
if_elif_else_ok.c
teste_indentacao.c
```

---

## Testes de Ponteiros

Responsáveis por validar o suporte básico a ponteiros dentro do subconjunto definido para o projeto.

### Verificações

* Declaração básica de ponteiros;
* Uso de `*`;
* Uso de `&`;
* Atribuições envolvendo ponteiros;
* Tradução simplificada para Python.

### Exemplos de arquivos relacionados

```text
ponteiro_01.c
ponteiro_02.c
ponteiro_03.c
ponteiro_04.c
ponteiro_05.c
```

---

## Testes de Entrada e Saída

Responsáveis por validar o suporte básico a comandos como `printf` e `scanf`.

### Verificações

* Reconhecimento léxico;
* Validação sintática;
* Tradução simplificada para Python;
* Integração com variáveis.

### Exemplo de arquivo relacionado

```text
printf_scanf.c
```

---

## Testes de Geração de Código

Responsáveis por validar a tradução correta do código C para Python.

### Entrada em C

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

### Saída esperada em Python

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

Antes de executar os testes, compile o projeto:

```bash
make clean
make
```

Para executar a suíte de testes:

```bash
bash tests/run_tests.sh
```

O script executa os casos definidos no diretório `tests/casos/` e valida se o compilador aceita ou rejeita os arquivos conforme esperado.

---

# Execução com Cobertura

O projeto também possui suporte à execução de testes com cobertura.

Para compilar com suporte à cobertura:

```bash
make coverage
```

Em seguida, execute os testes com a opção de cobertura:

```bash
bash tests/run_tests.sh --coverage
```

Caso necessário, instale a ferramenta `lcov`:

```bash
sudo apt update
sudo apt install lcov
```

---

# Fluxo de Testes

```text
Arquivo de Teste em C
        ↓
Execução do Compilador
        ↓
Análise Léxica
        ↓
Análise Sintática
        ↓
Análise Semântica
        ↓
Geração de Código Python
        ↓
Validação do Resultado
```

---

# Tratamento de Erros nos Testes

Os testes também validam o comportamento do compilador diante de entradas inválidas.

## Exemplos de erros verificados

* Caracteres inválidos;
* Estruturas sintáticas incorretas;
* Variáveis não declaradas;
* Redeclaração de variáveis;
* Incompatibilidade de tipos;
* Quantidade incorreta de argumentos;
* Uso de operações inválidas;
* Uso de construções fora do subconjunto suportado.

---

# Convenção para Testes Negativos

Arquivos que possuem nomes indicando erro, como `_erro` ou `_fail`, são tratados como casos negativos.

Nesses casos, o teste é considerado correto quando o compilador identifica o problema e rejeita a entrada.

Exemplo:

```text
var_nao_declarada_erro.c
redeclaracao_erro.c
tipo_mod_float_erro.c
func_args_faltando_erro.c
func_args_demais_erro.c
```

---

# Objetivos da Validação

A estratégia de testes busca garantir:

* Estabilidade do compilador;
* Confiabilidade das análises;
* Consistência da tradução;
* Correção da geração de código;
* Validação das regras semânticas;
* Facilidade de manutenção;
* Detecção de regressões;
* Evolução segura do projeto.

---

# Possíveis Evoluções

Futuramente, o sistema de testes poderá incluir:

* Integração contínua com GitHub Actions;
* Comparação automática entre saída gerada e saída esperada;
* Relatórios de cobertura publicados na documentação;
* Testes de regressão mais detalhados;
* Testes específicos para novos recursos da linguagem;
* Validação automática do código Python gerado.

---

# Considerações

A implementação de testes automatizados é fundamental para garantir a qualidade e evolução contínua do compilador ao longo do desenvolvimento do projeto.

A suíte de testes permite validar tanto os casos corretos quanto os casos incorretos, garantindo maior segurança durante refatorações, adição de funcionalidades e ajustes na documentação.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                             | Autor(es)                                               |
| :----: | :--------: | :-------------------------------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 30/04/2025 | Criação da documentação de testes                                     | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.1` | 08/06/2026 | Atualização da documentação de testes conforme suíte atual do projeto | [Arthur Fernandes](https://github.com/arthurfernandesj) |
