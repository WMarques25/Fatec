import Control.Monad
-- Aula 10
data Talvez a = Apenas a | Nada deriving Show

instance Functor Talvez where
    fmap func (Apenas a) = Apenas (func a)
    fmap func Nada       = Nada

(//) :: (Eq a, Num a, Fractional a) => a -> a -> Talvez a
(//) x 0 = Nada
(//) x y = Apenas (x / y)

{-
class Functor f => Applicative a where
    pure :: a -> f a
    (<*>) :: (a -> b) -> f a -> fb
-}

instance Applicative Talvez where
    pure x = Apenas x
    (<*>) (Apenas func) (Apenas a) = Apenas (func a)

-- Aula 11

instance Monad Talvez where
    return = pure
    (>>=) (Apenas a) func = func a -- join -> bind
    (>>=) Nada _ = Nada

{-
ghci> Just 10 >>= \ x -> Just (x+1) >>= \ y -> return y
Just 11
-}

main :: IO ()
main = 
    putStrLn "Digite o seu nome: " >>= \ _ ->
    getLine >>= \ y ->
    putStrLn ("Seja bem vindo " ++ y)

main' :: IO ()
main' = do
    putStrLn "Digite o seu nome: "
    y <- getLine
    putStrLn ("Seja bem vindo "++ y)

main'' :: IO ()
main'' = do 
    putStrLn "Entre um valor: "
    x <- readLn :: IO Int
    let r = x + 2
    putStrLn $ show r