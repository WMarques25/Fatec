# Polimorfismo paramétrico
### Tipos com Parâmetros

`:k` -> operador kind

```haskell
Java -> List<Pessoa> = kind 2
```
---
```haskell
data Caixa a b = UmaCaixa a | DuasCaixas a b deriving Show
estrutura kind 3 => Caixa :: * -> * -> *
```
---

### Tipo Recursivo

    Operadores Especias devem estar entre :_: -> :>:
`:>:` -> 

```haskell
data List a = a :>: List a deriving Show -- Def de lista recursiva sem condição de parada

data List a = a :>: List a | Nulo deriving Show -- Def de lista recursiva com condição de parada

data Lista a = Elemento a (Lista a) deriving Show -- Def de lista
```
`(Eq a) =>` restrinção de elementos `a` possiveis, para todo `a` que possa comparar com os elementos da lista.
```haskell
verificaElemento :: (Eq a) => a -> List a -> Bool
verificaElemento _ Nulo = False
verificaElemento elemento (x :>: resto)
    | elemento == x = True
    | otherwise = verificaElemento elemento resto
```

## Type Class -> Classes de Tipos

```haskell
class SimNao a where
    simnao :: a -> Bool

instance SimNao Int where
    simnao x
        | x < 18 = False
        | otherwise = True
```