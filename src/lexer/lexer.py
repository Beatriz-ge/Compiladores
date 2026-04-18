from .tokens import TokenType, Token

class Lexer:
    def __init__(self, source):
        self.source = source
        self.pos = 0
        self.current_char = self.source[self.pos] if source else None

    def advance(self):
        self.pos += 1
        if self.pos < len(self.source):
            self.current_char = self.source[self.pos]
        else:
            self.current_char = None

    def skip_whitespace(self):
        while self.current_char and self.current_char.isspace():
            self.advance()

    def number(self):
        result = ""

        while self.current_char and self.current_char.isdigit():
            result += self.current_char
            self.advance()

        return Token(TokenType.NUMBER, int(result))

    def identifier(self):
        result = ""

        while self.current_char and (
            self.current_char.isalnum() or self.current_char == "_"
        ):
            result += self.current_char
            self.advance()

        if result == "int":
            return Token(TokenType.INT)
        elif result == "return":
            return Token(TokenType.RETURN)

        return Token(TokenType.IDENTIFIER, result)

    def get_next_token(self):
        while self.current_char:

            if self.current_char.isspace():
                self.skip_whitespace()
                continue

            if self.current_char.isdigit():
                return self.number()

            if self.current_char.isalpha() or self.current_char == "_":
                return self.identifier()

            if self.current_char == "=":
                self.advance()
                return Token(TokenType.ASSIGN)

            if self.current_char == ";":
                self.advance()
                return Token(TokenType.SEMICOLON)

            if self.current_char == "(":
                self.advance()
                return Token(TokenType.LPAREN)

            if self.current_char == ")":
                self.advance()
                return Token(TokenType.RPAREN)

            if self.current_char == "{":
                self.advance()
                return Token(TokenType.LBRACE)

            if self.current_char == "}":
                self.advance()
                return Token(TokenType.RBRACE)

            if self.current_char == "+":
                self.advance()
                return Token(TokenType.PLUS)
            if self.current_char == "-":
                self.advance()
                return Token(TokenType.MINUS)
            if self.current_char == "*":
                self.advance()
                return Token(TokenType.MULT)
            if self.current_char == "/":
                self.advance()
                return Token(TokenType.DIV)

            raise Exception(f"Caractere inválido: {self.current_char}")

        return Token(TokenType.EOF)