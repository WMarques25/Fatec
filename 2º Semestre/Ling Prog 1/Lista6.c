#define ex5
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
int diasNoMes(int m, int a) {
    int dias;

    if (m == 2) {
        if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0) {
            dias = 29;
        } else {
            dias = 28;
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        dias = 30;
    } else {
        dias = 31;
    }

    return dias;
}

int main(void){
    char c, v;
    int d1,d2,d3,m1,m2,m3,a1,a2,a3;
    setlocale(LC_ALL, "");

    do{
        do{
            printf("Insira a data de nascimento (DD/MM/AAAA): ");
            scanf(" %2d/%2d/%4d",&d1,&m1,&a1);

            if(d1 > diasNoMes(m1, a1) || m1 > 12 || d1 < 1 || m1 < 1){
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
            if(d2 > diasNoMes(m2, a2) || m2 > 12 || d2 < 1 || m2 < 1){
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
            m2 -= 1;
            if (m2 < m1) {
                m2 += 12;
                a2 -= 1;
            }
            d3 = d2 + diasNoMes(m2, a2) - d1;
            m3 = m2 - m1;
            a3 = a2 - a1;
        }

        if(m3 < 0){
            a3--;
            m3 += 12;
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
int main(){
    int a, b;
    char c;
    do{
        printf("Insira o valor de 'a': ");
        scanf(" %d",&a);
        printf("Insira o valor de 'b': ");
        scanf(" %d",&b);

        printf(" Valor de 'a'= %3d         -->      0x%x\n",a , a);
        printf(" Valor de 'b'= %3d         -->      0x%x\n",b , b);
        printf(" Operadores bit-a-bit\n");
        printf(" AND                 a & b --> %3d  0x%x\n",a & b,a & b); /* 0x20 */
        printf(" OU                  a | b --> %3d  0x%x\n",a | b,a | b); /* 0x76 */
        printf(" OU EXCLUSIVO        a ^ b --> %3d  0x%x\n",a ^ b,a ^ b); /* 0x56 */
        printf(" NOT 'a'                ~a -->      0x%x\n",~a);
        printf(" NOT 'b'                ~b -->      0x%x\n",~b);

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;

}
#endif // ex4
#ifdef ex5
int main() {
    int d, m, a;
    char c;
    do{

        printf("Digite a data (DD/MM/AAAA): ");
        scanf(" %d/%d/%d", &d, &m, &a);

        int K = a % 100;
        int J = a / 100;

        int h = (d + (13*(m+1)/5) + K + (K/4) + (J/4) - 2*J) % 7;

        switch(h) {
            case 0:
                printf("Sábado\n");
                break;
            case 1:
                printf("Domingo\n");
                break;
            case 2:
                printf("Segunda\n");
                break;
            case 3:
                printf("Terça\n");
                break;
            case 4:
                printf("Quarta\n");
                break;
            case 5:
                printf("Quinta\n");
                break;
            case 6:
                printf("Sexta\n");
                break;
            default:
                printf("Erro\n");
                break;
        }

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif // ex5