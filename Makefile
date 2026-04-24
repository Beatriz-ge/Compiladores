CC = gcc
LEX = flex
YACC = bison
CFLAGS = -Wall

SRC = src
BUILD = build
BIN = bin

TARGET = $(BIN)/compilador

all: $(TARGET)

$(TARGET): $(BUILD)/lex.yy.o $(BUILD)/parser.tab.o $(BUILD)/main.o
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) $^ -o $@ -lfl

$(BUILD)/parser.tab.c $(BUILD)/parser.tab.h: $(SRC)/parser.y
	@mkdir -p $(BUILD)
	$(YACC) -d -o $(BUILD)/parser.tab.c $(SRC)/parser.y

$(BUILD)/lex.yy.c: $(SRC)/lexer.l $(BUILD)/parser.tab.h
	@mkdir -p $(BUILD)
	$(LEX) -o $(BUILD)/lex.yy.c $(SRC)/lexer.l

$(BUILD)/%.o: $(BUILD)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD)/main.o: $(SRC)/main.c
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(BUILD) -c $(SRC)/main.c -o $@

clean:
	rm -rf $(BUILD) $(BIN)