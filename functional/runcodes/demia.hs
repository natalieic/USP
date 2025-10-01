-- Natalie Isernhagen Coelho 15481332

import System.IO
import Data.List (sort, sortBy)
import Data.Ord (comparing)

main = do
    l <- getLine
    let [str1, str2, str3, str4] = words l
        n1 = read str1
        n2 = read str2
        n3 = read str3
        n4 = read str4

    csv <- openFile "dados.csv" ReadMode
    conteudo <- hGetContents csv

    let dados = extraiDados conteudo

    putStrLn $ 
        show $ 
        sum $ 
        map active $ 
        filter ((>= n1) . confirmed) dados

    putStrLn $ 
        show $ 
        sum $ 
        map deaths $ 
        take n3 $ 
        sortBy (comparing confirmed) $ 
        take n2 $ 
        sortBy (flip(comparing active)) dados

    putStr $ 
        unlines $
        sort $ 
        map country $ 
        take n4 $ 
        sortBy (flip(comparing confirmed)) dados

    hClose csv

data StatPais = StatPais {
        country :: String, 
        confirmed :: Integer, 
        deaths :: Integer, 
        recovery :: Integer,
        active :: Integer
    }
    deriving (Show, Read)

extraiDados :: String -> [StatPais]
extraiDados s = map convertePais $ map (split ',') $ lines s


convertePais :: [String] -> StatPais
convertePais [p, c, d, r, a] = 
    StatPais {
        country = p, 
        confirmed = read c, 
        deaths = read d, 
        recovery = read r, 
        active = read a
    }

split :: Char -> String -> [String]
split _ "" = [""]
split delim (x:xs)
    | x == delim = "":resto
    | otherwise = (x : head resto) : tail resto
    where
        resto = split delim xs
