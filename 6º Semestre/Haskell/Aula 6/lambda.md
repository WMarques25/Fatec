# Lambdas

    > somar = (\ x y -> x + y)
    > somar 2 2
    > 4

### Função de Alta Ordem recebe Funções como parametros => JAVA = .map() -- IMUTABILIDADE

### Tecnica de para reduzir o numero de entradas da função para 

    > ghci> :t (+)
    > (+) :: Num a => a -> a -> a
    > ghci> :t (+1)
    > (+1) :: Num a => a -> a

### Compreenção de Listas = map + filter

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

# Recursão