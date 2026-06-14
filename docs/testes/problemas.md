# Problemas Encontrados

Esta seção apresenta os principais problemas identificados durante o desenvolvimento do compilador, bem como as estratégias adotadas para resolução ou mitigação dessas dificuldades.

O registro desses problemas auxilia na documentação da evolução do projeto e no entendimento das decisões técnicas tomadas pela equipe durante a construção do compilador C → Python.

---

# Objetivo

Documentar dificuldades técnicas, limitações e desafios enfrentados ao longo da implementação do compilador, incluindo problemas relacionados à análise léxica, análise sintática, análise semântica, geração de código, testes, ambiente e documentação.

---

# Problemas Relacionados à Análise Léxica

## Reconhecimento Incorreto de Tokens

Durante a implementação inicial do analisador léxico, ocorreram conflitos entre regras de reconhecimento de identificadores e palavras reservadas.

### Problema

Algumas palavras reservadas estavam sendo classificadas como identificadores comuns, o que causava falhas na etapa sintática.

### Solução

Foi realizada a reorganização das expressões regulares no arquivo `src/lexer.l`, priorizando o reconhecimento de palavras reservadas antes das regras genéricas de identificadores.

---

## Tratamento de Espaços e Quebras de Linha

O analisador inicialmente precisava lidar corretamente com espaços, tabulações e quebras de linha.

### Problema

Caracteres sem relevância sintática poderiam interferir no reconhecimento dos tokens ou prejudicar o controle de linha para mensagens de erro.

### Solução

Foram adicionadas regras específicas para ignorar caracteres irrelevantes e manter o controle adequado das linhas analisadas.

```text
Espaços
Tabulações
Quebras de linha
```

---

## Reconhecimento de Comentários

Durante a evolução do projeto, surgiu a necessidade de preservar comentários do código C na saída Python.

### Problema

Inicialmente, comentários eram ignorados ou descartados pelo analisador léxico, não sendo preservados no código Python gerado.

### Solução

Foram adicionadas regras para reconhecer comentários de linha com `//` e comentários de bloco com `/* */`, permitindo sua conversão para comentários Python usando `#`.

---

## Operadores de Ponteiro

A implementação de ponteiros exigiu cuidado no léxico, pois símbolos como `*` e `&` podem assumir significados diferentes dependendo do contexto.

### Problema

O operador `*` pode representar multiplicação, declaração de ponteiro ou desreferência. Já o operador `&` pode representar referência de endereço.

### Solução

O léxico passou a reconhecer esses símbolos, deixando a interpretação contextual para o parser e para as validações semânticas.

---

# Problemas Relacionados à Análise Sintática

## Conflitos Shift/Reduce

Durante a construção da gramática no Bison, foram encontrados conflitos relacionados à ambiguidade de regras.

### Problema

O parser apresentava conflitos em expressões aritméticas, expressões relacionais e estruturas condicionais.

### Solução

Foram definidas regras de precedência e associatividade para operadores no arquivo `src/parser.y`.

Exemplo conceitual:

```bison
%left SOMA SUB
%left MULT DIV
```

---

## Integração entre Regras Sintáticas e AST

Com a evolução do projeto, o parser deixou de apenas validar a estrutura do programa e passou também a construir representações internas.

### Problema

Algumas regras sintáticas precisaram ser ajustadas para criar nós da AST corretamente e manter a organização das estruturas reconhecidas.

### Solução

As ações sintáticas foram adaptadas para integrar o reconhecimento das regras com a construção da AST, permitindo representar comandos, expressões, declarações e funções.

---

## Estruturas Condicionais Encadeadas

Estruturas com `if`, `else` e encadeamentos exigiram ajustes na gramática.

### Problema

Blocos condicionais aninhados ou encadeados poderiam gerar ambiguidades ou saídas incorretas.

### Solução

A gramática foi reorganizada para tratar blocos e condicionais de forma mais consistente, permitindo a tradução adequada para Python.

---

## Chamadas de Função

A validação de funções exigiu integração entre parser e tabela de funções.

### Problema

Era necessário diferenciar chamadas de função, declarações de função e uso comum de identificadores.

### Solução

Foram criadas regras específicas para funções e chamadas, com apoio da tabela de funções para validação posterior da quantidade de argumentos.

---

# Problemas Relacionados à Análise Semântica

## Controle de Escopo

O gerenciamento de escopo apresentou dificuldades durante a validação de variáveis.

### Problema

Variáveis locais e globais precisavam ser diferenciadas corretamente para evitar falsos erros ou aceitações indevidas.

