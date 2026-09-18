![Brasão da Universidade Federal do Ceará](https://www.ufc.br/brasao-vertical.svg)


## Operações básicas

Leia um vetor de inteiros e implemente as funções sem utilizar laço para iterar sobre os elementos. Você pode utilizar laço **apenas** para ler os elementos do vetor.

___

-   Entrada
    -   um vetor de inteiros. O vetor tem no mínimo 1 elemento.
-   Saída
    -   vet: o vetor
    -   rvet: o vetor impresso ao contrário
    -   sum: a soma dos elementos
    -   mult: a multiplicação dos elementos
    -   min: o menor elemento
    -   inv: inverte o vetor, depois imprime ele invertido

___

## Help

Existem várias formas de resolver esse problema. Logo abaixo dou uma sugestão.

Em C++, você pode ler a entrada de dados como mostrado abaixo. 

A ideia é ler a entrada como uma string e depois usar um objeto do tipo stringstream para acessar os valores individuais que foram digitados.

Os valores digitados são armazenados numa estrutura de dados chamada **vector**. Se você souber usá-la, pode usá-la. Se não souber, pode encontrar sobre ela na internet.

Se não quiser usá-la, pode ainda usar alocação dinâmica a fim de obter um array de inteiros dinâmico.

### C++

```cpp
#include <sstream> //cabeçalho que contém o tipo de dado stringstream
#include <vector>  //cabeçalho que contém a estrutura de dados vector
#include <string>
#include <iostream>

string line;
getline(cin, line);
stringstream ss(line);
vector<int> vet;
int value;
while(ss >> value)
    vet.push_back(value);
```

___

## Testes

```
>>>>>>>> 01
4
========
vet : [ 4 ]
rvet: [ 4 ]
sum : 4
mult: 4
min : 4
inv : [ 4 ]
<<<<<<<<

>>>>>>>> 02
3 4 2
========
vet : [ 3 4 2 ]
rvet: [ 2 4 3 ]
sum : 9
mult: 24
min : 2
inv : [ 2 4 3 ]
<<<<<<<<

>>>>>>>> 03
1 2 3 4
========
vet : [ 1 2 3 4 ]
rvet: [ 4 3 2 1 ]
sum : 10
mult: 24
min : 1
inv : [ 4 3 2 1 ]
<<<<<<<<

>>>>>>>> 04
1 2 3 4 0
========
vet : [ 1 2 3 4 0 ]
rvet: [ 0 4 3 2 1 ]
sum : 10
mult: 0
min : 0
inv : [ 0 4 3 2 1 ]
<<<<<<<<

>>>>>>>> 05
1 2 3 4 2 3
========
vet : [ 1 2 3 4 2 3 ]
rvet: [ 3 2 4 3 2 1 ]
sum : 15
mult: 144
min : 1
inv : [ 3 2 4 3 2 1 ]
<<<<<<<<

>>>>>>>> 06
1 2 3 4 7 2 9
========
vet : [ 1 2 3 4 7 2 9 ]
rvet: [ 9 2 7 4 3 2 1 ]
sum : 28
mult: 3024
min : 1
inv : [ 9 2 7 4 3 2 1 ]
<<<<<<<<

>>>>>>>> 07
0 1 2 3 -4 -7 -2
========
vet : [ 0 1 2 3 -4 -7 -2 ]
rvet: [ -2 -7 -4 3 2 1 0 ]
sum : -7
mult: 0
min : -7
inv : [ -2 -7 -4 3 2 1 0 ]
<<<<<<<<
```