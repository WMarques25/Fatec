-- P1
-- EX1
zar' :: (a -> Bool) -> [a] -> [a]
zar' f [] = []
zar' f (x:xs)
    | f x == False = zar' f xs
    | otherwise = [x] ++ zar' f xs

-- EX2
fA :: [Char] -> Int
fA xs = length [x | x <- xs, elem x ['A'..'Z']]
-- fA x = length $ map (\ c -> x) ['A'..'Z'] errado

fB :: [Int] -> Int
fB xs = foldl (\ a b -> a + b) 0 $ filter (>=0) xs

fC :: String -> Int
fC xs = length $ filter (\ x -> x == 'B') xs

fD :: [Double] -> Double
fD xs = foldl (\ a b -> a + b) 0 $ filter (>=0) xs

-- EX3
data Cor = Vermelho | Verde | Azul deriving (Show, Eq)
data Casa = Casa {cor::Cor, metragem::Float, preco::Double} deriving (Show, Eq)

casasVermelhas :: [Casa] -> [Casa]
casasVermelhas casas = [casa | casa <- casas, cor casa == Vermelho]

-- EX4
wd :: (Ord a) => [a] -> [a]
wd [] = []
wd (x:xs) = (wd sm) ++ [x] ++ (wd ms)
     where
        ms = filter (>= x) xs
        sm = filter (<= x) xs

-- EX5
a = map (\ (x,y) -> x * y) [(1,2),(3,4),(5,6)] -- [2, 12, 30]
b = filter (\ x -> x == 91 && x == 92) [90..100] -- :t (Eq a, Num a, Enum a) => [a]
c = (True, 4) -- :t (Bool, Int)
d = foldl (\ a b -> a - b) 0 [8, 7..2] -- [-35]