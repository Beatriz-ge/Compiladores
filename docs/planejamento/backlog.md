# Backlog do Projeto

## Compilador de C para Python

Este backlog apresenta a organização das principais entregas planejadas e desenvolvidas ao longo do projeto. O compilador foi construído de forma incremental, partindo da estrutura inicial do projeto até a integração entre análise léxica, análise sintática, AST, análise semântica, geração de código Python e testes automatizados.

---

# Estrutura das Entregas

<div style="display: flex; justify-content: center; gap: 20px; flex-wrap: wrap;">

<div style="background-color: #0d47a1; padding: 15px; border-radius: 10px; width: 250px; text-align:center;">
<strong> P1 — Fundação</strong><br>
Semanas 1 a 4
</div>

<div style="background-color: #1b5e20; padding: 15px; border-radius: 10px; width: 250px; text-align:center;">
<strong> P2 — Evolução</strong><br>
Semanas 5 a 8
</div>

<div style="background-color: #e65100; padding: 15px; border-radius: 10px; width: 250px; text-align:center;">
<strong> P3 — Consolidação</strong><br>
Semanas 9 em diante
</div>

</div>

---

#  P1 — Fundação

<table>
<tr>
<th>Sprint</th>
<th>Foco</th>
<th>Principais Atividades</th>
<th>Status</th>
</tr>

<tr>
<td>🟦 Sprint 1</td>
<td>Setup e Planejamento</td>
<td>
Definir o subconjunto inicial da linguagem C<br>
Definir a arquitetura geral do compilador<br>
Configurar a estrutura inicial de diretórios<br>
Criar o build inicial com Makefile<br>
Criar README, escopo e documentação inicial<br>
Configurar o repositório e organização da equipe
</td>
<td align="center">✅ Concluída</td>
</tr>

<tr>
<td>🟦 Sprint 2</td>
<td>Análise Léxica</td>
<td>
Implementar o arquivo <code>src/lexer.l</code><br>
Reconhecer palavras reservadas, tipos, identificadores e números<br>
Implementar operadores e delimitadores<br>
Reconhecer literais básicos<br>
Ignorar espaços, tabulações e quebras de linha sem relevância sintática<br>
Integrar o lexer com o parser<br>
Testar o reconhecimento de tokens
</td>
<td align="center">✅ Concluída</td>
</tr>

<tr>
<td>🟦 Sprint 3</td>
<td>Análise Sintática</td>
<td>
Implementar o arquivo <code>src/parser.y</code><br>
Definir a gramática inicial do subconjunto de C<br>
Reconhecer função <code>main</code>, blocos, declarações e comandos básicos<br>
Integrar parser com lexer<br>
Implementar tratamento inicial de erros sintáticos<br>
Validar programas simples em C
</td>
<td align="center">✅ Concluída</td>
</tr>

<tr>
<td>🟦 Sprint 4</td>
<td>AST e Expressões</td>
<td>
Criar estrutura inicial da AST<br>
Representar expressões, comandos e declarações<br>
Implementar operações aritméticas<br>
Definir precedência de operadores<br>
Integrar ações sintáticas com construção de nós<br>
Testar expressões e comandos básicos
</td>
<td align="center">✅ Concluída</td>
</tr>

</table>

---

#  P2 — Evolução

<table>
<tr>
<th>Sprint</th>
<th>Foco</th>
<th>Principais Atividades</th>
<th>Status</th>
</tr>

<tr>
<td>🟩 Sprint 5</td>
<td>Geração de Código</td>
<td>
Implementar geração de código Python<br>
Traduzir declarações e atribuições<br>
Traduzir expressões aritméticas e relacionais<br>
Traduzir comandos de retorno<br>
Gerar arquivo de saída <code>tests/saida.py</code><br>
Validar a equivalência básica entre entrada C e saída Python
</td>
<td align="center">✅ Concluída</td>
</tr>

<tr>
<td>🟩 Sprint 6</td>
<td>Variáveis, Tipos e Tabela de Símbolos</td>
<td>
Implementar suporte a declaração de variáveis<br>
Implementar atribuição e uso de identificadores<br>
Adicionar tipos como <code>int</code>, <code>float</code>, <code>double</code> e <code>char</code><br>
Criar e integrar a tabela de símbolos<br>
Controlar nome, tipo, escopo e linha de declaração<br>
Detectar variáveis não declaradas e redeclarações
</td>
<td align="center">✅ Concluída</td>
</tr>

<tr>
<td>🟩 Sprint 7</td>
<td>Controle de Fluxo e Indentação</td>
<td>
Implementar estruturas condicionais com <code>if</code> e <code>else</code><br>
Adicionar operadores relacionais<br>
Implementar operadores compostos, como <code>+=</code> e <code>-=</code><br>
Criar controle de indentação para Python<br>
Garantir geração correta de blocos indentados<br>
Validar a saída Python gerada
</td>
<td align="center">✅ Concluída</td>
</tr>

<tr>
<td>🟩 Sprint 8</td>
<td>Análise Semântica e Funções</td>
<td>
Implementar regras semânticas adicionais<br>
Validar compatibilidade entre tipos<br>
Controlar escopo local e global<br>
Implementar tabela de funções<br>
Registrar funções declaradas<br>
Validar chamadas de função com quantidade correta de argumentos<br>
Testar funções com e sem argumentos
</td>
<td align="center">✅ Concluída</td>
</tr>

</table>

---

#  P3 — Consolidação

