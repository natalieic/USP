import pandas as pd

df = pd.read_csv("(url)")

print(df.head()) #?
print(list(df['origin'])) # lista as data series do data frame
print(df[['origin', 'name']]) # retorna um df só com as colunas indicadas
print(df['origin'] == 'usa') # retorna um data series com os valores de cada linha pra origin == usa
print(df[df['origin'] == 'usa']) # imprime só as linhas que o origin é usa (filter)
print(df[df['origin'] == 'usa']['name']) # imprime só o campo nome das linhas '' (map em cima do de cima)

a = df[df['origin'] == 'usa'][['name', 'horsepower', 'weight']]
print(a)

a = df.assign(ratio=lambda x: x['weight'] / x['horsepower']) # cria outro df, mas sem copiar
print(a) # imprime o antigo + o novo, que é só a parte mudada

a = (
    df.assign(ratio=lambda x: x['weight'] / x['horsepower'])
    .groupby('origin')
    ['ratio'] # cria um slice só com o ratio
    .max()
    .sort_values()
) # a é o df com o maior ratio por origin do maior para o menor