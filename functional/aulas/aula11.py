# funções como primeira classe
def inc(x):
    return x + 1

novnoInc = inc
outroInc = lambda x: x + 1


# funções de alta ordem
def mapa(f, a):
    res = []
    for x in a:
        res.append(f(x))

    return res

print(mapa(lambda x: x*2, [2, 3, 7, 9]))


# list comprehension
a = [3, 4, 2, 7, 0, 9]
b = [x*2 for x in a] # considerado funcional, não como um for imperativo
# haskell: b = [x*2 | x <- a]

fs = [inc, lambda x: x-1, lambda x: 2 ** x]
print(fs) # imprime o nome e o endereço da função
print([f(5) for f in fs])


# não tem transparência referencial
fs.append(lambda x: x ** 2)
print([f(5) for f in fs])
# os dois prints são iguais mas não dá pra saber o que eles printam
# fs pode ter sido mudado no meio do programa

def algumaCoisa(f, a):
    a.append(f)

algumaCoisa(lambda x: 0, fs)
print([f for f in fs])


# função não pura
i = 10
fs.append(lambda x: x + i)
print([f(5) for f in fs])

i = 0
print([f(5) for f in fs])


# sistema de tipos
fs.append(lambda x, y: x + y)
print([f(5) for f in fs]) # erro porque a função anexada recebe dois parâmetros e a list comprehension só manda 1
