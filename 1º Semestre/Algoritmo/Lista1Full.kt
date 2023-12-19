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
    var n1: Double
    var n2: Double
    var n3: Double
    var n4: Double

    println("Digite a nota da primeira avaliação: ")
    do {
        n1 = teclado.nextDouble()
        if (n1 < 0 || n1 > 10){
            println("Valor invalido")
        }
    }while (n1 < 0 || n1 > 10)

    println("Digite a nota da segunda avaliação: ")
    do {
        n2 = teclado.nextDouble()
        if (n2 < 0 || n2 > 10){
            println("Valor invalido")
        }
    }while (n2 < 0 || n2 > 10)

    println("Digite a nota da terceira avaliação: ")
    do {
        n3 = teclado.nextDouble()
        if (n3 < 0 || n3 > 10) {
            println("Valor invalido")
        }
    }while (n3 < 0 || n3 > 10)

    println("Digite a nota da quarta avaliação: ")
    do {
        n4 = teclado.nextDouble()
        if (n4 < 0 || n4 > 10) {
            println("Valor invalido")
        }
    }while (n4 < 0 || n4 > 10)

    val media: Double = (n1+n2+n3+n4)/4
    println("A media do aluno é $media")
    if (media >= 6){
        println("O aluno foi aprovado")
    } else {
        println("O aluno foi reprovado")
    }

    println("Deseja voltar ao menu? (S/N)")
    return teclado.next().equals("s", true)
}

fun ex8(teclado: Scanner): Boolean {
    var n1: Double
    var n2: Double
    var n3: Double
    var n4: Double
    var n5: Double

    do{
        println("Digite um valor entre 10 e 25: ")
        do {
            n1 = teclado.nextDouble()
            if (n1 <= 10 || n1 >= 25) {
                println("Valor invalido")
            }
        } while (n1 <= 10 || n1 >= 25)

        println("Digite um valor positivo: ")
        do {
            n2 = teclado.nextDouble()
            if (n2 < 0) {
                println("Valor invalido")
            }
        } while (n2 < 0)

        n3 = n1 * n2
        n4 = n1 * n2 * n3
        n5 = (n1 * n1) + (n2 * n2) + (n3 * n3) + (n4 * n4)

        if (n5 < 50000) {
            println("O valor de $n5 é menor que 50.000")
            println("Por favor, digite novos valores")
            println("Pressione enter para continuar")
            teclado.nextLine()
        } else {
            println("O valor de $n5 é maior que 50.000")
            println("Pressione enter para continuar")
            teclado.nextLine()
        }
    }while (n5 < 50000)

    println("Deseja voltar ao menu? (S/N)")
    return teclado.next().equals("s", true)
}

fun ex9(teclado: Scanner): Boolean {
    var n1: Int
    var n2: Int

    do {
        println("Digite o primeiro numero: ")
        n1 = teclado.nextInt()
        if (n1 <= 0) {
            println("Valor invalido")
        }
    } while (n1 <= 0)

    do {
        println("Digite o segundo numero: ")
        n2 = teclado.nextInt()
        if (n2 <= 0) {
            println("Valor invalido")
        }
    } while (n2 <= 0)

    if (n1 % n2 == 0 || n2 % n1 == 0){
        println("Os numeros são multiplos")
    } else {
        println("Os numeros não são multiplos")
    }

    println("Deseja voltar ao menu? (S/N)")
    return teclado.next().equals("s", true)
}

fun ex10(teclado: Scanner): Boolean {
    var valor: Double

    do {
        println("Digite o valor do produto: ")
        valor = teclado.nextDouble()
        if (valor <= 0) {
            println("Valor invalido")
        }
    } while (valor <= 0)

    if (valor < 100){
        println("Preço reajustado: R$${valor*1.1}")
    }else{
        println("Preço reajustado: R$${valor*1.2}")
    }

    println("Deseja voltar ao menu? (S/N)")
    return teclado.next().equals("s", true)
}

fun ex11(teclado: Scanner): Boolean {

    println("Digite o primeiro numero: ")
    val n1: Int = teclado.nextInt()
    println("Digite o segundo numero: ")
    val n2: Int = teclado.nextInt()

    if (n1 > n2){
        println("$n1 > $n2")
    } else if (n1 < n2){
        println("$n2 > $n1")
    } else {
        println("$n1 = $n2")
    }

    println("Deseja voltar ao menu? (S/N)")
    return teclado.next().equals("s", true)
}

fun ex12(teclado: Scanner): Boolean {
    var n1: Double
    var n2: Double
    var n3: Double
    var mediaExercicios: Double
    val conceito: String

    println("Digite sua ID: ")
    val id: Int = teclado.nextInt()

    do {
        println("Digite a nota da primeira avaliação: ")
        n1 = teclado.nextDouble()
        if (n1 < 0 || n1 > 10) {
            println("Valor invalido")
        }
    } while (n1 < 0 || n1 > 10)

    do {
        println("Digite a nota da segunda avaliação: ")
        n2 = teclado.nextDouble()
        if (n2 < 0 || n2 > 10) {
            println("Valor invalido")
        }
    } while (n2 < 0 || n2 > 10)

    do {
        println("Digite a nota da terceira avaliação: ")
        n3 = teclado.nextDouble()
        if (n3 < 0 || n3 > 10) {
            println("Valor invalido")
        }
    } while (n3 < 0 || n3 > 10)

    do {
        println("Digite a media dos exercicios: ")
        mediaExercicios = teclado.nextDouble()
        if (mediaExercicios < 0 || mediaExercicios > 10) {
            println("Valor invalido")
        }
    } while (mediaExercicios < 0 || mediaExercicios > 10)

    val mediaAproveitamento: Double = (n1 + n2 * 2 + n3 * 3 + mediaExercicios) / 7

    conceito = if (mediaAproveitamento >= 9){
        "A"
    } else if (mediaAproveitamento >= 7.5){
        "B"
    } else if (mediaAproveitamento >= 6){
        "C"
    } else if (mediaAproveitamento >= 4){
        "D"
    } else {
        "E"
    }

    println("ID: $id")
    println("Nota da primeira avaliação: $n1")
    println("Nota da segunda avaliação: $n2")
    println("Nota da terceira avaliação: $n3")
    println("Media dos exercicios: $mediaExercicios")
    println("Media de aproveitamento: $mediaAproveitamento")
    println("Conceito: $conceito")

    when (conceito){
        "A", "B", "C" -> println("APROVADO")
        else -> println("REPROVADO")
    }

    println("Deseja voltar ao menu? (S/N)")
    return teclado.next().equals("s", true)
}
