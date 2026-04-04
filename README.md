# Compiladores - Equipe 11: 

# Sobre

Desenvolvimento de um compilador de C para python como parte da disciplina de Compiladores, na Faculdade de Ciência, Tecnologia e Engenharia (FCTE) da Universidade de Brasília (UnB) pelo grupo 11.

Utilizamos o repositório para compor nosso projeto final bem como as atividades realizadas na disciplina semanalmente.

## Visão Geral

Este projeto implementa um compilador para um subconjunto da linguagem C, com os seguintes recursos:

- **Linguagem de entrada**: Código C com suporte a `int`, `if`, `else`, `while` , `comparacoes` , `operadores aritmeticos` , `operadores logicos ` , `print` , `atribuição` , `declaração de variaveis` , `array` , `return`.
- **Backend**: Python 3 com a biblioteca [PLY (Python Lex-Yacc)](http://www.dabeaz.com/ply/).
- **Pipeline completo**: Análise léxica, análise sintática (AST) e interpretação.
- **Objetivo**: Compreensão prática de compiladores e linguagens formais.

## Instalação e Execução

### Requisitos

- Navegue até a pasta interpretadorPython
- Python 3.8 ou superior
- PLY 

### Instalando dependências

```bash
pip install -r requirements.txt
```

### Para Rodar o Projeto

```bash
python main.py testes.c
```
### Para Rodar nossa suíte de testes

```bash
python -m unittest test_interpreter.py
```
Obs.: Pode haver a quebra de algum teste casa o return não esteja de acordo com a saída planejada, nesse caso deve-se ajustar a saída do teste

<!--

- Montar os tópicos com a equipe de deploy e testes 

# Instruções para iniciar o site localmente (em ambientes X)

### Dependências

- Node.js v20.13.1
- NPM (Node Package Manager)
- PostgreSQL
- Ruby
- Rails
- Docker

-->

## Membros da Equipe 


| [![](https://avatars.githubusercontent.com/u/90862900?v=4)](https://github.com/arthurfernandesj) | [![](https://avatars.githubusercontent.com/u/129804255?v=4)](https://github.com/Beatriz-ge) | [![](https://avatars.githubusercontent.com/u/165945167?v=4)](https://github.com/BeatrizSants) | [![](https://avatars.githubusercontent.com/u/164348330?v=4)](https://github.com/dudaa28) | [![](https://avatars.githubusercontent.com/u/185298426?v=4)](https://github.com/isabellachoukaira) |
|:-:|:-:|:-:|:-:|:-:|
| [Arthur Fernandes](https://github.com/arthurfernandesj) | [Beatriz Lins](https://github.com/Beatriz-ge) | [Beatriz Santos](https://github.com/BeatrizSants) | [Maria Eduarda](https://github.com/dudaa28) | [Isabella Choukaira](https://github.com/isabellachoukaira) |
