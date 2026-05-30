CC = gcc
LEX = flex
YACC = bison
CFLAGS = -Wall
SRC = src
BUILD = build
BIN = bin

TARGET = $(BIN)/compilador

OBJS = \
	$(BUILD)/lex.yy.o \
	$(BUILD)/parser.tab.o \
	$(BUILD)/main.o \
	$(BUILD)/tabela.o \
	$(BUILD)/ast.o \
	$(BUILD)/indent_manager.o \
	$(BUILD)/semantic.o \
	$(BUILD)/tabela_funcoes.o

COVERAGE_FLAGS = --coverage -fprofile-arcs -ftest-coverage -O0

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BIN)
	$(CC) $(CFLAGS) $^ -o $@ -lfl

coverage: CFLAGS += $(COVERAGE_FLAGS)
coverage: clean $(TARGET)
	@echo ""
	@echo "Compilador instrumentado para coverage. Rode:"
	@echo "  bash tests/run_tests.sh --coverage"

report:
	@echo ""
	@mkdir -p coverage_report
	@lcov --capture \
	      --directory $(BUILD) \
	      --output-file coverage_report/coverage.info \
	      --ignore-errors mismatch \
	      2>/dev/null; true
	@lcov --remove coverage_report/coverage.info \
	      '/usr/*' '*/build/lex.yy.c' '*/build/parser.tab.c' \
	      --output-file coverage_report/coverage_filtered.info \
	      2>/dev/null; true
	@echo "=================================================="
	@echo "       COBERTURA DE LINHAS (gcov)"
	@echo "=================================================="
	@lcov --summary coverage_report/coverage_filtered.info 2>&1 \
	    | grep -E "lines|functions" \
	    | awk '{ printf "  %-12s %s\n", $$1, $$2 }'; true
	@echo "=================================================="

clean-coverage:
	@find $(BUILD) -name "*.gcda" -delete
	@find $(BUILD) -name "*.gcno" -delete
	@rm -rf coverage_report
	@echo "Arquivos de coverage removidos."

$(BUILD)/parser.tab.c $(BUILD)/parser.tab.h: $(SRC)/parser.y
	@mkdir -p $(BUILD)
	$(YACC) -d -o $(BUILD)/parser.tab.c $(SRC)/parser.y

$(BUILD)/lex.yy.c: $(SRC)/lexer.l $(BUILD)/parser.tab.h
	@mkdir -p $(BUILD)
	$(LEX) -o $(BUILD)/lex.yy.c $(SRC)/lexer.l

$(BUILD)/%.o: $(BUILD)/%.c
	$(CC) $(CFLAGS) -I$(SRC) -I$(SRC)/ast -I$(BUILD) -c $< -o $@

$(BUILD)/tabela.o: $(SRC)/tabela.c $(SRC)/tabela.h
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(SRC) -c $(SRC)/tabela.c -o $@

$(BUILD)/ast.o: $(SRC)/ast/ast.c $(SRC)/ast/ast.h
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(SRC) -I$(SRC)/ast -c $(SRC)/ast/ast.c -o $@

$(BUILD)/indent_manager.o: $(SRC)/ast/indent_manager.c $(SRC)/ast/indent_manager.h
	@mkdir -p $(BUILD)
	$(CC) $(CFLAGS) -I$(SRC) -I$(SRC)/ast -c $(SRC)/ast/indent_manager.c -o $@

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