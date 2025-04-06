from typing import List
import matplotlib.pyplot as plt
import numpy as np
import random

# Tipo para vetor de floats
Vector = List[float]

# Calcula o produto interno entre dois vetores
def dot(v: Vector, w: Vector) -> float:
    assert len(v) == len(w)
    return sum(v_i * w_i for v_i, w_i in zip(v, w))

# Função de ativação: retorna 1 se a soma ponderada for >= 0; caso contrário, retorna 0.
def degrau(x):
    return 1 if x >= 0 else 0

# Calcula a saída do perceptron para um conjunto de entradas
def perceptron_output(pesos, entradas):
    y = dot(pesos, entradas)
    return degrau(y)

# Ajusta os pesos (treinamento) usando a regra do perceptron
def ajustes(sinapses, entradas, saida):
    taxa_aprendizagem = 0.08
    saida_parcial = perceptron_output(sinapses, entradas)
    
    for j in range(3):
        sinapses[j] = sinapses[j] + taxa_aprendizagem * (saida[0] - saida_parcial) * entradas[j]
    
    saida = saida_parcial
    return sinapses, saida

# Testa a generalização do modelo em novos dados
def teste_generalizacao(sinapses, entradas, saida):
    saida_parcial = perceptron_output(sinapses, entradas)
    saida = saida_parcial
    return sinapses, saida

# Inicialização dos pesos do Perceptron (valores iniciais arbitrários)
neuronio = [0.5, -0.2, 0.3]

# ============================================================================
# Dados de treinamento: [viés, eliminações, mortes]
#
# No contexto Marvel Rivals com valores normalizados (0 a 1):
# - Consideramos que o número máximo de eliminações é 10.
# - Jogadores Perdedores (Classe 0): baixa eliminação e altas mortes.
# - Jogadores Vencedores (Classe 1): alta eliminação e baixas mortes.
# ============================================================================
# Jogadores considerados Perdedores (Classe 0)
padrao0 = [-1, 0.2, 0.8]    # Ex.: 0.2 (baixa eliminação), 0.8 (altas mortes)
padrao1 = [-1, 0.3, 0.9]
padrao2 = [-1, 0.4, 0.85]
padrao3 = [-1, 0.35, 0.8]
padrao4 = [-1, 0.3, 0.75]
padrao5 = [-1, 0.25, 0.8]

# Jogadores considerados Vencedores (Classe 1)
padrao6  = [-1, 0.9, 0.2]   # Ex.: 0.9 (alta eliminação), 0.2 (baixas mortes)
padrao7  = [-1, 0.85, 0.25]
padrao8  = [-1, 0.8, 0.3]
padrao9  = [-1, 1.0, 0.15]
padrao10 = [-1, 0.95, 0.2]
padrao11 = [-1, 0.9, 0.18]

saida0 = [0]  # Classe 0 – Perdedores
saida1 = [1]  # Classe 1 – Vencedores

# Treinamento do perceptron (12 ciclos)
n = 0
for _ in range(12):
    # Treina com jogadores Perdedores (Classe 0)
    neuronio, saida_0 = ajustes(neuronio, padrao0, saida0)
    print(neuronio, "saida0 =", saida_0)
    neuronio, saida_0 = ajustes(neuronio, padrao1, saida0)
    print(neuronio, "saida0 =", saida_0)
    neuronio, saida_0 = ajustes(neuronio, padrao2, saida0)
    print(neuronio, "saida0 =", saida_0)
    neuronio, saida_0 = ajustes(neuronio, padrao3, saida0)
    print(neuronio, "saida0 =", saida_0)
    neuronio, saida_0 = ajustes(neuronio, padrao4, saida0)
    print(neuronio, "saida0 =", saida_0)
    neuronio, saida_0 = ajustes(neuronio, padrao5, saida0)
    print(neuronio, "saida0 =", saida_0)
    
    # Treina com jogadores Vencedores (Classe 1)
    neuronio, saida_1 = ajustes(neuronio, padrao6, saida1)
    print(neuronio, "saida1 =", saida_1)
    neuronio, saida_1 = ajustes(neuronio, padrao7, saida1)
    print(neuronio, "saida1 =", saida_1)
    neuronio, saida_1 = ajustes(neuronio, padrao8, saida1)
    print(neuronio, "saida1 =", saida_1)
    neuronio, saida_1 = ajustes(neuronio, padrao9, saida1)
    print(neuronio, "saida1 =", saida_1)
    neuronio, saida_1 = ajustes(neuronio, padrao10, saida1)
    print(neuronio, "saida1 =", saida_1)
    neuronio, saida_1 = ajustes(neuronio, padrao11, saida1)
    print(neuronio, "saida1 =", saida_1)
    
    n += 1
    print("Número de ciclos =", n)

