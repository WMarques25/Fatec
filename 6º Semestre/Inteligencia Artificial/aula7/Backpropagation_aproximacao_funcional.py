# -*- coding: utf-8 -*-
"""
Criado: Seg 28/04/25

@autor: wmarques25 
"""

from __future__ import division
from collections import Counter
from functools import partial
from turtle import title
from linear_algebra import dot
import matplotlib.pyplot as plt
import networkx
import numpy as np
import math, random

def sigmoid(t):
    return ((2 / (1 + math.exp(-t)))-1)

def neuronio_MCP(pesos, entradas):
    uk = dot(pesos, entradas)
    return sigmoid(uk)

def feed_forward(rede_xor, vetor_entrada):
    # Recebe uma rede neural e retorna a saida da propagação direta da entrada
    
    vetor_saida = []
    
    for ponteiro in rede_xor:
        entrada_com_bias = vetor_entrada + [1]
        saida = [neuronio_MCP(neuronio, entrada_com_bias)
                    for neuronio in ponteiro]
        vetor_saida.append(saida)
        
        vetor_entrada = saida

    return vetor_saida

alpha = 0.08

def backpropagation(rede_neural, vetor_entrada, vetor_saida):
    saidas_intermediarias, saidas_neuronios = feed_forward(rede_neural, vetor_entrada)
    deltas_saidas = [(0.5 * (1 + saida) * (1 - saida)) * (saida - vetor_saida[i]) * alpha
                     for i, saida in enumerate(saidas_neuronios)]
                    
    for i, neuronio_saida in enumerate(rede_neural[-1]):
        for j, saida_intermediaria in enumerate(saidas_intermediarias + [1]):
            neuronio_saida[j] -= deltas_saidas[i] * saida_intermediaria
            
    deltas_intermediarios = [ 0.5 * alpha * (1 + saida_intermediaria) * (1 - saida_intermediaria) *
                             dot(deltas_saidas, [n[i] for n in rede_neural[-1]])
                            for i, saida_intermediaria in enumerate(saidas_intermediarias)]
    
    for i, neuronio_intermediario in enumerate(rede_neural[0]):
        for j, input in enumerate(vetor_entrada + [1]):
            neuronio_intermediario[j] -= deltas_intermediarios[i] * input

def seno(x):
    seno = [(math.sin(math.pi/180*x)*math.sin(2*math.pi/180*x))]
    return [seno]

def predict(inputs):
    return feed_forward(network, inputs)[-1]

inputs = []
targets = []

# Treinamento
random.seed(0)
input_size = 1
num_hidden = 6
output_size = 1

hidden_layer = [[random.random() for __ in range(input_size + 1)] 
                    for __ in range(num_hidden)]

output_layer = [[random.random() for __ in range(num_hidden + 1)] 
                    for __ in range(output_size)]

network = [hidden_layer, output_layer]

for __ in range(300):
    for x in range(360):
        inputs = seno(x)
        targets = seno(x)
        for input_vector, target_vector in zip(inputs, targets):
            backpropagation(network, input_vector, target_vector)

fig, ax = plt.subplots()
ax.set(xlabel="ângulo (º)", ylabel="função sen(x)*sen(2x)", title="Aproximação Funcional")
ax.grid()
t = np.arange(0, 360, 1)

# teste da rede com predict
saida = []
for x in range(360):
    inputs = seno(x)
    targets = seno(x)
    for input_vector, target_vector in zip(inputs, targets):
        sinal_saida = predict(input_vector)
        saida.extend(sinal_saida)

entrada = []
for x in range(360):
    entrada += seno(x)

ax.plot(t, entrada)
ax.plot(t, saida)
plt.show()

print("Camada de Entrada: ", hidden_layer)
print("Camada de Saida: ", output_layer)