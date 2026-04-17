from lexer.lexer import Lexer
from parser.parser import Parser


def test_var_decl():
    code = "int x = 5;"
    parser = Parser(Lexer(code))

    result = parser.parse_declaration()

    assert result.name == "x"
    assert result.value == 5


def test_return_number():
    code = "return 10;"
    parser = Parser(Lexer(code))

    result = parser.parse_return()

    assert result.value == 10


def test_return_identifier():
    code = "return y;"
    parser = Parser(Lexer(code))

    result = parser.parse_return()

    assert result.value == "y"

def test_parse_block(self):
        code = "{ int x = 5; return x; }"
        parser = Parser(Lexer(code))
        result = parser.parse_block()
        # Valida se o bloco foi criado e tem 2 comandos
        self.assertEqual(len(result.statements), 2)

def test_parse_main_program(self):
        code = "int main() { return 0; }"
        parser = Parser(Lexer(code))
        result = parser.parse_program()
        # Valida se a Main foi reconhecida e tem um corpo (Block)
        self.assertIsNotNone(result.body)