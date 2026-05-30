CC = gcc
LEX = flex
YACC = bison
CFLAGS = -Wall

SRC = src
BUILD = build
BIN = bin

# Adicionado o $(BUILD)/ast.o na lista de dependências
TARGET = $(BIN)/compilador
OBJS = $(BUILD)/lex.yy.o $(BUILD)/parser.tab.o $(BUILD)/main.o $(BUILD)/tabela.o $(BUILD)/ast.o $(BUILD)/semantic.o $(BUILD)/tabela_funcoes.o

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) $^ -o $@ -lfl

# Regra para o Bison
$(BUILD)/parser.tab.c $(BUILD)/parser.tab.h: $(SRC)/parser.y
	@mkdir -p $(BUILD)
	$(YACC) -d -o $(BUILD)/parser.tab.c $(SRC)/parser.y

# Regra para o Flex 
$(BUILD)/lex.yy.c: $(SRC)/lexer.l $(BUILD)/parser.tab.h
	@mkdir -p $(BUILD)
	$(LEX) -o $(BUILD)/lex.yy.c $(SRC)/lexer.l

# Regra genérica para objetos cujos .c estão no BUILD 
$(BUILD)/%.o: $(BUILD)/%.c
	$(CC) $(CFLAGS) -I$(SRC) -I$(SRC)/ast -I$(BUILD) -c $< -o $@

# Regra para compilar o TABELA.C 
$(BUILD)/tabela.o: $(SRC)/tabela.c $(SRC)/tabela.h
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(SRC) -c $(SRC)/tabela.c -o $@

# NOVO: Regra para compilar o AST.C que está dentro da pasta src/ast/
$(BUILD)/ast.o: $(SRC)/ast/ast.c $(SRC)/ast/ast.h
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(SRC) -c $(SRC)/ast/ast.c -o $@

# Regra para o MAIN.C (Adicionado o -I$(SRC)/ast para achar o header da árvore)
$(BUILD)/main.o: $(SRC)/main.c $(BUILD)/parser.tab.h
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(SRC) -I$(SRC)/ast -I$(BUILD) -c $(SRC)/main.c -o $@

$(BUILD)/semantic.o: $(SRC)/semantic.c $(SRC)/semantic.h
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(SRC) -I$(SRC)/ast -c $(SRC)/semantic.c -o $@

$(BUILD)/tabela_funcoes.o: $(SRC)/tabela_funcoes.c $(SRC)/tabela_funcoes.h
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(SRC) -c $(SRC)/tabela_funcoes.c -o $@

clean:
	rm -rf $(BUILD) $(BIN)