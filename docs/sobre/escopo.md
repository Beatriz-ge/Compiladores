# Escopo do Projeto

Este projeto tem como objetivo o desenvolvimento de um compilador acadêmico capaz de traduzir programas escritos em um subconjunto da linguagem C para código equivalente em Python, contemplando as principais etapas clássicas do processo de compilação.

---

# Visão Geral

O compilador realiza a leitura de códigos-fonte escritos em C e executa as etapas de análise léxica, análise sintática, construção de AST, análise semântica, gerenciamento de tabelas auxiliares e geração de código final em Python.

A implementação foi desenvolvida em C, utilizando Flex para a construção do analisador léxico e Bison para a construção do analisador sintático.

O projeto possui foco educacional, visando aplicar de forma prática os conceitos fundamentais da construção de compiladores, como reconhecimento de tokens, validação gramatical, verificação semântica, controle de escopo, manipulação de tipos e tradução entre linguagens.

---

# Escopo Funcional

<table>
  <thead>
    <tr>
      <th style="text-align:left;">Categoria</th>
      <th style="text-align:left;">Descrição</th>
      <th style="text-align:center;">Status</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td>Análise Léxica</td>
      <td>Reconhecimento de tokens como identificadores, palavras-chave, operadores, delimitadores, literais, tipos, comentários e símbolos especiais</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Análise Sintática</td>
      <td>Validação da estrutura gramatical do programa com base nas regras definidas em Bison</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>AST</td>
      <td>Construção de uma árvore sintática abstrata para representar comandos, expressões, declarações e estruturas do programa</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Análise Semântica</td>
      <td>Verificação de escopo, tipos, declarações, redeclarações, uso correto de variáveis e chamadas de função</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Tabela de Símbolos</td>
      <td>Armazenamento e controle de identificadores, tipos, escopos e linhas de declaração</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Tabela de Funções</td>
      <td>Registro de funções, controle de parâmetros e validação da quantidade de argumentos em chamadas</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Geração de Código</td>
      <td>Conversão de estruturas válidas da linguagem C para código equivalente em Python</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Controle de Indentação</td>
      <td>Geração adequada da indentação necessária para blocos em Python</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Testes Automatizados</td>
      <td>Execução de casos de teste positivos e negativos por meio de script</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Cobertura de Testes</td>
      <td>Suporte à geração de relatório de cobertura utilizando ferramentas como gcov e lcov</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Subconjunto da Linguagem C</td>
      <td>Suporte parcial às estruturas essenciais da linguagem C utilizadas no projeto</td>
      <td align="center">⚠️ Parcial</td>
    </tr>
    <tr>
      <td>Otimização de Código</td>
      <td>Aplicação de técnicas avançadas de otimização no código intermediário ou final</td>
      <td align="center">❌ Não incluído</td>
    </tr>
    <tr>
      <td>Interface Gráfica</td>
      <td>Ambiente visual para interação com o compilador</td>
      <td align="center">❌ Não incluído</td>
    </tr>
    <tr>
      <td>Múltiplas Linguagens</td>
      <td>Suporte a linguagens além de C como entrada ou além de Python como saída</td>
      <td align="center">❌ Não incluído</td>
    </tr>
    <tr>
      <td>Tratamento Avançado de Erros</td>
      <td>Recuperação automática de erros, sugestões de correção e mensagens detalhadas de diagnóstico</td>
      <td align="center">❌ Não incluído</td>
    </tr>
  </tbody>
</table>

---

# Subconjunto da Linguagem C

O compilador possui suporte apenas a um subconjunto controlado da linguagem C, incluindo estruturas fundamentais para validação acadêmica do projeto.

Entre os principais elementos suportados estão:

* Declaração de variáveis;
* Atribuição de valores;
* Tipos básicos como `int`, `float`, `double` e `char`;
* Expressões aritméticas;
* Operadores relacionais;
* Estruturas condicionais com `if` e `else`;
* Função principal `main`;
* Funções com e sem argumentos;
* Chamadas de função;
* Validação da quantidade de argumentos em chamadas de função;
* Controle de escopo local e global;
* Verificação de variáveis não declaradas;
* Verificação de redeclaração de variáveis;
* Verificação de compatibilidade de tipos;
* Comentários de linha com `//`;
* Comentários de bloco com `/* */`;
* Conversão de comentários C para comentários Python;
* Entrada e saída básica com `printf` e `scanf`;
* Suporte básico a ponteiros;
* Expressões simples;
* Geração de código Python equivalente.

Elementos avançados da linguagem C podem não ser suportados nesta versão do compilador, pois o objetivo do projeto é trabalhar com um subconjunto controlado da linguagem.

---

# Funcionalidades Não Contempladas

O projeto não possui como objetivo implementar todos os recursos da linguagem C. Portanto, algumas funcionalidades ficam fora do escopo atual, como:

* Otimizações avançadas de código;
* Interface gráfica;
* Suporte completo à biblioteca padrão da linguagem C;
* Suporte completo a múltiplos arquivos de entrada;
* Suporte a múltiplas linguagens de entrada ou saída;
* Tratamento avançado e recuperação automática de erros;
* Suporte completo a todos os recursos de ponteiros da linguagem C;
* Suporte completo a estruturas complexas como `struct`, `union` e `enum`;
* Compilação para código de máquina ou assembly.

---

# Linguagens Envolvidas

| Tipo          | Linguagem                                              |
| ------------- | ------------------------------------------------------ |
| Entrada       | C, considerando um subconjunto controlado da linguagem |
| Implementação | C                                                      |
| Saída         | Python                                                 |

---

# Tecnologias Utilizadas

| Tecnologia          | Finalidade                                         |
| ------------------- | -------------------------------------------------- |
| C                   | Linguagem principal de implementação do compilador |
| Flex                | Construção do analisador léxico                    |
| Bison               | Construção do analisador sintático                 |
| Make                | Automação do processo de compilação                |
| Python              | Linguagem de saída gerada pelo compilador          |
| Bash                | Execução dos scripts de teste                      |
| gcov/lcov           | Geração de relatório de cobertura de testes        |
| Git/GitHub          | Versionamento e colaboração                        |
| GitHub Pages/MkDocs | Publicação da documentação do projeto              |

---

# Fluxo Geral do Compilador

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

# Contexto de Uso

Este projeto foi desenvolvido para fins acadêmicos na disciplina de Compiladores, com foco na aplicação prática dos conceitos relacionados à construção de compiladores e tradutores de linguagem.

O compilador não tem como objetivo substituir ferramentas profissionais de compilação, mas sim demonstrar, de forma modular e funcional, como as etapas clássicas de um compilador podem ser implementadas e integradas.

---

# Considerações Finais

O escopo foi definido considerando o equilíbrio entre profundidade técnica, viabilidade de implementação e tempo disponível para desenvolvimento.

A proposta final contempla um compilador funcional e modular, capaz de reconhecer um subconjunto da linguagem C, realizar validações léxicas, sintáticas e semânticas, manter tabelas auxiliares e gerar código Python equivalente.

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                        | Autor(es)                                               |
| :----: | :--------: | :--------------------------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 07/04/2025 | Criação do documento                                             | [Beatriz Lins](https://github.com/Beatriz-ge)           |
|  `1.1` | 09/04/2025 | Refatoração do texto e melhorias estruturais                     | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.2` | 08/06/2026 | Atualização do escopo conforme implementação atual do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |
