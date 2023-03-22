#define ex4
#include <stdio.h>
#include <ctype.h>
#include <locale.h>

#ifdef ex1
int Comparar(char x[], char y[]){
    int a = 0;
    for(int i = 0; i < 11 && x[i] != '\0' && y[i] != '\0'; i++){
        if(x[i] == y[i]){
            a = 1;
        }
        else{
            a = 0;
            break;
        }
    }
    return a;
}

int main(void){
    char c, x [11], y [11];
    int f;
    setlocale(LC_ALL,"");

    do{
        printf("Digite a primeira string: ");
        scanf(" %s", &x[0]);
        printf("Digite a segunda string: ");
        scanf(" %s", &y[0]);
        f = Comparar(x, y);
        printf("%d",f);

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif // ex1
#ifdef ex2
int main(void){
    char c, nomes [5][8];
    setlocale(LC_ALL,"");

    do{
        for (int i = 0; i < 5; i++){
            printf("Insira o %dº nome: ", i+1);
            scanf(" %s", &nomes[i][0]);
        }

        printf("        10        20        30        40        50\n12345678901234567890123456789012345678901234567890\n");
        printf("%7s%40s\n", nomes[0],nomes[4]);
        printf("%17s%20s\n", nomes[1],nomes[3]);
        printf("%27s\n", nomes[2]);
        
        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif // ex2
#ifdef ex3
int main(void){
    char c, x[11];
    setlocale(LC_ALL,"");

    do{
        printf("Digite uma string: ");
        scanf("%10s", &x);

        for(int i = 0; x[i] != '\0'; i++){
            if (x[i] >= 'a' && x[i] <= 'z')
            {
                x[i] += (-'a'+'A');
            }
            
        }
        printf("%s", x);

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif // ex3
#ifdef ex4
int main(void){
    char c, x[11];
    setlocale(LC_ALL,"");

    do{
        printf("Digite uma string: ");
        scanf("%10s", &x);

        for(int i = 0; x[i] != '\0'; i++){
            if (x[i] >= 'A' && x[i] <= 'Z')
            {
                x[i] += (+'a'-'A');
            }
            
        }
        printf("%s", x);

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif // ex4
#ifdef ex5
int main(void){
    char c, nomes [5][8];
    setlocale(LC_ALL,"");

    do{
        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif // ex5