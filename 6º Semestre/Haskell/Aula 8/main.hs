-- Polimorfismo Parametrico
data Caixa a b = UmaCaixa a | DuasCaixas a b deriving Show

data Produto = Produto String Int deriving (Show, Eq)

data List a = a :>: List a | Nulo 

data Lista a = Elemento a (Lista a) 

lista = 1 :>: ( 2 :>: (3 :>: Nulo))

verificaElemento :: (Eq a) => a -> List a -> Bool
verificaElemento _ Nulo = False
verificaElemento elemento (x :>: resto)
    | elemento == x = True
    | otherwise = verificaElemento elemento resto

toStringList :: (Show a) => List a -> String
toStringList (x :>: Nulo) = show x ++ "]"
toStringList (x :>: resto) = show x ++ "," ++ toStringList resto

gerarStringList :: (Show a) => List a -> String
gerarStringList l = "[" ++ (toStringList l)

class SimNao a where
    simnao :: a -> Bool

instance SimNao Int where
    simnao x
        | x < 18 = False
        | otherwise = True

instance SimNao [a] where
    simnao [] = False
    simnao _ = True

instance SimNao Produto where 
    simnao (Produto "" 0) = False
    simnao _ = True

class Mostrar a where
    mostrar :: a -> String

instance Mostrar Produto where
    mostrar (Produto nome preco) = "Produto{" ++ nome ++ ", " ++ show preco ++ "}"

instance (Show a) => Show (List a) where
    show Nulo = "]"
    show (x :>: resto) = show x ++ "|" ++ show resto
