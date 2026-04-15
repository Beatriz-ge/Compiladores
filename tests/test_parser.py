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