#define ex3

#include <stdio.h>
#include <ctype.h>
#include <locale.h>

#ifdef  ex1
struct var{
	char a;
	int b;
	long c;
	float d;
	double e;
	unsigned char f;
	unsigned int g;
	unsigned long h;
};

struct var v;

void Entrada(){
	printf("Insira um caractere: ");
	scanf(" %c", &v.a);
	printf("Insira um inteiro: ");
	scanf(" %d", &v.b);
	printf("Insira um long: ");
	scanf(" %ld", &v.c);
	printf("Insira um float: ");
	scanf(" %f", &v.d);
	printf("Insira um double: ");
	scanf(" %lf", &v.e);
	printf("Insira um unsigned char: ");
	scanf(" %c", &v.f);
	printf("Insira um unsigned int: ");
	scanf(" %d", &v.g);
	printf("Insira um unsigned long: ");
	scanf(" %ld", &v.h);
}

void Saida(){
	printf("        10        20        30        40        50        60        70\n1234567890123456789012345678901234567890123456789012345678901234567890\n");
	printf("    %c%10d%10ld%20.2f%20.2lf\n          %c%20d%20ld\n", v.a, v.b, v.c, v.d, v.e, v.f, v.g, v.h);
}

int main(void){
    char c;
    setlocale(LC_ALL, "");

    do{
        Entrada();
		system("cls");
		Saida();

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif  //ex1
#ifdef  ex2
struct pessoa{
	char nome[50];
	char end[50];
	char cidade[50];
	char estado[3];
	char cep[8];
};

struct pessoa p[4];

void Cadastrar(){
	for(int i = 0; i < 4; i++){
		printf("\nInsira o nome da pessoa %d: ", i+1);
		scanf(" %s", p[i].nome);
		printf("Insira o endereço da pessoa %d: ", i+1);
		scanf(" %s", p[i].end);
		printf("Insira a cidade da pessoa %d: ", i+1);
		scanf(" %s", p[i].cidade);
		printf("Insira o estado da pessoa %d: ", i+1);
		scanf(" %s", p[i].estado);
		printf("Insira o CEP da pessoa %d: ", i+1);
		scanf(" %s", p[i].cep);
	}
}

void Consultar(){
	for(int i = 0; i < 4; i++){
		printf("\nPessoa %d:\n", i+1);
		printf("Nome: %s\n", p[i].nome);
		printf("Endereço: %s\n", p[i].end);
		printf("Cidade: %s\n", p[i].cidade);
		printf("Estado: %s\n", p[i].estado);
		printf("CEP: %s\n", p[i].cep);
	}
	system("pause");
}

int main(void){
	int op;
	setlocale(LC_ALL, "PORTUGUESE");

	do{
		system("cls");
		printf("1 - Cadastrar\n");
		printf("2 - Consultar\n");
		printf("3 - Sair\n");
		printf("Insira a opção desejada: ");
		scanf(" %d", &op);

		switch (op){
		case 1:
			Cadastrar();
			break;

		case 2:
			Consultar();
			break;
		
		case 3:
			exit(0);
			break;
		
		default:
			printf("Opção inválida!\n");
			break;
		}

	} while (1);

	return 0;
} 
#endif  //ex2
#ifdef  ex3
struct pessoa{
	char nome[50];
	float altura;
	float peso;
};

struct pessoa p[4];

void Entrada(){
	for(int i = 0; i < 4; i++){
		printf("Insira os dados da %dª pessoa:\n", i+1);
		printf("Nome: ");
		scanf(" %s", p[i].nome);
		printf("Altura: ");
		scanf(" %f", &p[i].altura);
		printf("Peso: ");
		scanf(" %f", &p[i].peso);
		printf("\n");
	}
}
void Imprime(){
	for(int i = 0; i < 4; i++){
		printf("Pessoa %d:\n", i+1);
		printf("Nome: %s\n", p[i].nome);
		printf("Altura: %.2f\n", p[i].altura);
		printf("Peso: %.2f\n", p[i].peso);
		printf("\n");
	}
}
void CalcularIMC(){
	float imc;
	for(int i = 0; i < 4; i++){
		imc = p[i].peso / (p[i].altura * p[i].altura);
		printf("IMC da pessoa %d: %.2f\n", i+1, imc);
	}
	
}

int main(void){
	int op;
	setlocale(LC_ALL, "PORTUGUESE");
	
	do{
		printf("1 - Receber todos os dados\n");
		printf("2 - Imprimir os dados\n");
		printf("3 - Calcular o IMC\n");
		printf("4 - Sair\n");

		printf("Insira a opção desejada: ");
		scanf(" %d", &op);

		switch (op){
		case 1:
			Entrada();
			break;
		
		case 2:
			Imprime();
			break;

		case 3:
			CalcularIMC();
			break;

		case 4:
			exit(0);
			break;

		default:
			printf("Opção inválida!\n");
			break;
		}
	} while (1);

	return 0;
}

#endif  //ex3
#ifdef  ex4
struct data{
    int dia;
    int mes;
    int ano;
};

struct data datas[3];

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
    setlocale(LC_ALL, "");

    do{
        do{
            printf("Insira a data de nascimento (DD/MM/AAAA): ");
            scanf(" %2d/%2d/%4d",&datas[1].dia,&datas[1].mes,&datas[1].ano);

            if(datas[1].dia > diasNoMes(datas[1].mes, datas[1].ano) 
				|| datas[1].mes > 12 || datas[1].dia < 1 || datas[1].mes < 1){
                printf("Data inválida.");
                v = 'i';
            } else{
                v = 'v';
            }
        }while(v == 'i');
        system("cls");

        do{
            printf("Insira a data de hoje (DD/MM/AAAA): ");
            scanf(" %2d/%2d/%4d",&datas[2].dia,&datas[2].mes,&datas[2].ano);
            if(datas[2].dia > diasNoMes(datas[2].mes, datas[2].ano) 
				|| datas[2].mes > 12 || datas[2].dia < 1 || datas[2].mes < 1){
                printf("Data inválida.");
                v = 'i';
            } else{
                v = 'v';
            }
        }while(v == 'i');
        system("cls");

        printf("Nasc: %2d/%2d/%4d\n",datas[1].dia,datas[1].mes,datas[1].ano);
        printf("Hoje: %2d/%2d/%4d\n",datas[2].dia,datas[2].mes,datas[2].ano);

        datas[3].dia = datas[2].dia - datas[1].dia;
        datas[3].mes = datas[2].mes - datas[1].mes;
        datas[3].ano = datas[2].ano - datas[1].ano;

        if(datas[3].dia < 0){
            datas[2].mes -= 1;
            if (datas[2].mes < datas[1].mes) {
                datas[2].mes += 12;
                datas[2].ano -= 1;
            }
            datas[3].dia = datas[2].dia + diasNoMes(datas[2].mes, datas[2].ano) - datas[1].dia;
            datas[3].mes = datas[2].mes - datas[1].mes;
            datas[3].ano = datas[2].ano - datas[1].ano;
        }

        if(datas[3].dia < 0){
            datas[3].ano--;
            datas[3].mes += 12;
        }

        printf("Idade: %d Dias %d Meses %d Anos", datas[3].dia, datas[3].mes, datas[3].ano);

        printf("\nDeseja continuar? ('S' / 'N')\n");
        scanf(" %c", &c);
        c = toupper(c);

    } while (c == 'S');

    return 0;
}
#endif  //ex4