#define ex3
#include <stdio.h>
#include <ctype.h>
#include <locale.h>

#ifdef ex1
int Soma(int x, int y){
    return (x + y);
}
int Sub(int x, int y){
    return (x - y);
}
int Mult(int x, int y){
    return (x * y);
}
float Div(int x, int y){
    return ((float)x / (float)y);
}

int main(void){
    int x, y;
    char c;
    do{
        setlocale(LC_ALL, "");
        system("cls");
        printf("Digite o primeiro valor: ");
        scanf(" %d", &x);
        printf("Digite o segundo valor: ");
        scanf(" %d", &y);

        printf("Os resultados:\nSoma =          %d\nSubtracao =     %d\nMultiplicacao = %d\nDivisao =       %f", Soma(x, y), Sub(x, y), Mult(x, y), Div(x, y));

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif // ex1
#ifdef ex2
int Soma(int x, int y){
    x += y;
    return x;
}
int Sub(int x, int y){
    x -= y;
    return x;
}
int Mult(int x, int y){
    x *= y;
    return x;
}
float Div(int x, int y){
    (float)x /= (float)y;
    return x;
}

int main(void){
    int x, y;
    char c;
    do{
        setlocale(LC_ALL, "");
        system("cls");
        printf("Digite o primeiro valor: ");
        scanf(" %d", &x);
        printf("Digite o segundo valor: ");
        scanf(" %d", &y);

        printf("Os resultados:\nSoma =          %d\nSubtracao =     %d\nMultiplicacao = %d\nDivisao =       %f", Soma(x, y), Sub(x, y), Mult(x, y), Div(x, y));

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif // ex2
#ifdef ex3
int toDia(int dia, int mes, int ano){
    
}
int main(void){
    char c, v;
    int d1,d2,d3,m1,m2,m3,a1,a2,a3;
    setlocale(LC_ALL, "");
    
    do{
        do{
            printf("Insira a data de nascimento (DD/MM/AAAA): ");
            scanf(" %2d/%2d/%4d",&d1,&m1,&a1);
            if(d1 >= 32 || m1 >= 13 || d1 < 1 || m1 < 0){
                printf("Data inválida.");
                v = 'i';
            } else{
                v = 'v';
            }
        }while(v == 'i');
        system("cls");

        do{
            printf("Insira a data de hoje (DD/MM/AAAA): ");
            scanf(" %2d/%2d/%4d",&d2,&m2,&a2);
            if(d2 >= 32 || m2 >= 13 || d2 < 1 || m2 < 0){
                printf("Data inválida.");
                v = 'i';
            } else{
                v = 'v';
            }
        }while(v == 'i');
        system("cls");

        printf("Nasc: %2d/%2d/%4d\n",d1,m1,a1);
        printf("Hoje: %2d/%2d/%4d\n",d2,m2,a2);

        d3 = d2 - d1;
        m3 = m2 - m1;
        a3 = a2 - a1;

        if(d3 < 0){
            d3 = 31 + d3;
            m3 -= 1;
            if(m3 < 1)
                m3 = 12 + m3;

            if(m3 > 11)
                m3 = 0;
                a3 += 1;
        }
        if(m3 < 1){
            a3 -= 1;
        }

        printf("Idade: %d Dias %d Meses %d Anos", d3, m3, a3);

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