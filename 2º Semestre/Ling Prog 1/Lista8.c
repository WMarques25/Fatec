#define ex2 
 
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
 
#endif  //ex3 
#ifdef  ex4 
 
#endif  //ex4 
#ifdef  ex5 
 
#endif  //ex5 
#ifdef  ex6 
 
#endif  //ex6 