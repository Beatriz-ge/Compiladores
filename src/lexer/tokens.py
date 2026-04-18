from enum import Enum, auto

class TokenType(Enum):
    INT = auto()
    RETURN = auto()

    IDENTIFIER = auto()
    NUMBER = auto()

    ASSIGN = auto()
    SEMICOLON = auto()

    LPAREN = auto()
    RPAREN = auto()   
    LBRACE = auto()
    RBRACE = auto() 

    EOF = auto()


class Token:
    def __init__(self, type, value=None, line=None, column=None):
        self.type = type
        self.value = value
        self.line = line
        self.column = column

    def __repr__(self):
        return f"[{self.line}:{self.column}] {self.type.name}" + \
               (f"({self.value})" if self.value is not None else "")