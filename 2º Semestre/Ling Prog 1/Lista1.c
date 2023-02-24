#define ex5
#include <stdio.h>
#include <locale.h>

#ifdef ex1
int main(void)
{
    int Input, s, m, h;

    do
    {
        printf("Insira um valor positivo em segundos(s): ");
        scanf("%d", &Input);
    } while (Input < 0);
    m = Input / 60;
    h = m / 60;
    m = m % 60;
    s = Input % 60;
    printf("\n%dh %dm %ds.", h, m, s);

    return 0;
}
#endif // ex1
#ifdef ex2
int main(void)
{
    int i;
    float f;
    short s;
    long l;
    double d;
    char c;

    printf("Insira um valor do tipo short: ");
    scanf(" %hd", &s);
    printf("Insira um valor do tipo long: ");
    scanf(" %ld", &l);
    printf("Insira um valor do tipo int: ");
    scanf(" %d", &i);
    printf("Insira um valor do tipo float: ");
    scanf(" %f", &f);
    printf("Insira um valor do tipo double: ");
    scanf(" %lf", &d);
    printf("Insira um valor do tipo char: ");
    scanf(" %c", &c);

    printf("        10        20        30        40        50        60\n");
    printf("12345678901234567890123456789012345678901234567890123456789012345\n");
    printf("%9hd%19ld%19d\n", s, l, i);
    printf("%19f%21f%18c\n", f, d, c);

    return 0;
}
#endif // ex2
#ifdef ex3
int main(void)
{
    int min, mult, i;

    printf("Insira o valor do multiplo: ");
    scanf(" %d", &mult);
    printf("Insira o valor do minimo: ");
    scanf(" %d", &min);
    i = min;

    do
    {
        printf("%d\n", i);
        i++;
    } while (i % mult != 0);
    printf("O menor multiplo de %d, acima de %d, eh %d.", mult, min, i);
}
#endif // ex3
#ifdef ex4
int main()
{
    setlocale(LC_ALL, "");
    int x, y;

    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de y: ");
    scanf("%d", &y);
    printf("a = %d, b = %d\n", x, y);

    x = x + y;
    y = x - y;
    x = x - y;
    printf("Depois da permutação: a = %d, b = %d\n", x, y);

    return 0;
}
#endif // ex4
#ifdef ex5
int main(void)
{
    int x, x1, x2, x3, y;
    setlocale(LC_ALL, "");
    do
    {
        printf("Insira um número de 3 digitos: ");
        scanf(" %d", &x);
    } while (x < 100 || x > 999);
    x1 = x / 100;
    x2 = (x % 100) / 10;
    x3 = x % 10;
    y = x3 * 100 + x2 * 10 + x1;
    printf("%d --> %d", x, y);

    return 0;
}
#endif // ex5