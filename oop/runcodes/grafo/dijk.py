import heapq as hq

class Grafo :
    # Recebe uma lista de triplas no formato (u, v, w)
    # e cria um dicionário que relaciona um vértice a 
    # um dicionário de vizinhos e pesos
    def __init__(self, arestas = []):
        self.G = {}

        for tripla in arestas :
            u, v, w = tripla

            if u not in self.G :
                self.G[u] = {}

            self.G[u][v] = w

    # Método que determina os menores caminhos do vértice u a todos os
    # outros pelo algoritmo de Dijkstra
    def menores_caminhos(self, u) :
        # Inicializa o dicionário status com nome do vértice, 
        # distância = inf, visitado = False e caminho vazio
        status = {v : {"distancia": float('inf'), "visitado": False, "caminho" : []} for v in self.G}

        status[u]["distancia"] = 0 # Distância ao vértice inicial recebe 0
        fila = []
        hq.heappush(fila, (status[u]["distancia"], u))

        while fila :
            dist_u, v = hq.heappop(fila)
            if status[v]["visitado"] : continue
            status[v]["visitado"] = True

            for adj in self.G[v] :
                dist = self.G[v][adj]
                nova_dist = dist + dist_u

                if nova_dist < status[adj]["distancia"] :
                    status[adj]["distancia"] = nova_dist
                    status[adj]["caminho"] = status[v]["caminho"] + [adj]
                    hq.heappush(fila, (nova_dist, adj))

        caminhos = Caminhos(u)
        for adj in status :
            caminhos.mapear(adj, status[adj]["distancia"], status[adj]["caminho"])

        return caminhos


    def get_vertices(self) :
        return [u for u in self.G]
    

# Classe que representa caminhos de um vértice origem a quaisquer destinos    
class Caminhos :
    def __init__(self, u) :
        self.origem = u
        self.C = {}

    def mapear(self, destino, distancia, trajeto) :
        if destino is not self.origem :
            self.C[destino] = (distancia, trajeto)

    def __str__(self) :
        s = ""
        for destino in self.C :
            dist, trajeto = self.C[destino]
            s += (f'{self.origem} para {destino}\n')
            s += (f'\tDistancia: {dist}\n'.replace(".", ","))
            s += (f'\tCaminho: ')
            s += " --> " + " --> ".join(trajeto)
            s += "\n"
        s += "---------------------------------------------"

        return s


def main() :
    # Lê as linhas da entrada
    linhas = []
    try :
        while True :
            linhas.append(input())
    except EOFError :
        pass

    arestas = processa_entrada(linhas)

    G = Grafo(arestas)

    vertices = G.get_vertices()

    caminhos_minimos = []
    for v in vertices :
        caminhos_minimos = G.menores_caminhos(v)
        print(caminhos_minimos)


def processa_entrada(linhas) :
    # Cria uma lista onde cada elemento é uma linha do input
    # e separa as linhas com espaços em dois elementos
    partes = []
    for linha in linhas : 
        linha = linha.strip()
        if not linha : continue
        partes.append(linha.split())

    # Cria uma lista de arestas no formato [(u, v, w)]
    arestas = []
    atual = None
    for linha in partes :
        if len(linha) == 1 :
            atual = linha[0]
        elif len(linha) == 2 :
            u, v, w = atual, linha[0], float(linha[1])
            arestas.append((u, v, w))

    return arestas
    

if __name__ == "__main__":
    main()