main = do
    putStrLn $ show $ somaSe "Par" a
    putStrLn $ show $ somaPar a
    putStrLn $ show $ somaTeste isPar a
    putStrLn $ show $ operaLista isPar soma 0 a
    putStrLn $ show $ operaLista (\x -> True) (\x y -> x*y) 1 a
    --putStrLn $ show $ operaLista (>10) (^) 1 a
    putStrLn $ show $ somaLista $ filtra (\x -> mod x 2 == 0) a

a = [3, 5, 1, -9, 42, -50, 90, 10]

somaLista [] = 0
somaLista (x:xs) = x + somaLista xs

somaPos [] = 0
somaPos (x:xs)
    | x > 0 = x + somaPos xs
    | otherwise = somaPos xs

somaPar [] = 0
somaPar (x:xs)
    | mod x 2 == 0 = x + somaPar xs
    | otherwise = somaPar xs

somaSe cond [] = 0
somaSe cond (x:xs)
    | cond == "Pos" && x > 0 = x + somaSe cond xs
    | cond == "Neg" && x < 0 = x + somaSe cond xs
    | cond == "Par" && mod x 2 == 0 = x + somaSe cond xs
    | otherwise = somaSe cond xs

somaTeste teste [] = 0
somaTeste teste (x:xs) -- função de alta ordem
    | teste x = x + somaTeste teste xs
    | otherwise = somaTeste teste xs

isPos = \x -> x > 0 -- isPos é uma func que recebe x como parâmetro e retorns o resultado da func depois da seta
isPar = \x -> mod x 2 == 0
soma x y = x + y

operaLista cond op neutro [] = neutro
operaLista cond op neutro (x:xs)
    | cond x = op x $ operaLista cond op neutro xs
    | otherwise = operaLista cond op neutro xs

filtra teste [] = []
filtra teste (x:xs)
    | teste x = x:r
    | otherwise = r
        where 
            r = filtra teste xs

filtra' _ [] = []
filtra' teste (x:xs)
    | teste x = x:r
    | otherwise = r
        where 
            r = filtra' teste xs

comparaLista :: [Integer] -> [Integer] -> Bool
comparaLista [] [] = True
comparaLista [] (_:_) = False
comparaLista (_:_) [] = False
comparaLista (x:xs) (y:ys)
    | x == y = comparaLista xs ys
    | otherwise = False