![Brasão da Universidade Federal do Ceará](https://www.ufc.br/brasao-vertical.svg)


## Queimada - Tocando fogo na floresta

-   Seja uma matriz de caracteres que representa um mapa de uma floresta.
-   Cada caractere representa um espaço vazio ou uma árvore.
-   O espaço vazio é representado por um ponto `.` e a árvore por uma hashtag `#`.
-   O fogo começa em um ponto inicial e se espalha para os vizinhos até que não haja mais árvores para queimar.

Dado a matriz da floresta e o ponto inicial onde começa o fogo, queime as árvores. O fogo não se espalha nas diagonais, apenas nas 4 direções cardeais.

## Entrada

-   1a linha: `nl, nc, l, c`:
    -   Número de linhas e colunas da matriz, linha e coluna onde começa o fogo.
-   Nas linhas subsequentes a matriz da floresta sendo que
    -   ‘#’ representa uma árvore
    -   ‘.’ representa um espaço vazio

## Saída

-   A matriz após a queimada acontecer colocando ‘o’ para cada árvore queimada.

## Ajuda

O exercício já encontra-se com parte da implementação feita. Representamos a matriz de caracteres como um vector de strings, assim: std::vector<std::string>

-   No arquivo `fogo.cpp`, você deve implementar a função `tocar_fogo`.

-   Utilize as seguintes regras para recursão:
    
    -   Se a posição for fora da matriz, retorne.
    -   Se a posição não for uma arvore retorne.
    -   Queime a arvore.
    -   Chame a recursão para todos os vizinhos.

## Testes

```
>>>>>>>> 01
2 3 1 1
#.#
.##
========
#.o
.oo
<<<<<<<<

>>>>>>>> 02
5 5 0 0
#..#.
#...#
###..
..#.#
..###
========
o..#.
o...#
ooo..
..o.o
..ooo
<<<<<<<<

>>>>>>>> 03
5 7 2 3
#..#.#.
#..####
####..#
..#.#..
#.###.#
========
o..o.o.
o..oooo
oooo..o
..o.o..
#.ooo.#
<<<<<<<<
```

## Arquivos requeridos

#### main.cpp
```cpp
#include <iostream>
#include <string>
#include <vector>
#include "fogo.hpp"

void show_mat(std::vector<std::string> mat);
void read_mat(std::vector<std::string> &mat, int nl);

int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    std::cin >> nl >> nc >> lfire >> cfire;
    std::vector<std::string> mat;
    read_mat(mat, nl);

    tocar_fogo(mat, lfire, cfire);
    
    show_mat(mat);
}

void show_mat(std::vector<std::string> mat){
    for(int l = 0; l < (int) mat.size(); l++) {
        std::cout << mat[l] << "\n";
    }
}

void read_mat(std::vector<std::string> &mat, int nl){
    for(int l = 0; l < nl; l++) {
        std::string linha;
        std::cin >> linha;
        mat.push_back(linha);
    }
}
```

#### fogo.hpp
```cpp
#pragma once

#include <iostream>
#include <vector>

void tocar_fogo(std::vector<std::string> &mat, int l, int c);
```

#### fogo.cpp
```cpp
#include "fogo.hpp"

void tocar_fogo(std::vector<std::string> &mat, int l, int c) {
    int nl = mat.size();     // numero de linhas
    int nc = mat[0].size();  // numero de colunas
    
    // Terminar de escrever essa funcao .....
}
```