# ============================================================================
# Plotagem: Representação dos jogadores em um gráfico de dispersão
#
# Eixos:
#  - X: Eliminações (normalizado de 0 a 1)
#  - Y: Mortes (normalizado de 0 a 1)
#
# A fronteira de decisão mostra a linha separando jogadores considerados vencedores
# dos perdedores, conforme o modelo treinado.
# ============================================================================
# Extração dos pontos para plotagem
# Classe 0: jogadores Perdedores (padrao0 a padrao5)
eliminacoes_class0 = [padrao0[1], padrao1[1], padrao2[1], padrao3[1], padrao4[1], padrao5[1]]
mortes_class0 = [padrao0[2], padrao1[2], padrao2[2], padrao3[2], padrao4[2], padrao5[2]]

# Classe 1: jogadores Vencedores (padrao6 a padrao11)
eliminacoes_class1 = [padrao6[1], padrao7[1], padrao8[1], padrao9[1], padrao10[1], padrao11[1]]
mortes_class1 = [padrao6[2], padrao7[2], padrao8[2], padrao9[2], padrao10[2], padrao11[2]]

plt.figure(figsize=(8, 6))
plt.scatter(eliminacoes_class0, mortes_class0, color='blue', label='Perdedores')
plt.scatter(eliminacoes_class1, mortes_class1, color='red', label='Vencedores')

# Cálculo da fronteira de decisão:
# -w0 + w1*Eliminações + w2*Mortes = 0  =>  Mortes = (w0 - w1*Eliminações) / w2
w0, w1, w2 = neuronio
elim_range = np.linspace(0, 1, 100)
mortes_boundary = (w0 - w1 * elim_range) / w2
plt.plot(elim_range, mortes_boundary, color='green', linestyle='--', label='Fronteira de Decisão')

plt.xlabel("Eliminações (normalizado)")
plt.ylabel("Mortes (normalizado)")
plt.title("Classificação de Jogadores - Marvel Rivals (Valores Normalizados)")
plt.xlim(0, 1)
plt.ylim(0, 1)
plt.legend()
plt.grid(True)
plt.show()

# ============================================================================
# Teste de Generalização: Novos jogadores com diferentes estatísticas (valores normalizados)
# ============================================================================
p0 = [-1, 0.3, 0.7]    # Expectativa: Perde (baixa razão elim/mortes)
p1 = [-1, 0.35, 0.65]  # Expectativa: Perde
p2 = [-1, 0.8, 0.4]    # Expectativa: Vence (alta razão)
p3 = [-1, 1.0, 0.2]    # Expectativa: Vence (elim alto, mortes baixas)
p4 = [-1, 0.5, 0.6]    # Expectativa: Perde

print("Testes de Generalização:")
neuronio, saida_test = teste_generalizacao(neuronio, p0, saida0)
print(neuronio, "saida =", saida_test, "->", "Perdedor" if saida_test == 0 else "Vencedor")
neuronio, saida_test = teste_generalizacao(neuronio, p1, saida0)
print(neuronio, "saida =", saida_test, "->", "Perdedor" if saida_test == 0 else "Vencedor")
neuronio, saida_test = teste_generalizacao(neuronio, p2, saida0)
print(neuronio, "saida =", saida_test, "->", "Perdedor" if saida_test == 0 else "Vencedor")
neuronio, saida_test = teste_generalizacao(neuronio, p3, saida0)
print(neuronio, "saida =", saida_test, "->", "Perdedor" if saida_test == 0 else "Vencedor")
neuronio, saida_test = teste_generalizacao(neuronio, p4, saida0)
print(neuronio, "saida =", saida_test, "->", "Perdedor" if saida_test == 0 else "Vencedor")

# ============================================================================
# Simulação da Partida: Cálculo da razão eliminações/mortes para determinar
# quem foi o melhor (MVP) e o pior da partida.
# Os dados simulados serão gerados em valores normalizados [0,1]
# ============================================================================
placar = []
for i in range(12):
    # Para simulação, eliminações variam de 0 até 1 (simulando um máximo de 10 eliminações)
    eliminacoes = random.uniform(0, 1)
    # Mortes variam de 0.1 até 1 (garantindo que não seja zero)
    mortes = random.uniform(0.1, 1)
    razao = eliminacoes / mortes
    placar.append((f"Jogador {(i+1):2.0f}", eliminacoes, mortes, razao))

# Ordena os jogadores pela razão (maior razão indica melhor desempenho)
placar.sort(key=lambda x: x[3], reverse=True)

print("\nPlacar Final da Partida (baseado na razão Eliminações/Mortes):")
for pos, (nome, elim, mort, razao) in enumerate(placar, start=1):
    print(f"{pos:2.0f}: {nome} - Eliminacoes: {elim:.2f}, Mortes: {mort:.2f}, Razão: {razao:.2f}")

print("\nMelhor jogador (MVP):", placar[0][0])
print("Pior jogador:", placar[-1][0])