### Solução

Foi implementada uma tabela de símbolos capaz de armazenar nome, tipo, escopo e linha de declaração das variáveis.

---

## Variáveis Não Declaradas

Durante os testes semânticos, foi necessário garantir que uma variável só pudesse ser usada após sua declaração.

### Problema

Sem essa verificação, o compilador poderia gerar Python para códigos C semanticamente inválidos.

### Solução

Foram adicionadas verificações semânticas para identificar o uso de variáveis não declaradas.

---

## Redeclaração de Variáveis

Outro problema identificado foi o controle de identificadores declarados mais de uma vez no mesmo escopo.

### Problema

A ausência dessa validação permitia ambiguidade no uso de variáveis.

### Solução

A tabela de símbolos passou a verificar se o identificador já existia no escopo atual antes de permitir uma nova declaração.

---

## Verificação de Tipos

Inicialmente, a validação de compatibilidade entre tipos era limitada.

### Problema

Atribuições e expressões envolvendo tipos diferentes poderiam ser aceitas sem validação adequada.

### Solução

Foram adicionadas verificações semânticas para compatibilidade entre tipos básicos, como `int`, `float`, `double` e `char`.

---

## Validação de Funções

Com a implementação de funções, foi necessário controlar declarações e chamadas.

### Problema

Chamadas com argumentos faltando ou em excesso precisavam ser detectadas.

### Solução

Foi implementada uma tabela de funções para registrar funções declaradas e validar a quantidade de argumentos em cada chamada.

---

# Problemas na Geração de Código

## Conversão de Blocos para Python

A principal dificuldade da geração de código foi adaptar a sintaxe baseada em chaves da linguagem C para a indentação obrigatória do Python.

### Problema

Blocos estavam sendo gerados com indentação incorreta ou inconsistente.

### Solução

Foi implementado um controle de nível de indentação por meio dos arquivos `src/ast/indent_manager.c` e `src/ast/indent_manager.h`.

---

## Remoção de Elementos Sintáticos de C

A linguagem C utiliza elementos que não existem da mesma forma em Python, como ponto e vírgula, chaves e tipos explícitos em declarações.

### Problema

Esses elementos precisavam ser removidos ou adaptados durante a geração.

### Solução

Foram definidas regras de conversão para remover `;`, substituir blocos `{}` por indentação e simplificar declarações de variáveis para atribuições em Python.

---

## Conversão de Declarações sem Inicialização

Declarações como `int x;` não possuem equivalente direto em Python.

### Problema

Python exige que uma variável receba algum valor antes de ser usada.

### Solução

Foi adotada a estratégia de gerar `None` para variáveis declaradas sem valor inicial.

Exemplo:

```c
int x;
```

Saída gerada:

```python
x = None
```

---

## Conversão de Comentários

Comentários em C e Python possuem sintaxes diferentes.

### Problema

Comentários de linha e de bloco precisavam ser convertidos para o padrão Python.

### Solução

Comentários com `//` e `/* */` passaram a ser convertidos para linhas iniciadas com `#`.

---

## Conversão de Ponteiros

Python não possui ponteiros como C.

### Problema

Não há equivalência direta para operações de memória como referência e desreferência.

### Solução

Foi implementado um suporte simplificado a ponteiros, suficiente para representar os casos básicos definidos no subconjunto do projeto, sem tentar reproduzir completamente o modelo de memória da linguagem C.

---

# Problemas de Integração

## Comunicação entre Flex e Bison

Ocorreram inconsistências entre tokens definidos no Flex e tokens esperados pelo Bison.

### Problema

Tokens retornados pelo analisador léxico nem sempre correspondiam às definições utilizadas pelo parser.

### Solução

Os tokens foram padronizados entre `src/lexer.l` e `src/parser.y`, utilizando as definições geradas pelo Bison no arquivo `parser.tab.h`.

---

## Integração entre Parser, Semântica e AST

À medida que o projeto evoluiu, o parser passou a integrar mais responsabilidades.

### Problema

Era necessário manter a coerência entre análise sintática, construção da AST, validações semânticas e geração de código.

### Solução

A arquitetura foi organizada em módulos, distribuindo responsabilidades entre `parser.y`, `semantic.c`, `tabela.c`, `tabela_funcoes.c` e `ast.c`.

---

# Problemas de Testes

## Organização dos Casos de Teste

Com o crescimento das funcionalidades, tornou-se necessário organizar melhor os testes.

### Problema

Testes manuais não eram suficientes para validar regressões e casos de erro.

### Solução

