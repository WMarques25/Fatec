# -*- coding: utf-8 -*-
"""
Criado: Seg 5/05/25

@autor: wmarques25 
"""

from linear_algebra import dot
import math, random

def sigmoid(t):
    return 1 / (1 + math.exp(-t))

def step_function(x):
    return 1 if x >= 0 else 0

def perceptron_output(weights, bias, x):
    return step_function(dot(weights, x) + bias)

def neuron_output(pesos, entradas):
    uk = dot(pesos, entradas)
    return sigmoid(uk)

def feed_forward(neural_network, input_vector):
    
    vetor_saida = []
    
    for ponteiro in neural_network:
        entrada_com_bias = input_vector + [1]
        saida = [neuron_output(neuronio, entrada_com_bias)
                    for neuronio in ponteiro]
        vetor_saida.append(saida)
        
        input_vector = saida

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

if __name__ == "__main__":
    raw_digits = [
        """..1..
           .1.1.
           1...1
           11111
           1...1""",
           
        """11111
           1....
           11111
           1....
           11111""",
           
        """11111
           ..1..
           ..1..
           ..1..
           11111""",

        """11111
           1...1
           1...1
           1...1
           11111""",

        """1...1
           1...1
           1...1
           1...1
           11111"""
    ]
    
    def make_digit(raw_digit):
        return [1 if c == '1' else 0
                for row in raw_digit.split('\n')
                for c in row.strip()]
    
    inputs = list(map(make_digit, raw_digits))

    targets = [[1 if i == j else 0 for i in range(10)]
               for j in range(10)]
    
    random.seed(0)
    input_size = 25
    num_hidden = 5
    output_size = 5
    
    hidden_layer = [[random.random() for __ in range(input_size + 1)]
                    for __ in range(num_hidden)]
    
    output_layer = [[random.random() for __ in range(num_hidden + 1)]
                    for __ in range(output_size)]

    network = [hidden_layer, output_layer]

    for __ in range(20000):
        for input_vector, target_vector in zip(inputs, targets):
            backpropagation(network, input_vector, target_vector)
    
    def predict(input):
        return feed_forward(network, input)[-1]
    
    for i, input in enumerate(inputs):
        outputs = predict(input)
        print(i, [round(p,2) for p in outputs])

    print("""
..@..
.@.@.
@...@
@@@@@
@...@""")
    print([round(x,2) for x in
           predict( [0,0,1,0,0,
                     0,1,0,1,0,
                     1,0,0,0,1,
                     1,1,1,1,1,
                     1,0,0,0,1])])
    print("""
@@@@@
@....
@@@@@
@....
@@@@@""")
    print([round(x,2) for x in
           predict( [1,1,1,1,1,
                     1,0,0,0,0,
                     1,1,1,1,1,
                     1,0,0,0,0,
                     1,1,1,1,1])])
    print("""
@@@@@
..@..
..@..
..@..
@@@@@""")
    print([round(x,2) for x in
           predict( [1,1,1,1,1,
                     0,0,1,0,0,
                     0,0,1,0,0,
                     0,0,1,0,0,
                     1,1,1,1,1])])
    print("""
@@@@@
@...@
@...@
@...@
@@@@@""")
    print([round(x,2) for x in
           predict( [1,1,1,1,1,
                     1,0,0,0,1,
                     1,0,0,0,1,
                     1,0,0,0,1,
                     1,1,1,1,1])])
    print("""
@...@
@...@
@...@
@...@
@@@@@""")
    print([round(x,2) for x in
           predict( [1,0,0,0,1,
                     1,0,0,0,1,
                     1,0,0,0,1,
                     1,0,0,0,1,
                     1,1,1,1,1])])
