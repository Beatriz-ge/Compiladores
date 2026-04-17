from lexer.tokens import TokenType
from ast_nodes.nodes import VarDecl, Return, Block, BinOp


class Parser:
    def __init__(self, lexer):
        self.lexer = lexer
        self.current_token = self.lexer.get_next_token()

    def eat(self, token_type):
        if self.current_token.type == token_type:
            self.current_token = self.lexer.get_next_token()
        else:
            raise Exception(
                f"Erro: esperado {token_type}, recebeu {self.current_token.type}"
            )

    def parse_declaration(self):
        self.eat(TokenType.INT)

        var_name = self.current_token.value
        self.eat(TokenType.IDENTIFIER)

        value = None

        if self.current_token.type == TokenType.ASSIGN:
            self.eat(TokenType.ASSIGN)
            value = self.parse_expression()

        self.eat(TokenType.SEMICOLON)

        return VarDecl(var_name, value)

    def parse_return(self):
        self.eat(TokenType.RETURN)

        value = self.parse_expression()

        self.eat(TokenType.SEMICOLON)

        return Return(value)

    def parse_block(self):
        self.eat(TokenType.LBRACE)

        statements = []

        while self.current_token.type != TokenType.RBRACE:
            if self.current_token.type == TokenType.INT:
                statements.append(self.parse_declaration())

            elif self.current_token.type == TokenType.RETURN:
                statements.append(self.parse_return())

            else:
                raise Exception(f"Token inesperado: {self.current_token}")

        self.eat(TokenType.RBRACE)

        return Block(statements)
    
    def parse_expression(self):
        left = self.parse_term()

        while self.current_token.type == TokenType.PLUS:
            op = self.current_token
            self.eat(TokenType.PLUS)
            right = self.parse_term()
            left = BinOp(left, op, right)

        return left
    
    def parse_term(self):
        token = self.current_token

        if token.type == TokenType.NUMBER:
            self.eat(TokenType.NUMBER)
            return token.value

        elif token.type == TokenType.IDENTIFIER:
            self.eat(TokenType.IDENTIFIER)
            return token.value

        else:
            raise Exception(f"Token inesperado: {token}")