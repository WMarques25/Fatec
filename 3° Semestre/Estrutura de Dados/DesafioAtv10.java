/*
* 1) Desafio (0,5) – tente implementar o algoritmo de fatorial na forma recursiva e de iteração. 
* 2) Como você saberia qual é o mais performático? Caso tenha implementado, mostre como foi feito.  
*/

import java.math.BigInteger;
import java.util.Scanner;

public class DesafioAtv10 {
    public static void main(String[] args) {
        long tempoInicial;
        long tempoFinal;
        Scanner sc = new Scanner(System.in);
        BigInteger n;
        
        System.out.print("\033[H\033[2J");
        System.out.flush();

        System.out.print("Digite um número inteiro positivo: ");
        n = sc.nextBigInteger();
        sc.close();

        System.out.println("\nFatorial Recursivo de " + n + ":");
        tempoInicial = System.currentTimeMillis();
        System.out.println(fatRec(n));
        tempoFinal = System.currentTimeMillis();
        System.out.println("Tempo de execução: " + (tempoFinal - tempoInicial) + " ms");

        System.out.println("\nFatorial Iterativo de " + n + ":");
        tempoInicial = System.currentTimeMillis();
        System.out.println(fatIte(n));
        tempoFinal = System.currentTimeMillis();
        System.out.println("Tempo de execução: " + (tempoFinal - tempoInicial) + " ms");
    }

    public static BigInteger fatRec(BigInteger n){
        if(n.equals(BigInteger.ONE)){
            return (BigInteger.ONE);
        }
        return n.multiply(fatRec(n.subtract(BigInteger.ONE)));
    }

    public static BigInteger fatIte(BigInteger n){
        BigInteger fat = BigInteger.ONE;
        for(BigInteger i = BigInteger.ONE; i.compareTo(n) <= 0; i = i.add(BigInteger.ONE)){
            fat = fat.multiply(i);
        }
        return fat;
    }
}
