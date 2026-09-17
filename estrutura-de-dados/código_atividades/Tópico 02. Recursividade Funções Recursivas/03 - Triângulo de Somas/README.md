![Brasão da Universidade Federal do Ceará](https://www.ufc.br/brasao-vertical.svg)



# **Descrição**

Dado um vetor com n inteiros A\=\[a0,a1,…,an−1\], n≥0, imprima um triângulo de números tal que:

-   na base do triângulo estejam todos os elementos do vetor original, ou seja: \[a0,a1,…,an−1\];
-   o número de elementos em cada nível acima da base é um a menos que no nível inferior;
-   e cada elemento no i-ésimo nível é a soma de dois elementos consecutivos do nível inferior.

**Entrada:**

A primeira linha deve ler o tamanho n do vetor A. O valor de n é maior ou igual a zero.

A segunda linha deve ler os n elementos do vetor, separados por espaço simples.

**Saída:**

O triângulo de somas.

**Exemplos:**

```
Entrada: 
5
1 2 3 4 5

Saída: 
[48]
[20, 28] 
[8, 12, 16] 
[3, 5, 7, 9] 
[1, 2, 3, 4, 5] 
```

```
Entrada: 
7
2 0 -7 8 45 0 33

Saída:
[765]
[237, 528]
[37, 200, 328]
[-11, 48, 152, 176]
[-5, -6, 54, 98, 78]
[2, -7, 1, 53, 45, 33]
[2, 0, -7, 8, 45, 0, 33]
```

**Explicação do Primeiro Exemplo:**

```
No topo,[48]
        [20, 28] -->(20 + 28 = 48)
        [8, 12, 16] -->(8 + 12 = 20, 12 + 16 = 28)
        [3, 5, 7, 9] -->(3 + 5 = 8, 5 + 7 = 12, 7 + 9 = 16)
        [1, 2, 3, 4, 5] -->(1 + 2 = 3, 2 + 3 = 5, 3 + 4 = 7, 4 + 5 = 9)
```

**Observação:**

Use recursão para resolver este problema.