<table>
<tr>
<th>Sprint</th>
<th>Foco</th>
<th>Principais Atividades</th>
<th>Status</th>
</tr>

<tr>
<td>🟧 Sprint 9</td>
<td>Comentários e Entrada/Saída</td>
<td>
Implementar reconhecimento de comentários de linha com <code>//</code><br>
Implementar reconhecimento de comentários de bloco com <code>/* */</code><br>
Converter comentários C para comentários Python<br>
Adicionar suporte básico a <code>printf</code><br>
Adicionar suporte básico a <code>scanf</code><br>
Criar casos de teste para comentários e entrada/saída
</td>
<td align="center">✅ Concluída</td>
</tr>

<tr>
<td>🟧 Sprint 10</td>
<td>Ponteiros</td>
<td>
Adicionar suporte léxico para operadores relacionados a ponteiros<br>
Adicionar regras sintáticas para declaração e uso básico de ponteiros<br>
Tratar referência com <code>&</code><br>
Tratar desreferência básica com <code>*</code><br>
Adaptar geração de código Python de forma simplificada<br>
Criar casos de teste específicos para ponteiros
</td>
<td align="center">✅ Concluída</td>
</tr>

<tr>
<td>🟧 Sprint 11</td>
<td>Testes Automatizados</td>
<td>
Organizar diretório <code>tests/</code><br>
Criar casos de teste positivos e negativos<br>
Implementar script <code>tests/run_tests.sh</code><br>
Validar erros semânticos esperados<br>
Testar funções, tipos, escopo, ponteiros, condicionais e entrada/saída<br>
Padronizar execução da suíte de testes
</td>
<td align="center">✅ Concluída</td>
</tr>

<tr>
<td>🟧 Sprint 12</td>
<td>Finalização e Documentação</td>
<td>
Refatorar documentação da GitPages<br>
Atualizar escopo, objetivos e arquitetura<br>
Atualizar documentação léxica, sintática, semântica e de geração de código<br>
Documentar estrutura real do projeto<br>
Adicionar instruções de execução local<br>
Preparar demonstração final do compilador
</td>
<td align="center">✅ Concluída</td>
</tr>

</table>

---

# Funcionalidades Implementadas

<div style="background-color: #e8f5e9; padding: 15px; border-radius: 10px;">

✔️ Compilador acadêmico funcional
✔️ Tradução de subconjunto de C para Python
✔️ Análise léxica com Flex
✔️ Análise sintática com Bison
✔️ Construção e uso de AST
✔️ Análise semântica integrada
✔️ Tabela de símbolos
✔️ Tabela de funções
✔️ Controle de escopo
✔️ Verificação de tipos
✔️ Detecção de variáveis não declaradas
✔️ Detecção de redeclaração de variáveis
✔️ Validação de chamadas de função
✔️ Geração de código Python
✔️ Controle de indentação em Python
✔️ Suporte a declarações e atribuições
✔️ Suporte a expressões aritméticas e relacionais
✔️ Suporte a estruturas condicionais
✔️ Suporte a funções com e sem argumentos
✔️ Suporte a comentários de linha e bloco
✔️ Conversão de comentários C para Python
✔️ Suporte básico a <code>printf</code> e <code>scanf</code>
✔️ Suporte básico a ponteiros
✔️ Testes automatizados
✔️ Suporte à cobertura de testes

</div>

---

# Fora do Escopo Atual

<div style="background-color: #ffebee; padding: 15px; border-radius: 10px;">

❌ Otimizações avançadas de código
❌ Interface gráfica
❌ Geração de código de máquina ou assembly
❌ Suporte completo à linguagem C
❌ Suporte completo à biblioteca padrão de C
❌ Suporte completo a ponteiros avançados
❌ Suporte completo a arrays, structs, unions e enums
❌ Compilação de múltiplos arquivos de entrada
❌ Suporte a múltiplas linguagens de entrada ou saída

</div>

---

# Resultado Esperado

Ao final do projeto, espera-se obter um compilador acadêmico funcional, capaz de processar arquivos escritos em um subconjunto da linguagem C, validar sua estrutura léxica, sintática e semântica, e gerar código equivalente em Python.

O compilador deve ser capaz de:

* Receber um arquivo `.c` como entrada;
* Reconhecer tokens válidos da linguagem;
* Validar a gramática do programa;
* Executar verificações semânticas;
* Utilizar tabela de símbolos e tabela de funções;
* Gerar código Python equivalente;
* Produzir o arquivo `tests/saida.py`;
* Executar testes automatizados por meio do script `tests/run_tests.sh`.

---

# Execução Esperada

Para compilar o projeto:

```bash
make clean
make
```

Para executar o compilador:

```bash
./bin/compilador tests/teste.c
```

Para executar a suíte de testes:

```bash
bash tests/run_tests.sh
```

Para executar com cobertura:

```bash
make coverage
bash tests/run_tests.sh --coverage
```

---

# Histórico de Versões

| Versão |    Data    | Descrição                                                   | Autor(es)                                               |
| :----: | :--------: | :---------------------------------------------------------- | :------------------------------------------------------ |
|  `1.0` | 07/04/2025 | Criação do documento                                        | [Beatriz Lins](https://github.com/Beatriz-ge)           |
|  `1.1` | 09/04/2025 | Refatoração do texto                                        | [Arthur Fernandes](https://github.com/arthurfernandesj) |
|  `1.2` | 08/06/2026 | Atualização do backlog conforme evolução real do compilador | [Arthur Fernandes](https://github.com/arthurfernandesj) |
