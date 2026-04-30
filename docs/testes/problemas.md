# Problemas Encontrados

Esta seção apresenta os principais problemas identificados durante o desenvolvimento do compilador, bem como as estratégias adotadas para resolução ou mitigação dessas dificuldades.

O registro desses problemas auxilia na documentação da evolução do projeto e no entendimento das decisões técnicas tomadas pela equipe.

---

# Objetivo

Documentar dificuldades técnicas, limitações e desafios enfrentados ao longo da implementação do compilador.

---

# Problemas Relacionados à Análise Léxica

## Reconhecimento Incorreto de Tokens

Durante a implementação inicial do analisador léxico, ocorreram conflitos entre regras de reconhecimento de identificadores e palavras reservadas.

### Problema

Tokens válidos estavam sendo classificados incorretamente.

### Solução

Foi realizada reorganização das expressões regulares no arquivo do Flex, priorizando palavras reservadas antes das regras genéricas de identificadores.

---

## Tratamento de Espaços e Quebras de Linha

O analisador inicialmente não ignorava corretamente espaços em branco e caracteres de nova linha.

### Problema

Caracteres irrelevantes estavam interferindo na leitura dos tokens.

### Solução

Foram adicionadas regras específicas para ignorar:

```text
Espaços
Tabulações
Quebras de linha
Comentários
```

---

# Problemas Relacionados à Análise Sintática

## Conflitos Shift/Reduce

Durante a construção da gramática no Bison, foram encontrados conflitos relacionados à ambiguidade de regras.

### Problema

O parser apresentava conflitos Shift/Reduce em expressões e estruturas condicionais.

### Solução

Foram definidas regras de precedência e associatividade para operadores.

Exemplo:

```bison
%left SOMA SUB
%left MULT DIV
```

---

## Estruturas Aninhadas

Estruturas condicionais e de repetição aninhadas apresentaram inconsistências durante o parsing.

### Problema

Blocos internos não estavam sendo reconhecidos corretamente.

### Solução

A gramática foi reorganizada em regras recursivas para permitir aninhamento adequado.

---

# Problemas Relacionados à Análise Semântica

## Controle de Escopo

O gerenciamento de escopo apresentou dificuldades durante a validação de variáveis.

### Problema

Variáveis locais e globais não eram diferenciadas corretamente.

### Solução

Foi planejada a utilização de tabela de símbolos para controle de contexto e escopo.

---

## Verificação de Tipos

Inicialmente não havia validação de compatibilidade entre tipos.

### Problema

Atribuições inválidas eram aceitas pelo compilador.

### Solução

Foram adicionadas verificações semânticas para compatibilidade entre variáveis e expressões.

---

# Problemas na Geração de Código

## Conversão de Blocos para Python

A principal dificuldade da geração de código foi adaptar a sintaxe baseada em chaves da linguagem C para a indentação obrigatória do Python.

### Problema

Blocos estavam sendo gerados sem indentação correta.

### Solução

Foi implementado controle de nível de indentação durante a geração do código.

---

## Conversão de Operadores

Alguns operadores e estruturas da linguagem C não possuem equivalência direta em Python.

### Problema

Diferenças sintáticas dificultavam a tradução automática.

### Solução

Foram definidas regras específicas de conversão para operadores e estruturas compatíveis.

---

# Problemas de Integração

## Comunicação entre Flex e Bison

Ocorreram inconsistências entre tokens definidos no Flex e reconhecidos pelo Bison.

### Problema

Tokens retornados pelo analisador léxico não correspondiam às definições do parser.

### Solução

Os arquivos foram padronizados utilizando definições compartilhadas no `parser.tab.h`.

---

# Problemas de Ambiente

## Compatibilidade entre Linux e Windows

A execução do projeto apresentou diferenças de comportamento entre sistemas operacionais.

### Problema

Alguns comandos e scripts funcionavam apenas em Linux.

### Solução

Foram realizadas adaptações para compatibilidade com:

- Ubuntu/Linux
- Windows utilizando MSYS2

---

# Limitações Atuais

A versão atual do compilador ainda apresenta algumas limitações conhecidas:

- Suporte parcial à linguagem C
- Ausência de otimizações
- Tratamento de erros limitado
- Sem geração de AST completa
- Sem suporte a ponteiros e structs

---

# Lições Aprendidas

Durante o desenvolvimento do projeto, foi possível consolidar conhecimentos relacionados a:

- Construção de compiladores
- Flex e Bison
- Gramáticas formais
- Processamento de linguagens
- Modularização de software
- Trabalho colaborativo

---

# Considerações

Os problemas enfrentados ao longo do desenvolvimento contribuíram diretamente para o amadurecimento técnico da equipe e para a evolução da arquitetura do compilador.

A documentação dessas dificuldades também auxilia futuras melhorias e manutenção do projeto.

---

# Histórico de Versões

| Versão | Data | Descrição | Autor(es) |
|:--:|:--:|:--|:--|
| `1.0` | 30/04/2026 | Criação da documentação de problemas encontrados | [Arthur Fernandes](https://github.com/arthurfernandesj) |