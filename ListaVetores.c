#define ex8
#include <stdio.h>
#include <locale.h>
#include <ctype.h>

#ifdef ex1
int main(void)
{
    setlocale(LC_ALL,"");
    float v[15];
    int i;
    for(i=0;i<15;i++)
    {
        printf("Digite o %dï¿½ nï¿½mero: ",i+1);
        scanf(" %f",&v[i]);
    }
    system("cls");
    printf("v[15] = {");
    for(i=0;i<15;i++)
    {
        if(i<14)
        {
            printf(" %.2f ,",v[i]);
        }
        else
        {
            printf(" %.2f }",v[i]);
        }
    }
    return 0;

}
#endif // ex1
#ifdef ex2
int main(void)
{
    setlocale(LC_ALL,"");
    int A[12],i=0,x=0;
    for(i=0;i<12;i++)
    {
        printf("Insira o %dï¿½ nï¿½mero: ",i+1);
        scanf(" %d",&A[i]);
        while(A[i]<=0)
        {
            printf("insira valores positivos!\n");
            scanf(" %d",&A[i]);
        }
        if(A[i]<=121)
            x+=1;
    }
    system("cls");
    if(x == 12)
        printf("Nenhum dos nï¿½meros digitados ï¿½ maior que 121.\n");
    else
    {
        printf("Os nï¿½meros maiores que 121 sï¿½o: \n");
        for(i=0;i<12;i++)
        {
            if(A[i]>121)
                printf("A[%d] = %d\n",i,A[i]);
        }
    }
    return 0;
}
#endif // ex2
#ifdef ex3
int main(void)
{
    setlocale(LC_ALL,"");
    int A[8],B[8],i;
    for(i=0;i<8;i++)
    {
        printf("Insira o %dï¿½ valor: ",i+1);
        scanf(" %d",&A[i]);
        B[i] = A[i]*3;
    }
    system("cls");
    for(i=0;i<8;i++)
    {
        printf("A[%d] = %d\tB[%d] = %d\n",i,A[i],i,B[i]);
    }
    return 0;
}
#endif // ex3
#ifdef ex4
int main(void)
{
    setlocale(LC_ALL,"");
    float A[6],somq=0;
    int i;
    do{
        system("cls");
        for(i=0;i<6;i++)
        {
            printf("Insira o %dï¿½ nï¿½mero: ",i+1);
            scanf(" %f",&A[i]);
            while(A[i]>=0)
            {
                printf("Insira apenas nï¿½meros negativos.\n");
                printf("Insira o %dï¿½ nï¿½mero: ",i+1);
                scanf(" %f",&A[i]);
            }
            somq+=(A[i]*A[i]);
        }
        if(somq < 1000)
        {
            printf("\nSoma dos quadrados ï¿½ menor que 1000.\nInsira novos dados.\n");
            system("Pause");
        }
    }while(somq < 1000);
    printf("\nA soma dos quadrados ï¿½: %.2f",somq);
    return 0;
}
#endif // ex4
#ifdef ex5
int main(void)
{
    setlocale(LC_ALL, "");
    float n[10],maior=0;
    int i,x=0,s=0;

    for(i=0;i<10;i++)
    {
        do{
        printf("Digite o %dï¿½ nï¿½mero: ",i+1);
        scanf(" %f",&n[i]);
        if(n[i]<0)
        {
            printf("Apenas nï¿½meros positivos!");
        }
        }while(n[i]<0);
    }
    system("cls");
    printf("n[10] = {");
    for(i=0;i<10;i++)
    {
        if(i<9)
        {
            printf(" %.2f ,",n[i]);
        }
        else
        {
           printf(" %.2f }",n[i]);
        }
    }
    for(i=0;i<10;i++)
    {
        if(n[i]>maior)
        {
            maior = n[i];
        }
    }
    for(i=0;i<10;i++)
    {
        if(maior == n[i])
        {
            x++;
        }
    }
    printf("\nO maior nï¿½mero ï¿½ %.2f, e foi digitado %d vezes nas posiï¿½ï¿½es:\n",maior,x);
    for(i=0;i<10;i++)
    {
        if(maior == n[i])
        {
            s++;
            if(s<x)
            {
            printf("n[%d], ",i);
            }
            else
            {
                printf("n[%d].",i);
            }
        }
    }
    return 0;
}
#endif // ex5
#ifdef ex6
int A[15],B[15];
int i,y,z=0;
char xx;

