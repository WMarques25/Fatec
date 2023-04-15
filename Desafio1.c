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
char alt_livro[20];

void Atualizar(){

    FILE * f;
    f = fopen("livros", "r");
     if (f == NULL) {
        printf("\n\tArquivo não encontrado.\n\n");
        Entrada();
    }
    livro1[20] = '\0';
    livro2[20] = '\0';
    livro3[20] = '\0';
    autor1[20] = '\0';
    autor2[20] = '\0';
    autor3[20] = '\0';

    fread(livro1, sizeof(livro1), 1, f);
    fread(autor1, sizeof(autor1), 1, f);
    fread(livro2, sizeof(livro2), 1, f);
    fread(autor2, sizeof(autor2), 1, f);
    fread(livro3, sizeof(livro3), 1, f);
    fread(autor3, sizeof(autor3), 1, f);
    
    fclose(f);

}

// Funcoes do Menu
void Entrada(){
    FILE * f;
    f = fopen("livros", "w+");

    printf("Entre com o nome do primeiro livro: ");
    gets(livro1);
    fwrite(livro1, sizeof(livro1), 1, f);

    printf("Entre com o nome do autor: ");
    gets(autor1);
    fwrite(autor1, sizeof(autor1), 1, f);

    printf("Entre com o nome do segundo livro: ");
    gets(livro2);
    fwrite(livro2, sizeof(livro2), 1, f);

    printf("Entre com o nome do autor: ");
    gets(autor2);
    fwrite(autor2, sizeof(autor2), 1, f);

    printf("Entre com o nome do terceiro livro: ");
    gets(livro3);
    fwrite(livro3, sizeof(livro3), 1, f);

    printf("Entre com o nome do autor: ");
    gets(autor3);
    fwrite(autor3, sizeof(autor3), 1, f);

    fclose(f);

}

void Listar(){
    printf("\n\t 1 - %s - %s.", livro1, autor1);
    printf("\n\t 2 - %s - %s.", livro2, autor2);
    printf("\n\t 3 - %s - %s.\n", livro3, autor3);
    
}

void PesquisaLivro(){
        printf("Digite o livro que vc quer pesquisar: ");
        gets(pesq_livro);
        int a;
    

        for(int i=0;i<20;i++){

            if (pesq_livro[i] != livro1[i] && pesq_livro[i]!=livro2[i] && pesq_livro[i]!= livro3[i]){
            
            a=0;
            printf("Livro não encontrado!\n");
            break;
            
            } else{
                a=1;
            }

            if(a==1 && pesq_livro[i]==livro1[i]){
                printf("O Livro %s do autor %s foi encontrado \n",livro1, autor1);
                break;
            }

            if(a==1 && pesq_livro[i]==livro2[i]){
                printf("O Livro %s do autor %s foi encontrado \n",livro2, autor2);
                break;
            }

            if(a==1 && pesq_livro[i]==livro3[i]){
                printf("O Livro %s do autor %s foi encontrado \n",livro3, autor3);
                break;
            }

        }

    }

void PesquisaAutor(){
    char inicial;
    int a = 1, b = 1, c = 1; // Boleanos
    
    system("cls");
    
    printf("Insira a inicial do autor: ");
    inicial = getchar();

    // verificando se os autores tem o mesmo nome
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

    // Imprimindo o autor e seus livros
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
    if(inicial != autor1[0] && inicial != autor2[0] && inicial != autor3[0]){
        printf("\nAutor não encontrado!");
    }
    printf("\n");
    
}

void AlteraDados(){
    Listar();
    int op;
    printf("Digite o numero do livro que deseja alterar: ");
    scanf(" %d", &op);
    getchar();

    FILE * f;
    f = fopen("livros", "r+");  

    switch(op){
        case 1:
            printf("Digite o novo nome do livro:\n");
            gets(livro1);
            fwrite(livro1, sizeof(livro1), 1, f);
            printf("Digite o novo nome do autor:\n");
            gets(autor1);
            fwrite(autor1, sizeof(autor1), 1, f);
            break;
        
        case 2:
            fwrite(livro1, sizeof(livro1), 1, f);
            fwrite(autor1, sizeof(autor1), 1, f);
            printf("Digite o novo nome do livro:\n");
            gets(livro2);
            fwrite(livro2, sizeof(livro2), 1, f);
            printf("Digite o novo nome do autor:\n");
            gets(autor2);
            fwrite(autor2, sizeof(autor2), 1, f);
            break;
        
        case 3:
            fwrite(livro1, sizeof(livro1), 1, f);
            fwrite(autor1, sizeof(autor1), 1, f);
            fwrite(livro2, sizeof(livro2), 1, f);
            fwrite(autor2, sizeof(autor2), 1, f);
            printf("Digite o novo nome do livro:\n");
            gets(livro3);
            fwrite(livro3, sizeof(livro3), 1, f);
            printf("Digite o novo nome do autor:\n");
            gets(autor3);
            fwrite(autor3, sizeof(autor3), 1, f);
            break;
        
        default:
            printf("Opção inválida.\n");
            break;

    }

    fclose(f);

}

void ExcluirDados(){
    Listar();
    int op;
    printf("Digite o numero do livro que deseja excluir: ");
    scanf(" %d", &op);
    getchar();

    FILE * f;
    f = fopen("livros", "w+");  


    switch(op){
        case 1:
            livro1[0] = '\0';
            autor1[0] = '\0';
            fwrite(livro1, sizeof(livro1), 1, f);
            fwrite(autor1, sizeof(autor1), 1, f);

            printf("Livro 1 excluido com sucesso.\n");
            break;
        
        case 2:
            livro2[0] = '\0';
            autor2[0] = '\0';
            fwrite(livro1, sizeof(livro1), 1, f);
            fwrite(autor1, sizeof(autor1), 1, f);
            fwrite(livro2, sizeof(livro2), 1, f);
            fwrite(autor2,sizeof(autor2),1,f);
            printf("Livro 2 excluido com sucesso.\n");
            break;
        
        case 3:
            livro3[0] = '\0';
            autor3[0] = '\0';
            fwrite(livro1, sizeof(livro1), 1, f);
            fwrite(autor1, sizeof(autor1), 1, f);
            fwrite(livro2, sizeof(livro2), 1, f);
            fwrite(autor2, sizeof(autor2), 1, f);
            fwrite(livro3, sizeof(livro3), 1, f);
            fwrite(autor3, sizeof(autor3), 1, f);

            printf("Livro 3 excluido com sucesso.\n");
            break;
        
        default:
            printf("Opção inválida.\n");
            break;
    }
}

char Sair(){
    exit(0);

}

int main(void){

    int op;
    setlocale(LC_ALL, "Portuguese");

    do{
        Atualizar();
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
                Sair();
                break;

            default:
                printf("\nOpção Inválida.\n");
                break;
        }

        system("pause");
    }while(1);

    return 0;
}