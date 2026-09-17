![Brasão da Universidade Federal do Ceará](https://www.ufc.br/brasao-vertical.svg)
# Pintando a casa
## Contexto

Fernando comprou uma casa triangular. Ao tentar calcular a quantidade de tinta necessária para pintar as paredes, ele percebeu que precisava saber como calcular a área de um triângulo. Felizmente, ele encontrou a Fórmula de Heron, que permite calcular a área de um triângulo a partir do tamanho de seus lados.

Implemente um programa que, dado o tamanho dos três lados de um triângulo, calcule a área utilizando a Fórmula de Heron:

![](qxd0010-estrutura/heron.jpg)

### Entrada

-   Três números em ponto flutuante representando os lados do triângulo, um por linha.

### Saída

-   A área do triângulo com duas casas decimais.

## Testes

```
>>>>>>>> INSERT
4
3
5
======== EXPECT
6.00
<<<<<<<< FINISH
```

```
>>>>>>>> INSERT
10
12
16
======== EXPECT
59.92
<<<<<<<< FINISH
```

## Dicas

### Programando em: C++

-   Para exibir um número de ponto flutuante do tipo `double`, recomendado por sua maior precisão, com seis casas decimais em C++, utilize os manipuladores de formato std::fixed e std::setprecision juntamente como o `cout`. 

```cpp
int main() {
    double resultado {435.87654325};
    std::cout << std::fixed << std::setprecision(6) << resultado << "\n";
    return 0;
}
```
