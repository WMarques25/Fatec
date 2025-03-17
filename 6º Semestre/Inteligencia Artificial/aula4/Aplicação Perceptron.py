# -*- coding: utf-8 -*-
"""
Criado: Seg 17/03/25

@autor: wmarques25 
"""

from typing import List
import matplotlib.pyplot as plt

Vector = List[float]

def dot(v: Vector, w: Vector) -> float:
    assert len(v) == len(w)
    return sum(v_i * w_i for v_i,w_i in zip(v,w))
assert dot([1, 2, 3], [4, 5, 6]) == 32

def degrau(x):
    return 1 if x >= 0 else 0

def perceptron_output(pesos, entradas):
    y = dot(pesos, entradas)
    return degrau(y)

def ajustes(sinapses, entradas, saida):
    taxa_aprendizagem = 0.08
    
    saida_parcial = perceptron_output(sinapses, entradas)
    
    for j in range(3):
        sinapses[j] = sinapses[j] +  taxa_aprendizagem * (saida[0] - saida_parcial) * entradas[j]
    
    saida = saida_parcial
    return sinapses, saida

def teste_generalizacao(sinapses, entradas, saida):
    saida_parcial = perceptron_output(sinapses, entradas)
    saida = saida_parcial
    return sinapses, saida

neuronio = [0.22, -0.33, 0.44]
padrao_0_0 = [-1, 0.1, 0.1]
padrao_0_1 = [-1, 0.1, 0.5]
padrao_0_2 = [-1, 0.3, 0.3]
padrao_1_0 = [-1, 0.6, 0.6]
padrao_1_1 = [-1, 0.8, 0.2]
padrao_1_2 = [-1, 0.9, 0.5]

saida0 = [0]
saida1 = [1]

# 11 ciclos de treinamento
n = 0
for _ in range(11):
    neuronio, saida_0 = ajustes(neuronio, padrao_0_0, saida0)
    print(neuronio, "saida0 = ", saida_0)
    neuronio, saida_0 = ajustes(neuronio, padrao_0_1, saida0)
    print(neuronio, "saida0 = ", saida_0)
    neuronio, saida_0 = ajustes(neuronio, padrao_0_2, saida0)
    print(neuronio, "saida0 = ", saida_0)
    neuronio, saida_1 = ajustes(neuronio, padrao_1_0, saida1)
    print(neuronio, "saida1 = ", saida_1)
    neuronio, saida_1 = ajustes(neuronio, padrao_1_1, saida1)
    print(neuronio, "saida1 = ", saida_1)
    neuronio, saida_1 = ajustes(neuronio, padrao_1_2, saida1)
    print(neuronio, "saida1 = ", saida_1)
    n += 1
    print ("número de ciclos = ", n)

x = [0.9, 0.8, 0.7, 0.6, 0.5, 0.4, 0.3, 0.2, 0.1, 0.0]
y = [-0.125, -0.0125, 0.1, 0.2125, 0.325, 0.4375, 0.55, 0.6625, 0.775, 0.8875]
# y = 1.0 - 1.125*x - eq da reta de separação de clases

x1 = [0.1, 0.1, 0.3]
x2 = [0.6, 0.8, 0.9]
y1 = [0.1, 0.5, 0.3]
y2 = [0.6, 0.2, 0.5]

# insere os pontos no grafico {x1, x2, y1, y2}
plt.scatter(x1, y1)
plt.scatter(x2, y2)

# plota a reta x, y
plt.plot(y, x, color = 'green', marker = '*', linestyle = '--')

# definição dos nomes das opçoes linestyle
"""
a valid value for ls; supported values are '-',

"""

plt.title("separação de classes com Perceptron")

plt.xlabel("Eixo X")
plt.ylabel("Eixo Y")
plt.show()

# Teste de Generalização
pt0 = [-1, 0.2, 0.4]
pt1 = [-1, 0.7, 0.8]
pt2 = [-1, 0.6, 0.3]
pt3 = [-1, 0.1, 0.9]
pt4 = [-1, 0.2, 0.6]
pt5 = [-1, 0.8, 0.1]

# Testes
print("Testes de Generalização")
neuronio, saida_0 = teste_generalizacao(neuronio, pt0, saida0)
print(neuronio, "saida0=", saida_0)
neuronio, saida_1 = teste_generalizacao(neuronio, pt1, saida1)
print(neuronio, "saida1=", saida_1)
neuronio, saida_0 = teste_generalizacao(neuronio, pt2, saida0)
print(neuronio, "saida0=", saida_0)
neuronio, saida_1 = teste_generalizacao(neuronio, pt3, saida1)
print(neuronio, "saida1=", saida_1)
neuronio, saida_0 = teste_generalizacao(neuronio, pt4, saida0)
print(neuronio, "saida0=", saida_0)
neuronio, saida_1 = teste_generalizacao(neuronio, pt5, saida1)
print(neuronio, "saida1=", saida_1)