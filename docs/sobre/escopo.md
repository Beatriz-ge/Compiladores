# Escopo do Projeto

Este projeto tem como objetivo o desenvolvimento de um compilador acadêmico capaz de traduzir programas escritos em um subconjunto da linguagem C para a linguagem Python, contemplando as principais etapas clássicas do processo de compilação.

---

# Visão Geral

O compilador realiza a leitura de códigos-fonte escritos em C, executando análises léxica, sintática e semântica para validar a estrutura do programa e gerar um código equivalente em Python.

O projeto possui foco educacional, visando aplicar de forma prática os conceitos fundamentais da construção de compiladores.

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
      <td>Reconhecimento de tokens como identificadores, palavras-chave, operadores e literais</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Análise Sintática</td>
      <td>Validação da estrutura gramatical do programa com base em regras definidas em Bison</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Análise Semântica</td>
      <td>Verificação de tipos, escopo, declarações e uso correto de variáveis</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Geração de Código</td>
      <td>Conversão de estruturas válidas da linguagem C para código equivalente em Python</td>
      <td align="center">✅ Incluído</td>
    </tr>
    <tr>
      <td>Subconjunto da Linguagem C</td>
      <td>Suporte parcial às estruturas essenciais da linguagem C utilizadas no projeto</td>
      <td align="center">⚠️ Parcial</td>
    </tr>
    <tr>
      <td>Otimização de Código</td>
      <td>Aplicação de técnicas de otimização no código intermediário ou final</td>
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
      <td>Recuperação automática de erros e mensagens detalhadas de diagnóstico</td>
      <td align="center">❌ Não incluído</td>
    </tr>
  </tbody>
</table>

---

# Subconjunto da Linguagem C

O compilador possui suporte apenas a um subconjunto controlado da linguagem C, incluindo estruturas fundamentais para validação acadêmica do projeto.

Entre os principais elementos suportados estão:

- Declaração de variáveis
- Operações aritméticas
- Operadores relacionais
- Estruturas condicionais
- Estruturas de repetição
- Função principal `main`
- Expressões simples

Elementos avançados da linguagem C podem não ser suportados nesta versão do compilador.

---

# Linguagens Envolvidas

| Tipo | Linguagem |
|------|------------|
| Entrada | C (subconjunto) |
| Saída | Python |

---

# Fluxo Geral do Compilador

```text
Código em C
     ↓
Análise Léxica
     ↓
Análise Sintática
     ↓
Análise Semântica
     ↓
Geração de Código
     ↓
Código em Python
```

---

# Contexto de Uso

Este projeto foi desenvolvido para fins acadêmicos na disciplina de Compiladores, com foco na aplicação prática de conceitos relacionados à construção de compiladores e tradutores de linguagem.

---

# Considerações Finais

O escopo foi definido considerando o equilíbrio entre profundidade técnica, viabilidade de implementação e tempo disponível para desenvolvimento, permitindo a construção de um compilador funcional e modular.

---

# Histórico de Versões

| Versão | Data | Descrição | Autor(es) |
|:--:|:--:|:--|:--|
| `1.0` | 07/04/2025 | Criação do documento | [Beatriz Lins](https://github.com/Beatriz-ge) |
| `1.1` | 09/04/2025 | Refatoração do texto e melhorias estruturais | [Arthur Fernandes](https://github.com/arthurfernandesj) |