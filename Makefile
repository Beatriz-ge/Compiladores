CC = gcc
LEX = flex
YACC = bison
CFLAGS = -Wall

SRC = src
BUILD = build
BIN = bin

# Adicionamos o tabela.o aqui na lista de objetos
TARGET = $(BIN)/compilador
OBJS = $(BUILD)/lex.yy.o $(BUILD)/parser.tab.o $(BUILD)/main.o $(BUILD)/tabela.o

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
	$(CC) $(CFLAGS) -I$(SRC) -I$(BUILD) -c $< -o $@

# Regra para compilar o TABELA.C 
$(BUILD)/tabela.o: $(SRC)/tabela.c $(SRC)/tabela.h
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(SRC) -c $(SRC)/tabela.c -o $@

# Regra para o MAIN.C 
$(BUILD)/main.o: $(SRC)/main.c $(BUILD)/parser.tab.h
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(SRC) -I$(BUILD) -c $(SRC)/main.c -o $@

clean:
	rm -rf $(BUILD) $(BIN)