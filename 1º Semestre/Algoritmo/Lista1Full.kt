import java.util.*

fun main() {
    val teclado = Scanner(System.`in`)
    var continuar = true
    do{
        println("""
            Este programa contem todos os exercicios da lista 1 de Algoritmos.
            Ex 1 - Antecessor e Sucessor      |      Ex 7 - Calculo da media escolar
            Ex 2 - Reajuste +10%              |      Ex 8 - N > 50.000?
            Ex 3 - Desconto de 9%             |      Ex 9 - São multiplos?
            Ex 4 - Salario Professor          |      Ex 10 - inflação de Produtos
            Ex 5 - Carro Novo                 |      Ex 11 - Maior Numero
            Ex 6 - Reajuste Salarial          |      Ex 12 - Media + Conceito Escolar
            Digite o numero do exercicio que deseja executar:
        """.trimIndent())

        when (teclado.nextInt()){
            1 -> continuar = ex1(teclado)
            2 -> continuar = ex2(teclado)
            3 -> continuar = ex3(teclado)
            4 -> continuar = ex4(teclado)
            5 -> continuar = ex5(teclado)
            6 -> continuar = ex6(teclado)
            7 -> continuar = ex7(teclado)
            8 -> continuar = ex8(teclado)
            9 -> continuar = ex9(teclado)
            10 -> continuar = ex10(teclado)
            11 -> continuar = ex11(teclado)
            12 -> continuar = ex12(teclado)
            else -> println("Exercicio não encontrado")
        }
    }while (continuar)
    teclado.close()
}

fun ex1(teclado: Scanner): Boolean {
    println("Digite um numero inteiro: ")
    if (teclado.hasNextInt()){
        val numero = teclado.nextInt()
        println("O antecessor de $numero é ${numero-1} e o sucessor é ${numero+1}")
    } else {
        println("Valor invalido")
    }
    println("Deseja voltar ao menu? (S/N)")
    return teclado.next().equals("s", true)
}

fun ex2(teclado: Scanner): Boolean {
    println("Digite um valor para ser reajustado: ")
    if (teclado.hasNextDouble()){
        val valor = teclado.nextDouble()
        println("O valor reajustado é ${valor*1.1}")
    } else {
        println("Valor invalido")
    }
    println("Deseja voltar ao menu? (S/N)")
    return teclado.next().equals("s", true)
}

fun  ex3(teclado: Scanner): Boolean {
    println("Digite um valor para ser descontado: ")
    if (teclado.hasNextDouble()){
        val valor = teclado.nextDouble()
        println("O valor com desconto é ${valor*0.91}")
    } else {
        println("Valor invalido")
    }
    println("Deseja voltar ao menu? (S/N)")
    return teclado.next().equals("s", true)
}

fun ex4(teclado: Scanner): Boolean {
    println("Digite o valor da hora/aula: ")
    if (teclado.hasNextDouble()){
        val valor = teclado.nextDouble()
        println("Digite a quantidade de aulas dadas: ")
        if (teclado.hasNextInt()){
            val aulas = teclado.nextInt()
            println("Digite o percentual de desconto do INSS: ")
            if (teclado.hasNextDouble()){
                val desconto = teclado.nextDouble()
                println("O salario liquido do professor é ${valor*aulas*(1-desconto/100)}")
            } else {
                println("Valor invalido")
            }
        }
    }
    println("Deseja voltar ao menu? (S/N)")
    return teclado.next().equals("s", true)
}

fun ex5(teclado: Scanner): Boolean{
    var preco: Double
    var lucro: Double
    var imposto: Double
    println("Digite o preço de fabrica do carro: ")
    do {
        preco = teclado.nextDouble()
        if (preco <= 0){
            println("Valor invalido")
        }
    }while (preco <= 0)
    println("Digite o percentual de lucro do distribuidor: ")
    do {
        lucro = teclado.nextDouble()
        if (lucro <= 0){
            println("Valor invalido")
        }
    }while (lucro <= 0)
    println("Digite o percentual de impostos: ")
    do {
        imposto = teclado.nextDouble()
        if (imposto <= 0){
            println("Valor invalido")
        }
    }while (imposto <= 0)
    println("O preço final do carro é ${preco*(1+lucro/100)*(1+imposto/100)}")
    println("O valor do imposto é ${preco*(1+lucro/100)*imposto/100}")
    println("O valor do lucro do distribuidor é ${preco*lucro/100}")
    println("Deseja voltar ao menu? (S/N)")
    return teclado.next().equals("s", true)
}

fun ex6(teclado: Scanner): Boolean {
    var valor: Double
    println("Digite o valor do salario: ")
    do {
        valor = teclado.nextDouble()
        if (valor <= 0){
            println("Valor invalido")
        }
    }while (valor <= 0)
    if (valor < 800){
        println("O salario de R$${valor} foi reajustado para R$${valor*1.15}")
    } else if (valor > 1000){
        println("O salario de R$${valor} foi reajustado para R$${valor*1.05}")
    } else {
        println("O salario de R$${valor} foi reajustado para R$${valor*1.1}")
    }
    println("Deseja voltar ao menu? (S/N)")
    return teclado.next().equals("s", true)
}

fun ex7(teclado: Scanner): Boolean {

}
fun ex12(teclado: Scanner): Boolean {
    TODO("Not yet implemented")
}
