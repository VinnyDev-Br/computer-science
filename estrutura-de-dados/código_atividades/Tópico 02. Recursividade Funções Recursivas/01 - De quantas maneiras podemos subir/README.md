
![Brasão da Universidade Federal do Ceará](https://www.ufc.br/brasao-vertical.svg)
## L0 - @escada - De quantas maneiras podemos subir

Ao subir a escada de seu prédio, José às vezes sobe três degraus de uma vez e às vezes sobe um de cada vez. Dado uma escada com n degraus de quantas maneiras diferentes José pode subir essa escada. Para resolver esse problema, vamos pensar nos casos menores:

-   Uma escada de 1 degrau, podemos subir as escadas de 1 maneira (1).
-   Uma escada de 2 degrau, podemos subir as escadas de 1 maneiras ((1,1)).
-   Uma escada de 3 degraus, podemos subir as escadas de 2 maneiras ((1,1,1),(3)).

Seja xn número de maneira de subir uma escada de n degraus. O primeiro passo para subir uma escada de n degraus pode ser dado de duas maneiras:

-   Se você subir apenas um degrau, então teremos xn−1 maneiras de subir o restante da escada.
-   Se você subir três degraus, então teremos xn−3 maneiras de subir o restante da escada.

A recorrência para xn será:

xn\={1n\=11n\=22n\=3xn−1+xn−3n\>3

## Entrada

A entrada é composta por uma única linha contendo um inteiro n representando o número de degraus da escada

## Saída

A saída é composta por uma única linha contendo o número de maneiras que uma escada com n degraus pode ser subida saltando 1 ou 3 degraus por vez.

## Exemplo de Entrada

```
4
```

## Exemplo de Saída

```
3
```