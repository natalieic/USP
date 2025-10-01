-- Prelude contém as funções já implementadas em haskell
import Data.List ( nomeDaFuncao )
import qualified Data.Maybe as DM
main = do
    -- soma dos quadrados dos ímpares de a
    putStrLn $ show $ sum $ map $ (^2) $ filter ((==1).(`mod` 2)) a

    putStrLn $ show $ DM.nub a -- nub filtra os elementos únicos

a = [3, 4, 2, 5, 1, 2, 3, 4, 7, 8]