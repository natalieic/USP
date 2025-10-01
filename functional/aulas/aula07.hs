main = do
    putStrLn $ show $ horaDeAcordar Ter
    putStrLn $ show $ Dom
    putStrLn $ show $ elem Sab [Seg, Ter, Sex]
    putStrLn $ show $ [Seg .. Sex]
    -- l <- getLine
    -- let d = read l
    -- putStrLn $ show $ elem d [Seg, Ter, Sex]
    putStrLn $ show $ elem Jun [Jan, Fev, Nov]
    -- putStrLn $ show $ Nula
    putStrLn $ show $ criaNo 10
    -- putStrLn $ show $ 
    --     bst_inserir 10 $
    --     bst_inserir 5 $
    --     bst_inserir 8 $
    --     bst_inserir 20 Nula
    putStrLn $ show $ 
        adicionaElem 10 $
        adicionaElem 5 $
        adicionaElem 8 $
        adicionaElem 20 Nula

    putStrLn $ show $ encontra (>10) [4, 5, 10, 19, 30]
    putStrLn $ show $ 
        case encontra (>100) [4, 5, 10, 19, 30] of
            Nada -> "Nao encontrado"
            Algum x -> "Encontrado: " ++ show x

    putStrLn $ show $ multTest1 (>7) (<4) [4, 5, 10, 19, 3]
    putStrLn $ show $ multTest2 (>7) (<4) [4, 5, 10, 19, 3]

data DiaDaSemana = Dom | Seg | Ter | Qua | Qui | Sex | Sab
    deriving (Enum, Read)
instance Show DiaDaSemana where
    show Dom = "Sun"
    show Seg = "Mon"
    show Ter = "Tue"
    show Qua = "Wed"
    show Qui = "Thu"
    show Sex = "Fri"
    show Sab = "Sat"

-- elem :: (Eq a ) => a -> [a] -> Bool
instance Eq DiaDaSemana where
    Dom == Dom = True
    Dom == _ = False
    Sab == Sab = True
    Sab == _ = False
    Sex == Sex = True
    Sex == _ = False
    _ == _ = True

-- instance Enum DiaDaSemana where
--     succ Dom = Seg
--     succ Seg = Ter

--     pred Seg = Dom
--     pred Ter = Seg

horaDeAcordar :: DiaDaSemana -> (Integer, Integer)
horaDeAcordar Dom = (9, 30)
horaDeAcordar Sab = (8, 0)
horaDeAcordar _ = (7, 15)

data Mes = Jan | Fev | Mar | Abr | Mai | Jun | Jul | Ago | Set | Out | Nov | Dez
    deriving (Eq, Show, Read, Ord, Enum, Bounded)

-- data BST = Nula | No BST Integer BST
--     deriving (Show, Read, Eq)

criaNo :: a -> Arvore a
criaNo x = No Nula x Nula

-- bst_inserir :: Integer -> BST -> BST
-- bst_inserir x Nula = criaNo x
-- bst_inserir x (No e n d)
--     | x == n = No e n d
--     | x < n = No (bst_inserir x e) n d
--     | otherwise = No e n (bst_inserir x d)

data Arvore a = Nula | No (Arvore a) a (Arvore a)
    deriving (Show, Read, Eq)

adicionaElem :: (Ord a) => a -> Arvore a -> Arvore a
adicionaElem x Nula = criaNo x
adicionaElem x (No e n d)
    | x == n = No e n d
    | x < n = No (adicionaElem x e) n d
    | otherwise = No e n (adicionaElem x d)

data Talvez a = Nada | Algum a
    deriving (Eq, Ord, Show, Read)

encontra :: (a -> Bool) -> [a] -> Talvez a
encontra _ [] = Nada
encontra teste (x:xs)
    | teste x = Algum x
    | otherwise = encontra teste xs

multTest1 :: (Num a) => (a->Bool) -> (a -> Bool) -> [a] -> a
multTest1 t1 t2 l =
    case encontra t1 l of
        Nada -> 0
        Algum x1 -> case encontra t2 l of 
                        Nada -> 0
                        Algum x2 -> x1 * x2

multTest2 :: (Num a) => (a->Bool) -> (a -> Bool) -> [a] -> Talvez a
multTest2 t1 t2 l =
    case encontra t1 l of
        Nada -> Nada
        Algum x1 -> case encontra t2 l of 
                        Nada -> Nada
                        Algum x2 -> Algum (x1 * x2)

multTest3 :: (Num a) => (a->Bool) -> (a -> Bool) -> [a] -> Talvez a
multTest3 t1 t2 l =
    case (encontra t1 l, encontra t2 l ) of
        (Algum x1, Algum x2) -> Algum (x1 * x2)
        _ -> Nada