# -*- coding: utf-8 -*-
"""
Criado: Seg 17/02/25

@autor: wmarques25 
"""

from typing import List

Vector = List[float]

def dot(v: Vector, w: Vector) -> float:
    assert len(v) == len(w)
    return sum(v_i * w_i for v_i,w_i in zip(v,w))
assert dot([1, 2, 3], [4, 5, 6]) == 32

def step_function(x):
    return 1 if x >= 1.5 else 0

def perceptron_output(weights, bias, x):
    calculation = dot(weights, x) + bias
    return step_function(calculation)

x0 = [0, 0]
x1 = [0, 1]
x2 = [1, 0]
x3 = [1, 1]

weights = [1, 1]
bias = 0

saida0 = perceptron_output(weights, bias, x0)
saida1 = perceptron_output(weights, bias, x1)
saida2 = perceptron_output(weights, bias, x2)
saida3 = perceptron_output(weights, bias, x3)

print("PERCEPTRON IMPLEMENTANDO FUNÇÃO AND")
print("0 AND 0 =", saida0)
print("0 AND 1 =", saida1)
print("1 AND 0 =", saida2)
print("1 AND 1 =", saida3)