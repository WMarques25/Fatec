import qualified Control.Applicative as Binario
-- Pattern Matching | Combinação de Padrão

-- "Override" de input
numerosExtenso :: Int -> String
numerosExtenso 1 = "Um"
numerosExtenso 2 = "Dois"
numerosExtenso x = "?"

saudar :: String -> String
saudar "Fulano" = "Seja bem vindo Fulano"
saudar "Cicrano" = "Seja Mal vindo Cicrano"
saudar "Palmeiras" = "Nao tem mundial"
saudar nome = "Seja bem vindo: " ++ nome

pmTupla :: (Int,Int) -> Int
pmTupla (1,1) = 2
pmTupla (x,1) = 1
pmTupla (1,x) = x
pmTupla (321,4) = 326
pmTupla (x,y) = x + y

pmLista :: [Int] -> Int
pmLista [] = 0
pmLista [x] = x
pmLista [y,_] = y -- Operador '_' para ignorar valor
pmLista [z,y,x] = z
pmLista (x:xs) = x -- x:y:z:xs-> x = primeiro elemento da lista

-- Tipos de Dados Algébricos -> "Classe"

data Binario = Zero | Um deriving Show -- Classe Binario, Zero extends Binario...

binarioParaInt :: Binario -> Int
binarioParaInt Um = 1
binarioParaInt Zero = 0

data Pessoa = Fisica String Int | Juridica String Int deriving Show

getNome :: Pessoa -> String
getNome (Fisica nome cpf) = nome
getNome (Juridica nome cnpj) = nome

setNome :: Pessoa -> String -> Pessoa
setNome (Fisica nome cpf) novoNome = Fisica novoNome cpf

-- os sets na verdade criam outro dado ao inves de mudar uma parte

-- Anotação de Records
data PessoaRecord = FisicaRecord{nome::String, cpf::String}
              | JuridicaRecord{nome::String, cnpj::String}
              deriving Show