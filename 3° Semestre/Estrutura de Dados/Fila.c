#define Ex1
#ifdef Ex1
/*
1) Implemente um algoritmo com  uma estrutura de dados  com 10 posições de números inteiros em que os elementos após serem 
        inseridos podem mostrar sua ordem na forma de Fila ou Pilha.

Estrutura de Dados Entrada
    1   2   3   4         5         6         7         8         9        10
    7   8   10  20        30        40        50        60        70       80

Estrutura de Dados Saída em forma de Fila
7 8 10 20 30 40 50 60 70 80
Estrutura de Dados Saída em forma de Pilha
80 70 60 50 40 30 20 10 8 7 
*/

#include <stdio.h>
#include <locale.h>

struct a
{
    int num[10];
    int i;
}a;

int main(void){
    setlocale(LC_ALL, "");

    // Lendo a lista
    printf("Entre os 10 valores inteiros:\n");

    for (a.i = 0; a.i < 10; a.i++)
    {
        printf("%dº: ",a.i+1);
        scanf("%d",&a.num[a.i]);
    }

    // Imprimindo a lista em forma de fila
    system("cls");
    printf("Lista em forma de fila:\n");

    for (a.i = 0; a.i < 10; a.i++)
    {
        printf("%d",a.num[a.i]);

        if(a.i<9)
            printf(", ");
        else
            printf(".");
    }

    // Imprimindo a lista em forma de pilha
    printf("\n\nLista em forma de pilha:\n");

    for (a.i = 9; a.i >= 0; a.i--)
    {
        printf("%d",a.num[a.i]);

        if(a.i>0)
            printf(", ");
        else
            printf(".");
    }


}

#endif // Ex1
#ifdef Ex2
/*
2) Faça um algoritmo que crie uma Lista de 5 elementos do tipo inteiro, com os passos abaixo: 

- ler 5 valores e inserir na lista 
- imprimir a lista 
- achar o maior valor e mostrar 
- achar o menor valor e mostrar 
- mostrar a diferença entre a média e o maior valor 
*/

#include <stdio.h>
#include <locale.h>
struct Lista
{
    int Lista[5];
    int i;
    int max;
    int min;
    int med;
}Lista;

int main(void){
    
    setlocale(LC_ALL, "");

    // Lendo a lista
    printf("Entre os 5 valores inteiros:\n");

    for (Lista.i = 0; Lista.i < 5; Lista.i++)
    {
        printf("%dº: ",Lista.i+1);
        scanf("%d",&Lista.Lista[Lista.i]);
        Lista.med += Lista.Lista[Lista.i];
    }
    Lista.med = Lista.med/5;
    Lista.max = Lista.Lista[0];
    Lista.min = Lista.Lista[0];

    // Imprimindo a lista
    system("cls");
    printf("Lista:\n");
    for (Lista.i = 0; Lista.i < 5; Lista.i++)
    {
        printf("%d",Lista.Lista[Lista.i]);

        if(Lista.i<4)
            printf(", ");
        else
            printf(".");
        
        if (Lista.Lista[Lista.i] < Lista.min)
            Lista.min = Lista.Lista[Lista.i];
        if (Lista.Lista[Lista.i] > Lista.max)
            Lista.max = Lista.Lista[Lista.i]; 
    }
    printf("\nMax: %d\nMin: %d", Lista.max, Lista.min);

    printf("\n\nDiferença entre a média e o maior valor: %d", Lista.max - (Lista.med));

    return 0;
}
#endif // Ex2
#ifdef Ex3
/*
3) Escreva um algoritmo para implementar uma Fila Circular. O algoritmo irá realizar as seguintes ações:
    a) aceitar 5 elementos na Fila
    b) imprimir os 5 elementos inseridos em A
    c) remover da Fila 2 elementos
    d) imprimir os elementos restantes da opção C
    e) Inserir 2 novos elementos na Fila
    f) Imprimir os elementos da Fila, após a operação E
*/

#include <stdio.h>
#include <locale.h>
struct Fila
{
    int Fila[5];
    int i;
    int j;
    int k;
}Fila;

int main(void){
        
        setlocale(LC_ALL, "");
    
        // Lendo a lista
        printf("Entre os 5 valores inteiros:\n");
    
        for (Fila.i = 0; Fila.i < 5; Fila.i++)
        {
            printf("%dº: ",Fila.i+1);
            scanf("%d",&Fila.Fila[Fila.i]);
        }
    
        // Imprimindo a lista
        system("cls");
        printf("Lista:\n");
        for (Fila.i = 0; Fila.i < 5; Fila.i++)
        {
            printf("%d",Fila.Fila[Fila.i]);
    
            if(Fila.i<4)
                printf(", ");
            else
                printf(".");
        }
    
        // Removendo 2 elementos
        for (Fila.i = 0; Fila.i < 2; Fila.i++)
        {
            for (Fila.j = 0; Fila.j < 4; Fila.j++)
            {
                Fila.Fila[Fila.j] = Fila.Fila[Fila.j+1];
            }
        }
    
        // Imprimindo a lista
        printf("\nLista com 2 removidos:\n");
        for (Fila.i = 0; Fila.i < 3; Fila.i++)
        {
            printf("%d",Fila.Fila[Fila.i]);
    
            if(Fila.i<2)
                printf(", ");
            else
                printf(".");
        }
    
        // Inserindo 2 elementos
        printf("\n\nEntre os 2 valores inteiros:\n");
        for (Fila.i = 0; Fila.i < 2; Fila.i++)
        {
            printf("%dº: ",Fila.i+1);
            scanf("%d",&Fila.Fila[Fila.i+3]);
        }
    
        // Imprimindo a lista
        printf("\nLista:\n");
        for (Fila.i = 0; Fila.i < 5; Fila.i++)
        {
            printf("%d",Fila.Fila[Fila.i]);
    
            if(Fila.i<4)
                printf(", ");
            else
                printf(".");
        }
    
        return 0;
}

#endif // Ex3
