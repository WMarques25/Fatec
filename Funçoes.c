#define ex8
#include <stdio.h>
#include <locale.h>
#include <locale.h>
#include <ctype.h>

#ifdef ex1

void verifica(int a)
{
   if(a<0)
   {
      printf("O nùmero digitado ù negativo.\n");
   }
   else
   {
      if(a>0)
      {
         printf("O nùmero digitado ù positivo.\n");
      }
      else
      {
         printf("O nùmero digitado ù 0.\n");
      }
   }
}

int main(void)
{
    int a;
    setlocale(LC_ALL,"");
    printf("Digite um nùmero inteiro: ");
    scanf(" %d", &a);
    verifica(a);
    return 0;
}
#endif // ex1
#ifdef ex2
float divisao(float a, float b)
{
    a = a/b;
    return a;
}

int check(float a)
{
    if(a==0)
    {
        printf("Digite um nùmero diferente de 0.\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

 ex6
 int main(void)
{
    float x, y, div;
    int z;
    setlocale(LC_ALL, "");
    do{
    printf("Digite o primeiro nùmero: ");
    scanf(" %f",&x);
    z = check(x);
    }while(z == 0);
    do{
    printf("Digite o segundo nùmero: ");
    scanf(" %f",&y);
    z = check(y);
    }while(z == 0);
    div = divisao(x,y);
    printf("O resultado da divisùo de %g por %g ù igual a %g.\n", x, y, div);
    return 0;
}

#endif // ex2
#ifdef ex3
int notas(float a)
{
    if((a<0) || (a>10))
    {
        printf("Apenas valores entre 0 e 10.\n");
        return 0;
    }
    else
    {
        return 1;
    }
}

float media(float x1, xloat n2, float n3, float n4)
{
    return (x1+nx+n3+n4)/4;
}

 ex6
 int main(void)
{
    char x;
    float x1,nx,n3,n4,med;
    int z=0;

    setlocale(LC_ALL, "");
    do{
        system("cls");

        // NOTA 1
        while(z == 0){
        printf("Digite a primeira nota: ");
        scanf(" %f", &x1);x        z = notas(x1);x        }
        z = 0;

        // NOTA 2
        while(z == 0){
        printf("Digite a segunda nota: ");
        scanf(" %f", &n2);
        z = notas(n2);
        }
        z = 0;

        // NOTA 3
        while(z == 0){
        printf("Digite a terceira nota: ");
        scanf(" %f", &n3);
        z = notas(n3);
        }
        z = 0;

        // NOTA 4
        while(z == 0){
        printf("Digite a quarta nota: ");
        scanf(" %f", &n4);
        z = notas(n4);
        }
        z = 0;

        // MùDIA
        med = media(x1,nx,n3,n4);
        if(med>=6)
        {
            printf("\nMùdia = %.2f.\nAprovado.\n",med);
        }
        else
        {
            printf("\nMùdia = %.2f.\nReprovado.\n",med);
        }

        printf("\nDeseja realisar outra verificaùùo? ('S' = SIM)\n");
        scanf(" %c",&x);
        x = toupper(x);
    }while(x == 'S');
    return 0;
}
#endif // ex3
#ifdef ex4

#endif // ex4
#ifdef ex5

#endif // ex5
// Tarefa algoritmo
#ifdef ex6
float positivo(void)
{
    float x;
    do{
        scanf(" %f",&x);
        if(x<=0)
        {printf("\tValor inv·lido!\n\tDigite um valor maior que zero.");}
    }while(x<=0);
    return x;
}

int Existencia_Triangulo(float x1, float x2, float x3)
{
    if(x1 > (x2+x3))
        {printf("\n\tTri‚ngulo inv·lido.\n\tUm dos lados È maior qua a soma dos outros.");
        return 0;}
    else
    {
        if(x2 > (x1+x3))
            {printf("\n\tTri‚ngulo inv·lido.\n\tUm dos lados È maior qua a soma dos outros.");
            return 0;}
        else
        {
            if(x3 > (x1+x2))
                {printf("\n\tTri‚ngulo inv·lido.\n\tUm dos lados È maior qua a soma dos outros.");
                return 0;}
            else
                return 1;
        }
    }
    
}

void exiba(float x1,float x2,float x3)
{
    if((x1==x2)&&(x1==x3))
        {
            printf("\nEste tri‚ngulo È equil·tero!\n");
        }
        else
        {
            if(((x1==x2)||(x2==x3))||(x1==x3))
                printf("\nEste tri‚ngulo È isÛcele!\n");
            else
                printf("\nEste tri‚ngulo È escaleno!\n");
        }
}

int main(void)
{
    float t1 = 0, t2 = 0, t3= 0;
    int triangulo = 0;

    setlocale(LC_ALL, "");
    do{
        system("cls");
        printf("Este programa verifica se um tri‚ngulo È isÛscele, equil·tero ou escaleno.");
        printf("\nInforme o tamanho do primeiro lado: ");
        t1 = positivo();
        printf("\nInforme o tamanho do segundo lado: ");
        t2 = positivo();
        printf("\nInforme o tamanho do terceiro lado: ");
        t3 = positivo();
        triangulo = Existencia_Triangulo(t1,t2,t3);
    }while(triangulo == 0);
    exiba(t1, t2, t3);
    system("pause");
    return 0;
}
#endif // ex6
#ifdef ex7
float positivo(void)
{
    float x;
    do{
        scanf(" %f",&x);
        if(x<=0)
        {printf("\tValor inv·lido!\n\tDigite um valor maior que zero.");}
    }while(x<=0);
    return x;
}

char Sexo()
{
    char x;
    do{
        scanf(" %c",&x);
        x = toupper(x);
        if((x != 'F')&&(x != 'M'))
            printf("Digite apenas 'F' ou 'M': ");
    }while((x != 'F')&&(x != 'M'));
    return x;
}

classifica(float imc)
{
if(imc<17)
    printf("Muito abaixo do peso!\n");
else
    if(imc<18.49)
        printf("Abaixo do peso!\n");
    else
        if(imc<24.99)
            printf("Peso normal!\n");
        else
            if(imc<29.99)
                printf("Acima do peso!\n");
            else
                if(imc<34.99)
                    printf("Obesidade 1!\n");
                else
                    if(imc<39.99)
                        printf("Obesidade 2!\n");
                    else
                        printf("Obesidade 3!\n");
}

peso(char x, float a)
{
    if(x == 'F')
    {printf("\nSeu peso ideal È: %.2fkg",((62.1*a)-44.7));}
    else
    {printf("\nSeu peso ideal È: %.2fkg",((72*a)-58));}
}

int main(void)
{
    float p, a, imc;
    char zn, sexo;

    setlocale(LC_ALL,"Portuguese");
    do{
        system("cls");
        printf("Este programa calcula o IMC e o peso ideal de um adulto.\n");
        printf("Insira o peso(kg): ");
        p = positivo();
        printf("Insira a altura(m): ");
        a = positivo();
        printf("Insira 'F' para Femininno ou 'M' para Masculino: ");
        sexo = Sexo();
        imc=p/(a*a);
        peso(sexo, a);
        printf("\nSeu IMC È: %.2f. - ", imc);
        classifica(imc);
    printf("\nDeseja repetir? (S/N)\n");
    scanf(" %c", &zn);
    }while ((zn != 'n') && (zn != 'N'));
    printf("\n\tFIM");
    return 0;
}
#endif // ex7
#ifdef ex8

float Sal[10], SalNovo[10];

void sal(int k)
{
    int i=0;
    for(i; i<k; i++)
    {
        system("cls");
        do{
        printf("Digite o sal·rio do %d∫ funcion·rio: R$",i+1);
        scanf(" %f",&Sal[i]);
        if (Sal[i]<=0)
        {
            printf("Digite um valor maior que 0.\n");
        }
        }while(Sal[i]<=0);
    }
}

void ReajSalNovo(int k)
{
    int i=0;
    for(i=0; i<k; i++)
    {
        if(Sal[i]<800)
            {SalNovo[i]=1.15*Sal[i];}
        else
            if(Sal[i]>1000)
                {SalNovo[i]=1.05*Sal[i];}
            else
                SalNovo[i]=1.1*Sal[i];
    }
}

int main(void)
{
    int k=0, i;

    setlocale(LC_ALL, "");
    printf("Este programa reajusta o sal·rio de atÈ 10 funcion·rios.\n");
    printf("Digite a quantidade de funcion·rios que deseja reajustar o sal·rio.\nMax 10 : ");
    while(k<=0||k>10)
    {
        scanf("%d",&k);
        printf("\tDigite um valor v·lido.\n");
    }
    sal(k);
    ReajSalNovo(k);
    system("cls");
    printf("* Funcion·rios  |  Sal·rio   |  Reajustado *\n");
    for(i=0; i<k; i++)
    {
        if (i < k-1)    
            printf("|%d∫ Funcion·rio:  R$%.2f  -  R$%.2f |\n",i+1,Sal[i],SalNovo[i]);
        else
        {
            printf("|%d∫ Funcion·rio: R$%.2f  -  R$%.2f |\n",k,Sal[9],SalNovo[9]);
        }
    }
    printf("*-----------------------------------------*");

    return 0;
}
#endif // ex8
#ifdef ex9

#endif // ex9