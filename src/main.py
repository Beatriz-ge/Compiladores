from lexer.lexer import Lexer
from parser.parser import Parser

def debug_tokens(code):
    from lexer.lexer import Lexer
    lexer = Lexer(code)
    print("\n" + "="*20)
    print(" DEBUG DE TOKENS")
    print("="*20)
    
    while True:
        token = lexer.get_next_token()
        print(token)
        if token.type.name == 'EOF': # Verifique se o seu fim de arquivo se chama EOF
            break
            
    print("="*20 + "\n")

def main():
    code = """
    int main() {
        int x = 10;
        return x;
    }
    """
    debug_tokens(code)

    parser = Parser(Lexer(code))
    result = parser.parse_program()
    print("AST GERADA:")
    print(result)


if __name__ == "__main__":
    main()