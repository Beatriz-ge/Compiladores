# Planejamento das Sprints

## Compilador de C para Python

---

# Visão Geral

Este documento descreve o planejamento das sprints semanais do projeto, seguindo uma abordagem ágil baseada em Scrum.

O projeto foi organizado em 11 sprints, com entregas incrementais voltadas ao desenvolvimento de um compilador acadêmico capaz de traduzir programas escritos em um subconjunto da linguagem C para código equivalente em Python.

Cada sprint possui duração aproximada de 1 semana e contempla tarefas organizadas por categorias:

* Desenvolvimento;
* Testes;
* Documentação;
* Infraestrutura;
* Validação.

---

# Organização Geral

As sprints foram divididas em três grandes fases:

| Fase              | Sprints | Objetivo                                                                                                            |
| ----------------- | ------: | ------------------------------------------------------------------------------------------------------------------- |
| P1 — Fundação     |   1 a 4 | Estruturar o projeto, definir o subconjunto da linguagem, implementar lexer, parser, AST e expressões básicas       |
| P2 — Evolução     |   5 a 8 | Implementar geração de código, variáveis, tipos, tabela de símbolos, controle de fluxo, semântica e funções         |
| P3 — Consolidação |  9 a 11 | Consolidar funcionalidades, adicionar comentários, entrada/saída, ponteiros, testes, cobertura e documentação final |

---

# Planejamento por Sprint

## Sprint 1 — Setup e Planejamento

| Categoria       | Atividades                                                                       |
| --------------- | -------------------------------------------------------------------------------- |
| Desenvolvimento | Definir o subconjunto inicial da linguagem C e a arquitetura geral do compilador |
| Infraestrutura  | Configurar estrutura inicial do repositório, diretórios e Makefile               |
| Documentação    | Criar README, escopo inicial e documentação base                                 |
| Validação       | Validar ambiente de desenvolvimento e compilação inicial                         |

---

## Sprint 2 — Análise Léxica

| Categoria       | Atividades                                                                                  |
| --------------- | ------------------------------------------------------------------------------------------- |
| Desenvolvimento | Implementar o analisador léxico em `src/lexer.l` utilizando Flex                            |
| Desenvolvimento | Reconhecer palavras reservadas, tipos, identificadores, números, operadores e delimitadores |
| Testes          | Criar testes iniciais para reconhecimento de tokens                                         |
| Validação       | Verificar integração inicial entre lexer e parser                                           |

---

## Sprint 3 — Análise Sintática

| Categoria       | Atividades                                                                            |
| --------------- | ------------------------------------------------------------------------------------- |
| Desenvolvimento | Implementar o analisador sintático em `src/parser.y` utilizando Bison                 |
| Desenvolvimento | Definir regras gramaticais para função `main`, blocos, declarações e comandos básicos |
| Testes          | Validar programas simples em C                                                        |
| Validação       | Testar erros sintáticos e integração com o lexer                                      |

---

## Sprint 4 — AST e Expressões

| Categoria       | Atividades                                                             |
| --------------- | ---------------------------------------------------------------------- |
| Desenvolvimento | Criar estrutura inicial da AST                                         |
| Desenvolvimento | Representar expressões, comandos e declarações                         |
| Desenvolvimento | Implementar operações aritméticas e precedência de operadores          |
| Testes          | Validar expressões aritméticas e comandos básicos                      |
| Validação       | Verificar se as estruturas reconhecidas são representadas corretamente |

---

## Sprint 5 — Geração de Código

| Categoria       | Atividades                                                                |
| --------------- | ------------------------------------------------------------------------- |
| Desenvolvimento | Implementar geração de código Python a partir das estruturas reconhecidas |
| Desenvolvimento | Traduzir declarações, atribuições, expressões e comandos de retorno       |
| Desenvolvimento | Gerar arquivo de saída `tests/saida.py`                                   |
| Testes          | Comparar entrada em C com saída Python gerada                             |
| Validação       | Verificar se o código Python gerado mantém a lógica do programa original  |

---

## Sprint 6 — Variáveis, Tipos e Tabela de Símbolos

| Categoria       | Atividades                                                                  |
| --------------- | --------------------------------------------------------------------------- |
| Desenvolvimento | Implementar suporte a declaração e uso de variáveis                         |
| Desenvolvimento | Adicionar tipos como `int`, `float`, `double` e `char`                      |
| Desenvolvimento | Criar e integrar tabela de símbolos                                         |
| Desenvolvimento | Controlar nome, tipo, escopo e linha de declaração                          |
| Testes          | Criar testes para variáveis declaradas, não declaradas e redeclarações      |
| Validação       | Verificar consistência entre parser, tabela de símbolos e geração de código |

---

## Sprint 7 — Controle de Fluxo e Indentação

