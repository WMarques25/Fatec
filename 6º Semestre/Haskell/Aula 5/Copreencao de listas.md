## Listas

`[ x | x <- [1,2,3,4]]` -> copreende q x pertence ao grupo(lista) - lista é passada recursivamente

> [1,2,3,4]
---
`[ x | x <- [1..50], x>10 && x<20]` -> limita os valores da lista com os predicados
    
> [11,12,13,14,15,16,17,18,19]
---
`ghci> [ x | x <- "palavra", x /= 'a' ]`
> "plvr"

## Funções
> `odd [1..50]` -> retorna os impares

> `even [1..50]` -> retorna os pares

> `zip [odd x | x <- [1..10]] [1..10]`-> junta as listas `[(True,1),(False,2)....]`

> `fst [1,2]` -> `1` | pega primeiro elemento da Tupla (2 elementos de tipos diferentes)

> `snd [1,2]` -> `2` | pega segundo elemento da Tupla

> usar `[]` para listas com limites conhecidos e `(x:y:xs)` para indefinido

> Se uma função nao consegue passar tds as entradas possiveis para uma saida -> ERRO non-exhaustive patterns