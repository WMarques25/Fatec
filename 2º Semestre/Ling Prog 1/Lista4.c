#define ex5
#include <stdio.h>
#include <ctype.h>
#include <locale.h>

#ifdef ex1
int v[10], u[5], w[5];

int main(){
    char c;
    int j = 0;

    setlocale(LC_ALL, "");

    do{
        for (int i = 0; i < 10; i++){
            printf("Insira o %dº número: ",i+1);
            scanf(" %d", &v[i]);
        }
        system("cls");
        printf("Os vetores decompostos são: \n");

        for (int i = 0; i < 5; i++){
            u[i] = v[j++];
            w[i] = v[j++];
        }

        printf("u[5] = {");

        for (int i = 0; i < 5; i++){
            printf("%d, ",u[i]);
        }
        printf("\b\b}\n");

        printf("w[5] = {");
        for (int i = 0; i < 5; i++){
            printf("%d, ", w[i]);
        }
        printf("\b\b}\n");

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    }while (c == 'S');

        return 0;
}

#endif // ex1
#ifdef ex2
int v[10], u[10], w[10];

int main()
{
        char c;
        int j = 0, k = 0;

        setlocale(LC_ALL, "");

        do{
            for (int i = 0; i < 10; i++){
                printf("Insira o %dº número: ", i + 1);
                scanf(" %d", &v[i]);
            }
            system("cls");
            printf("Os vetores decompostos são: \n");

            for (int i = 0; i < 10; i++){
                if(v[i] % 2 != 0){
                    u[j++] = v[i];
                }
                else{
                    w[k++] = v[i];
                }
                
            }

            printf("u[5] = {");

            for (int i = 0; i < j; i++)
            {
                printf("%d, ", u[i]);
            }
            printf("\b\b}\n");

            printf("w[5] = {");
            for (int i = 0; i < k; i++)
            {
                printf("%d, ", w[i]);
            }
            printf("\b\b}\n");

            printf("\nDeseja continuar? ('S' / 'N')\n");
            scanf(" %c", &c);
            c = toupper(c);

        } while (c == 'S');

        return 0;
}

#endif // ex2
#ifdef ex3
int x[2][3], y[2][3];

int main(void){
        char c;
        int j = 0;

        setlocale(LC_ALL, "");
        do{
            //system("cls");
            printf("Insira os valores para cada posição das matrizes.\n");
            for (int i = 0; i < 2; i++){
                for (j = 0; j < 3; j++){
                    printf("x[%d][%d] = ", i, j);
                    scanf(" %d", &x[i][j]);
                }
            }
            system("cls");
            printf("Insira os valores para cada posição das matrizes.\n");
            for (int i = 0; i < 2; i++){
                for (j = 0; j < 3; j++){
                    printf("y[%d][%d] = ", i, j);
                    scanf(" %d", &y[i][j]);
                }
            }

            printf("As somas são: \n");
            for (int i = 0; i < 2; i++){
                for (j = 0; j < 3; j++){
                    printf("z[%d][%d] = %d\n", i, j, (x[i][j] + y[i][j]));
                }
            }

            printf("\nDeseja continuar? ('S' / 'N')\n");
            scanf(" %c", &c);
            c = toupper(c);

        } while (c == 'S');

        return 0;
} 
#endif // ex3
#ifdef ex4
int main() {
    int inteiro[3];
    long longo[3];
    unsigned unsig[3];
    float flutuante[3];
    double duplo[3];

    do{

        printf("Entre com 3 valores inteiros: ");
        for(int i=0; i<3; i++){
            scanf("%d", &inteiro[i]);
        }

        printf("Entre com 3 valores longos: ");
        for(int i=0; i<3; i++){
            scanf("%ld", &longo[i]);
        }

        printf("Entre com 3 valores unsigned: ");
        for(int i=0; i<3; i++){
            scanf("%u", &unsig[i]);
        }

        printf("Entre com 3 valores float: ");
        for(int i=0; i<3; i++){
            scanf("%f", &flutuante[i]);
        }

        printf("Entre com 3 valores double: ");
        for(int i=0; i<3; i++){
            scanf("%lf", &duplo[i]);
        }

        printf("\n");
        printf("%3s%20s%20s\n%13s%20s\n", "int", "long", "unsigned", "float", "double");
        printf("%50s\n", "12345678901234567890123456789012345678901234567890");

        for(int i=0; i<3; i++){
            printf("%3d%20ld%20u\n%13.2f%20.2lf\n", inteiro[i], longo[i], unsig[i], flutuante[i], duplo[i]);
        } 
        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    }while (c == 'S');

    return 0;
}
#endif // ex4
#ifdef ex5
int main() {
    setlocale(LC_ALL, "");
    char c;
    do{
        int vetor[10];
        int valor, i, j;

        for (i = 0; i < 10; i++) {
            printf("Digite o %dº valor: ", i+1);
            scanf("%d", &valor);

            for (j = i-1; j >= 0 && vetor[j] > valor; j--) { // Comparando o valor novo com os valores no vetor e  
                vetor[j+1] = vetor[j];                       // mudando as posições para +1 cada valor maior q o novo
            }
            vetor[j+1] = valor;                              // Inserindo o novo valor na posição correta
        }

        printf("Valores ordenados: ");
        for (i = 0; i < 10; i++) {
            printf("%d ", vetor[i]);
        }

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    }while (c == 'S');

    return 0;
}   
#endif // ex5