| Categoria       | Atividades                                                         |
| --------------- | ------------------------------------------------------------------ |
| Desenvolvimento | Implementar estruturas condicionais com `if` e `else`              |
| Desenvolvimento | Adicionar operadores relacionais                                   |
| Desenvolvimento | Implementar operadores compostos como `+=` e `-=`                  |
| Desenvolvimento | Criar controle de indentação para a saída Python                   |
| Testes          | Validar geração de blocos condicionais em Python                   |
| Validação       | Verificar se a indentação gerada é compatível com a sintaxe Python |

---

## Sprint 8 — Análise Semântica e Funções

| Categoria       | Atividades                                                                |
| --------------- | ------------------------------------------------------------------------- |
| Desenvolvimento | Implementar validações semânticas adicionais                              |
| Desenvolvimento | Controlar escopo local e global                                           |
| Desenvolvimento | Validar compatibilidade entre tipos                                       |
| Desenvolvimento | Criar tabela de funções                                                   |
| Desenvolvimento | Registrar funções e validar chamadas com quantidade correta de argumentos |
| Testes          | Criar testes para funções com argumentos corretos, faltando e em excesso  |
| Validação       | Confirmar rejeição de programas semanticamente inválidos                  |

---

## Sprint 9 — Comentários e Entrada/Saída

| Categoria       | Atividades                                                                       |
| --------------- | -------------------------------------------------------------------------------- |
| Desenvolvimento | Implementar reconhecimento de comentários de linha com `//`                      |
| Desenvolvimento | Implementar reconhecimento de comentários de bloco com `/* */`                   |
| Desenvolvimento | Converter comentários C para comentários Python                                  |
| Desenvolvimento | Adicionar suporte básico a `printf` e `scanf`                                    |
| Testes          | Criar testes para comentários, `printf` e `scanf`                                |
| Validação       | Verificar se comentários e comandos de entrada/saída são traduzidos corretamente |

---

## Sprint 10 — Ponteiros e Ajustes Semânticos

| Categoria       | Atividades                                                                        |
| --------------- | --------------------------------------------------------------------------------- |
| Desenvolvimento | Adicionar suporte léxico para operadores relacionados a ponteiros                 |
| Desenvolvimento | Adicionar regras sintáticas para declaração e uso básico de ponteiros             |
| Desenvolvimento | Tratar referência com `&` e desreferência básica com `*`                          |
| Desenvolvimento | Adaptar geração de código Python de forma simplificada                            |
| Testes          | Criar casos de teste específicos para ponteiros                                   |
| Validação       | Verificar se o suporte a ponteiros respeita as limitações do subconjunto definido |

---

## Sprint 11 — Testes, Cobertura e Documentação

| Categoria    | Atividades                                                                           |
| ------------ | ------------------------------------------------------------------------------------ |
| Testes       | Organizar diretório `tests/` e consolidar casos positivos e negativos                |
| Testes       | Implementar e validar o script `tests/run_tests.sh`                                  |
| Testes       | Validar funções, tipos, escopo, ponteiros, condicionais, comentários e entrada/saída |
| Testes       | Adicionar suporte à execução com cobertura                                           |
| Documentação | Atualizar documentação da GitPages                                                   |
| Documentação | Revisar escopo, objetivos, arquitetura, testes, estrutura e demo                     |
| Validação    | Preparar demonstração final do compilador                                            |

---

# Protótipo Visual — Figma

Para visualizar o planejamento de forma mais interativa e visual:

**Acesse o board no Figma:**

<iframe style="border: 1px solid rgba(0, 0, 0, 0.1);" width="800" height="450" src="https://embed.figma.com/board/WV0Vbxww4bzvufeUuGunbV/ROADMAP-COMPILADORES?node-id=0-1&embed-host=share" allowfullscreen></iframe>

---

# Resultado Esperado

Ao final das sprints, o projeto deverá entregar um compilador acadêmico funcional, capaz de processar arquivos escritos em um subconjunto da linguagem C e gerar código equivalente em Python.

Resultados esperados:

* Implementar um compilador funcional C → Python;
* Realizar análise léxica com Flex;
* Realizar análise sintática com Bison;
* Construir e utilizar AST;
* Executar análise semântica;
* Controlar tabela de símbolos e tabela de funções;
* Suportar variáveis, tipos, expressões, condicionais e funções;
* Suportar comentários, entrada/saída básica e ponteiros de forma limitada;
* Gerar código Python com indentação adequada;
* Executar testes automatizados;
* Disponibilizar documentação atualizada na GitPages.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                                                | Autor(es)                                               |
| :----: | :--------: | :--------------------------------------------------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 07/04/2025 | Criação do documento                                                                     | [Beatriz Lins](https://github.com/Beatriz-ge)           |
|  `1.1` | 09/04/2025 | Refatoração do texto                                                                     | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.2` | 08/06/2026 | Atualização do planejamento conforme roadmap de 11 sprints e evolução real do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |
