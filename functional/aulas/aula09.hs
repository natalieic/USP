import System.IO
import Data.List (sortBy)
import Data.Ord (comparing)

data Curso = BCC | BSI | EC
    deriving (Show, Read)
data Aluno = Aluno { -- funções nome, nusp, ..., que dado um aluno, retorna uma string, ou um int, etc.
    nome :: [Char], 
    nusp :: Integer, 
    curso :: Curso, 
    notas :: [Float]
    } -- tipo e construtor têm o mesmo nome
    deriving (Show, Read)

a1 :: Aluno
a1 = Aluno {
    nome = "Natalie",
    nusp = 15481332,
    curso = BCC,
    notas = [10, 9, 10, 6]
}
a2 = a1 {
    curso = BSI
}

a3 = Aluno {
    notas = [2,5, 8]
}

data Data = Data {
    ano :: Integer,
    mes :: Integer,
    dia :: Integer
}
    deriving (Show, Read)

type Idade = Integer
type Venda = Integer

data Vendedor = Vendedor{
    nome :: [Char],
    cpf :: [Char],
    uf :: [Char],
    aniversario :: Data
    dependentes :: [Idade]
    vendas :: [Venda]
}

processaVendedores l = map read $ lines contArq


main = do 
    h <- openFile "example.txt" ReadMode
    contents <- hGetContents h
    --hClose h fecha o arquivo sem ter executado o get contents

    let ls = lines contents
    let l = length ls
    putStrLn $ show l
    hClose h
    putStrLn $ show a1
    putStrLn $ show a2
    putStrLn $ show $ sum $ notas a1
    putStrLn $ show a3

    h <- openFile "vendedores.txt" ReadMode
    contArq <- hGetContents h
-- Numero de vendedores no estado de SP
    let vendedores = processaVendedores contArq
    putStrLn $
        show $
        length $
        filter ((=="SP") . uf) $
        vendedores
-- Soma das vendas dos vendedores de MG
    putStrLn $
        show $
        sum $
        map (sum . vendas) $ -- retorna uma lista da suma das vendas de cada vendedor
        filter ((=="MG") . uf) $
        vendedores
-- Primeiros nomes em ordem alfabética dos vendedores com pelo menos 3 dependentes
    putStrLn $
        show $ 
        map (head . words) $
        sort $
        map nome $
        filter ((>=3) . length . dependentes) $
        vendedores
-- vendedores ordenados pelo número de vendas 
    putStrLn $
        show $
        sortBy (flip (comparing (length . vendas))) $
        vendedores