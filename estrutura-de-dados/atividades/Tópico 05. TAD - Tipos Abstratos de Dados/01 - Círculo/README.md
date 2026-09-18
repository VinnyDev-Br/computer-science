![Brasão da Universidade Federal do Ceará](https://www.ufc.br/brasao-vertical.svg)
# [TAD] Círculo


> ⚠️ Você deve implementar **apenas** o arquivo `Circle.cpp`. Os demais arquivos (`Point.h`, `Point.cpp`, `Circle.h`, `main.cpp`) já são fornecidos na atividade.

## Motivação

Usando programação orientada a objetos, crie um tipo de dado abstrato chamado `Circle` para representar um círculo no plano Cartesiano R².

O TAD `Circle` possui exatamente dois atributos (dados):
- um atributo do tipo `Point` que representa o centro do círculo;
- o comprimento do raio do círculo.

O TAD `Circle` possui as seguintes operações:
- criar um círculo;
- mudar o valor da coordenada x ou y do centro do círculo;
- obter o valor da coordenada x ou y do centro do círculo;
- mudar o centro do círculo passando um `Point` como argumento;
- obter o comprimento do raio do círculo;
- mudar o comprimento do raio do círculo;
- calcular a área do círculo;
- verificar se um ponto (da classe `Point`) está no interior do círculo;
- liberar memória alocada na criação do tipo de dado círculo (quando um círculo for liberado, a mensagem `"circulo liberado"` deve ser impressa).

Como visto acima, o TAD `Circle` usa o TAD `Point` como tipo auxiliar (implementado em aula ou como exercício de casa).

## Point.h (fornecido)

```cpp
#ifndef PONTO_ED_2026
#define PONTO_ED_2026

/************************************
* Declaracao da classe
*************************************/
class Point {
private:
    double m_x, m_y;

public:
    // Construtores
    Point();
    Point(double X, double Y);

    // Setters
    void setX(double x);
    void setY(double y);

    // Getters
    double getX();
    double getY();

    // Calcula a distancia entre dois pontos
    double distance(Point& p);

    // Imprime o ponto na tela no formato "(x,y)"
    void print();
};

#endif
```

## Circle.h (fornecido)

```cpp
#ifndef CIRCLE_ED_2026
#define CIRCLE_ED_2026
#include "Point.h"

class Circle {
private:
    Point  m_center;
    double m_radius;

public:
    // Construtor sem argumentos:
    // Inicializa o circulo na origem (0,0)
    // e com raio igual a 1.0
    Circle();

    // Construtor com dois argumentos
    // Os dois argumentos sao obrigatorios
    Circle(Point& p, double radius);

    // setters
    void setRadius(double rad);
    void setCenter(Point& p);

    // getters
    Point& getCenter(); // Devolve uma referencia para m_center
    double getRadius(); // Devolve o valor de m_radius

    // Funcao-membro que devolve a area do circulo
    double area();

    // Funcao-membro que recebe um Point como argumento e
    // devolve 'true' se o ponto p estiver contido no circulo;
    // ou devolve 'false' caso contrario.
    bool contains(Point& p);
};

#endif
```

## Objetivo

Implementar o arquivo `Circle.cpp` para finalizar a criação do TAD `Circle`.

O arquivo `main.cpp` espera receber (via Moodle/VPL) uma lista de comandos como entrada, especificada na tabela abaixo. Para ler esses comandos, foi usado o tipo de dado `stringstream` da biblioteca `<sstream>`.

## Exemplo de Entrada

```
cria 77 3 5
cria 98 3 2
cria 98 0 0
imprime_todos
exit
```

## Exemplo de Saída

```
[raio:77, X:3, Y:5]
[raio:98, X:3, Y:2]
[raio:98, X:0, Y:0]
```

## Descrição dos comandos (main.cpp)

| Comando | Significado |
|---|---|
| `cria [R] [x] [y]` | cria círculo com raio de comprimento R e centro na coordenada (x,y) |
| `imprime [i]` | imprime os dados do (i+1)-ésimo círculo criado |
| `imprime_todos` | imprime os dados de todos os círculos criados |
| `getx [i]` | imprime a coordenada x do (i+1)-ésimo círculo |
| `gety [i]` | imprime a coordenada y do (i+1)-ésimo círculo |
| `setx [i] [n]` | muda o valor da coordenada x do (i+1)-ésimo círculo para n |
| `sety [i] [n]` | muda o valor da coordenada y do (i+1)-ésimo círculo para n |
| `getarea [i]` | imprime a área do (i+1)-ésimo círculo |
| `getraio [i]` | imprime o raio do (i+1)-ésimo círculo |
| `getcentro [i]` | imprime as coordenadas x e y do centro do (i+1)-ésimo círculo |
| `setraio [i] [n]` | muda o valor do raio do (i+1)-ésimo círculo para n |
| `setcentro [i] [xx] [yy]` | muda o valor das coordenadas x e y do (i+1)-ésimo círculo para xx e yy, respectivamente |
| `interior [i] [x] [y]` | imprime `"true"` se o ponto (x,y) está contido no interior do (i+1)-ésimo círculo; `"false"` caso contrário |

#
