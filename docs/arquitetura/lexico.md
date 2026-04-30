# Arquitetura — Léxico

O módulo léxico é responsável pela primeira etapa do processo de compilação, realizando a leitura do código-fonte e convertendo os caracteres de entrada em tokens válidos para as próximas fases do compilador.

O analisador léxico foi desenvolvido utilizando a ferramenta Flex.

---

# Objetivo

O objetivo do módulo léxico é identificar padrões pertencentes à linguagem C e transformá-los em unidades léxicas compreensíveis pelo analisador sintático.

---

# Responsabilidades

O analisador léxico é responsável por:

- Ler o código-fonte caractere por caractere
- Reconhecer tokens da linguagem
- Ignorar espaços em branco e comentários
- Identificar palavras reservadas
- Identificar operadores e delimitadores
- Reconhecer identificadores
- Reconhecer constantes numéricas e literais
- Reportar erros léxicos

---

# Tokens Reconhecidos

## Palavras-chave

```text
int
float
char
if
else
while
for
return
main
```

---

## Operadores

```text
+
-
*
/
%
=
==
!=
<
>
<=
>=
```

---

## Delimitadores

```text
;
,
(
)
{
}
```

---

## Identificadores

Variáveis e nomes definidos pelo usuário.

Exemplo:

```c
contador
resultado
valorFinal
```

---

# Fluxo Léxico

```text
Código Fonte
      ↓
Leitura de Caracteres
      ↓
Reconhecimento de Padrões
      ↓
Geração de Tokens
      ↓
Envio ao Parser
```

---

# Ferramenta Utilizada

| Ferramenta | Finalidade |
|---|---|
| Flex | Geração automática do analisador léxico |

---

# Estrutura do Arquivo Léxico

```text
lexer.l
```

O arquivo contém:

- Definições de tokens
- Expressões regulares
- Regras léxicas
- Código auxiliar em C

---

# Exemplo de Funcionamento

## Entrada

```c
int x = 10;
```

## Tokens Gerados

```text
INT
IDENTIFIER(x)
ATRIB
NUMBER(10)
PONTO_VIRGULA
```

---

# Tratamento de Erros Léxicos

O analisador léxico é capaz de identificar caracteres inválidos ou padrões não reconhecidos.

Exemplo:

```text
Erro léxico: caractere inválido '@'
```

---

# Considerações

A implementação léxica foi desenvolvida visando simplicidade, modularidade e facilidade de integração com o analisador sintático.

Além disso, sua estrutura permite expansão futura para suporte a novos tokens e construções da linguagem C.

---

# Histórico de Versões

| Versão | Data | Descrição | Autor(es) |
|:--:|:--:|:--|:--|
| `1.0` | 30/04/2026 | Criação da documentação do módulo léxico | [Arthur Fernandes](https://github.com/arthurfernandesj) |