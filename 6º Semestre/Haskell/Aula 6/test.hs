data Cor = Vermelho | Verde | Azul deriving (Show, Eq)
data Casa = Casa {cor :: Cor, metragem, preco :: Double} deriving Show

cV :: [Casa] -> [Casa]
cV [] = []
cV (x:xs)
    | cor x == Vermelho = x : cV xs
    | otherwise = cV xs