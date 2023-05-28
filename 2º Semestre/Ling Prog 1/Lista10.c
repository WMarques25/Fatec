#define ex4

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

    system("cls");
    
    clientes = fopen("clientes.txt", "a");
    printf("Insira o nome do cliente: ");
    gets(p->nome);
    printf("Insira o email do cliente: ");
    gets(p->email);
    printf("Insira o telefone do cliente: ");
    gets(p->telefone);

    fwrite(p->nome, sizeof(p->nome), 1, clientes);
    fwrite(p->email, sizeof(p->email), 1, clientes);
    fwrite(p->telefone, sizeof(p->telefone), 1, clientes);
    
    fclose(clientes);
}

void Listar(Cliente *p){
    FILE *clientes;
    int i = 0;

    system("cls");
    clientes = fopen("clientes.txt", "r");

    while(fread(p->nome, sizeof(p->nome), 1, clientes) != NULL){
        if(p->nome[0] == '*'){
            fseek(clientes, sizeof(p->email) + sizeof(p->telefone), SEEK_CUR);
            continue;
        }

        i++;
        printf("Cliente %d\n", i);
        printf("Nome: %s", p->nome);
        fread(p->email, sizeof(p->email), 1, clientes);
        printf("\nEmail: %s", p->email);
        fread(p->telefone, sizeof(p->telefone), 1, clientes);
        printf("\nTelefone: %s", p->telefone);
        printf("\n\n");

    }
    if(i == 0){
        printf("Não há clientes cadastrados!\n");
    }

    fclose(clientes);
    system("pause");
}

void Pesquisar(Cliente *p){
    FILE *clientes;
    char nome[50];
    char *n1, *n2;

    system("cls");
    clientes = fopen("clientes.txt", "r");

    printf("Digite o nome do cliente: ");
    gets(nome);

    while(fread(p->nome, sizeof(p->nome), 1, clientes) != NULL){
        n1 = &nome;
        n2 = &p->nome;

        if(*n2 == '*'){
            fseek(clientes, sizeof(p->email) + sizeof(p->telefone), SEEK_CUR);
            continue;
        }

        while(*n1 == *n2 && *n1 != '\0' && *n2 != '\0'){
            n1++;
            n2++;
            if(*n1 == '\0' && *n2 == '\0'){
                printf("Nome: %s", p->nome);
                fread(p->email, sizeof(p->email), 1, clientes);
                printf("\nEmail: %s", p->email);
                fread(p->telefone, sizeof(p->telefone), 1, clientes);
                printf("\nTelefone: %s", p->telefone);
                printf("\n\n");
                fclose(clientes);
                system("pause");
                return;
            }
            
        }
        fseek(clientes, sizeof(p->email) + sizeof(p->telefone), SEEK_CUR);
    }

    printf("Cliente não encontrado!\n");
    system("pause");
    fclose(clientes);

}

void Alterar(Cliente *p){
    FILE *clientes;
    int i = 0;
    char nome[50];
    char *n1, *n2;

    system("cls");
    clientes = fopen("clientes.txt", "r+");

    printf("Digite o nome do cliente: ");
    gets(nome);

    while(fread(p->nome, sizeof(p->nome), 1, clientes) != NULL){
        i++;
        n1 = &nome;
        n2 = &p->nome;

        if(*n2 == '*'){
            fseek(clientes, sizeof(p->email) + sizeof(p->telefone), SEEK_CUR);
            continue;
        }

        while(*n1 == *n2 && *n1 != '\0' && *n2 != '\0'){
            n1++;
            n2++;
            if(*n1 == '\0' && *n2 == '\0'){
                printf("Cliente encontrado!\n\n");
                printf("Nome: %s", p->nome);
                fread(p->email, sizeof(p->email), 1, clientes);
                printf("\nEmail: %s", p->email);
                fread(p->telefone, sizeof(p->telefone), 1, clientes);
                printf("\nTelefone: %s", p->telefone);
                printf("\n\n");

                fseek(clientes, -sizeof(*p), 1);
                printf("Insira o novo nome do cliente: ");
                gets(p->nome);
                printf("Insira o novo email do cliente: ");
                gets(p->email);
                printf("Insira o novo telefone do cliente: ");
                gets(p->telefone);

                fwrite(p->nome, sizeof(p->nome), 1, clientes);
                fwrite(p->email, sizeof(p->email), 1, clientes);
                fwrite(p->telefone, sizeof(p->telefone), 1, clientes);
                printf("Cliente alterado com sucesso!\n");

                fclose(clientes);
                system("pause");
                return;
            }
            
        }
        fseek(clientes, sizeof(p->email) + sizeof(p->telefone), SEEK_CUR);
    }

    printf("Cliente não encontrado!\n");
    system("pause");
    fclose(clientes);

}

