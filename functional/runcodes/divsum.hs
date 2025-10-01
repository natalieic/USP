main = do
    -- Recebe duas linhas de input do usuário
    l1 <- getLine 
    l2 <- getLine
    let num1 = read l1 :: Integer
    let num2 = read l2 :: Integer

    let lst =    -- Transfroma em uma lista de pares (numero, [divisores própios])
                operaLista (\(x:xs) -> (x, xs)) $
                 -- Para cada lista, filtra os elementos da cauda que são divisores da cabeça
                operaLista (\(x:xs) -> filtra (\y -> y `divisor` x) (x:xs)) $
                 -- Para cada elemento x da lista, transforma em uma lista de x a zero
                operaLista (\x -> [x, x-1..0]) $
                -- Gera uma lista com os números de num1 a num2
                trataZero [min num1 num2 .. max num1 num2] 

    -- Filtra os pares defeituosos e imprime a quantidade
    putStrLn $ show $ contaLista $ filtra (\(x, y) -> x > somaLista y) lst
    -- Filtra os pares perfeitos e imprime a quantidade
    putStrLn $ show $ contaLista $ filtra (\(x, y) -> x == somaLista y) lst
    -- Filtra os pares abundantes e imprime a quantidade
    putStrLn $ show $ contaLista $ filtra (\(x, y) -> x < somaLista y) lst

{- 
    Função que realiza uma operação op sobre todos 
    os elementos de uma lista
 -}
operaLista :: (a -> b) -> [a] -> [b]
operaLista _ [] = []
operaLista op (x:xs) = op x:operaLista op xs

{- 
    Função que reduz uma lista aos elementos que 
    satisfazem uma condição 
 -}
filtra :: (a -> Bool) -> [a] -> [a]
filtra _ [] = []
filtra condicao (x:xs)
    | condicao x = x:filtra condicao xs
    | otherwise = filtra condicao xs

{- 
    Função que verifica se um inteiro 'a' é 
    divisor de outro 'b'
 -}
divisor :: Integer -> Integer -> Bool
b `divisor` a = b /= 0 && a `mod` b == 0

{- 
    Função que soma a quantidade de elementos 
    em uma lista
 -}
somaLista :: (Num a) => [a] -> a
somaLista [] = 0
somaLista (x:xs) = x + somaLista xs

{- 
    Função que conta a quantidade de elementos 
    em uma lista
 -}
contaLista :: [a] -> Integer
contaLista [] = 0
contaLista (x:xs) = 1 + contaLista xs

{-
    Função que arbitrariamente substitui os zeros de 
    uma lista pelo número doze (que também é abundante)
-}
trataZero [] = []
trataZero (x:xs)
    | x == 0 = 12:trataZero xs
    | otherwise = x:trataZero xs
