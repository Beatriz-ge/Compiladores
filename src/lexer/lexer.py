from .tokens import TokenType, Token

class Lexer:
    def __init__(self, source):
        self.source = source
        self.pos = 0

        self.line = 1
        self.column = 1

        self.current_char = self.source[self.pos] if source else None

    # Avança para o próximo caractere, atualizando linha e coluna
    def advance(self):
        if self.current_char == "\n":
            self.line += 1
            self.column = 0
        else:
            self.column += 1

        self.pos += 1

        if self.pos < len(self.source):
            self.current_char = self.source[self.pos]
        else:
            self.current_char = None

    def skip_whitespace(self):
        while self.current_char and self.current_char.isspace():
            self.advance()

    def make_token(self, type, value=None):
        token = Token(type, value, self.line, self.column)

        if hasattr(self, "debug") and self.debug:
            print(f"[TOKEN] {token}")

        return token

    def number(self):
        result = ""

        while self.current_char and self.current_char.isdigit():
            result += self.current_char
            self.advance()

        return Token(TokenType.NUMBER, int(result), self.line, self.column)

    def identifier(self):
        result = ""

        while self.current_char and (
            self.current_char.isalnum() or self.current_char == "_"
        ):
            result += self.current_char
            self.advance()

        if result == "int":
            return Token(TokenType.INT, None, self.line, self.column)
        elif result == "return":
            return Token(TokenType.RETURN, None, self.line, self.column)

        return Token(TokenType.IDENTIFIER, result, self.line, self.column)

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
                return Token(TokenType.ASSIGN, None, self.line, self.column)

            if self.current_char == ";":
                self.advance()
                return Token(TokenType.SEMICOLON, None, self.line, self.column)

            if self.current_char == "(":
                self.advance()
                return Token(TokenType.LPAREN, None, self.line, self.column)

            if self.current_char == ")":
                self.advance()
                return Token(TokenType.RPAREN, None, self.line, self.column)

            if self.current_char == "{":
                self.advance()
                return Token(TokenType.LBRACE, None, self.line, self.column)

            if self.current_char == "}":
                self.advance()
                return Token(TokenType.RBRACE, None, self.line, self.column)

            raise Exception(f"Caractere inválido: {self.current_char}")

        return Token(TokenType.EOF, None, self.line, self.column)