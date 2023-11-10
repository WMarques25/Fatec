/*
 * 3) Desafio (0,5) – implemente qualquer outro algoritmo de forma recursiva e de iteração para confirmar a ideia do exercício 2. Ex: Fibonacci, números naturais, etc.
 */

import java.math.BigInteger;
import java.util.Scanner;

public class DesafioAtv10_3 {
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

        System.out.println("\nFibonacci Recursivo de " + n + ":");
        tempoInicial = System.currentTimeMillis();
        System.out.println(fibRec(n));
        tempoFinal = System.currentTimeMillis();
        System.out.println("Tempo de execução: " + (tempoFinal - tempoInicial) + " ms");

        System.out.println("\nFibonacci Iterativo de " + n + ":");
        tempoInicial = System.currentTimeMillis();
        System.out.println(fibIte(n));
        tempoFinal = System.currentTimeMillis();
        System.out.println("Tempo de execução: " + (tempoFinal - tempoInicial) + " ms");
    }

    public static BigInteger fibRec(BigInteger n){
        if(n.equals(BigInteger.ZERO) || n.equals(BigInteger.ONE)){
            return n;
        }
        return fibRec(n.subtract(BigInteger.ONE)).add(fibRec(n.subtract(BigInteger.valueOf(2))));
    }

    public static BigInteger fibIte(BigInteger n){
        if(n.equals(BigInteger.ZERO) || n.equals(BigInteger.ONE)){
            return n;
        }
        BigInteger fib = BigInteger.ONE;
        BigInteger fib1 = BigInteger.ONE;
        for(BigInteger i = BigInteger.valueOf(2); i.compareTo(n) < 0; i = i.add(BigInteger.ONE)){
            BigInteger temp = fib;
            fib = fib.add(fib1);
            fib1 = temp;
        }
        return fib;
    }
}
