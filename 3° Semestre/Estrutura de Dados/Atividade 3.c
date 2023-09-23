// 1) Implemente através de um algoritmo o exemplo de Lista Encadeada descrito nos slides de 11 a 16.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do nó da lista
struct Lista {
    char nome[10];
    struct Lista* prox;
};

// Função para criar um novo nó
struct Lista* inserir(const char* nome) {
    struct Lista* novo = (struct Lista*)malloc(sizeof(struct Lista));
    if (novo == NULL) {
        printf("Erro: Falha na alocação de memória\n");
        exit(1);
    }
    strncpy(novo->nome, nome, sizeof(novo->nome) - 1);
    novo->nome[sizeof(novo->nome) - 1] = '\0'; // Garante que a string seja terminada corretamente
    novo->prox = NULL;
    return novo;
}

// Função para imprimir a lista
void imprimir(struct Lista* cabeca) {
    struct Lista* atual = cabeca;
    while (atual != NULL) {
        printf("%s -> ", atual->nome);
        atual = atual->prox;
    }
    printf("NULL\n");
}

// Função para remover um nó com um nome específico
void remover(struct Lista** cabeca, const char* nome) {
    struct Lista* atual = *cabeca;
    struct Lista* ant = NULL;

    // Procurar o nó com o nome especificado
    while (atual != NULL && strcmp(atual->nome, nome) != 0) {
        ant = atual;
        atual = atual->prox;
    }

    // Se o nome não foi encontrado, não faz nada
    if (atual == NULL) {
        printf("Nome %s não encontrado na lista.\n", nome);
        return;
    }

    // Remove o nó
    if (ant == NULL) {
        // O nó a ser removido é o primeiro nó
        *cabeca = atual->prox;
    } else {
        ant->prox = atual->prox;
    }

    free(atual);
}

int main() {
    setlocale(LC_ALL, "");
    // Criando nós
    struct Lista* cabeca = inserir("Anta");
    struct Lista* atual = cabeca;

    // Construindo a lista conforme os dados fornecidos
    const char* nomes[] = { "Tatu", "Cotia", "Paca", "Prea" };
    int prox[] = { 2, 5, 1, -1 }; // Usamos -1 para indicar NULL

    for (int i = 0; i < 4; i++) {
        int proxIndex = prox[i] - 1; // Convertendo para índice de array (1-based para 0-based)
        struct Lista* novo = inserir(nomes[i]);
        atual->prox = novo;
        atual = novo;

        if (proxIndex == -1) {
            break;
        }
    }

    // Imprimindo a lista
    printf("Lista: ");
    imprimir(cabeca);

    // Removendo o nó com nome "Paca" (por exemplo)
    const char* nomeARemover = "Paca";
    remover(&cabeca, nomeARemover);
    printf("Lista após a remoção do nome %s: ", nomeARemover);
    imprimir(cabeca);

    // Liberando a memória alocada
    atual = cabeca;
    while (atual != NULL) {
        struct Lista* temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}
