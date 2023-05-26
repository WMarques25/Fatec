#define ex3

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
    char nome[50];
    char telefone[15];
    Aniversario aniversario;
}Contato;

void Inserir(Contato *pp){
    system("cls");
    for(int i = 0; i < 4; i++, pp++){
        printf("Insira o %dº nome: ", i+1);
        gets(pp->nome);
        printf("Insira o telefone: ");
        gets(pp->telefone);
        printf("Insira o aniversário (DD/MM): ");
        scanf(" %d/%d", &pp->aniversario.dia, &pp->aniversario.mes);
        getchar();
        printf("\n");

    }
}

void Listar(Contato *p){
    system("cls");
    for(int i = 0; i < 4; i++, p++){
        printf("%dº contato:\n", i+1);
        printf("Nome: %s\n", p->nome);
        printf("Telefone: %s\n", p->telefone);
        printf("Aniversário: %d/%d\n\n", p->aniversario.dia, p->aniversario.mes);
    }
    system("pause");
}

void Pesquisar(Contato *p){
    char n[50], *str1, *str2;
    
    system("cls");
    printf("Digite o nome a ser pesquisado: ");
    gets(n);
    

    for(int i = 0; i < 4; i++, p++){
        str2 = p->nome;
        str1 = n;
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

void ListarInicial(Contato *p){
    char letra;
    int verificacao = 0;
    system("cls");
    printf("Digite a letra inicial: ");
    scanf(" %c", &letra);

    for(int i = 0; i < 4; i++, p++){
        if(p->nome[0] == letra){
            verificacao += 1;
            printf("\nNome: %s\n", p->nome);
            printf("Telefone: %s\n", p->telefone);
            printf("Aniversário: %d/%d\n", p->aniversario.dia, p->aniversario.mes);
        }
    }
    if(verificacao == 0){
        printf("Nenhum contato encontrado.\n");
    }
    system("pause");
}

void Aniversariantes(Contato *p){
    int mes, verificacao;
    system("cls");
    printf("Digite o mês: ");
    scanf(" %d", &mes);

    for(int i = 0; i < 4; i++, p++){
        verificacao += 1;
        if(p->aniversario.mes == mes){
            printf("\nNome: %s\n", p->nome);
            printf("Telefone: %s\n", p->telefone);
            printf("Aniversário: %d/%d\n", p->aniversario.dia, p->aniversario.mes);
        }
    }
    if(verificacao == 0){
        printf("Nenhum contato encontrado.\n");
    }
    system("pause");
}

void Alterar(Contato *p){
    char nome[50], *str1, *str2;
    
    system("cls");
    printf("Digite o nome do contato a ser alterado: ");
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

                printf("\nInsira o novo nome: ");
                // scanf(" %s", p->nome);
                gets(p->nome);
                printf("Insira o novo telefone: ");
                // scanf(" %s", p->telefone);
                gets(p->telefone);
                printf("Insira o novo aniversário (DD/MM): ");
                scanf(" %d/%d", &p->aniversario.dia, &p->aniversario.mes);

                system("pause");
                return;
            }
        }
    }
    printf("Nome não encontrado!\n");
    system("pause");
}

void Excluir(Contato *p){
    char nome[50], *str1, *str2;
    
    system("cls");
    printf("Digite o nome a ser excluído: ");
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

                printf("\nDeseja excluir? (S/N) ");
                char op;
                scanf(" %c", &op);
                op = toupper(op);
                if(op == 'S'){
                    p->nome[0] = '\0';
                    p->telefone[0] = '\0';
                    p->aniversario.dia = 0;
                    p->aniversario.mes = 0;
                }

                system("pause");
                return;
            }
        }
    }
    printf("Nome não encontrado!\n");
    system("pause");
}

void Sair(Contato *p1){
    FILE *Contatos;

    Contatos = fopen("contatos.txt", "w");
    for(int i = 0; i < 4; i++, p1++){
        fwrite(p1->nome, sizeof(p1->nome), 1, Contatos);
        fwrite(p1->telefone, sizeof(p1->telefone), 1, Contatos);
        fputs("\n", Contatos);
        fprintf(Contatos, "%d\n", p1->aniversario.dia);
        fprintf(Contatos, "%d\n", p1->aniversario.mes);
    }

    fclose(Contatos);
    exit(0);
}

