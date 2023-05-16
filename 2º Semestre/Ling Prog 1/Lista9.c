#define ex6

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>

#ifdef ex1
void entrada(float *valor, char *op) {
    printf("Digite uma operação (+ - * / =): ");
    scanf(" %c", op);
    if(*op == '='){
        return;
    }
    printf("Digite o um valor: ");
    scanf(" %f", valor);
}

void somar(float *valor, float *resultado) {
    *resultado += *valor;
}

void subtrair(float *valor, float *resultado) {
    *resultado -= *valor;
}

void multiplicar(float *valor, float *resultado) {
    *resultado *= *valor;
}

void dividir(float *valor, float *resultado) {
    *resultado /= *valor;
}

int main(void){
    setlocale(LC_ALL, "Portuguese");
    do{
        float resultado = 0;
        char opcao;

        do{
            int n;
            float valor;
            char operacao;
            system("cls");

            printf("Resultado: %.2f\n", resultado);
            entrada(&valor, &operacao);
            
            switch (operacao) {
                case '+':
                    somar(&valor, &resultado);
                    break;
                case '-':
                    subtrair(&valor, &resultado);
                    break;
                case '*':
                    multiplicar(&valor, &resultado);
                    break;
                case '/':
                    dividir(&valor, &resultado);
                    break;
                case '=':
                    break;
                default:
                    printf("Operação inválida!\n");
                    break;
            }

            if(operacao == '='){
                system("cls");
                printf("Resultado: %.2f\n", resultado);
                break;
            }

        }while(1);

        printf("\nDeseja sair? ('S' / 'N')\n");
        scanf(" %c", &opcao);
        if(toupper(opcao) == 'S'){
            exit(0);
        }

    }while(1);
    
}
#endif  //ex1
#ifdef  ex2
int Pesquisa(char *pc, char *letras){
    char *p;
    p = letras;
    while(*p != '\0'){
        if(*p == *pc){
            return 1;
        }
        p++;
    }
 
    return 0;
}
 
