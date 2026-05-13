typedef struct Simbolo {
    char *nome;
    char *tipo;      
    int escopo;     
    int linha;       
    struct Simbolo *proximo;
} Simbolo;

void inserir(char *nome, char *tipo, int escopo, int linha);
Simbolo* buscar(char *nome);
void remover_escopo(int escopo);