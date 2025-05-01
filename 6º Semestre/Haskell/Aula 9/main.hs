--  Monoids

data Sum a = Sum{getSum :: a} deriving Show

data Mult a = Mult{getMult :: a} deriving Show

instance (Num a) => Semigroup (Sum a) where
    (<>) (Sum x) (Sum y) = Sum (x + y)
--  (Sum x) <> (Sum y) = Sum (x + y)

instance (Num a) => Monoid (Sum a) where
    mempty = Sum 0
    mappend = (<>)

sums = [Sum 1, Sum 2, Sum 3, Sum 4, Sum 5]

-- 

mconcat' :: (Monoid a) => [a] -> a
mconcat' xs = foldl (<>) mempty xs