main = do
    s1 <- getLine
    s2 <- getLine
    let lb = read s1
    let ub = read s2

    -- putStrLn $ show $ takeWhile (<=ub) $ dropWhile (<lb) $ crivo [2..]
    putStrLn $ show $ abs $ minimo 0 $ opDoisADois (-) $ takeWhile (<=ub) $ dropWhile (<lb) $ crivo [2..]

crivo [] = []
crivo (x:xs) = x:(crivo $ filter ((/=0).(`mod` x)) xs)

opDoisADois :: (Eq a) => (a -> a -> a) -> [a] -> [a]
opDoisADois _ [] = []
opDoisADois  _ (x:[]) = []
opDoisADois op (x:y:zs)
    | zs == [] = op x y : []
    | otherwise = op x y : opDoisADois op (y:zs)

minimo minAtual [] = minAtual
minimo minAtual (x:xs)
    | x < minAtual = minimo x xs
    | otherwise = minimo minAtual xs