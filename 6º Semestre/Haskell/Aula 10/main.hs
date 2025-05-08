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