void Excluir(Cliente *p){
    FILE *clientes;
    int i = 0;
    char nome[50];
    char *n1, *n2;

    system("cls");
    clientes = fopen("clientes.txt", "r+");

    printf("Digite o nome do cliente: ");
    gets(nome);

    while(fread(p->nome, sizeof(p->nome), 1, clientes) != '\0'){
        i++;
        n1 = &nome;
        n2 = &p->nome;

        if(*n2 == '*'){
            fseek(clientes, sizeof(p->email) + sizeof(p->telefone), SEEK_CUR);
            continue;
        }

        while(*n1 == *n2 && *n1 != '\0' && *n2 != '\0'){
            n1++;
            n2++;
            if(*n1 == '\0' && *n2 == '\0'){
                printf("Cliente encontrado!\n\n");
                printf("Nome: %s", p->nome);
                fread(p->email, sizeof(p->email), 1, clientes);
                printf("\nEmail: %s", p->email);
                fread(p->telefone, sizeof(p->telefone), 1, clientes);
                printf("\nTelefone: %s", p->telefone);
                printf("\n\n");

                fseek(clientes, -sizeof(*p), 1);
                
                p->nome[0] = '*';
                fwrite(p->nome, sizeof(p->nome), 1, clientes);
                printf("Cliente excluido com sucesso!\n");

                fclose(clientes);
                system("pause");
                return;
            }
            
        }
        fseek(clientes, sizeof(p->email) + sizeof(p->telefone), SEEK_CUR);
    }

    printf("Cliente não encontrado!\n");
    system("pause");
    fclose(clientes);

}

void Sair(){
    exit(0);

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
                Sair();

            default:
                printf("Opção inválida!\n");
                system("pause");
                break;
        }        
    }
    
}


#endif // ex3
#ifdef ex4
typedef struct{
    int codigo;
    char nome[50];
    int quantidade;
}Mercadoria;

void Incliur(Mercadoria *p){
    FILE *Dispensa;
    int i = 0;
    int codigo, x;

    system("cls");
    Dispensa = fopen("dispensa.txt", "r+");
    printf("Digite o código da mercadoria: ");
    scanf(" %d", &codigo);
    getchar();

    // while(fread(p->codigo, sizeof(p->codigo), 1, Dispensa) != '\0'){
    // while((p->codigo = getc(Dispensa)) != EOF){
        while((fscanf(Dispensa,"%d ", p->codigo)) != EOF){
        i++;
        if(codigo == p->codigo){
            printf("Código já cadastrado!\n");
            fclose(Dispensa);
            system("pause");
            return;
        }
        fseek(Dispensa, sizeof(p->nome) + sizeof(p->quantidade), SEEK_CUR);
        getc(Dispensa);
    }

    fseek(Dispensa, 0, SEEK_END);
    p->codigo = codigo;
    printf("Digite o nome da mercadoria: ");
    gets(p->nome);
    printf("Digite a quantidade da mercadoria: ");
    scanf(" %d", &p->quantidade);

    // fwrite(p->codigo, sizeof(p->codigo), 1, Dispensa);
    // putc(p->codigo, Dispensa);
    fprintf(Dispensa, "%d ", p->codigo);
    fwrite(p->nome, sizeof(p->nome), 1, Dispensa);
    // fwrite(p->quantidade, sizeof(p->quantidade), 1, Dispensa);
    // putc(p->quantidade, Dispensa);
    fprintf(Dispensa, "%d ", p->quantidade);
    putc('\n', Dispensa);
    printf("\nMercadoria cadastrada com sucesso!\n");

    fclose(Dispensa);
    system("pause");

}
void Listar(Mercadoria *p){
    FILE *Dispensa;
    
    system("cls");
    Dispensa = fopen("test.txt", "w");
    putc(10, Dispensa);
    putc(2, Dispensa);
    putc(15, Dispensa);

    fclose(Dispensa);
    system("pause");

    Dispensa = fopen("test.txt", "r");

    printf("%d\n", getc(Dispensa));
    printf("%d\n", getc(Dispensa));
    printf("%d\n", getc(Dispensa));

    fclose(Dispensa);
    system("pause");
}
void Pesquisar(Mercadoria *p){}
void ListarIndisponiveis(Mercadoria *p){}
void AlterarQuantidade(Mercadoria *p){}
void Alterar(Mercadoria *p){}
void Excluir(Mercadoria *p){}
void Sair(){}
int main(void){
    setlocale(LC_ALL, "Portuguese");
    Mercadoria Mercadoria;
    int op;

    while (1){
        system("cls");
        printf("Dispensa\n");
        printf("1 - Incluir mercadoria\n");
        printf("2 - Listar todas as mercadorias\n");
        printf("3 - Pesquisar uma mercadoria pela descrição\n");
        printf("4 - Listar as mercadorias não disponíveis\n");
        printf("5 - Alterar a quantidade atual\n");
        printf("6 - Alterar mercadoria\n");
        printf("7 - Excluir mercadoria\n");
        printf("8 - Sair\n");
        printf("Digite a opção: ");
        scanf(" %d", &op);
        getchar();

        switch(op){
            case 1:
                Incliur(&Mercadoria);
                break;

            case 2:
                Listar(&Mercadoria);
                break;

            case 3:
                Pesquisar(&Mercadoria);
                break;

            case 4:
                ListarIndisponiveis(&Mercadoria);
                break;

            case 5:
                AlterarQuantidade(&Mercadoria);
                break;

            case 6:
                Alterar(&Mercadoria);
                break;

            case 7:
                Excluir(&Mercadoria);
                break;

            case 8:
                Sair();

            default:
                printf("Opção inválida!\n");
                system("pause");
                break;
        }        
    }
    
}
#endif // ex4