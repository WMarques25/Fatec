// Usando o conceito de pilha, carregue uma pilha com 10 elementos do tipo real
// e imprima posteriormente a saída destes elementos. 
#include <stdio.h>
#include <locale.h>

int main(void){
    int Pilha[10];
    int i;
    system("cls");
    setlocale(LC_ALL,"Portuguese");
    for(i=0;i<10;i++){
        printf("Digite o %2d° valor: ",i+1);
        scanf("%d",&Pilha[i]);
    }
    printf("\n");
    i--;
    for(i;i>=0;i--){
        printf("%2d° valor = %d\n", i+1, Pilha[i]);
    }
    return 0;
}