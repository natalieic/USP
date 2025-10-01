-- Natalie Isernhagen Coelho - 15481332
main = do
    line <- getLine
    let pins = map read $ words line :: [Int]
    putStrLn $ score 1 0 pins

score :: (Num a, Eq a, Show a) => a -> a -> [a] -> String
score _ sum (r:[]) = checkStrike r ++ "| " ++ show (sum + r)
score _ sum (r1:r2:[]) = checkStrike r1 ++ checkSpare r1 r2 ++ "| " ++ show (sum + r1 + r2)
score cnt sum (roll1:roll2:roll3:r) = score1 ++ score2 ++ nextscore
    where
        score1 = checkStrike roll1
        score2
            | strike && lastFrame = checkStrike roll2
            | strike = "_ "
            | spare = "/ "
            | otherwise = show roll2 ++ " "
        nextscore
            | spare && lastFrame = checkSpare roll2 roll3 ++ "| " ++ show (sum + 10 + roll3)
            | strike && lastFrame = checkSpare roll2 roll3 ++ "| " ++ show (sum + 10 + roll2 + roll3)
            | strike = "| " ++ score (cnt + 1) (sum + 10 + roll2 + roll3) (roll2:roll3:r)
            | spare = "| " ++ score (cnt + 1) (sum + 10 + roll3) (roll3:r)
            | otherwise = "| " ++ score (cnt + 1) (sum + roll1 + roll2) (roll3:r)
        strike = roll1 == 10
        spare = roll1 + roll2 == 10
        lastFrame = cnt == 10

checkStrike :: (Eq a, Num a, Show a) => a -> String
checkStrike r
    | r == 10 = "X "
    | otherwise = show r ++ " "

checkSpare :: (Eq a, Num a, Show a) => a -> a -> String
checkSpare r1 r2
    | r1 + r2 == 10 = "/ "
    | r2 == 10 = "X "
    | otherwise = show r2 ++ " "