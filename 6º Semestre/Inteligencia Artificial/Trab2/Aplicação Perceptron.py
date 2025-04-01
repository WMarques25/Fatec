# -*- coding: utf-8 -*-
"""
Criado: Seg 31/03/25

@autor: wmarques25 
"""

from typing import List
import matplotlib.pyplot as plt
import numpy as np

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
    taxa_aprendizagem = 0.5
    
    saida_parcial = perceptron_output(sinapses, entradas)
    
    for j in range(3):
        sinapses[j] = sinapses[j] +  taxa_aprendizagem * (saida[0] - saida_parcial) * entradas[j]
    
    saida = saida_parcial
    return sinapses, saida

def teste_generalizacao(sinapses, entradas, saida):
    saida_parcial = perceptron_output(sinapses, entradas)
    saida = saida_parcial
    return sinapses, saida

# Inicialização dos pesos do Perceptron
neuronio = [0.5, -0.2, 0.3]  # Pesos iniciais

# Dados de treinamento: [viés, Re, velocidade]  
# Fluxo laminar (Re < 2300) -> Classe 0
# Fluxo turbulento (Re >= 2300) -> Classe 1

padrao0 = [-1, 500, 1.0]   # Laminar
padrao1 = [-1, 1000, 1.2]  # Laminar
padrao2 = [-1, 1500, 1.5]  # Laminar
padrao3 = [-1, 2000, 1.8]  # Laminar
padrao4 = [-1, 2200, 2.0]  # Laminar

padrao5 = [-1, 2500, 2.2]  # Turbulento
padrao6 = [-1, 3000, 2.5]  # Turbulento
padrao7 = [-1, 3500, 2.8]  # Turbulento
padrao8 = [-1, 4000, 3.0]  # Turbulento
padrao9 = [-1, 4500, 3.2]  # Turbulento

saida0 = [0]  # Classe 0 - Laminar
saida1 = [1]  # Classe 1 - Turbulento

# 11 ciclos de treinamento
n = 0
for _ in range(15):
    neuronio, saida_0 = ajustes(neuronio, padrao0, saida0)
    print(neuronio, "saida0 = ", saida_0)
    neuronio, saida_0 = ajustes(neuronio, padrao1, saida0)
    print(neuronio, "saida0 = ", saida_0)
    neuronio, saida_0 = ajustes(neuronio, padrao2, saida0)
    print(neuronio, "saida0 = ", saida_0)
    neuronio, saida_0 = ajustes(neuronio, padrao3, saida0)
    print(neuronio, "saida0 = ", saida_0)
    neuronio, saida_0 = ajustes(neuronio, padrao4, saida0)
    print(neuronio, "saida0 = ", saida_0)
    neuronio, saida_1 = ajustes(neuronio, padrao5, saida1)
    print(neuronio, "saida1 = ", saida_1)
    neuronio, saida_1 = ajustes(neuronio, padrao6, saida1)
    print(neuronio, "saida1 = ", saida_1)
    neuronio, saida_1 = ajustes(neuronio, padrao7, saida1)
    print(neuronio, "saida1 = ", saida_1)
    neuronio, saida_1 = ajustes(neuronio, padrao8, saida1)
    print(neuronio, "saida1 = ", saida_1)
    neuronio, saida_1 = ajustes(neuronio, padrao9, saida1)
    print(neuronio, "saida1 = ", saida_1)
    
    n += 1
    print ("número de ciclos = ", n)
    

# Extração dos pontos para plotagem
# Classe 0: padrao0 a padrao4; Classe 1: padrao5 a padrao9
Re_class0 = [padrao0[1], padrao1[1], padrao2[1], padrao3[1], padrao4[1]]
v_class0 = [padrao0[2], padrao1[2], padrao2[2], padrao3[2], padrao4[2]]
Re_class1 = [padrao5[1], padrao6[1], padrao7[1], padrao8[1], padrao9[1]]
v_class1 = [padrao5[2], padrao6[2], padrao7[2], padrao8[2], padrao9[2]]

# Geração do gráfico
plt.figure(figsize=(8, 6))
plt.scatter(Re_class0, v_class0, color='blue', label='Fluxo Laminar')
plt.scatter(Re_class1, v_class1, color='red', label='Fluxo Turbulento')

# Cálculo da fronteira de decisão: 
# -w0 + w1*Re + w2*v = 0  =>  v = (w0 - w1*Re) / w2
w0, w1, w2 = neuronio
Re_range = np.linspace(min(Re_class0), max(Re_class1), 100)
v_boundary = (w0 - w1 * Re_range) / w2
plt.plot(Re_range, v_boundary, color='green', linestyle='--', label='Fronteira de Decisão')

plt.xlabel("Número de Reynolds (Re)")
plt.ylabel("Velocidade (v)")
plt.title("Classificação de Fluxo Laminar vs. Turbulento")
plt.legend()
plt.grid(True)
plt.show()


# Teste de Generalização

p0 = [-1, 1800, 1.6]
p1 = [-1, 2300, 2.1]
p2 = [-1, 2800, 2.3]
p3 = [-1, 5000, 3.5]
p4 = [-1, 1000, 1.4]

# Testes
print("Testes de Generalização")
neuronio, saida_0 = teste_generalizacao(neuronio, p0, saida0)
print(neuronio, "saida0=", saida_0)
neuronio, saida_0 = teste_generalizacao(neuronio, p1, saida0)
print(neuronio, "saida0=", saida_0)
neuronio, saida_0 = teste_generalizacao(neuronio, p2, saida0)
print(neuronio, "saida0=", saida_0)
neuronio, saida_0 = teste_generalizacao(neuronio, p3, saida0)
print(neuronio, "saida0=", saida_0)
neuronio, saida_0 = teste_generalizacao(neuronio, p4, saida0)
print(neuronio, "saida0=", saida_0)
