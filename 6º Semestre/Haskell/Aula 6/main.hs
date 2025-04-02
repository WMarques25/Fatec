somarLista :: [Int] -> Int
somarLista = foldl (\ b a -> b + a) 0

verificarFaixaEtaria :: Int -> String
verificarFaixaEtaria idade
    | idade < 13 = "Criança"
    | idade < 18 = "Adolescente"
    | otherwise  = "Veio"

verificarFaixaEtaria2 :: Int -> String
verificarFaixaEtaria2 idade
    | ehCrianca idade = "Criança"
    | ehAdolescente = "Adolescente"
    | otherwise  = "Veio"
    where
        ehCrianca x = x < 13
        ehAdolescente = idade < 18 

-- recursão -> (reverse)
reverter :: [a] -> [a]
reverter [] = []
reverter (x:xs) = reverter xs ++ [x]