# -*- coding: utf-8 -*-
"""
Criado: Seg 07/04/25

@autor: wmarques25
"""

# Solução do XOR

from typing import List
import matplotlib.pyplot as plt

Vector = List[float]

def dot(v: Vector, w: Vector) -> float:
    assert len(v) == len(w)
    return sum(v_i * w_i for v_i,w_i in zip(v,w))
assert dot([1, 2, 3], [4, 5, 6]) == 32

def degrau(x):
    return 1 if x >= 0 else 0

def neuronio_MCP(pesos, entradas):
    uk = dot(pesos, entradas)
    return degrau(uk)

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
    [[1, 1, -1.5],
     [1, 1, -0.5]],
    [[-2, 1, -0.5]]]

for x in [0, 1]:
    for y in [0, 1]:
        print (x, " XOR ", y, " = ", feed_forward(sinapses_xor, [x, y])[-1])