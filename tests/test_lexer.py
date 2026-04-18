from lexer.lexer import Lexer
from lexer.tokens import TokenType

def test_lexer_multiplication_division():

    code = "* /"
    lexer = Lexer(code)
    
    token_mult = lexer.get_next_token()
    token_div = lexer.get_next_token()
    
    assert token_mult.type == TokenType.MULT
    assert token_div.type == TokenType.DIV

def test_lexer_expression_tokens():
    
    code = "int x = 10 * 2 / 5;"
    lexer = Lexer(code)
    
    tokens = []
    while True:
        tok = lexer.get_next_token()
        tokens.append(tok.type)
        if tok.type == TokenType.EOF:
            break
            
    assert TokenType.MULT in tokens
    assert TokenType.DIV in tokens
    assert TokenType.SEMICOLON in tokens