#define ex4
#include <stdio.h>
#include <ctype.h>

#ifdef ex1
int main(void)
{
    char c;
    int h1, h2, m1, m2, s1, s2;

    do
    {
        system("cls");
        printf("Insira a quantidade de horas do primeiro instante: ");
        scanf(" %d", &h1);
        printf("Insira a quantidade de minutos do primeiro instante: ");
        scanf(" %d", &m1);
        printf("Insira a quantidade de segundos do primeiro instante: ");
        scanf(" %d", &s1);

        system("cls");
        printf("Insira a quantidade de horas do segundo instante: ");
        scanf(" %d", &h2);
        printf("Insira a quantidade de minutos do segundo instante: ");
        scanf(" %d", &m2);
        printf("Insira a quantidade de segundos do segundo instante: ");
        scanf(" %d", &s2);

        h1 *= 3600;
        m1 *= 60;
        s1 = s1 + m1 + h1;

        h2 *= 3600;
        m2 *= 60;
        s2 = s2 + m2 + h2;

        s1 = s2 - s1;
        h1 = s1 / 3600;
        m1 = (s1 % 3600) / 60;
        s1 = (s1 % 3600) % 60;

        printf("A duracao da ligacao eh de: %d horas %d minutos %d segundos.", h1, m1, s1);

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');
}
#endif // ex1
#ifdef ex2
int main(void)
{
    char c, s = 'x';
    do
    {
        int min = 1, max = 99, chute;
        printf("Pense em um numero entre 1 e 99.\n");
        system("pause");

        while (s != '=')
        {
            chute = (min + max) / 2;
            printf("O numero eh %d? ('=' / '>' / '<')\n", chute);
            scanf(" %c", &s);

            if (s == '=')
            {
                printf("Acertei!!\n");
            }
            else if (s == '<')
            {
                max = chute;
            }
            else if (s == '>')
            {
                min = chute;
            }
            else
            {
                printf("Opcao invalida\n");
            }
        }

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');
}
#endif // ex2
#ifdef ex3
int main(void)
{
    char c, s = 'x';
    do
    {
        int min = 1, max = 99, chute, tentativa = 0;
        printf("Pense em um numero entre 1 e 99.\n");
        system("pause");

        while (s != '=')
        {
            tentativa++;
            chute = (min + max) / 2;
            printf("O numero eh %d? ('=' / '>' / '<')\n", chute);
            scanf(" %c", &s);

            switch (s)
            {
            case '=':
                printf("Acertei!!\nTentativas: %d", tentativa);
                break;

            case '<':
                max = chute;
                break;

            case '>':
                min = chute;
                break;

            default:
                printf("Opcao invalida\n");
            }
        }

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');
}
#endif // ex3
#ifdef ex4

int main(void)
{

    char c;

    do
    {
        int i = 0, n = 0, soma = 0;
        float med;

        while (n >= 0)
        {

            printf("Digite um numero positivo: ");
            scanf(" %d", &n);

            if (n < 0)
                break;

            soma += n;
            i++;
        }
        med = (float)soma / (float)i;
        printf("A media dos %d eh %.2f", i, med);

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');
}
#endif // ex4
#ifdef ex5
int main(void)
{

    char c;

    do
    {
        int i = 0, n = 0, soma = 0;
        float med;

        while (n >= 0)
        {

            printf("Digite um numero positivo: ");
            scanf(" %d", &n);

            if (n < 0)
                break;

            soma += n;
            i++;
        }
        med = (float)soma / (float)i;
        printf("A media dos %d eh %.2f", i, med);

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');
}
#endif // ex5