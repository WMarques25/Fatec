#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int p;
int main(void)
{
    setlocale(LC_ALL, "");
    do{
    printf("T�st�\n");
    system("cls");
    printf("Este programa contem todos os exerc�cios da Lista 1 de Algoritmo\n");
    printf("Exerc�cios:\n");
    printf("EX 1 Antecessor/Sucessor                        EX 7 Calculo da M�dia Escolar\n");
    printf("EX 2 Reajuste +10%%                              EX 8 N > 50.000?             \n");
    printf("EX 3 Desconto de 9%%                             EX 9 S�o Multiplos?          \n");
    printf("EX 4 Sal�rio Professor                          EX 10 Infla��o de Produtos   \n");
    printf("EX 5 Carro Novo                                 EX 11 Maior N�mero           \n");
    printf("EX 6 Reajuste Sal�rial                          EX 12 M�dia + Conceito Escolar\n");
    printf("\nDigite o n�mero do exerc�cio: ");
    scanf("%d",&p);
    getchar();
    //
    if(p==1)
        ex1();
    else
    {
        if(p==2)
            ex2();
        else
        {
            if(p==3)
                ex3();
            else
            {
                if(p==4)
                    ex4();
                else
                {
                    if(p==5)
                        ex5();
                    else
                    {
                        if(p==6)
                            ex6();
                        else
                        {
                            if(p==7)
                                ex7();
                            else
                            {
                                if(p==8)
                                    ex8();
                                else
                                {
                                    if(p==9)
                                        ex9();
                                    else
                                    {
                                        if(p==10)
                                            ex10();
                                        else
                                        {
                                            if(p==11)
                                                ex11();
                                            else
                                            {
                                                if(p==12)
                                                    ex12();
                                                else
                                                    break;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    }while(p==0);
}
ex1()
{
    setlocale(LC_ALL, "Portuguese");
    int a,s,x;
    char z;
    do{
    system("cls");
    printf("Este programa mostra o sucessor e o antecessor do n�mero digitado.\n");
    printf("Digite o primeiro n�mero: ");
    scanf("%d",&x);
    a=x-1;
    s=x+1;
    printf("O antecessor �: %d\n",a);
    printf("O sucessor �: %d\n",s);
    printf("\n\nDeseja fazer outra consulta? ('N' para sair)\n\t");
    scanf("%c", &z);
    z=getchar();
    }while ((z!='n') && (z!='N'));
    printf("\n\n\t\tFIM\n\n");
    p=0;
}
ex2()
{
    setlocale(LC_ALL, "Portuguese");
    float x;
    char z;
    do{
    system("cls");
    printf("Este programa reajusta um valor em 10%%\n");
    printf("Digite um valor para ser reajustado: ");
    scanf("%f",&x);
    printf("O valor reajustado �: %.2f\n",x*1.1);
    printf("\n\nDeseja fazer outra consulta? ('N' para sair)\n\t");
    scanf("%c", &z);
    z=getchar();
    }while ((z!='n') && (z!='N'));
    printf("\n\n\tFIM\n\n");
    p=0;
}
ex3()
{
    setlocale(LC_ALL, "Portuguese");
    float x;
    char z;
    do{
    system("cls");
    printf("Este programa desconta 9%% do pre�o de um produto.\n");
    printf("Digite o pre�o do produto: R$");
    scanf("%f",&x);
    while(x<=0)
    {
        printf("Valor Inv�lido!");
        printf("Digite o pre�o do produto: R$");
        scanf("%f",&x);
    }
    printf("O valor com desconto �: R$%.2f\n",x*.91);

    printf("\nDeseja fazer outra consulta? ('N' para sair)\n\t");
    scanf("%c", &z);
    z=getchar();
    }while ((z!='n') && (z!='N'));
    printf("\n\n\tFIM\n");
    p=0;
}
ex4()
{
        setlocale(LC_ALL, "Portuguese");
    float x,i;
    int n;
    char z;
    do{
    system("cls");
    printf("Este programa calcula o sal�rio de professor.\n");
    printf("Insira o valor da Hora/Aula: R$");
    scanf("%f",&x);
    while(x<=0)
    {
        printf("Valor Inv�lido!");
        printf("Insira um valor maior que 0: R$");
        scanf("%f",&x);
    }
    printf("Insira a quantidade de aulas dadas: ");
    scanf("%d",&n);
    while(n<=0)
    {
        printf("Valor Inv�lido!");
        printf("Insira um valor maior que 0: ");
        scanf("%d",&n);
    }
    printf("Insira o percentual do INSS: ");
    scanf("%f",&i);
    while(i<=0)
    {
        printf("Valor Inv�lido!");
        printf("Insira um valor maior que 0: ");
        scanf("%f",&i);
    }
    printf("\nO sal�rio �: R$%.2f",(x*n*(1-(i/100))));
    printf("\n\nDeseja fazer outra consulta? ('N' para sair)\n\t");
    scanf("%c", &z);
    z=getchar();
    }while ((z!='n') && (z!='N'));
    printf("\n\n\tFIM\n");
    p=0;
}
ex5()
{
    float vfab, imp, luc;
    char zn;

    setlocale(LC_ALL, "");
    do{
    system("cls");
    printf("Este programa calcula o custo de um carro novo.\n");

    //Entrada Pre�o
    printf("Informe o pre�o de f�brica: R$");
    scanf("%f",&vfab);
    getchar();
    while(vfab<=0)
    {
        printf("Valor Inv�lido!\nInforme um valor maior que 0: R$");
        scanf("%f",&vfab);
        getchar();
    }

    //Entrada lucro
    printf("Informe o percentual de lucro: ");
    scanf("%f",&luc);
    getchar();
    while(luc<=0)
    {
        printf("Valor Inv�lido!\nInforme um valor maior que 0: ");
        scanf("%f",&luc);
        getchar();
    }

    //Entrada Lucro
    printf("Informe o percentual de impostos: ");
    scanf("%f",&imp);
    getchar();
    while(imp<=0)
    {
        printf("Valor Inv�lido!\nInforme um valor maior que 0: ");
        scanf("%f",&imp);
        getchar();
    }

    //Sa�da
    printf("O lucro do distribuidor �: R$%.2f",(vfab*(luc/100)));
    printf("\nO valor dos impostos �   : R$%.2f",(vfab*(imp/100)));
    printf("\nO valor final do carro � : R$%.2f",(vfab*(1+imp/100)*(1+luc/100)));

    printf("\n\nDeseja repetir? (S/N)\n");
    scanf("%c", &zn);
    getchar();

    }while ((zn != 'n') && (zn != 'N'));
   printf("\nfim \n");
    p=0;
}
ex6()
{
    float valor;
    char zn;

    setlocale(LC_ALL, "Portuguese");
    do{
    system("cls");
    printf("Este programa calcula o reajuste do sal�rio dependendo de seu valor.\n");
    printf("Insira o sal�rio para reajuste: R$");
    scanf("%f", &valor);
    getchar();
    while(valor<=0)
    {
        printf("Valor Inv�lido!");
        printf("\nInsira um sal�rio v�lido(>0): ");
        scanf("%f", &valor);
        getchar();
    }
    if(valor<800)
    {
        printf("De R$%.2f, o sal�rio foi reajustado para R$%.2f.",valor,valor*1.15);
    }
    else
    {
        if(valor>1000)
        {
            printf("De R$%.2f, o sal�rio foi reajustado para R$%.2f.",valor,valor*1.05);
        }
        else
        {
            printf("De R$%.2f, o sal�rio foi reajustado para R$%.2f.",valor,valor*1.1);
        }
    }

    printf("\nDeseja repetir? (S/N)\n");
    scanf("%c", &zn);
    getchar();

    }while ((zn != 'n') && (zn != 'N'));
   printf("\nfim \n");
    p=0;
}
ex7()
{
    float n1, n2, n3, n4, ma;
    char zn;

    setlocale(LC_ALL, "Portuguese");
    do{
    system("cls");
    printf("Este programa calcula a m�dia das notas de 4 avalia��es.\n");
   //Entrada de dados
   //N1
   printf("Insira a nota da Primeira Avalia��o: ");
   scanf("%f", &n1);
   getchar();
    while((10 < n1) || (n1 < 0))
      {
        printf("Valor Invalido! \n");
         printf("Insira um valor de 0 a 10: ");
         scanf("%f", &n1);
         getchar();
      }
   //N2
   printf("Insira a nota da Segunda Avalia��o: ");
   scanf("%f", &n2);
   while((10<n2) || (n2<0))
      {
         printf("Valor Invalido! \n");
         printf("Insira um valor de 0 a 10: ");
         scanf("%f", &n2);
         getchar();
      }
   //N3
   printf("Insira a nota da Terceira Avalia��o: ");
   scanf("%f", &n3);
   while((10<n3) || (n3<0))
      {
         printf("Valor Invalido! \n");
         printf("Insira um valor de 0 a 10: ");
         scanf("%f", &n3);
         getchar();
      }
   //n4
   printf("Insira a nota da Quarta Avalia��o: ");
   scanf("%f", &n4);
   while((10<n4) || (n4<0))
      {
         printf("Valor Invalido! \n");
         printf("Insira um valor de 0 a 10: ");
         scanf("%f", &n4);
         getchar();
      }
   //Processamento
   ma = ((n1+n2+n3+n4)/4);

   //Saida de dados
   printf("M�dia: %.2f\n", ma);
   if(ma>=6)
   {
      printf("Aprovado! \n");
   }
   else
   {
      printf("Reprovado! \n");
   }
    printf("\nDeseja repetir? (S/N)\n");
    scanf("%c", &zn);
    zn=getchar();

   }while ((zn != 'n') && (zn != 'N'));
   printf("\nfim \n");
    p=0;
}
ex8()
{
       float n1, n2, n3, n4, n5;
    char zn, x;

    setlocale(LC_ALL, "Portuguese");
    do{
            do{
    system("cls");
   //Entrada de dados
   //N1
   printf("Insira o Primeiro valor: ");
   scanf("%f", &n1);
   while ((25<=n1) || (n1<=10))
      {
        printf("Valor Invalido! \n");
         printf("Insira um valor maior que 10 e menor que 25: ");
         scanf("%f", &n1);
      }
      //N2
   printf("Insira o Segundo valor: ");
   scanf("%f", &n2);
   getchar();
    while(n2 < 0)
      {
        printf("Valor Invalido! \n");
         printf("Insira um valor maior que 0: ");
         scanf("%f", &n2);
         getchar();
      }
      //Processamento
      n3=n1+n2;
      n4=n1*n2*n3;
      n5=((n1*n1)+(n2*n2)+(n3*n3)+(n4*n4));
      if(n5<50000)
      {
          printf("\n\t(%.2f^2)+(%.2f^2)+(%.2f^2)+(%.2f^2) = %.2f < 50.000\n", n1,n2,n3,n4,n5);
          printf("Por favor insira novos valores.\n'ENTER' para continuar.");
          scanf("%c", &x);
      }
      else
      {
          printf("\n\t(%.2f^2)+(%.2f^2)+(%.2f^2)+(%.2f^2) = %.2f >= 50.000\n", n1,n2,n3,n4,n5);
          printf("Parabens! pressione 'ENTER' para sair.");
          scanf("%c", &x);

      }
    }while(n5<50000);
    printf("\nDeseja repetir? (S/N)\n");
    scanf("%c", &zn);
    getchar();

    }while ((zn != 'n') && (zn != 'N'));
    printf("\n\tFIM");
    p=0;
}
ex9()
{
    int a, b;
    char zn;
    setlocale(LC_ALL, "Portuguese");
    do{
    system("cls");
    printf("Este programa determina se dois valores s�o multiplos.\n");
    printf("Insira o primeiro n�mero: ");
    scanf("%d", &a);
    getchar();
    printf("Insira o segundo n�mero: ");
    scanf("%d", &b);
    getchar();
    if((a % b == 0)||(b % a == 0))
        {
        printf("\nOs n�meros s�o multiplos!");
    }
    else
    {
        printf("\nOs n�meros n�o s�o multiplos!");
    }
    printf("\nDeseja repetir? (S/N)\n");
    scanf("%c", &zn);
    getchar();
    }while ((zn != 'n') && (zn != 'N'));
    printf("\n\tFIM");
    p=0;
}
ex10()
{
    float valor;
    char zn;
    setlocale(LC_ALL, "Portuguese");
    //Loop
    do{
    system("cls");
    printf("Este programa calcula o pre�o reajustado de um produto.\n");
    //Entrada de dados
    printf("Insira o pre�o do produto: R$");
    scanf("%f", &valor);
    getchar();
    while(valor<=0)
    {
        printf("Pre�o Inv�lido");
        printf("Insira um valor maior que 0: R$");
        scanf("%f", &valor);
        getchar();
    }
    //Processamento
    if(valor<100)
        printf("\nPre�o reajustado: R$%.2f",valor*1.1);
    else
        printf("\nPre�o reajustado: R$%.2f",valor*1.2);
    //Loop ou fim
    printf("\nDeseja repetir? (S/N)\n");
    scanf("%c", &zn);
    getchar();
    }while ((zn != 'n') && (zn != 'N'));
    printf("\n\tFIM");
    p=0;
}
ex11()
{
//se��o de Declara��es das vari�veis
int n1, n2;
char zn;

    setlocale(LC_ALL, "Portuguese");
    do{
    system("cls");
    printf("Este programa determina o maior de dois n�meros\n");
    printf("Insira o primeiro n�mero: ");
    scanf("%d",&n1);
    getchar();
    printf("Insira o segundo n�mero : ");
    scanf("%d",&n2);
    getchar();
    if(n1>n2)
        printf("%d > %d",n1,n2);
    else
        if(n2>n1)
        printf("%d > %d",n2,n1);
    else
        printf("%d = %d",n1,n2);

    printf("\nDeseja repetir? (S/N)\n");
    scanf("%c", &zn);
    getchar();
    }while ((zn != 'n') && (zn != 'N'));
    printf("\n\tFIM");
    p=0;
}
ex12()
{
//se��o de Declara��es das vari�veis
int id;
float n1, n2, n3, me, ma;
char x, zn;

    setlocale(LC_ALL, "Portuguese");
    do{
            system("cls");
   //Entrada de dados  ID
   printf("Digite sua Identifica��o:");
   scanf("%d", &id);
   getchar();

   //N1
   printf("Insira a nota da Primeira Avalia��o:");
   scanf("%f", &n1);
   getchar();

    while((10 < n1) || (n1 < 0))
      {
        printf("Valor Invalido! \n");
         printf("Insira um valor de 0 a 10:");
         scanf("%f", &n1);
         getchar();
      }


   //N2
   printf("Insira a nota da Segunda Avalia��o:");
   scanf("%f", &n2);
   while((10<n2) || (n2<0))
      {
         printf("Valor Invalido! \n");
         printf("Insira um valor de 0 a 10:");
         scanf("%f", &n2);
         getchar();
      }

   //N3
   printf("Insira a nota da Terceira Avalia��o:");
   scanf("%f", &n3);
   while((10<n3) || (n3<0))
      {
         printf("Valor Invalido! \n");
         printf("Insira um valor de 0 a 10:");
         scanf("%f", &n3);
         getchar();
      }

   //ME
   printf("Insira a media dos exercicios:");
   scanf("%f", &me);
   while((10<me) || (me<0))
      {
         printf("Valor Invalido! \n");
         printf("Insira um valor de 0 a 10:");
         scanf("%f", &me);
         getchar();
      }

   //Processamento
   ma = ((n1+n2*2+n3*3+me)/7);
   if(ma >= 9.0)
    {
      x = 'A';
    }
   if(( 9 > ma ) && ( ma >= 7.5 ))
    {
      x = 'B';
    }
   if((7.5>ma) && (ma>=6))
    {
      x = 'C';
    }
   if((6>ma) && (ma>=4))
    {
      x = 'D';
    }
   if(4.0>ma)
    {
      x = 'E';
    }
   //Saida de dados
   printf("Aluno   : %d\n",id);
   printf("Nota   1: %.2f \n",n1);
   printf("Nota   2: %.2f \n",n2);
   printf("Nota   3: %.2f \n",n3);
   printf("Nota  EX: %.2f \n",me);
   printf("Media de Aproveitamento: %.2f  ===> ", ma);
   printf("%c \n", x);
   if(ma>=6)
   {
      printf("Aprovado! \n");
   }
   else
   {
      printf("Reprovado! \n");
   }
   printf("Deseja continuar? (S/N)\n");

   scanf("%c", &zn);
   zn = getchar();


   }while ((zn != 'n') && (zn != 'N'));
   printf("\nfim \n");
   p=0;
}
