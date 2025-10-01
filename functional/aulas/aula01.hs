main = do --monad
  putStrLn "Hello World"
  putStrLn $ show y
  putStrLn $ show $ g 5.1
  putStrLn $ show $ h 4  $ 4 < 5
  putStrLn $ show $ j 40
  putStrLn $ show $ k o1



x = x + 1
y = 6.2
z = y + 1

a = True
b = False
c = 5 < y

f True = 5 -- função
f False = 42

g x = 42 + x


t x = x > 5

h x True = x - 1
h x False = x + 1

j 0 = 1
j x = x * j (x - 1) -- fatorial

o1 = []
o2 = [5]
o3 = [1, 2, 3, 4, 5]
-- o4 = [9, "oi", 3] -- errada
o5 = [True, False, False, y < 6, x > 0] 
o6 = 7:o2

k [] = 0
k (x:xs) = x + k xs -- retorna a soma da lista

lista = [(*2), (+5), g]