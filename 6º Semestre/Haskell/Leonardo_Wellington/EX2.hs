-- EX 2.2
isEven :: String -> Bool
isEven x = even (length x)

-- EX 2.3
reverso :: String -> String
reverso = reverse

-- EX 2.4
tamLista :: [String] -> [Int]
tamLista xs = [length x | x <- xs, odd(length x)]

-- EX 2.5
