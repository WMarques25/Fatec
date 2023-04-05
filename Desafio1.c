#include<stdio.h>
#include<locale.h>
#include<ctype.h>

// Vetores
char livro1[20];
char livro2[20];
char livro3[20];
char autor1[20];
char autor2[20];
char autor3[20];

// Funções do Menu
void Entrada(){
    printf("Entre com o nome do primeiro livro:");
    gets(livro1);

    printf("Entre com o nome do autor:");
    gets(autor1);

    printf("Entre com o nome do segundo livro:");
    gets(livro2);

    printf("Entre com o nome do autor:");
    gets(autor2);

    printf("Entre com o nome do terceiro livro:");
    gets(livro3);

    printf("Entre com o nome do autor:");
    gets(autor3);
}

void Listar(){}

void PesquisaLivro(){}

void PesquisaAutor(){}

void AlteraDados(){}

void ExcluirDados(){}

char Sair(){
    return 
}

int main(void){

    char c = 'a';
    int op;
    setlocale(LC_ALL, "");

    do{
        system("cls");
        
        // print menu
        printf(" * - Biblioteca - *\n\n");
        printf(" 1 - Entrar com os livros.\n");
        printf(" 2 - Listar os livros.\n");
        printf(" 3 - Pesquisar por livro.\n");
        printf(" 4 - Pesquisar por autor.\n");
        printf(" 5 - Alterar livro.\n");
        printf(" 6 - Excluir livro.\n");
        printf(" 7 - Sair.\n\n");
        printf("Insira a opção desejada: ");
        scanf(" %d", &op);
        getchar();

        // switch case
        switch(op){
            case 1:
                Entrada();
                break;
            
            case 2:
                Listar();
                break;
            
            case 3:
                PesquisaLivro();
                break;

            case 4:
                PesquisaAutor();
                break;
            
            case 5:
                AlteraDados();
                break;
            
            case 6:
                ExcluirDados();
                break;

            case 7:
                c = Sair();
                break;

            default:
                printf("\nOpção Inválida.\n");
                break;
        }

        //  
    }while(c != 'S');

    return 0;
}