#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

typedef struct{
    char titulo[50];
    char autor[50];
    float preco;
    int quantidade;

} Livro;

void Inserir(Livro *livros){
    FILE *arq;
    char pesq[50];
    char *n1, *n2;
    int i = 0;

    system("cls");
    arq = fopen("livros.txt", "r+");
    printf("Insira o titulo do livro: ");
    gets(pesq);
    while(fread(livros, sizeof(*livros), 1, arq) != 0){
        n1 = &pesq;
        n2 = &livros->titulo;

        if(livros->titulo[0] == '*'){
            getc(arq);
            continue;
        }

        while(*n1 == *n2 && *n1 != '\0' && *n2 != '\0'){
            n1++;
            n2++;
            if(*n1 == '\0' && *n2 == '\0'){
                printf("Livro já cadastrado!\n");
                fclose(arq);
                system("pause");
                return;
            }

        }

    }
    
    while(pesq[i] != '\0'){
        livros->titulo[i] = pesq[i];
        i++;
        if(pesq[i] == '\0'){
            livros->titulo[i] = '\0';
        }
    }

    fseek(arq, 0, SEEK_END);
    printf("Insira o autor do livro: ");
    gets(livros->autor);
    printf("Insira o preço do livro: ");
    scanf("%f", &livros->preco);
    getchar();
    printf("Insira a quantidade do livro: ");
    scanf("%d", &livros->quantidade);
    getchar();
    fwrite(livros, sizeof(*livros), 1, arq);
    putc('\n', arq);
    fclose(arq);
    printf("Livro cadastrado com sucesso!\n");
    system("pause");

}
void Listar(Livro *livros){
    FILE *arq;
    int i = 0;
    arq = fopen("livros.txt", "r");
    system("cls");
    while(fread(livros, sizeof(*livros), 1, arq) != 0){
        if(livros->titulo[0] == '*'){
            continue;
        }
        i++;
        printf("Livro %dº:\n", i);
        printf("Titulo: %s\n", livros->titulo);
        printf("Autor: %s\n", livros->autor);
        printf("Preço: %.2f\n", livros->preco);
        printf("Quantidade: %d\n", livros->quantidade);
        printf("\n");
        getc(arq);
    }
    fclose(arq);
    system("pause");
}
void Pesquisar(Livro *livros){
    FILE *arq;
    char pesq[50];
    char *n1, *n2;

    system("cls");
    arq = fopen("livros.txt", "r");
    printf("Insira o titulo do livro: ");
    gets(pesq);
    while(fread(livros, sizeof(*livros), 1, arq) != 0){
        n1 = &pesq;
        n2 = &livros->titulo;

        if(livros->titulo[0] == '*'){
            getc(arq);
            continue;
        }

        while(*n1 == *n2 && *n1 != '\0' && *n2 != '\0'){
            n1++;
            n2++;
            if(*n1 == '\0' && *n2 == '\0'){
                printf("Livro encontrado!\n");
                printf("Titulo: %s\n", livros->titulo);
                printf("Autor: %s\n", livros->autor);
                printf("Preço: %.2f\n", livros->preco);
                printf("Quantidade: %d\n", livros->quantidade);
                printf("\n");
                fclose(arq);
                system("pause");
                return;
            }

        }
        getc(arq);

    }
    printf("Livro não encontrado!\n");
    fclose(arq);
    system("pause");
}
void PesquisarAutor(Livro *livros){
    FILE *arq;
    char pesq[50];
    char *n1, *n2;
    int i = 0;

    system("cls");
    arq = fopen("livros.txt", "r");
    printf("Insira o nome do autor: ");
    gets(pesq);
    while(fread(livros, sizeof(*livros), 1, arq) != 0){
        n1 = &pesq;
        n2 = &livros->autor;

        if(livros->titulo[0] == '*'){
            getc(arq);
            continue;
        }

        while(*n1 == *n2 && *n1 != '\0' && *n2 != '\0'){
            n1++;
            n2++;
            if(*n1 == '\0' && *n2 == '\0'){
                i++;
                printf("Livro %dº:\n", i);
                printf("Titulo: %s\n", livros->titulo);
                printf("Preço: %.2f\n", livros->preco);
                printf("Quantidade: %d\n", livros->quantidade);
                printf("\n");
                
            }

        }
        getc(arq);
    }

    if(i == 0){
        printf("Autor não encontrado!\n");
    }
    
    fclose(arq);
    system("pause");
}
void PesquisarPreco(Livro *livros){
    FILE *arq;
    float min, max;
    int i = 0;

    system("cls");
    arq = fopen("livros.txt", "r");
    printf("Insira o preço minimo: ");
    scanf("%f", &min);
    getchar();
    printf("Insira o preço maximo: ");
    scanf("%f", &max);
    getchar();

    while(fread(livros, sizeof(*livros), 1, arq) != 0){
        if(livros->titulo[0] == '*'){
            getc(arq);
            continue;
        }

        if(livros->preco >= min && livros->preco <= max){
            i++;
            printf("Livro %dº:\n", i);
            printf("Titulo: %s\n", livros->titulo);
            printf("Autor: %s\n", livros->autor);
            printf("Preço: %.2f\n", livros->preco);
            printf("Quantidade: %d\n", livros->quantidade);
            printf("\n");
        }
        getc(arq);
    }

    if(i == 0){
        printf("Nenhum livro encontrado!\n");
    }

    fclose(arq);
    system("pause");
}
void AlterarQuantidade(Livro *livros){
    FILE *arq;
    char pesq[50];
    char *n1, *n2;
    int qtd;

    system("cls");
    arq = fopen("livros.txt", "r+");
    printf("Insira o titulo do livro: ");
    gets(pesq);
    while(fread(livros, sizeof(*livros), 1, arq) != 0){
        n1 = &pesq;
        n2 = &livros->titulo;

        if(livros->titulo[0] == '*'){
            getc(arq);
            continue;
        }

        while(*n1 == *n2 && *n1 != '\0' && *n2 != '\0'){
            n1++;
            n2++;
            if(*n1 == '\0' && *n2 == '\0'){
                printf("Livro encontrado!\n");
                printf("Titulo: %s\n", livros->titulo);
                printf("Autor: %s\n", livros->autor);
                printf("Preço: %.2f\n", livros->preco);
                printf("Quantidade: %d\n", livros->quantidade);
                printf("\n");
                printf("Insira a movimentação: ");
                scanf(" %d", &qtd);
                getchar();
                livros->quantidade += qtd;
                fseek(arq, -sizeof(*livros), SEEK_CUR);
                fwrite(livros, sizeof(*livros), 1, arq);
                fclose(arq);
                printf("Quantidade alterada com sucesso!\n");
                system("pause");
                return;
            }

        }
        getc(arq);
    }
    printf("Livro não encontrado!\n");
    fclose(arq);
    system("pause");
}
void AlterarPreco(Livro *livros){
    FILE *arq;
    char pesq[50];
    char *n1, *n2;
    float preco;

    system("cls");
    arq = fopen("livros.txt", "r+");
    printf("Insira o titulo do livro: ");
    gets(pesq);
    while(fread(livros, sizeof(*livros), 1, arq) != 0){
        n1 = &pesq;
        n2 = &livros->titulo;

        if(livros->titulo[0] == '*'){
            getc(arq);
            continue;
        }

        while(*n1 == *n2 && *n1 != '\0' && *n2 != '\0'){
            n1++;
            n2++;
            if(*n1 == '\0' && *n2 == '\0'){
                printf("Livro encontrado!\n");
                printf("Titulo: %s\n", livros->titulo);
                printf("Autor: %s\n", livros->autor);
                printf("Preço: %.2f\n", livros->preco);
                printf("Quantidade: %d\n", livros->quantidade);
                printf("\n");
                printf("Insira o novo preço: ");
                scanf(" %f", &preco);
                getchar();
                livros->preco = preco;
                fseek(arq, -sizeof(*livros), SEEK_CUR);
                fwrite(livros, sizeof(*livros), 1, arq);
                fclose(arq);
                printf("Preço alterado com sucesso!\n");
                system("pause");
                return;
            }

        }
        getc(arq);

    }
    printf("Livro não encontrado!\n");
    fclose(arq);
    system("pause");
}
void AlterarDados(Livro *livros){
    FILE *arq;
    char pesq[50];
    char *n1, *n2;

    system("cls");
    arq = fopen("livros.txt", "r+");
    printf("Insira o titulo do livro: ");
    gets(pesq);

    while(fread(livros, sizeof(*livros), 1, arq) != 0){
        n1 = &pesq;
        n2 = &livros->titulo;

        if(livros->titulo[0] == '*'){
            getc(arq);
            continue;
        }

        while(*n1 == *n2 && *n1 != '\0' && *n2 != '\0'){
            n1++;
            n2++;
            if(*n1 == '\0' && *n2 == '\0'){
                printf("Livro encontrado!\n");
                printf("Titulo: %s\n", livros->titulo);
                printf("Autor: %s\n", livros->autor);
                printf("Preço: %.2f\n", livros->preco);
                printf("Quantidade: %d\n", livros->quantidade);
                printf("\n");
                printf("Insira o novo titulo: ");
                gets(livros->titulo);
                printf("Insira o novo autor: ");
                gets(livros->autor);
                printf("Insira o novo preço: ");
                scanf("%f", &livros->preco);
                getchar();
                printf("Insira a nova quantidade: ");
                scanf("%d", &livros->quantidade);
                getchar();
                fseek(arq, -sizeof(*livros), SEEK_CUR);
                fwrite(livros, sizeof(*livros), 1, arq);
                putc('\n', arq);
                fclose(arq);
                printf("Dados alterados com sucesso!\n");
                system("pause");
                return;
            }

        }
        getc(arq);

    }
}
void ExcluirLivro(Livro *livros){
    FILE *arq;
    char pesq[50];
    char *n1, *n2;

    system("cls");
    arq = fopen("livros.txt", "r+");
    printf("Insira o titulo do livro: ");
    gets(pesq);

    while(fread(livros, sizeof(*livros), 1, arq) != 0){
        n1 = &pesq;
        n2 = &livros->titulo;

        if(livros->titulo[0] == '*'){
            getc(arq);
            continue;
        }

        while(*n1 == *n2 && *n1 != '\0' && *n2 != '\0'){
            n1++;
            n2++;
            if(*n1 == '\0' && *n2 == '\0'){
                printf("Livro encontrado!\n");
                printf("Titulo: %s\n", livros->titulo);
                printf("Autor: %s\n", livros->autor);
                printf("Preço: %.2f\n", livros->preco);
                printf("Quantidade: %d\n", livros->quantidade);
                printf("\n");
                livros->titulo[0] = '*';
                fseek(arq, -sizeof(*livros), SEEK_CUR);
                fwrite(livros, sizeof(*livros), 1, arq);
                fclose(arq);
                printf("Livro excluido com sucesso!\n");
                system("pause");
                return;
            }

        }
        getc(arq);

    }
    printf("Livro não encontrado!\n");
    fclose(arq);
    system("pause");
}

