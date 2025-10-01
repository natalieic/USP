main = do
    l1 <- getLine
    l2 <- getLine
    l3 <- getLine
    let a = read l1
    let b = read l2
    let c = read l3

    putStrLn $ heron a b c

isTriangle a b c
    | a > b + c = False
    | b > a + c = False
    | c > a + b = False
    | otherwise = True

heron a b c
    | isTriangle a b c == True = show $ sqrt(p * (p - a) * (p - b) * (p - c))
    | otherwise = "-"
        where
            p = (a + b + c)/2