from lexer.lexer import Lexer
from parser.parser import Parser

def main():
    code = """
    int main() {
        int x = 10;
        return x;
    }
    """
    parser = Parser(Lexer(code))
    result = parser.parse_program() 
    print(result)


if __name__ == "__main__":
    main()