int	main(void){
    setlocale(LC_ALL, "");
    char letras[] = { 'b', 'd', 'f', 'h', 'j', 'k', 'm', 'o', 'q', 's', 'u', 'w', 'y'};
    char *pc, op;
    pc = &op;
    do{
        printf("Digite um caractere: ");
        scanf(" %c", pc);
    
        if(Pesquisa(pc, letras) == 1){
            printf("O caractere '%c' está no vetor!.\n", *pc);
            
        }else{
            printf("O caractere '%c' não está no vetor!.\n", *pc);
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
void entrada(char *str1, char *str2){
    printf("Digite a primeira string: ");
    scanf(" %s", str1);    

    printf("Digite a segunda string: ");
    scanf(" %s", str2);
}
 
int Compara(char *str1, char *str2){
     
    while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0'){
        str1++;
        str2++;
        
        if(*str1 == '\0' && *str2 == '\0'){
            return 1;
        }
    }
    return 0;
}
 
int main(void){
    setlocale(LC_ALL, "");
    char op, str1[11], str2[11];
    
    do{
        system("cls");
        entrada(str1, str2);
        if(Compara(str1, str2) == 1){
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
#endif  //ex3
#ifdef  ex4
struct tipos{
    char a;
    int b;
    long c;
    float d;
    double e;
    unsigned char f;
    unsigned int g;
    unsigned long h;
};

void entrada(struct tipos *p){
    printf("Insira um caractere: ");
    scanf(" %c", &p->a);
    printf("Insira um inteiro: ");
    scanf(" %d", &p->b);
    printf("Insira um long: ");
    scanf(" %ld", &p->c);
    printf("Insira um float: ");
    scanf(" %f", &p->d);
    printf("Insira um double: ");
    scanf(" %lf", &p->e);
    printf("Insira um unsigned char: ");
    scanf(" %c", &p->f);
    printf("Insira um unsigned int: ");
    scanf(" %u", &p->g);
    printf("Insira um unsigned long: ");
    scanf(" %ld", &p->h);

}

void imprime(struct tipos *p){
    printf("        10        20        30        40        50        60        70\n1234567890123456789012345678901234567890123456789012345678901234567890\n");
    printf("    %-10c%-10d%-20ld%-20f%lf\n", p->a, p->b, p->c, p->d, p->e);
    printf("          %-20u%-20u%lu\n", p->f, p->g, p->h);

}

int main(void){
    setlocale(LC_ALL, "");
    struct tipos v;
    char op;

    do{
        entrada(&v);
        imprime(&v);

        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &op);

        if(toupper(op) == 'N'){
            exit(0);
        }
    }while(1);
    
    return 0;
}
#endif  //ex4
#ifdef  ex5
struct pessoa{
	char nome[50];
	char end[50];
	char cidade[50];
	char estado[3];
	char cep[8];
};

void Cadastrar(struct pessoa *pp){
	for(int i = 0; i < 4; i++){
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

void Consultar(struct pessoa *pp){
	for(int i = 0; i < 4; i++){
		printf("\nPessoa %d:\n", i+1);
		printf("Nome: %s\n", (pp + i)->nome);
		printf("Endereço: %s\n", (pp + i)->end);
		printf("Cidade: %s\n", (pp + i)->cidade);
		printf("Estado: %s\n", (pp + i)->estado);
		printf("CEP: %s\n", (pp + i)->cep);
	}
	system("pause");
}

int main(void){
	int op;
    struct pessoa p[4];
	setlocale(LC_ALL, "PORTUGUESE");

	do{
		system("cls");
		printf("1 - Cadastrar\n");
		printf("2 - Consultar\n");
		printf("3 - Sair\n");
		printf("Insira a opção desejada: ");
		scanf(" %d", &op);
        getchar();
		
        switch (op){
		case 1:
			Cadastrar(p);
			break;

		case 2:
			Consultar(p);
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
#endif  //ex5
#ifdef  ex6
struct pessoa{
	char nome[50];
	char end[50];
	char cidade[50];
	char estado[3];
	char cep[8];
};

void Cadastrar(struct pessoa *pp){
	for(int i = 0; i < 4; i++){
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

void Consultar(struct pessoa *pp){
	for(int i = 0; i < 4; i++){
		printf("\nPessoa %d:\n", i+1);
		printf("Nome: %s\n", (pp + i)->nome);
		printf("Endereço: %s\n", (pp + i)->end);
		printf("Cidade: %s\n", (pp + i)->cidade);
		printf("Estado: %s\n", (pp + i)->estado);
		printf("CEP: %s\n", (pp + i)->cep);
	}
	system("pause");
}

void Pesquisar(struct pessoa *pp){
    char nome[50], *str1, *str2;
    
    system("cls");
    printf("Digite o nome a ser pesquisado: ");
    gets(nome);

    for(int i = 0; i < 4; i++, pp++){
        str2 = pp->nome;
        str1 = nome;
        while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0'){
            str1++;
            str2++;
            
            if(*str1 == '\0' && *str2 == '\0'){
                printf("\nNome encontrado!\n");
                printf("Nome: %s\n", pp->nome);
                printf("Endereço: %s\n", pp->end);
                printf("Cidade: %s\n", pp->cidade);
                printf("Estado: %s\n", pp->estado);
                printf("CEP: %s\n", pp->cep);
                system("pause");
                return;
            }
        }
    }
    printf("Nome não encontrado!\n");
    system("pause");

}

void Alterar(struct pessoa *pp){
    char nome[50], *str1, *str2;
    
    system("cls");
    printf("Digite o nome a ser pesquisado: ");
    gets(nome);

    for(int i = 0; i < 4; i++, pp++){
        str2 = pp->nome;
        str1 = nome;
        while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0'){
            str1++;
            str2++;
            
            if(*str1 == '\0' && *str2 == '\0'){
                printf("\nNome encontrado! Insira novos dados\n");
                
                printf("\nInsira o nome da pessoa %d: ", i+1);
                gets((pp)->nome);
                printf("Insira o endereço da pessoa %d: ", i+1);
                gets((pp)->end);
                printf("Insira a cidade da pessoa %d: ", i+1);
                gets((pp)->cidade);
                printf("Insira o estado da pessoa %d: ", i+1);
                gets((pp)->estado);
                printf("Insira o CEP da pessoa %d: ", i+1);
                gets((pp)->cep);
                system("pause");
                return;
            }
        }
    }
    printf("Nome não encontrado!\n");
    system("pause");

}

void Excluir(struct pessoa *pp){
    char nome[50], *str1, *str2;
    
    system("cls");
    printf("Digite o nome a ser pesquisado: ");
    gets(nome);

    for(int i = 0; i < 4; i++, pp++){
        str1 = nome;
        str2 = pp->nome;
        while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0'){
            str1++;
            str2++;
            
            if(*str1 == '\0' && *str2 == '\0'){
                printf("\nNome encontrado! Excluindo dados\n");
                char x = '\0';
                *pp->nome = x;
                *pp->end = x;
                *pp->cidade = x;
                *pp->estado = x;
                *pp->cep = x;
                system("pause");
                return;
            }
        }
    }
    printf("Nome não encontrado!\n");
    system("pause");

}

int main(void){
	int op;
    struct pessoa p[4];
	setlocale(LC_ALL, "PORTUGUESE");

	do{
		system("cls");
		printf("1 - Cadastrar\n");
		printf("2 - Consultar\n");
        printf("3 - Pesquisar\n");
        printf("4 - Alterar\n");
        printf("5 - Excluir\n");
		printf("6 - Sair\n");
		printf("Insira a opção desejada: ");
		scanf(" %d", &op);
        getchar();
		
        switch (op){
		case 1:
			Cadastrar(p);
			break;

		case 2:
			Consultar(p);
			break;
		
        case 3:
            Pesquisar(p);
            break;

        case 4:
            Alterar(p);
            break;

        case 5:
            Excluir(p);
            break;

		case 6:
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
