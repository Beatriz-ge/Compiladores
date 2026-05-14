---
name: Feature Request
about: Solicitação de nova funcionalidade para o compilador
title: "[FEATURE] "
labels: enhancement
assignees: ''
---

## Objetivo
Descreva de forma clara o objetivo principal da funcionalidade.

---

## Descrição
Explique detalhadamente o que deve ser implementado.

Inclua:
- comportamento esperado
- impacto no compilador
- integração com lexer/parser/semântica/codegen
- possíveis regras gramaticais
- geração de código esperada

---

## Critérios de Aceitação

- [ ] Implementação concluída no lexer.
- [ ] Implementação concluída no parser.
- [ ] Integração semântica realizada.
- [ ] Geração de código funcionando corretamente.
- [ ] Compilação limpa utilizando `make`.
- [ ] Testes adicionados/atualizados.
- [ ] Suíte de testes executando corretamente.
- [ ] Funcionalidade validada manualmente.

---

## Arquivos Possivelmente Afetados

- `src/lexer.l`
- `src/parser.y`
- `src/tabela.c`
- `src/common.h`
- `tests/`

---

## Resultado Esperado
Descreva o comportamento esperado após a implementação da funcionalidade.

Exemplo:
```text
Entrada C → saída Python equivalente gerada corretamente.