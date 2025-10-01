    main = do
    putStrLn "Hi"
    putStrLn $ show $ mapa dobro a
    putStrLn $ show $ mapa (2*) a
    putStrLn $ show $ mapa (`mod` 3) $ mapa (*2) a
    putStrLn $ show $ pega 3 a
    putStrLn $ show $ mapa (^2) $ filtra impar a
    putStrLn $ show $ soma $ mapa (2^) $ pega 3 $ filtra impar a
    putStrLn $
        show $
        5 `pertence` a
    putStrLn $
        show $
        'f' `pertence` "false"
    putStrLn $ show $ qs a
    putStrLn $ show $ qs "Haskell"


a = [3, 5, 2, 6, 7, 8, 1, 9, 0, 2]

dobro x = 2*x

x = 42
y = x + 5
z = (+) x 5

f a b = a^2 + 2*b   -- função prefix
a +-=-@ b = a^2 + 2*b -- função infix

impar x = (x `mod` 2) == 1 -- mod sendo usada como infix e == é função infix

add :: Integer -> Integer -> Integer -- add é uma função que, dado um inteiro, retorna uma função que, dado um inteiro, retorna um inteiro
add a b = a + b

g x = add x 5  -- g é um afunção que, dado um inteiro, retorna esse inteiro somado a 5
h = add 5  -- equivalente à linha de cima

m x = (+) 5 x
n = (+) 5
p = (+5) -- p é um afunção que, dado um número, ela soma 5

mapa :: (a -> b) -> [a] -> [b]  -- dado uma função que vai de a em b e dado uma lista de a, retorna uma lista de b
mapa _ [] = []
mapa f (x:xs) = f x:mapa f xs

filtra :: (a -> Bool) -> [a] -> [a]
filtra _ [] = []
filtra teste (x:xs)
    | teste x = x:filtra teste xs
    | otherwise = filtra teste xs

pega :: Integer -> [b] -> [b]
pega 0 _ = []
pega _ [] = []
pega n (x:xs) = x:pega (n-1) xs

soma :: (Num a) => [a] -> a
soma [] = 0
soma (x:xs) = x + soma xs

-- pertence :: a -> [a] -> Bool não compila por que não sabe comparar a1 com a2
-- Eq é type class
pertence :: (Eq a) => a -> [a] -> Bool -- dado um tipo a que pode ser comparado e uma lista de a, retorna um bool
_ `pertence` [] = False
e `pertence` (x:xs)
    | e == x = True
    | otherwise = e `pertence` xs

qs :: (Ord a) => [a] -> [a]
qs [] = []
qs (pivo:xs) = menores ++ iguais ++ maiores
    where
        menores = qs $ filtra (<pivo) xs
        iguais = pivo:filtra (==pivo) xs
        maiores = qs $ filtra (>pivo) xs