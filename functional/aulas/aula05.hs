main = do
    putStrLn $ show $ pega 10 $ eratostenes [2..100]
    putStrLn $ show $ pegaEnquanto (< 1000) primos
    putStrLn $ show $ zipa [1..7] "Natalie"
    putStrLn $ show $ zipaCom (+) [1..] primos
    putStrLn $ show $ zipaCom (,) [1..] primos

primos = crivo [2..]
    where
        crivo [] = []
        --crivo (x:xs) = x:(crivo $ filtra (\y -> y `mod` x /= 0) xs)
        crivo (x:xs) = x:(crivo $ filtra ((/=0).(`mod` x)) xs)

--(.) :: (a -> b) -> (c -> a) -> (c -> b) -- composição de funções   

uns = 1:uns

eratostenes [] = []
eratostenes (x:xs) = x:(eratostenes $ filtra (naoMultiplo x) xs)

naoMultiplo :: Integer -> Integer -> Bool
naoMultiplo x y = y `mod` x /= 0

filtra :: (a -> Bool) -> [a] -> [a]
filtra _ [] = []
filtra teste (x:xs)
    | teste x = x:filtra teste xs
    | otherwise = filtra teste xs

pega :: Integer -> [a] -> [a]
pega _ [] = []
pega 0 _ = []
pega n (x:xs) = x:pega (n-1) xs

pegaEnquanto :: (a -> Bool) -> [a] -> [a]
pegaEnquanto _ [] = []
pegaEnquanto teste (x:xs)
    | teste x = x:pegaEnquanto teste xs
    | otherwise = []

ignoraEnquanto :: (a -> Bool) -> [a] -> [a]
ignoraEnquanto _ [] = []
ignoraEnquanto teste (x:xs)
    | teste x = ignoraEnquanto teste xs
    | otherwise = x:xs

zipa :: [a] -> [b] -> [(a,b)]
zipa [] _ = []
zipa _ [] = []
zipa (x:xs) (y:ys) = (x, y):zipa xs ys

primeiro :: (a, b) -> a
primeiro (x, _) = x

segundo :: (a, b) -> b
segundo (_, x) = x

zipaCom :: (a -> b -> c) -> [a] -> [b] -> [c]
zipaCom _ _ [] = []
zipaCom _ [] _ = []
zipaCom op (x:xs) (y:ys) = (op x y):zipaCom op xs ys