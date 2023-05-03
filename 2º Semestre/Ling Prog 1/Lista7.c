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

void Entrada(){}
void Imprime(){}
void CalcularIMC(){}

int main(void){
	setlocale(LC_ALL, "PORTUGUESE");
	

}


#endif  //ex3
#ifdef  ex4

#endif  //ex4