int main(void){
    setlocale(LC_ALL, "Portuguese");
    Contato p[4];
    Contato *p1 = p;
    FILE *Contatos;
    int op;

    if((Contatos = fopen("contatos.txt", "r")) == NULL){
        fclose(Contatos);
        Contatos = fopen("contatos.txt", "w");
        fclose(Contatos);
    }else{

        for(int i = 0; i < 4; i++, p1++){
            fread(p1->nome, sizeof(p1->nome), 1, Contatos);
            fread(p1->telefone, sizeof(p1->telefone), 1, Contatos);
            fscanf(Contatos, "%d", &p1->aniversario.dia);
            fscanf(Contatos, "%d", &p1->aniversario.mes);
            fgetc(Contatos);
        }
        fclose(Contatos);
    }
    do{
        system("cls");
        printf("Agenda de contatos\n");
        printf("1 - Inserir contato\n");
        printf("2 - Listar todos os contatos\n");
        printf("3 - Pesquisar um contato pelo nome\n");
        printf("4 - Listar os contatos cujo nome inicia com uma letra digitada\n");
        printf("5 - Imprimir os aniversariantes do mês\n");
        printf("6 - Alterar contato\n");
        printf("7 - Excluir contato\n");
        printf("8 - Sair\n");
        printf("Digite a opção: ");
        scanf(" %d", &op);
        getchar();

        switch(op){
            case 1:
                Inserir(p);
                break;

            case 2:
                Listar(p);
                break;

            case 3:
                Pesquisar(p);
                break;

            case 4:
                ListarInicial(p);
                break;

            case 5:
                Aniversariantes(p);
                break;

            case 6:
                Alterar(p);
                break;

            case 7:
                Excluir(p);
                break;

            case 8:
                Sair(p);

            default:
                printf("Opção inválida!\n");
                system("pause");
                break;
        }
    } while (op != 8);

    return 0;

}

#endif // ex2
#ifdef ex3
typedef struct{
    char nome[50];
    char email[50];
    char telefone[15];
}Cliente;

void Inserir(Cliente *p){
    FILE *clientes;

    clientes = fopen("clientes.txt", "a");
    printf("Insira o nome do cliente: ");
    gets(p->nome);
    printf("Insira o email do cliente: ");
    gets(p->email);
    printf("Insira o telefone do cliente: ");
    gets(p->telefone);

    fputs(p->nome, clientes);
    fputs("\n", clientes);
    fputs(p->email, clientes);
    fputs("\n", clientes);
    fputs(p->telefone, clientes);
    fputs("\n", clientes);

    fclose(clientes);
}

void Listar(Cliente *p){
    FILE *clientes;
    int i = 0;

    clientes = fopen("clientes.txt", "r");

    while(fgets(p->nome, 50, clientes) != NULL){
        i++;
        printf("Cliente %d\n", i);
        printf("Nome: %s", p->nome);
        fgets(p->email, 50, clientes);
        printf("Email: %s", p->email);
        fgets(p->telefone, 15, clientes);
        printf("Telefone: %s", p->telefone);
        printf("\n");

    }

    fclose(clientes);
    system("pause");
}

void Pesquisar(Cliente *p){
    FILE *clientes;
    char nome[50];

    clientes = fopen("clientes.txt", "r");

    printf("Digite o nome do cliente: ");
    gets(nome);

    while(fgets(p->nome, 50, clientes) != NULL){
        if(){}
    }

}

void Alterar(Cliente *p){
    FILE *clientes;

}

void Excluir(Cliente *p){
    FILE *clientes;

}

void Sair(Cliente *p){
    FILE *clientes;

}


int main(void){
    setlocale(LC_ALL, "Portuguese");
    Cliente Cliente;
    int op;

    while (1){
        system("cls");
        printf("Cadastro de clientes\n");
        printf("1 - Inserir cliente\n");
        printf("2 - Listar todos os clientes\n");
        printf("3 - Pesquisar um cliente pelo nome\n");
        printf("4 - Alterar cliente\n");
        printf("5 - Excluir cliente\n");
        printf("6 - Sair\n");
        printf("Digite a opção: ");
        scanf(" %d", &op);
        getchar();

        switch(op){
            case 1:
                Inserir(&Cliente);
                break;

            case 2:
                Listar(&Cliente);
                break;

            case 3:
                Pesquisar(&Cliente);
                break;

            case 4:
                Alterar(&Cliente);
                break;

            case 5:
                Excluir(&Cliente);
                break;

            case 6:
                Sair(&Cliente);

            default:
                printf("Opção inválida!\n");
                system("pause");
                break;
        }        
    }
    
}


#endif // ex3
#ifdef ex4

#endif // ex4
