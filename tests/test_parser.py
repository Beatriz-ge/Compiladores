from lexer.lexer import Lexer
from parser.parser import Parser
from lexer.tokens import TokenType


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

def test_parse_block():
        code = "{ int x = 5; return x; }"
        parser = Parser(Lexer(code))
        result = parser.parse_block()

        assert len(result.statements) == 2

def test_parse_main_program():
        code = "int main() { return 0; }"
        parser = Parser(Lexer(code))
        result = parser.parse_program()
        
        assert result.body is not None

def test_precedencia_multiplicacao():
    
    code = "int x = 2 + 3 * 4;"
    parser = Parser(Lexer(code))
    result = parser.parse_declaration() 

    expr = result.value
    assert expr.op.type == TokenType.PLUS
    assert expr.right.op.type == TokenType.MULT
    assert expr.right.left == 3
    assert expr.right.right == 4

def test_precedencia_divisao_subtracao():
    
    code = "int y = 10 / 2 - 1;"
    parser = Parser(Lexer(code))
    result = parser.parse_declaration()

    expr = result.value
    assert expr.op.type == TokenType.MINUS
    assert expr.left.op.type == TokenType.DIV

def test_parenteses_prioridade():
    
    code = "int z = (2 + 3) * 4;"
    parser = Parser(Lexer(code))
    result = parser.parse_declaration()

    expr = result.value
   
    assert expr.op.type == TokenType.MULT
    
    assert expr.left.op.type == TokenType.PLUS