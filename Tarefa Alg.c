#define ex2
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#ifdef ex1
// Exercício 3 da lista 2.
int main(void)
{
    int k,idade,soma=0,i=0;
    char zn;
    setlocale(LC_ALL,"portuguese");
    do{
        system("cls");
        printf("Este programa calcula a soma de k idades.\n");
        printf("Insira a quantidade(k) de idades que serão somadas: ");
        scanf(" %d",&k);
        while(k<0)
        {
            printf("Insira um valor positivo para k.");
            scanf(" %d",&k);
        }
        for(i;i<k;)
        {
            i++;
            printf("\tDigite a %dª idade: ",i);
            scanf(" %d",&idade);
            while(idade<0)
            {
                printf("\t\tA idade deve ser um valor positivo.");
                printf("\n\tDigite a %dª idade: ",i);
                scanf(" %d",&idade);
            }
            soma += idade;
        }
        printf("\nA soma das idades é: %d",soma);

    printf("\nDeseja repetir? (S/N)\n");
    scanf(" %c", &zn);
    }while ((zn != 'n') && (zn != 'N'));
    printf("\n\tFIM");
    return 0;
}
#endif // ex1
#ifdef ex2
char x;
p1()
{
    int a,s,n;
    char z;
    do{
    system("cls");
    printf("Este programa mostra o sucessor e o antecessor do número digitado.\n");
    printf("Digite o número: ");
    scanf(" %d",&n);
    a=n-1;
    s=n+1;
    printf("O antecessor é: %d\n",a);
    printf("O sucessor é: %d\n",s);
    printf("\n\nDeseja fazer outra consulta? ('N' para sair)\n\t");
    scanf(" %c", &z);
    }while ((z!='n') && (z!='N'));
    printf("Digite 'S' para voltar ao menu.\n");
    scanf(" %c",&x);
    x = toupper(x);
}
p2()
{

    setlocale(LC_ALL, "Portuguese");
    float d,v;
    char z;
    do{
    system("cls");
    printf("Este programa desconta X%% do preço de um produto.\n");
    printf("Digite o preço do produto: R$");
    scanf(" %f",&v);
    while(v<=0)
    {
        printf("Valor Inválido!\n");
        printf("Digite o preço do produto: R$");
        scanf(" %f",&v);
    }
    printf("Digite o valor do desconto(%%): ");
    scanf(" %f",&d);
    while((d<0)||(d>100))
    {
        printf("Valor Inválido!\n");
        printf("Digite um valor de 0 a 100: ");
        scanf(" %f",&d);
    }
    printf("O valor com desconto é: R$%.2f\n",v*(1-d/100));

    printf("\nDeseja fazer outra consulta? ('N' para sair)\n\t");
    scanf(" %c", &z);
    }while ((z!='n') && (z!='N'));
    printf("Digite 'S' para voltar ao menu.\n");
    scanf(" %c",&x);
    x = toupper(x);
}
p3()
{
    int n,m,n1,m1,k,i;
    float soma,prod,media;
    char z;
    do{
        i=0;
        n=0;
        n1=1;
        m1=1;
        m=0;
        soma=0;
        prod=1;
        system("cls");
        printf("Este programa gera uma sequencia de (n/m) com k termos, sendo n+2 e m+5,\ne retorna a soma, média e o produto dos k termos.\n");
        printf("\nDigite a quantidade de termos(k) da sequencia: ");
        scanf(" %d",&k);
        while(k<0)
        {
            printf("\nO número de termos deve ser positivo.");
            printf("\nDigite a quantidade de termos(k) da sequencia: ");
            scanf(" %d",&k);
        }
        for(i;i<k;i++)
        {
            n+=2;
            m+=5;
            n1=n1*2;
            m1=m1*5;
            soma=soma+(0.4);
            prod=prod*(0.4);
        }

        media=soma/k;
        if(k==0)
        media=0;
        printf("\n\tA soma dos %d termos é   : %g\t %d/%d",k,soma,n,5);
        printf("\n\tA média dos %d termos é  : %.1g\t %d/%d",k,media,2,5);
        printf("\n\tO produto dos %d termos é: %g\t %d/%d",k,prod,n1,m1);
        printf("\n\nDeseja fazer outra consulta? ('N' para sair)\n\t");
        scanf(" %c", &z);
    }while (( z != 'n' ) && ( z != 'N' ));
    printf("Digite 'S' para voltar ao menu.\n");
    scanf(" %c",&x);
    x = toupper(x);
}
int main(void)
{
    int op;
    char zn;
    setlocale(LC_ALL,"portuguese");
    do{
        x='S';
        system("cls");
        printf("Selecione um dos 3 programas a seguir:\n");
        printf("\t+--------------------------------+\n");
        printf("\t|* 1 --> Antecessor e Sucessor. *|\n");
        printf("\t|* 2 --> Desconto em produtos.  *|\n");
        printf("\t|* 3 --> Calculo de sequencia.  *|\n");
        printf("\t+--------------------------------+\n");
        printf("Digite o número do programa desejado ou qualquer outro número para sair.\n");
        scanf(" %d",&op);
        switch(op)
        {
            case 1:
            p1();
            break;

            case 2:
            p2();
            break;

            case 3:
            p3();
            break;

            default:
            x='b';
            break;
        }
    }while(x=='S');
    return 0;
}
#endif
