# Objetivos do Projeto

Desenvolver um compilador acadêmico capaz de traduzir programas escritos em um subconjunto da linguagem C para código equivalente em Python, aplicando na prática os principais conceitos relacionados à construção de compiladores.

O projeto foi desenvolvido em C, utilizando Flex para a análise léxica e Bison para a análise sintática, com integração entre AST, análise semântica, tabela de símbolos, tabela de funções e geração de código final.

---

# Objetivo Geral

Construir um compilador funcional e modular capaz de executar as principais etapas do processo de compilação, desde a leitura e validação do código-fonte em C até a geração de um arquivo Python equivalente.

O objetivo central é demonstrar, de forma prática, o funcionamento de um compilador acadêmico, contemplando análise léxica, análise sintática, construção de AST, análise semântica, controle de escopo, validação de tipos e geração de código.

---

# Objetivos Específicos

| Categoria              | Objetivo                                                                                                                                                                                      |
| ---------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Análise Léxica         | Implementar um analisador léxico com Flex para reconhecer e classificar tokens da linguagem C, como identificadores, palavras-chave, tipos, operadores, delimitadores, literais e comentários |
| Análise Sintática      | Desenvolver um analisador sintático com Bison para validar a estrutura gramatical dos programas de entrada                                                                                    |
| AST                    | Construir uma árvore sintática abstrata para representar comandos, expressões, declarações, funções e estruturas do programa                                                                  |
| Análise Semântica      | Realizar verificações relacionadas a escopo, tipos, declarações, redeclarações, uso de variáveis e chamadas de função                                                                         |
| Tabela de Símbolos     | Implementar uma tabela para armazenar identificadores, tipos, escopos e linhas de declaração                                                                                                  |
| Tabela de Funções      | Registrar funções declaradas, controlar parâmetros e validar chamadas com quantidade correta de argumentos                                                                                    |
| Geração de Código      | Traduzir estruturas válidas do subconjunto da linguagem C para código equivalente em Python                                                                                                   |
| Controle de Indentação | Garantir a geração correta da indentação dos blocos no código Python produzido                                                                                                                |
| Tratamento de Erros    | Identificar e reportar erros léxicos, sintáticos e semânticos durante o processo de compilação                                                                                                |
| Testes Automatizados   | Validar o funcionamento do compilador por meio de casos de teste positivos e negativos executados por script                                                                                  |
| Cobertura de Testes    | Disponibilizar suporte à análise de cobertura utilizando ferramentas como `gcov` e `lcov`                                                                                                     |

---

# Objetivos Acadêmicos

* Consolidar os conhecimentos teóricos da disciplina de Compiladores;
* Aplicar técnicas de análise e processamento de linguagens formais;
* Desenvolver experiência prática com Flex e Bison;
* Compreender a integração entre lexer, parser, AST, análise semântica e geração de código;
* Exercitar conceitos de arquitetura de software, modularização e organização de código em C;
* Fortalecer habilidades de desenvolvimento colaborativo em equipe;
* Utilizar Git e GitHub para versionamento, revisão e acompanhamento da evolução do projeto;
* Documentar tecnicamente o projeto por meio de GitHub Pages/MkDocs.

---

# Resultados Esperados

Ao final do projeto, espera-se obter:

* Um compilador funcional para um subconjunto controlado da linguagem C;
* Tradução correta de estruturas válidas de C para Python;
* Reconhecimento léxico de tokens, operadores, tipos, literais, comentários e delimitadores;
* Validação sintática baseada em gramática formal;
* Construção de AST para representação interna do programa;
* Verificações semânticas de escopo, tipos, declarações e chamadas de função;
* Tabela de símbolos para controle de variáveis e escopos;
* Tabela de funções para controle de declarações e argumentos;
* Geração de código Python com indentação adequada;
* Suporte a funcionalidades como variáveis, expressões, condicionais, funções, comentários, entrada/saída básica e ponteiros dentro do subconjunto definido;
* Casos de teste automatizados para validação das funcionalidades implementadas;
* Estrutura modular e extensível para evolução futura do compilador;
* Documentação técnica clara, organizada e coerente com a implementação atual.

---

# Funcionalidades Alvo do Compilador

O compilador tem como objetivo oferecer suporte às principais estruturas necessárias para a validação acadêmica do projeto, incluindo:

* Declaração de variáveis;
* Atribuições;
* Tipos básicos como `int`, `float`, `double` e `char`;
* Expressões aritméticas;
* Operadores relacionais;
* Estruturas condicionais com `if` e `else`;
* Função principal `main`;
* Funções com e sem argumentos;
* Chamadas de função;
* Validação da quantidade de argumentos;
* Comentários de linha e de bloco;
* Conversão de comentários C para comentários Python;
* Entrada e saída básica com `printf` e `scanf`;
* Suporte básico a ponteiros;
* Controle de escopo;
* Verificação de erros semânticos;
* Geração de arquivo Python de saída.

---

# Fluxo Esperado do Sistema

```text
Código em C
     ↓
Análise Léxica
     ↓
Análise Sintática
     ↓
Construção da AST
     ↓
Análise Semântica
     ↓
Tabela de Símbolos e Tabela de Funções
     ↓
Geração de Código
     ↓
Código em Python
```

---

# Limitações do Objetivo

O projeto não tem como objetivo implementar um compilador completo para toda a linguagem C. O foco está em um subconjunto controlado, suficiente para demonstrar as etapas clássicas de compilação.

Dessa forma, não fazem parte dos objetivos principais:

* Otimização avançada de código;
* Interface gráfica;
* Compilação para código de máquina ou assembly;
* Suporte completo à biblioteca padrão da linguagem C;
* Suporte completo a múltiplos arquivos de entrada;
* Suporte completo a todos os recursos avançados de ponteiros;
* Suporte a estruturas complexas como `struct`, `union` e `enum`;
* Suporte a múltiplas linguagens de entrada ou saída.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                            | Autor(es)                                               |
| :----: | :--------: | :------------------------------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 07/04/2025 | Criação do documento                                                 | [Beatriz Lins](https://github.com/Beatriz-ge)           |
|  `1.1` | 09/04/2025 | Refatoração do texto e melhorias estruturais                         | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.2` | 08/06/2026 | Atualização dos objetivos conforme implementação atual do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |
