/*
2) Implemente uma Lista Encadeada contendo nomes de pessoas [ 10 posições]. - DESAFIO
Em seguida:
a)  remova um nome especifico informado.
b) insira um novo nome na mesma posição onde o nome anterior foi removido.

OBS: Isto vale para qualquer quantidade de elementos removidos ou inseridos na Lista.
*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    char nome[20];
    struct lista *prox;
}Lista;

Lista *remover(Lista *l, char nome[20]){

    Lista *ant = NULL;
    Lista *p = l;
    while(p != NULL && strcmp(p->nome, nome) != 0){
        ant = p;
        p = p->prox;
    }
    if(p == NULL){
        return l;
    }
    if(ant == NULL){
        l = p->prox;
    }else{
        ant->prox = p->prox;
    }
    return l;
}

void imprimir(Lista *l){
    Lista *p;
    printf("Lista: \n");
    for(p = l; p != NULL; p = p->prox){
        printf("%s ", p->nome);
    }
    printf("\n");
}

Lista *inserirPosicao(Lista *l, char nome[20], int posicao){
    Lista *novo = (Lista*)malloc(sizeof(Lista));
    Lista *p = l;
    Lista *ant = NULL;
    int i = 0;
    strcpy(novo->nome, nome);
    while(p != NULL && i < posicao){
        ant = p;
        p = p->prox;
        i++;
    }
    if(p == NULL){
        return l;
    }
    if(ant == NULL){
        l = novo;
    }else{
        ant->prox = novo;
    }
    novo->prox = p;
    return l;
}

Lista A[10] = { { "João", &A[1] }, { "Maria", &A[2] }, { "José", &A[3] },
                { "Ana", &A[4] }, { "Pedro", &A[5] }, { "Paulo", &A[6] },
                { "Carlos", &A[7] }, { "Lucas", &A[8] }, { "Marcos", &A[9] }, { "Mateus", NULL } };

int main(){
    setlocale(LC_ALL, "Portuguese");
    int opcao, posicao;
    char nome[20];
    Lista *l = NULL;
    l = &A[0];
    
    system("cls");
    imprimir(l);
    printf("\n");
    printf("Removendo o nome 'Pedro'.\n");
    l = remover(l, "Pedro");
    imprimir(l);
    printf("\n");
    printf("Inserindo o nome 'Leticia' na posição 4.\n");
    l = inserirPosicao(l, "Leticia", 4);
    imprimir(l);
    printf("\n");

    return 0;
}