int main(void){
    Livro livros;
    setlocale(LC_ALL, "PORTUGUESE");
    int op;
    FILE *arq;

    if((arq = fopen("livros.txt", "r")) == NULL){
        fclose(arq);
        arq = fopen("livros.txt", "w");
        fclose(arq);
    }

    while(1){
        system("cls");
        printf(" 1 - Cadastrar livro\n");
        printf(" 2 - Listar livros\n");
        printf(" 3 - Pesquisar livro por titulo\n");
        printf(" 4 - Pesquisar livro por autor\n");
        printf(" 5 - Pesquisar livro por faixa de preço\n");
        printf(" 6 - Alterar quantidade\n");
        printf(" 7 - Alterar preço\n");
        printf(" 8 - Alterar dados\n");
        printf(" 9 - Excluir livro\n");
        printf("10 - Sair\n");
        printf("Insira a opção: ");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:
                Inserir(&livros);
                break;
            case 2:
                Listar(&livros);
                break;
            case 3:
                Pesquisar(&livros);
                break;
            case 4:
                PesquisarAutor(&livros);
                break;
            case 5:
                PesquisarPreco(&livros);
                break;
            case 6:
                AlterarQuantidade(&livros);
                break;
            case 7:
                AlterarPreco(&livros);
                break;
            case 8:
                AlterarDados(&livros);
                break;
            case 9:
                ExcluirLivro(&livros);
                break;
            case 10:
                exit(0);
                break;
            default:
                printf("Opção inválida!\n");
                system("pause");
                break;
        }
    }

    return 0;
}