main :: IO ()
-- io unit
main = do
    putStrLn $ show a
    putStrLn $ show b
    putStrLn $ show c
    func'


func = do
    la <- getLine
    let a = read la
    putStrLn $ show $ a+1

func' x = getLine >>= \la -> let a = read la in putStrLn (show (a + x))
-- >>= bind junta duas operações io. bind getLine com a função que vem depois
-- do e a função bind definem funções monad (classe de tipo)
-- f' é pura e retorna sempre a mesma coisa. Impura é a main

-- putStrLn :: IO ()
-- getLine :: IO [Char]
-- (>>=) :: (Monad m) => m a -> (a -> m b) -> (m b)

h :: IO Integer
h = do
    la <- getLine
    let a = read la
    return (a + 1) -- transforma valor em um monad

prodNegpos l = case find (<0) l of
    Nothing -> Nothing
    Just a -> case find (>0) l of
                Nothing -> Nothing
                Just b -> Just (a*b)

pnp :: (Ord a) => [a] -> Maybe a
pnp l = do
    a <- find (<0) l
    b <- find (>0) l
    return $ a*b

pnp' l = find (<0) 1 >>= \a -> find (>0) l >>= \b -> return (a*b)

a = [1..10]
b = map (^2) $ filter ((==1).(`mod` 2)) a
c = [x ^ 2 | x <- a, x `mod` 2 == 1] -- List comprehension
-- haskell converte c pra b, mas c favorece legibilidade
d = [x + y | x <- a, x `mod` 3 == 0, y <- a , x - y < 15]
-- d é uma lista de x mais y tal que x pertence a a e x é múltiplo de 3 e y pertence a a e x menos y é menor que 15
e = [(x, y, x*y) | x <- [-2, -1, 0, 2], y <- [z | z <- a, z > 5]]
-- e é uma lista de tuplas x, y, x*y tal que x pertence àquela lista e y pertence à lista dos z que pertencem a a e são maiores que 5


qs [] = []
qs (x:xs) = menores ++ iguais ++ maiores
    where
        menores = qs [y | y <- xs, y < x]
        iguais = [y | y <- xs, y == x]
        maiores = qs [y | y <- xs, y > x]
-- Bem menos eficiente que em c

crivo = p [2..]
    where p (x:xs) = x:p [y | y <- xs, y `mod` x /= 0]





-- foldr :: (a -> b -> b) -> b -> [a] -> b
-- foldr op base [] = base
-- foldr op base (x:xs) = op x (foldr op base xs)

-- somaLista [] = 0
-- somaLista (x:xs) = (+) x (sum xs)

-- prodLista [] = 1
-- prodLista (x:xs) = (*) x (prodLista xs)

-- mapa f [] = []
-- mapa f (x:xs) = (f x):(map f xs)

-- soma l = foldr (+) 0 l
-- soma = foldr (+) 0 -- equivalente a somaLista

-- produto = foldr (*) 1 -- equivalente a prodLista

-- (f x):map f xs
-- (:) (f x) (map f xs)
-- ((:).f) (map f xs) -- pega a função :, aplica f e retorna uma função que aplica map f xs
-- mapa = foldr ((:).f) []

-- foldl começa pela cauda => não dá pra usar com lista u=infinita