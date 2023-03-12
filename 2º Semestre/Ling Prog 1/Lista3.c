#define ex2
#include <stdio.h>
#include <ctype.h>

#ifdef ex1
    int verifica(int a){
        if(a == 0){
            return -1;
        }
        else if (a < 0){
            return 0;
        }
        else{
            return 1;
        }
    }

    int soma(int a, int b){
        int somat = 0;

        if (a < b){
            for(a; a+1<b; ){
                a++;
                somat += a;
            }
        }
        else if(a > b){
            for(b; b+1<a; ){
                b++;
                somat += b;
            }
        }

        return somat;
    }

    int mult(int a, int b){
        int multi = 1;
        if (a < b){
            for(a; a+1<b; ){
                a++;
                multi *= a;
            }
        }
        else if(a > b){
            for(b; b+1<a; ){
                b++;
                multi *= b;
            }
        }

        return multi;
    }

    float div(int a, int b){
        
            return((float)a/(float)b);
        
    }

    int main(void){
        char c;

        do{
            int x, y, v1, v2;
            system("cls");

            printf("Digite o primeiro numero: ");
            scanf(" %d", &x);
            v1 = verifica(x);

            printf("Digite o segundo numero: ");
            scanf(" %d", &y);
            v2 = verifica(y);

            if(v1 == 1 && v2 == 1){
                printf("A soma dos numeros entre %d e %d e´ %d", x, y, soma(x, y));
            }
            else if (v1 == 0 && v2 == 0){
                printf("A multiplicacao dos numeros entre %d e %d e´ %d", x, y, mult(x, y));
            }
            else if((v1 == 1 && v2 == 0) || (v1 == 0 && v2 == 1)){
                printf("A divisao dos numeros entre %d e %d e´ %f", x, y, div(x, y));
            }


            printf("\nDeseja continuar? ('S' / 'N')\n");
            scanf(" %c", &c);
            c = toupper(c);

        } while (c == 'S');

        return 0;

    }
#endif // ex1
#ifdef ex2
    int func(int x){
        int soma = 0;
        // for de fatorial
        for(int i=x-1 ; i>1 ; i--){
            x *= i;
            printf(" %d", x); // remover
        }
        // for de soma dos alg (y = x % 10; soma += y; x = x/10)
        while(x>0){
            soma += x%10;
            x /= 10;
        }
        return soma;
    }

    int main(void){
        char c;
        int x;

        do{
            printf("Digite um numero: ");
            scanf(" %d",&x);
            
            printf("A soma dos algarismos do fatorial de %d eh: %d",x, func(x));

            printf("\nDeseja continuar? ('S' / 'N')\n");
            scanf(" %c", &c);
            c = toupper(c);

        } while (c == 'S');

        return 0;

    }
#endif // ex2
#ifdef ex3

#endif // ex3
#ifdef ex4

#endif // ex4
#ifdef ex5

#endif // ex5
