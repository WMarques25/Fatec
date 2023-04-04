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
void Entrada(){}

void Listar(){}

void PesquisaLivor(){}

void PesquisaAutor(){}

void AlteraDados(){}

void ExcluirDados(){}

void Sair(){}

int main(void){

    char c = 'a';
    setlocale(LC_ALL, "");

    do{
        // system("cls");
        // print menu
        printf(" * - Biblioteca - *\n\n");
        printf(" 1 - Entrar com os livros.\n");
        printf(" 2 - Listar os livros.");
        printf(" 3 - Pesquisar por livro.");
        printf(" 4 - Pesquisar por autor.");
        printf(" 5 - Alterar livro.");
        printf(" 6 - Excluir livro.");
        printf(" 7 - Sair.");

        // switch case

        //  
    }while(c != 'S');

    return 0;
}