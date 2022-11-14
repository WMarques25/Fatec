#define ex9
#include <stdio.h>
#include <locale.h>
#include <locale.h>
#include <ctype.h>

#ifdef ex1

void verifica(int a)
{
   if(a<0)
   {
      printf("O número digitado é negativo.\n");
   }
   else
   {
      if(a>0)
      {
         printf("O número digitado é positivo.\n");
      }
      else
      {
         printf("O número digitado é 0.\n");
      }
   }
}

int main(void)
{
    int a;
    setlocale(LC_ALL,"");
    printf("Digite um número inteiro: ");
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
        printf("Digite um número diferente de 0.\n");
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
    printf("Digite o primeiro número: ");
    scanf(" %f",&x);
    z = check(x);
    }while(z == 0);
    do{
    printf("Digite o segundo número: ");
    scanf(" %f",&y);
    z = check(y);
    }while(z == 0);
    div = divisao(x,y);
    printf("O resultado da divisão de %g por %g é igual a %g.\n", x, y, div);
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

        // MDIA
        med = media(x1,nx,n3,n4);
        if(med>=6)
        {
            printf("\nMédia = %.2f.\nAprovado.\n",med);
        }
        else
        {
            printf("\nMédia = %.2f.\nReprovado.\n",med);
        }

        printf("\nDeseja realisar outra verificação? ('S' = SIM)\n");
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
        {printf("\tValor inválido!\n\tDigite um valor maior que zero.");}
    }while(x<=0);
    return x;
}

int Existencia_Triangulo(float x1, float x2, float x3)
{
    if(x1 > (x2+x3))
        {printf("\n\tTriângulo inválido.\n\tUm dos lados é maior qua a soma dos outros.");
        return 0;}
    else
    {
        if(x2 > (x1+x3))
            {printf("\n\tTriângulo inválido.\n\tUm dos lados é maior qua a soma dos outros.");
            return 0;}
        else
        {
            if(x3 > (x1+x2))
                {printf("\n\tTriângulo inválido.\n\tUm dos lados é maior qua a soma dos outros.");
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
            printf("\nEste triângulo é equilátero!\n");
        }
        else
        {
            if(((x1==x2)||(x2==x3))||(x1==x3))
                printf("\nEste triângulo é isócele!\n");
            else
                printf("\nEste triângulo é escaleno!\n");
        }
}

int main(void)
{
    float t1 = 0, t2 = 0, t3= 0;
    int triangulo = 0;

    setlocale(LC_ALL, "");
    do{
        system("cls");
        printf("Este programa verifica se um triângulo é isóscele, equilátero ou escaleno.");
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
        {printf("\tValor inválido!\n\tDigite um valor maior que zero.");}
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
    {printf("\nSeu peso ideal é: %.2fkg",((62.1*a)-44.7));}
    else
    {printf("\nSeu peso ideal é: %.2fkg",((72*a)-58));}
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
        printf("\nSeu IMC é: %.2f. - ", imc);
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
            printf("Digite o salário do %dº funcionário: R$",i+1);
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
        printf("Este programa reajusta o salário de até 10 funcionários.\n");
        printf("Digite a quantidade de funcionários que deseja reajustar o salário.\nMax 10 : ");
        while(k<=0||k>10)
        {
            scanf("%d",&k);
            printf("\tDigite um valor válido.\n");
        }
        sal(k);
        ReajSalNovo(k);
        system("cls");
        printf("* Funcionários |   Salário   | Reajustado *\n");
        for(i=0; i<k; i++)
        {
            if (i < 9)    
                printf("|%dº Funcionário:  R$%.2f  -  R$%.2f |\n",i+1,Sal[i],SalNovo[i]);
            else
            {
                printf("|%dº Funcionário: R$%.2f  -  R$%.2f |\n",k,Sal[9],SalNovo[9]);
            }
        }
        printf("*-----------------------------------------*");

        return 0;
    }
#endif // ex8
#ifdef ex9
    float Salarios_Antigo[10], Salarios_Novo[10];

    void sal(int k)
    {
        int i=0;
        for(i; i<k; i++)
        {
            system("cls");
            do{
            printf("Digite o salário do %dº funcionário: R$",i+1);
            scanf(" %f",&Salarios_Antigo[i]);
            if (Salarios_Antigo[i]<=0)
            {
                printf("Digite um valor maior que 0.\n");
            }
            }while(Salarios_Antigo[i]<=0);
        }
    }

    void ReajSalNovo(int k)
    {
        int i=0;
        for(i=0; i<k; i++)
        {
            if(Salarios_Antigo[i]<800)
                {Salarios_Novo[i]=1.15*Salarios_Antigo[i];}
            else
                if(Salarios_Antigo[i]>1000)
                    {Salarios_Novo[i]=1.05*Salarios_Antigo[i];}
                else
                    Salarios_Novo[i]=1.1*Salarios_Antigo[i];
        }
    }

    int main(void)
    {
        int k=0, i;

        setlocale(LC_ALL, "");
        printf("Este programa reajusta o salário de até 10 funcionários.\n");
        printf("Digite a quantidade de funcionários que deseja reajustar o salário.\nMin 5, Max 20 : ");
        while(k<5||k>=20)
        {
            scanf("%d",&k);
            printf("\tDigite um valor válido.\n");
        }
        sal(k);
        ReajSalNovo(k);
        system("cls");
        printf("* Funcionários |   Salário   | Reajustado *\n");
        for(i=0; i<k; i++)
        {
            if (i < 9)    
                printf("|%dº Funcionário:  R$%.2f  -  R$%.2f |\n",i+1,Salarios_Antigo[i],Salarios_Novo[i]);
            else
            {
                printf("|%dº Funcionário: R$%.2f  -  R$%.2f |\n",i+1,Salarios_Antigo[i],Salarios_Novo[i]);
            }
        }
        printf("*-----------------------------------------*");

        return 0;
    }
#endif // ex9