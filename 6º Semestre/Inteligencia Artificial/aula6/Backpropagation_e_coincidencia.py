# -*- coding: utf-8 -*-
"""
Criado: Seg 14/04/25

@autor: wmarques25
"""

import matplotlib.pyplot as plt
import numpy as np
import math, random
from typing import List

Vector = List[float]

def dot(v: Vector, w: Vector) -> float:
    assert len(v) == len(w)
    return sum(v_i * w_i for v_i,w_i in zip(v,w))
assert dot([1, 2, 3], [4, 5, 6]) == 32

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

hidden_layer = [[-0.1, -1.1, 1.55], [-0.91, -0.81, 0.125]]
output_layer = [[0.2, -2.1, 0.98]]

e_network = [hidden_layer, output_layer]

print("e_network = ", e_network, "\n\n")

inputs = [[0,0], [0,1], [1,0], [1,1]]
targets = [[1],[0],[0],[1]]

# Treinamento
for n in range(10000):
    for input_vector, target_vector in zip(inputs, targets):
        backpropagation(e_network, input_vector, target_vector)

print("pesos sinapticos atualizados = ", e_network, "\n\n")

for x in [0,1]:
    for y in [0,1]:
        print(x, " COINCIDENCIA ", y, " = ", feed_forward(e_network, [x, y])[-1])