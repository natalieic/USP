# Atividade realizada individualmente
# Natalie nUSP - 15481332

import random
from collections import Counter

class Dado :
    def __init__(self, lados, seed):
        self.lados = lados
        self.rand = random.Random(seed)
        self.rolar()
    
    def getLado(self):
        return self.face

    def rolar(self):
        self.face = self.rand.randint(1, self.lados)
        return self.face
    
    def toString(self):
        tercos = ["|     |\n", "|*    |\n", "|  *  |\n", "|    *|\n", "|*   *|\n", "|* * *|\n"]
        div = "+-----+\n"
        match self.face:
            case 1: strdado = div + tercos[0] + tercos[2] + tercos[0] + div
            case 2: strdado = div + tercos[1] + tercos[0] + tercos[3] + div
            case 3: strdado = div + tercos[1] + tercos[2] + tercos[3] + div
            case 4: strdado = div + tercos[4] + tercos[0] + tercos[4] + div
            case 5: strdado = div + tercos[4] + tercos[2] + tercos[4] + div
            case 6: strdado = div + tercos[5] + tercos[0] + tercos[5] + div

        return strdado

class RolaDados :
    def __init__(self, seed, n):
        self.ndados = n
        self.rand = random.Random(seed)
        self.dados = []
        for i in range(n):
            self.dados.append(Dado(6, self.rand.randint(1, 10000)))

    def rolar(self, quais):
        if len(quais) == 0:
            return [dado.getLado() for dado in self.dados]
        for i in quais:
            if 1 <= i <= 5:
                self.dados[i-1].rolar()
        return [dado.getLado() for dado in self.dados]
    
    def toString(self):
        # Quebra em uma string por linha
        linhas_dados = [dado.toString().split('\n') for dado in self.dados]
        linhas = ["    ".join(linha[i] for linha in linhas_dados) for i in range(5)]

        return "    \n".join(linhas) + "    \n"
    
class Placar :
    def __init__(self):
        self.placar = [(False, 0)] * 10

    def add(self, pos, dados):
        if self.placar[pos-1][0]:
            return False
        
        score = 0
        match pos:
            case 1:
                score = self.__conta(1, dados)
            case 2:
                score = 2 * self.__conta(2, dados)
            case 3:
                score = 3 * self.__conta(3, dados)
            case 4:
                score = 4 * self.__conta(4, dados)
            case 5:
                score = 5 * self.__conta(5, dados)
            case 6:
                score = 6 * self.__conta(6, dados)
            case 7: 
                if self.__checkFull(dados):
                    score = 15
            case 8:
                if self.__checkSeq(dados):
                    score = 2
            case 9:
                if self.__checkQuadra(dados):
                    score = 3
            case 10:
                if self.__checkQuina(dados):
                    score = 4
            case _:
                print("Valor da posição ilegal")
                return False

        self.placar[pos-1] = (True, score)

        return True

    def getScore(self):
        return sum(casa[1] for casa in self.placar if casa[0])
    
    def toString(self):
        div = "-------|----------|-------\n"
        valores = self.__valoresPlacar()

        ultimastr = valores[9]
        if valores[9] != '(10)':
            ultimastr = valores[9] + " "

        strplacar = valores[0] + "    |   " + valores[6] + "    |  " + valores[3] + " \n" + div
        strplacar += valores[1] + "    |   " + valores[7] + "    |  " + valores[4] + " \n" + div
        strplacar += valores[2] + "    |   " + valores[8] + "    |  " + valores[5] + " \n" + div
        strplacar += "       |   " + ultimastr + "   |\n       +----------+\n"

        return strplacar

    def __conta(self, valor, valores):
        return valores.count(valor)
    
    def __checkFull(self, valores):
        contagem = Counter(valores)
        return sorted(contagem.values()) == [2, 3]
    
    def __checkQuadra(self, valores):
        contagem = Counter(valores)
        return sorted(contagem.values()) == [2, 4]
    
    def __checkQuina(self, valores):
        contagem = Counter(valores)
        return sorted(contagem.values()) == [1, 5]
    
    def __checkSeq(self, valores):
        valores.sort()
        return (valores == list(range(1, 6))) or (valores == list(range(2, 7)))
    
    def __valoresPlacar(self):
        valores = []
        for idx, (taken, pts) in enumerate(self.placar):
            if taken:
                valores.append(f" {pts} ")
            else:
                valores.append(f"({idx + 1})")

        return valores
        
def bozo():
        seed = int(input("Digite a semente (zero para aleatório): "))
        dados = RolaDados(seed, 5)
        placar = Placar()
        print(placar.toString())

        for rodada in range(10):
            print("****** Rodada", (rodada + 1))
            input("Pressione ENTER para lançar os dados\n")
            dados.rolar([1, 2, 3, 4, 5])
            print("1          2          3          4          5")
            print(dados.toString())

            trocas = input("Digite os números dos dados que quiser TROCAR. Separados por espaços.\n")
            dados.rolar([int(x) for x in trocas.split() if x.isdigit()])
            print("1          2          3          4          5")
            print(dados.toString())

            trocas = input("Digite os números dos dados que quiser TROCAR. Separados por espaços.\n")
            resultado = dados.rolar(list(set(int(x) for x in trocas.split() if x.isdigit())))
            print("1          2          3          4          5")
            print(dados.toString())

            print("\n\n")
            print(placar.toString())

            while True:
                pos = (input("Escolha a posição que quer ocupar com essa jogada ===> "))
                pos = next((int(x) for x in pos.split() if x.isdigit()), None)
                if pos > 0 and pos <= 10 and placar.add(pos, resultado):
                    break
                print("Valor inválido. Posição ocupada ou inexistente.")

            print("\n\n")
            print(placar.toString())

        print("***********************************")
        print("***")
        print("*** Seu escore final foi:", placar.getScore())
        print("***")
        print("***********************************")


if __name__ == "__main__":
    bozo()