Foi criado e consolidado o script `tests/run_tests.sh`, permitindo executar testes positivos e negativos de forma padronizada.

---

## Testes Positivos e Negativos

Alguns testes deveriam passar quando o compilador aceitasse o código, enquanto outros deveriam passar quando o compilador rejeitasse corretamente o código inválido.

### Problema

Era necessário diferenciar casos válidos e inválidos na suíte de testes.

### Solução

Foi adotada uma convenção de nomes para identificar casos de erro, como arquivos contendo `_erro` ou `_fail`.

---

## Cobertura de Testes

A equipe também precisou validar quais partes do código estavam sendo exercitadas pelos testes.

### Problema

Sem relatório de cobertura, era mais difícil identificar trechos não testados.

### Solução

Foi adicionado suporte à execução com cobertura utilizando ferramentas como `gcov` e `lcov`.

---

# Problemas de Ambiente

## Dependências do Projeto

A execução do projeto depende de ferramentas específicas.

### Problema

Ambientes sem `flex`, `bison`, `gcc`, `make` ou `lcov` apresentavam falhas de compilação ou cobertura.

### Solução

A documentação passou a indicar as dependências necessárias para compilar, testar e gerar cobertura.

Exemplo:

```bash
sudo apt update
sudo apt install gcc make flex bison lcov
```

---

## Compatibilidade entre Sistemas

A execução do projeto foi planejada principalmente para ambiente Linux.

### Problema

Alguns comandos e scripts podem não funcionar da mesma forma em Windows sem ambiente compatível.

### Solução

A recomendação principal passou a ser o uso de Linux, WSL ou ambiente equivalente com suporte às ferramentas utilizadas.

---

# Problemas na Documentação

## Divergência entre Documentação e Código

Durante a evolução do projeto, algumas páginas da documentação ficaram desatualizadas em relação à implementação real.

### Problema

Algumas páginas descreviam estruturas antigas, como pastas `lexer/`, `parser/` e `generator/`, que não correspondiam mais ao projeto atual.

### Solução

A documentação da GitPages foi revisada para refletir a estrutura real do projeto, incluindo arquivos como `src/lexer.l`, `src/parser.y`, `src/semantic.c`, `src/tabela.c`, `src/tabela_funcoes.c` e `src/ast/ast.c`.

---

## Blocos de Código no MkDocs

Durante a atualização da documentação, alguns blocos de código foram renderizados de forma incorreta.

### Problema

O uso de identificadores dentro dos blocos, como ` ```text id="..." `, causava problemas de renderização no MkDocs.

### Solução

Os blocos de código foram padronizados para o formato Markdown comum.

Exemplo correto:

````md
```text
src/
├── lexer.l
├── parser.y
└── main.c
```
````

---

# Limitações Atuais

A versão atual do compilador ainda apresenta algumas limitações conhecidas:

* Suporte parcial à linguagem C;
* Ausência de otimizações avançadas;
* Tratamento de erros ainda limitado;
* Suporte limitado a ponteiros;
* Suporte limitado a entrada e saída;
* Suporte limitado ou inexistente a arrays completos;
* Ausência de suporte a `struct`, `union` e `enum`;
* Ausência de geração de código intermediário;
* Ausência de geração para assembly ou código de máquina;
* Ausência de interface gráfica;
* Suporte apenas a C como entrada e Python como saída.

---

# Lições Aprendidas

Durante o desenvolvimento do projeto, foi possível consolidar conhecimentos relacionados a:

* Construção de compiladores;
* Uso de Flex e Bison;
* Gramáticas formais;
* Processamento de linguagens;
* Integração entre lexer e parser;
* Construção e uso de AST;
* Análise semântica;
* Controle de escopo;
* Tabela de símbolos;
* Tabela de funções;
* Geração de código;
* Testes automatizados;
* Cobertura de testes;
* Modularização de software;
* Trabalho colaborativo com Git e GitHub;
* Documentação técnica com GitHub Pages/MkDocs.

---

# Considerações

Os problemas enfrentados ao longo do desenvolvimento contribuíram diretamente para o amadurecimento técnico da equipe e para a evolução da arquitetura do compilador.

A documentação dessas dificuldades também auxilia futuras melhorias, manutenção do projeto e compreensão das decisões tomadas durante o desenvolvimento.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                                  | Autor(es)                                               |
| :----: | :--------: | :------------------------------------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 30/04/2025 | Criação da documentação de problemas encontrados                           | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.1` | 08/06/2026 | Atualização dos problemas encontrados conforme evolução real do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |
