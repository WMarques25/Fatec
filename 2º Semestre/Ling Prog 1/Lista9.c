#define ex3

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#ifdef  ex1
void entrada(float *valor, char *op) {
    printf("Digite uma opera��o (+ - * / =): ");
    scanf(" %c", op);
    if(*op == '='){
        return;
    }
    printf("Digite o um valor: ");
    scanf(" %f", valor);
}

void somar(float *valor, float *resultado) {
    *resultado += *valor;
}

void subtrair(float *valor, float *resultado) {
    *resultado -= *valor;
}

void multiplicar(float *valor, float *resultado) {
    *resultado *= *valor;
}

void dividir(float *valor, float *resultado) {
    *resultado /= *valor;
}

int main(void){
    setlocale(LC_ALL, "Portuguese");
    do{
        float resultado = 0;
        char opcao;

        do{
            int n;
            float valor;
            char operacao;
            system("cls");

            printf("Resultado: %.2f\n", resultado);
            entrada(&valor, &operacao);
            
            switch (operacao) {
                case '+':
                    somar(&valor, &resultado);
                    break;
                case '-':
                    subtrair(&valor, &resultado);
                    break;
                case '*':
                    multiplicar(&valor, &resultado);
                    break;
                case '/':
                    dividir(&valor, &resultado);
                    break;
                case '=':
                    break;
                default:
                    printf("Opera��o inv�lida!\n");
                    break;
            }

            if(operacao == '='){
                system("cls");
                printf("Resultado: %.2f\n", resultado);
                break;
            }

        }while(1);

        printf("\nDeseja sair? ('S' / 'N')\n");
        scanf(" %c", &opcao);
        if(toupper(opcao) == 'S'){
            exit(0);
        }

    }while(1);
    
}
#endif  //ex1
#ifdef  ex2
int Pesquisa(char *pc, char *letras){
    char *p;
    p = letras;
    while(*p != '\0'){
        if(*p == *pc){
            return 1;
        }
        p++;
    }
 
    return 0;
}
 
int	main(void){
    setlocale(LC_ALL, "");
    char letras[] = { 'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};
    char *pc, op;
    pc = &op;
    do{
        printf("Digite um caractere: ");
        scanf(" %c", pc);
    
        if(Pesquisa(pc, letras) == 1){
            printf("O caractere '%c' est� no vetor!.\n", *pc);
            
        }else{
            printf("O caractere '%c' n�o est� no vetor!.\n", *pc);
        }
 
        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &op);
 
        if(toupper(op) == 'N'){
            exit(0);
        }
    }while(1);
    return 0;
}
#endif  //ex2
#ifdef  ex3

void entrada(char *str1, char *str2){
    printf("Digite a primeira string: ");
    scanf(" %s", str1);    

    printf("Digite a segunda string: ");
    scanf(" %s", str2);
}
 
int Compara(char *str1, char *str2){
     
    while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0'){
        str1++;
        str2++;
        
        if(*str1 == '\0' && *str2 == '\0'){
            return 1;
        }
    }
    return 0;
}
 
int main(void){
    setlocale(LC_ALL, "");
    char op, str1[11], str2[11];
    
    do{
        system("cls");
        entrada(str1, str2);
        if(Compara(str1, str2) == 1){
            printf("As strings s�o iguais.\n");
        }else{
            printf("As strings s�o diferentes.\n");
        }
 
        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &op);
 
        if(toupper(op) == 'N'){
            exit(0);
        }
    }while(1);
 
    return 0;
}
#endif  //ex3
#ifdef  ex4

#endif  //ex4
#ifdef  ex5

#endif  //ex5
#ifdef  ex6

#endif  //ex6
