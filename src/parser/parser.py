from lexer.tokens import TokenType
from ast_nodes.nodes import VarDecl, Return, Block, MainNode


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
            value = self.current_token.value
            self.eat(TokenType.NUMBER)

        self.eat(TokenType.SEMICOLON)

        return VarDecl(var_name, value)

    def parse_return(self):
        self.eat(TokenType.RETURN)

        value = None

        if self.current_token.type == TokenType.NUMBER:
            value = self.current_token.value
            self.eat(TokenType.NUMBER)

        elif self.current_token.type == TokenType.IDENTIFIER:
            value = self.current_token.value
            self.eat(TokenType.IDENTIFIER)

        else:
            raise Exception("Erro: return precisa de um valor válido")

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

    # Procure onde terminam as outras funções e cole esta
    def parse_program(self):
        """ Regra: Programa -> INT MAIN LPAREN RPAREN Bloco """
        self.eat(TokenType.INT)

        if self.current_token.value != 'main':
            raise Exception(f"Erro: Esperado 'main', mas veio '{self.current_token.value}'")
        self.eat(TokenType.IDENTIFIER)

        # Certifique-se que seu Lexer tem esses tokens
        self.eat(TokenType.LPAREN)
        self.eat(TokenType.RPAREN)

        corpo = self.parse_block()
        return MainNode(corpo) # Usando a classe que você criou no passo 1