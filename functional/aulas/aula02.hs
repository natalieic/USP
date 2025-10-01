main = do
    la <- getLine -- setinha da função impura
    let a = read la
    lb <- getLine
    let b = read lb
    lc <- getLine
    let c = read lc
    let res = bhaskara a b c -- let da função pura
    -- ou let res = bhaskara (read la) (read lb) (read lc)
    putStrLn $ show $ res
    {- haskell só vai atrás do a, b e c quando for usar. 
       Como ele sabe que na func bhaskara a, b e c são 
       números, o read converte a str em número -}
    {- let res = bhaskara a b c nessa linha não funciona pq a main 
       é impura e executa em ordem -}

    {-
    putStrLn $ explica $ bhaskara a b c
        where
            explica [] = "Não há raízes"
            explica [x] = "Há uma raiz: " ++ show x
            explica [x1, x2] = "Há duas raízes: " ++ show x1 ++ show x2
    -}

sinal x
    | x < 0 = -1
    | x == 0 = 0
    | otherwise = 1
    -- guarda

sinal2 x = if x < 0
            then -1
            else if x == 0
                    then 0
                    else 1

absoluto x
    | x >= 0 = x
    | otherwise = -x

somaPos [] = 0
somaPos (x:xs)
    | x > 0 = x + somaPos xs
    | otherwise = somaPos xs

somaPos2 (x:xs)
    | x > 0 = x + sc
    | otherwise = sc
        where
            sc = somaPos2 xs
        -- where se aplica a todos os casos da guarda

bhaskara a b c
    | delta < 0 = []
    | delta == 0 = [x]
    | otherwise = [x', x'']
        where
            delta = b^2 - 4*a*c
            x = (-b)/(2*a)
            x' = (-b + sqrt(delta))/(2*a)
            x'' = (-b - sqrt(delta))/(2*a)
        {- x, x' e x'' são usados só uma vez mas o where
         é usado pra nomear esses resultados e para organização estética -}

bhaskaraFelipe a b c
    | delta < 0 = []
    | delta == 0 = [x]
    | otherwise = [x', x'']
        where
            delta = b^2 - 4*a*c
            x = (-b)/(2*a)
            x' = (-b + raizD)/(2*a)
            x'' = (-b - raizD)/(2*a)
            raizD = sqrt(delta)
        -- sqrt(delta) era calculado duas vezes