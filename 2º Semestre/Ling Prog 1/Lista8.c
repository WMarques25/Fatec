#define ex6
 
#include <stdio.h> 
#include <ctype.h> 
#include <locale.h> 
 
#ifdef  ex1 
char str1[11], str2[11];
 
int Compara(){
    char *p1, *p2;
    p1 = str1;
    p2 = str2;
 
    while(*p1 == *p2 && *p1 != '\0' && *p2 != '\0'){
        p1++;
        p2++;
        
        if(*p1 == '\0' && *p2 == '\0'){
            return 1;
        }
    }
    return 0;
}
 
int main(void){
    setlocale(LC_ALL, "");
    char op;
    
    do{
        printf("Digite a primeira string: ");
        scanf(" %s", str1);
        
 
        printf("Digite a segunda string: ");
        scanf(" %s", str2);
        
        
        if(Compara() == 1){
            printf("As strings são iguais.\n");
        }else{
            printf("As strings são diferentes.\n");
        }
 
        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &op);
 
        if(toupper(op) == 'N'){
            exit(0);
        }
    }while(1);
 
    return 0;
}
#endif  //ex1 
#ifdef  ex2 
char letras[] = { 'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};
 
int Pesquisa(char c){
    char *p;
    p = letras;
    while(*p != '\0'){
        if(*p == c){
            return 1;
        }
        p++;
    }
 
    return 0;
}
 
int	main(void){
    setlocale(LC_ALL, "");
 
    char *pc, op;
    pc = &op;
    do{
        printf("Digite um caractere: ");
        scanf(" %c", pc);
    
        if(Pesquisa(*pc) == 1){
            printf("O caractere %c está no vetor!.\n", *pc);
            
        }else{
            printf("O caractere %c não está no vetor!.\n", *pc);
        }
 
        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &op);
 
        if(toupper(op) == 'N'){
            exit(0);
        }
    }while(1);
    return 0;
}
#endif  //ex2 
#ifdef  ex3 
int main(void){
    setlocale(LC_ALL, "");
    char op, *pa, a;
    int *pb, b;
    long *pc, c;
    float *pd, d;
    double *pe, e;
    unsigned char *pf, f;
    unsigned int *pg, g;
    unsigned long *ph, h;

    pa = &a;
    pb = &b;
    pc = &c;
    pd = &d;
    pe = &e;
    pf = &f;
    pg = &g;
    ph = &h;

    do{
        system("cls");

        printf("Insira um caractere: ");
        scanf(" %c", pa);
        printf("Insira um inteiro: ");
        scanf(" %d", pb);
        printf("Insira um long: ");
        scanf(" %ld", pc);
        printf("Insira um float: ");
        scanf(" %f", pd);
        printf("Insira um double: ");
        scanf(" %lf", pe);
        printf("Insira um unsigned char: ");
        scanf(" %c", pf);
        printf("Insira um unsigned int: ");
        scanf(" %d", pg);
        printf("Insira um unsigned long: ");
        scanf(" %ld", ph);

        printf("        10        20        30        40        50        60\n123456789012345678901234567890123456789012345678901234567890\n");
        printf("    %d%20ld%20d\n", *pb, *pc, *pg);
        printf("    %10f%10lf%10c\n", *pd, *pe, *pa);
        printf("         %ld%20lc\n", *ph, *pf);

        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &op);

        if(toupper(op) == 'N'){
            exit(0);
        }
    }while(1);

    return 0;
 }
#endif  //ex3 
#ifdef  ex4 
 
int main(void){
    int *pi, i, n = 0, soma = 0;
    char op;
    pi = &i;

    do{
        do{
            printf("Insira um número inteiro positivo: ");
            scanf(" %d", pi);

            if(*pi < 0){
                break;
            }

            soma =+ *pi;
            n++;
        }while(1);

        printf("A média dos números digitados é: %.2f\n", (float)soma/n);

        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &op);

        if(toupper(op) == 'N'){
            exit(0);
        }
    }while(1);
}
#endif  //ex4 
#ifdef  ex5 
struct data {
    int dia;
    int mes;
    int ano;
};

int DiasNoMes(int mes, int ano) {
    if (mes == 2) {
        if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        return 30;
    } else {
        return 31;
    }
}

int DiasEntreDatas(struct data *data1, struct data *data2) {
    int dias1 = data1->dia;
    int dias2 = data2->dia;
    int mes1 = data1->mes;
    int mes2 = data2->mes;
    int ano1 = data1->ano;
    int ano2 = data2->ano;
    int dias = 0;

    if (ano2 < ano1 || (ano2 == ano1 && mes2 < mes1) || (ano2 == ano1 && mes2 == mes1 && dias2 < dias1)) {
        struct data *temp = data1;
        data1 = data2;
        data2 = temp;
        dias1 = data1->dia;
        dias2 = data2->dia;
        mes1 = data1->mes;
        mes2 = data2->mes;
        ano1 = data1->ano;
        ano2 = data2->ano;
    }

    while (ano1 < ano2 || (ano1 == ano2 && mes1 < mes2) || (ano1 == ano2 && mes1 == mes2 && dias1 < dias2)) {
        dias += DiasNoMes(mes1, ano1) - dias1 + 1;
        dias1 = 1;
        mes1++;
        if (mes1 > 12) {
            mes1 = 1;
            ano1++;
        }
    }

    dias += dias2 - dias1;

    return dias;
}

int main() {
    struct data datas[2];

    for (int i = 0; i < 2; i++) {
        printf("Digite a data %d (DD/MM/AAAA): ", i + 1);
        scanf(" %d/%d/%d", &datas[i].dia, &datas[i].mes, &datas[i].ano);
    }

    printf("O número de dias entre %02d/%02d/%04d e %02d/%02d/%04d é %d.\n",
           datas[0].dia, datas[0].mes, datas[0].ano, datas[1].dia, datas[1].mes, datas[1].ano,
           DiasEntreDatas(&datas[0], &datas[1]));

    return 0;
}
#endif  //ex5 
#ifdef  ex6 
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
        struct pessoa *pp;
        pp = &p[i];
		printf("\nInsira o nome da pessoa %d: ", i+1);
        gets((pp+i)->nome);
        printf("Insira o endereço da pessoa %d: ", i+1);
        gets((pp+i)->end);
		printf("Insira a cidade da pessoa %d: ", i+1);
        gets((pp+i)->cidade);
        printf("Insira o estado da pessoa %d: ", i+1);
        gets((pp+i)->estado);
		printf("Insira o CEP da pessoa %d: ", i+1);
        gets((pp+i)->cep);
	}
}

void Consultar(){
	for(int i = 0; i < 4; i++){
        struct pessoa *pp = &p[i];
		printf("\nPessoa %d:\n", i+1);
		printf("Nome: %s\n", pp->nome);
		printf("Endereço: %s\n", pp->end);
		printf("Cidade: %s\n", pp->cidade);
		printf("Estado: %s\n", pp->estado);
		printf("CEP: %s\n", pp->cep);
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
#endif  //ex6 