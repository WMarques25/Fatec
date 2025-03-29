import Text.Read (Lexeme(Char))
-- EX 2.1
-- A
listaA = [ 11 ^ x | x <- [0..6]]

-- B
listaB = [ x | x <- [1..40], x `mod` 4 /= 0]

-- C
listaC = [['A', x, 'B', 'B'] | x <- ['a'..'g']]

-- D
-- ????

-- E
listaE = [0.5 ^ n | n <- [0..5]]

-- F
listaF = [ 1+9*x | x <- [0..7]]

-- G
listaG = [2,4..30]

-- H
listaH = [toEnum x :: Char | x <- [64,65,67,68,69,71,74,76]]