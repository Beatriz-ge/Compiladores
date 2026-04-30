# Testes

Esta seção apresenta a estratégia de testes utilizada durante o desenvolvimento do compilador, bem como os tipos de validação realizados para garantir o funcionamento correto das etapas do processo de compilação.

---

# Objetivo dos Testes

Os testes possuem como finalidade validar o comportamento do compilador em diferentes cenários, assegurando:

- Reconhecimento correto de tokens
- Validação sintática adequada
- Verificações semânticas consistentes
- Tradução correta para Python
- Identificação apropriada de erros

---

# Estratégia de Testes

O projeto utiliza testes baseados em arquivos de entrada localizados no diretório:

```text
tests/
```

Cada arquivo contém casos específicos utilizados para validar funcionalidades do compilador.

---

# Estrutura dos Testes

```text
tests/
├── basico.c
├── operadores.c
├── condicionais.c
├── repeticao.c
├── erros_lexicos.c
├── erros_sintaticos.c
└── erros_semanticos.c
```

---

# Categorias de Testes

## Testes Léxicos

Responsáveis por validar o reconhecimento correto de tokens.

### Verificações

- Palavras reservadas
- Identificadores
- Operadores
- Delimitadores
- Literais numéricos
- Caracteres inválidos

### Exemplo

```c
int numero = 10;
```

---

## Testes Sintáticos

Responsáveis por validar a estrutura gramatical do programa.

### Verificações

- Declarações válidas
- Estruturas condicionais
- Estruturas de repetição
- Expressões
- Blocos de código

### Exemplo

```c
if (x > 0) {
    x = x + 1;
}
```

---

## Testes Semânticos

Responsáveis por validar regras semânticas do compilador.

### Verificações

- Variáveis não declaradas
- Compatibilidade de tipos
- Escopo
- Redeclaração de variáveis

### Exemplo

```c
x = 10;
```

Resultado esperado:

```text
Erro semântico: variável não declarada
```

---

## Testes de Geração de Código

Responsáveis por validar a tradução correta do código C para Python.

### Exemplo

#### Entrada em C

```c
while (x < 5) {
    x++;
}
```

#### Saída Esperada em Python

```python
while x < 5:
    x += 1
```

---

# Execução dos Testes

Os testes automatizados podem ser executados utilizando:

```bash
make test
```

O script executa automaticamente todos os arquivos presentes na pasta `tests/`.

---

# Fluxo de Testes

```text
Arquivo de Teste
        ↓
Execução do Compilador
        ↓
Validação da Saída
        ↓
Resultado do Teste
```

---

# Tratamento de Erros

Os testes também validam o comportamento do compilador diante de entradas inválidas.

## Exemplos de erros verificados

- Caracteres inválidos
- Estruturas sintáticas incorretas
- Variáveis não declaradas
- Incompatibilidade de tipos

---

# Objetivos da Validação

A estratégia de testes busca garantir:

- Estabilidade do compilador
- Confiabilidade das análises
- Consistência da tradução
- Facilidade de manutenção
- Evolução segura do projeto

---

# Possíveis Evoluções

Futuramente, o sistema de testes poderá incluir:

- Integração contínua (CI)
- Testes automatizados com GitHub Actions
- Comparação automática de saída
- Relatórios de cobertura
- Testes de regressão

---

# Considerações

A implementação de testes automatizados é fundamental para garantir a qualidade e evolução contínua do compilador ao longo do desenvolvimento do projeto.

---

# Histórico de Versões

| Versão | Data | Descrição | Autor(es) |
|:--:|:--:|:--|:--|
| `1.0` | 30/04/2026 | Criação da documentação de testes | [Arthur Fernandes](https://github.com/arthurfernandesj) |