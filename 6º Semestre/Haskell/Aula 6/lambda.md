# Lambdas

    > somar = (\ x y -> x + y)
    > somar 2 2
    > 4

### Função de Alta Ordem recebe Funções como parametros => JAVA = .map() -- IMUTABILIDADE

### Currying - Tecnica de para reduzir o numero de entradas da função
    > somarTresNum :: Int -> Int -> Int -> Int
    > somarTresNum x y z = x+y+z

    > somarCurr :: Int -> Int
    > somarCurr = somarTresNum 4 5
    > ghci> :t (+)
    > (+) :: Num a => a -> a -> a
    > ghci> :t (+1)
    > (+1) :: Num a => a -> a

### Compreensão de Listas = map + filter

> `$`-> equivale a ( )
    
    > sum $ [ x | x <- [1..10], even x]
    > 30 => 2 + 4 + 6 + 8 + 10

> `filter` -> retorna os valores q retornarem `True`

    > filter even [1..5]
    > [2,4]

> `foldl` | `foldr` -> acumula enquanto intera na lista 

    > foldl (\ b a -> b + a) 0 [1..5]  | `sum [a]`
    > 15 => 0 + 1 + 2 + 3 + 4 + 5

# Sintaxe de funções

    > verificarFaixaEtaria :: Int -> String
    > verificarFaixaEtaria idade
        | idade < 13 = "Criança"
        | idade < 18 = "Adolescente"
        | otherwise  = "Veio"

---
    > verificarFaixaEtaria2 :: Int -> String
    > verificarFaixaEtaria2 idade
        | ehCrianca idade = "Criança"
        | ehAdolescente = "Adolescente"
        | otherwise  = "Veio"
        where
            ehCrianca x = x < 13
            ehAdolescente = idade < 18 

---
    > map (+2) [1..5]
    [3,4,5,6,7]

## função infixa . (ponto)

    > (contar . traseira) "Haskell"
    6

## função $ -> ( )
## função |>  (&)
    > (|>) :: a -> (a -> b) -> b
    > (|>) x f = f x
---
    > func :: String -> String
    > func x = x ++ (tail (take 3 (reverse x)))
    ---
    > funcI :: String -> String
    > funcI x = x
         |> reverse
         |> take 3
         |> tail
         |> (x ++)

## guards |
    > imc p a
        | p/(a*a) <= 18.5 = "Abaixo do peso"
        | p/(a*a) < 25.0 = "Peso ideal"
        | p/(a*a) <= 30 = "Acima do peso"
        | otherwise = "Obesidade"
---
    > imc p a
        | valorImc <= 18.5 = "Abaixo do peso"
        | valorImc < 25.0 = "Peso ideal"
        | valorImc <= 30 = "Acima do peso"
        | otherwise = "Obesidade"
        where
        valorImc = p/(a*a)
---
    > fat n
        | n <= 1 = 1
        | otherwise = n*fat(n-1)