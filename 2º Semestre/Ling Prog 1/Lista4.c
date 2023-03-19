#define ex3
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

            printf("As somas são: ");
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

#endif // ex4
#ifdef ex5

#endif // ex5