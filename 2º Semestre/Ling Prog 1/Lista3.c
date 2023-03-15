#define ex5
#include <stdio.h>
#include <ctype.h>
#include <locale.h>

#ifdef ex1
int verifica(int a)
{
    if (a == 0)
    {
        return -1;
    }
    else if (a < 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int soma(int a, int b)
{
    int somat = 0;

    if (a < b)
    {
        for (a; a + 1 < b;)
        {
            a++;
            somat += a;
        }
    }
    else if (a > b)
    {
        for (b; b + 1 < a;)
        {
            b++;
            somat += b;
        }
    }

    return somat;
}

int mult(int a, int b)
{
    int multi = 1;
    if (a < b)
    {
        for (a; a + 1 < b;)
        {
            a++;
            multi *= a;
        }
    }
    else if (a > b)
    {
        for (b; b + 1 < a;)
        {
            b++;
            multi *= b;
        }
    }

    return multi;
}

float div(int a, int b)
{

    return ((float)a / (float)b);
}

int main(void)
{
    char c;

    do
    {
        int x, y, v1, v2;
        system("cls");

        printf("Digite o primeiro numero: ");
        scanf(" %d", &x);
        v1 = verifica(x);

        printf("Digite o segundo numero: ");
        scanf(" %d", &y);
        v2 = verifica(y);

        if (v1 == 1 && v2 == 1)
        {
            printf("A soma dos numeros entre %d e %d eÂ´ %d", x, y, soma(x, y));
        }
        else if (v1 == 0 && v2 == 0)
        {
            printf("A multiplicacao dos numeros entre %d e %d eÂ´ %d", x, y, mult(x, y));
        }
        else if ((v1 == 1 && v2 == 0) || (v1 == 0 && v2 == 1))
        {
            printf("A divisao dos numeros entre %d e %d eÂ´ %f", x, y, div(x, y));
        }

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif // ex1
#ifdef ex2
int func(int x)
{
    int soma = 0;
    // for de fatorial
    for (int i = x - 1; i > 1; i--)
    {
        x *= i;
        printf(" %d", x); // remover
    }
    // for de soma dos alg (y = x % 10; soma += y; x = x/10)
    while (x > 0)
    {
        soma += x % 10;
        x /= 10;
    }
    return soma;
}

int main(void)
{
    char c;
    int x;

    do
    {
        system("cls");
        printf("Digite um numero: ");
        scanf(" %d", &x);

        printf("A soma dos algarismos do fatorial de %d eh: %d", x, func(x));

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif // ex2
#ifdef ex3
int Soma(int x, int y)
{
    return (x + y);
}
int Sub(int x, int y)
{
    return (x - y);
}
int Mult(int x, int y)
{
    return (x * y);
}
float Div(int x, int y)
{
    return ((float)x / (float)y);
}

int main(void)
{
    int x, y;
    char c;
    do
    {
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
#endif // ex3
#ifdef ex4

int nums[999];

int Soma(int n){
    int soma = 0;
    for (int i = 0; i <= n; i++){
        soma += nums[i];
    }
    return soma;
}
int Sub(int n){
    int sub = 0;
    for (int i = 0; i <= n; i++){
        sub -= nums[i];
    }
    return sub;
}
int Mult(int n){
    int mult = 1;
    for (int i = 0; i <= n; i++){
        mult *= nums[i];
    }
    return mult;
}
float Div(int n){
    float div = 1;
    for (int i = 0; i <= n; i++){
        div /= (float)nums[i];
    }
    return div;
}

int main(void){

    char c, l;
    do{
        system("cls");
        int n = 0;

        for (n = 0; n < 999 ;n++){
            printf("Digite o %dº valor: ", n + 1);
            scanf(" %d", &nums[n]);
            printf("Deseja inserir mais um valor? ('N' para sair) ");
            scanf(" %c", &l);
            
            if (toupper(l) == 'N')
                break;
        }

        printf("Os resultados:\nSoma =          %d\nSubtracao =     %d\nMultiplicacao = %d\nDivisao =       %.2f", Soma(n), Sub(n), Mult(n), Div(n));

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif // ex4
#ifdef ex5
float Soma(float x, int y){
    return (x + (float)y);
}
float Sub(float x, int y){
    return (x - (float)y);
}
float Mult(float x, int y){
    return (x * (float)y);
}
float Div(float x, int y){
    return ((float)x / (float)y);
}
int main(void){
    char c;

    setlocale(LC_ALL, "");

    do{
        system("cls");
        float res = 0;
        int x;
        char op;

        printf("Para sair da calculadora digite 'X' na opção\n");

        for (;;){
            printf("Resultado:\t\t\t\t%.2f\n", (float)res);
            printf("Selecione a operação (+, -, *, /, c):\t");
            scanf(" %c", &op);

            if(toupper(op) == 'C' ){
                res = 0;
                continue;
            }

            printf("Digite o numero para fazer a operação:  ");
            scanf(" %d", &x);
            switch (op){
                case '+':
                res = Soma(res, x);
                break;
                
                case '-':
                res = Sub(res, x);
                break;

                case '*':
                res = Mult(res, x);
                break;

                case '/':
                res = Div(res, x);
                break;

            }
            if(toupper(op) == 'X'){
                break;
            }
        }

            printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif // ex5
