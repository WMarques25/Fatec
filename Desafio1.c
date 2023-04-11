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
char pesq_livro[20];

// Funcoes do Menu
void Entrada(){
    FILE * f;
    f = fopen("livros.txt", "w");

    printf("Entre com o nome do primeiro livro: ");
    gets(livro1);

    printf("Entre com o nome do autor: ");
    gets(autor1);

    printf("Entre com o nome do segundo livro: ");
    gets(livro2);

    printf("Entre com o nome do autor: ");
    gets(autor2);

    printf("Entre com o nome do terceiro livro: ");
    gets(livro3);

    printf("Entre com o nome do autor: ");
    gets(autor3);
}

void Listar(){
    printf("\n\t 1 - %s - %s.", livro1, autor1);
    printf("\n\t 2 - %s - %s.", livro2, autor2);
    printf("\n\t 3 - %s - %s.\n", livro3, autor3);
    // system("pause");
}

void PesquisaLivro(){
    // TODO
    // comparar tds os caracteres -- Lista 5 ex 1

    //FUNCAO DA LISTA 5 EX 1 PARA COMPARAR STRINGS

    // int compara(){
    //     int c;
    // for(int i=0;i<11;i++){

    //     if (a[i] != b[i]){
    //      c = 0;
    //     break;}

    //     else{
    //         c = 1;
    //     }

    // }

    // return c;
    // }

    printf("Digite o livro que vc quer pesquisar: ");
    gets(pesq_livro);
    int a;

    for(int i=0;i<20;i++){

        if (pesq_livro[i] != livro1[i] && pesq_livro[i]!=livro2[i] && pesq_livro[i]!= livro3[i]){
        
         a=0;
        break;
        
        }
        else{
                a=1;
        }
        }

        if(a==0)
        printf("Sem corrrespondencia\n");
        else
        printf("Livro encontrado\n");
    // system("pause");
}

void PesquisaAutor(){
    char inicial;
    int a = 1, b = 1, c = 1; // Boleanos
    
    system("cls");
    
    printf("Insira a inicial do autor: ");
    inicial = getchar();

    for(int i=0;i<20;i++){

        if (autor1[i] != autor2[i]){
            a = 0;
        }
        if (autor1[i] != autor3[i]){
            b = 0;
        }
        if (autor2[i] != autor3[i]){
            c = 0;
        }
    }

    // livro = inicial == livro1[0] ? 1 : (inicial == livro2[0] ? 2 : (inicial == livro3[0] ? 3 : 0));
    
    if (inicial == autor1[0]){
        printf("\nAutor: %s",autor1);
        printf("\n\t1 - %s",livro1);

        a == 1 ? printf("\n\t2 - %s",livro2): 0;
        b == 1 ? printf("\n\t3 - %s",livro3): 0;
    }
    if(inicial == autor2[0] && a == 0){
        printf("\nAutor: %s",autor2);
        printf("\n\t2 - %s",livro2);

        c == 1 ? printf("\n\t3 - %s",livro3): 0;
    }
    if(inicial == autor3[0] && b == 0 && c == 0){
        printf("\nAutor: %s",autor3);
        printf("\n\t3 - %s",livro3);
    }
    printf("\n");
    // system("pause");
}

void AlteraDados(){
    // TODO
}

void ExcluirDados(){
    Listar();
    int op;
    printf("Digite o numero do livro que deseja excluir: ");
    scanf(" %d", &op);

    switch(op){
        case 1:
            livro1[0] = '\0';
            autor1[0] = '\0';
            printf("Livro 1 excluido com sucesso.\n");
            break;
        
        case 2:
            livro2[0] = '\0';
            autor2[0] = '\0';
            printf("Livro 2 excluido com sucesso.\n");
            break;
        
        case 3:
            livro3[0] = '\0';
            autor3[0] = '\0';
            printf("Livro 3 excluido com sucesso.\n");
            break;
        
        default:
            printf("Opção inválida.\n");
            break;
    }
}

char Sair(){
    return 'S';
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

        system("pause");
    }while(c != 'S');

    return 0;
}