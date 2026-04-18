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

    PLUS = auto()
    MINUS = auto()
    MULT = auto()
    DIV = auto()


class Token:
    def __init__(self, type, value=None):
        self.type = type
        self.value = value

    def __repr__(self):
        return f"{self.type.name}({self.value})"