/*
2) Desafio (1,0 ponto) 

Se conseguir implemente os algoritmos e verifique a diferença de tempo (desempenho) entre eles. 

Obs: usar alguma função de tempo; 

Obs: talvez com 2000 elementos já seja suficiente para verificar a diferença. 
Caso não visualize com essa quantidade, aumente a quantidade até verificar uma 
quantidade de tempo significativa entre os algoritmos. 
 */

import java.util.ArrayList;
import java.util.Random;

public class DesafioAtv8 {
    public static void main(String[] args) {
        int qntNum = 10000;
        int limite = 200000;
        ArrayList<Integer> lista;
        ArrayList<Integer> lista2;
        Random gerador = new Random();

        System.out.print("\033[H\033[2J");
        System.out.flush();

        lista = new ArrayList<Integer>();
        for (int i = 0; i < qntNum; i++) {
            lista.add(gerador.nextInt(limite));
        }
        lista2 = new ArrayList<Integer>(lista);

        System.out.println("Lista: " + lista);
        insertion(lista);
        // System.out.println("Lista 1 ordenada: " + lista); // Descomentar para ver a lista ordenada
        
        // System.out.println("\nLista 2: " + lista2); // Descomentar para ver a lista desordenada
        bubble(lista2);
        // System.out.println("Lista 2 ordenada: " + lista2); // Descomentar para ver a lista ordenada

    }

    public static void bubble(ArrayList<Integer> lista){
        long tempoInicial;
        long tempoFinal;
        int n = lista.size();
        long comp = 0;
        long trocas = 0;

        System.out.println("\nBubble Sort:");
        
        tempoInicial = System.currentTimeMillis();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                comp++;
                if (lista.get(j) > lista.get(j + 1)) {
                    trocas++;
                    int temp = lista.get(j);
                    lista.set(j, lista.get(j + 1));
                    lista.set(j + 1, temp);
                }
            }
        }
        tempoFinal = System.currentTimeMillis();
        System.out.println("Tempo: " + ((tempoFinal - tempoInicial) / 1000.0) + " segundos");
        System.out.println("Comparações: " + comp + "\nTrocas: " + trocas);
    }
    
    public static void insertion(ArrayList<Integer> lista){
        long tempoInicial;
        long tempoFinal;
        int n = lista.size();
        int comp1 = 0;
        int trocas1 = 0;
        
        System.out.println("\nInsertion Sort:");
        
        tempoInicial = System.currentTimeMillis();
        for (int i = 1; i < n; i++) {
            int chave = lista.get(i);
            int j = i - 1;
            
            while (true) {
                comp1++;
                if (j < 0) {
                    break;
                }
                
                comp1++;
                if (lista.get(j) > chave) {
                    lista.set(j + 1, lista.get(j));
                    j--;
                    trocas1++;
                } else {
                    break;
                }
            }
            lista.set(j + 1, chave);
        }
        tempoFinal = System.currentTimeMillis();
        System.out.println("Tempo: " + ((tempoFinal - tempoInicial) / 1000.0) + " segundos.");
        System.out.println("Comparações: " + comp1 + "\nTrocas: " + trocas1);
    }
}