int main(void)
{
    setlocale(LC_ALL,"");
    for(i=0;i<15;i++)
    {

        z++;
        printf("Digite o %dï¿½ nï¿½mero: ",i+1);
        scanf(" %d",&A[i]);
        system("cls");
        printf("Vocï¿½ digitou %d nï¿½meros",z);
        printf("\nDeseja digitar mais um nï¿½mero? ('S' = sim)\n");
        scanf(" %c", &xx);
        xx = toupper(xx);
        if(xx != 'S')
        {
            break;
        }
    }
    for(i = 0 ; i < z ; i++)
    {
        B[i] = 1;
    }

    for(i=0;i<z;i++)
    {
        y=A[i];
        for(y;y>0;y--)
        {
            B[i]=y*B[i];
        }
    }
    printf("A[%d] = {",z);
    for(i=0;i<z;i++)
    {
        printf(" %d ,",A[i]);
    }
    printf("\b}\n");

    printf("B[%d] = {",z);
    for(i=0;i<z;i++)
    {
        printf(" %d ,",B[i]);
    }
    printf("\b}\n");
    return 0;
}
#endif // ex6
#ifdef ex7
int A[999],B[999];
int i=0,y=0,z=0;
char xx;

int main(void)
{
    setlocale(LC_ALL,"portuguese");
    for(;;)
    {
        do{
        printf("Digite o %dï¿½ nï¿½mero: ",i+1);
        scanf(" %d",&A[z]);
        if((A[z]<=4)||(A[z]>20))
        {
            printf("\tDigite um nï¿½mero maior que 4 e menor ou igual a 20.\n");
        }
        }while((A[z]<=4)||(A[z]>20));
        system("cls");
   //     printf("%d",A[z-1]);
        printf("Vocï¿½ digitou %d nï¿½meros",z+1);
        printf("\nDeseja digitar mais um nï¿½mero? ('S' = sim)\n");
        scanf(" %c", &xx);
        xx = toupper(xx);
        if(xx != 'S')
        {
            break;
        }
        z++;
        i++;
    }

    for(i;i>=0;i--)
    {
        B[y]=A[i];
       // printf("%d | %d\n",B[y],A[i]);
        y++;
    }
    printf("A[%d] = {",z+1);
    for(i=0;i<=z;i++)
    {
        printf(" %d ,",A[i]);
    }
    printf("\b}\n");

    printf("B[%d] = {",z+1);
    for(i=0;i<=z;i++)
    {
        printf(" %d ,",B[i]);
    }
    printf("\b}\n");
    system("pause");
    return 0;
}
#endif // ex7
#ifdef ex8
float A[5],B[5],C[5],D[15];
int i=0,x=0;

int main(void)
{
    system("cls");
    setlocale(LC_ALL,"portuguese");
    printf("Insira os valores do vetor A:\n");
    for ( i = 0; i < 5; i++)
    {
        printf("%dï¿½: ",i+1);
        scanf(" %f",&A[i]);
    }
    system("cls");
    printf("Insira os valores do vetor B:\n");
    for ( i = 0; i < 5; i++)
    {
        printf("%dï¿½: ",i+1);
        scanf(" %f",&B[i]);
    }
    system("cls");
    printf("Insira os valores do vetor C:\n");
    for ( i = 0; i < 5; i++)
    {
        printf("%dï¿½: ",i+1);
        scanf(" %f",&C[i]);
    }
    system("cls");
    for ( i = 0; i < 5; i++)
    {
        D[x] = A[i];
        x++;
        D[x] = B[i];
        x++;
        D[x] = C[i];
        x++;
    }
    x=0;

    printf("A[%d] = {",5);
    for(i = 0; i < 5; i++)
    {
        printf(" %g ,",A[i]);
    }
    printf("\b}\n");
    printf("B[%d] = {",5);
    for(i = 0; i < 5; i++)
    {
        printf(" %g ,",B[i]);
    }
    printf("\b}\n");
    printf("C[%d] = {",5);
    for(i = 0; i < 5; i++)
    {
        printf(" %g ,",C[i]);
    }
    printf("\b}\n");

    printf("D[%d] = {",15);
    for(i = 0; i < 15; i++)
    {
        printf(" %g ,",D[i]);
    }
    printf("\b}\n");
    x=0;
    for ( i = 0; i < 15; i++)
    {
        if(D[i]<0)
        {
            x++;
        }
    }
    printf("O vetor D[15] possui %d nï¿½meros negativos.\n",x);
    system("pause");
    return 0;
}
#endif // ex8
#ifdef ex9
float A[10],B[10];
int i=0;

ScanP()
{
    float X;
    do{
        printf("Insira o %dº valor: ",i+1);
        scanf(" %f",&X);
        if(X[i]<0)
        {
            printf("Apenas valores positivos.\n");
        }
    }while(X[i]<0);
    return X;
}

int main(void)
{
    setlocale(LC_ALL,"");
    for(i;i<10;i++)
    {
        A[i] = ScanP();
        B[i] = A[i]/2;
    }
    
    return 0;
}
#endif