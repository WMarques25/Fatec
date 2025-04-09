# -*- coding: utf-8 -*-
"""
Criado: Seg 07/04/25

@autor: wmarques25
"""

# Solução do XOR

from typing import List
import math

Vector = List[float]

def dot(v: Vector, w: Vector) -> float:
    assert len(v) == len(w)
    return sum(v_i * w_i for v_i,w_i in zip(v,w))
assert dot([1, 2, 3], [4, 5, 6]) == 32

def sigmoid(t):
    return 1 / (1 + math.exp(-t))

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

sinapses_xor = [
    [[20, 20, -30],
     [20, 20, -10]],
    [[-60, 60, -30]]]

for x in [0, 1]:
    for y in [0, 1]:
        print (x, " XOR ", y, " = ", feed_forward(sinapses_xor, [x, y])[-1])