#define ex2

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#ifdef ex1
int main(void){
    char op;

    do{
        FILE *p;
        char c;
        if((p = fopen("arq.txt", "w")) == NULL){
            printf("Erro ao abrir o arquivo.\n");
            exit(0);
        }

        while(1){
            system("cls");
            printf("Insira uma letra ('0' para imprimir): ");
            scanf(" %c", &c);
            if (c == '0'){
                fclose(p);
                break;
            }

            fprintf(p, "%c ", c);
            
        }

        if((p = fopen("arq.txt", "r")) == NULL){
            printf("Erro ao abrir o arquivo.\n");
            exit(0);
        }

        while(1){
            c = fgetc(p);
            if(c == EOF){
                fclose(p);
                break;
            }
            printf("%c", c);
        }

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &op);
        op = toupper(op);

    } while (op == 'S');
    return 0;
}
#endif // ex1
#ifdef ex2
typedef struct{
    int dia;
    int mes;
}Aniversario;

typedef struct{
    char nome[30];
    char telefone[15];
    Aniversario aniversario;
}Contato;

//     1 - inserir contato
//     2 - listar todos os contatos
//     3 - pesquisar um contato pelo nome
//     4 - listar os contatos cujo nome inicia com uma letra digitada
//     5 - imprimir os aniversariantes do mês.
//     6 - altera contato
//     7 - exclui contato
//     8 - saida

void Inserir(Contato *p){
    for(int i = 0; i < 4; i++, p++){
        printf("Insira o %dº nome: ", i+1);
        scanf(" %s", p->nome);
        printf("Insira o telefone: ");
        scanf(" %s", p->telefone);
        printf("Insira o aniversário (DD/MM): ");
        scanf(" %d/%d", &p->aniversario.dia, &p->aniversario.mes);
        
    }
}

void Listar(Contato *p){
    for(int i = 0; i < 4; i++, p++){
        printf("Nome: %s\n", p->nome);
        printf("Telefone: %s\n", p->telefone);
        printf("Aniversário: %d/%d\n", p->aniversario.dia, p->aniversario.mes);
    }
}

void Pesquisar(Contato *p){
    char nome[50], *str1, *str2;
    
    system("cls");
    printf("Digite o nome a ser pesquisado: ");
    gets(nome);

    for(int i = 0; i < 4; i++, p++){
        str2 = p->nome;
        str1 = nome;
        while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0'){
            str1++;
            str2++;
            
            if(*str1 == '\0' && *str2 == '\0'){
                printf("\nNome encontrado!\n");
                printf("Nome: %s\n", p->nome);
                printf("Telefone: %s\n", p->telefone);
                printf("Aniversário: %d/%d\n", p->aniversario.dia, p->aniversario.mes);

                system("pause");
                return;
            }
        }
    }
    printf("Nome não encontrado!\n");
    system("pause");

}

void 
#endif // ex2
#ifdef ex3

#endif // ex3
#ifdef ex4

#endif // ex4
