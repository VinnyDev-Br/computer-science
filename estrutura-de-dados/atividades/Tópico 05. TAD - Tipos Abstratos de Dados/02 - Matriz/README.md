![Brasão da Universidade Federal do Ceará](https://www.ufc.br/brasao-vertical.svg)
# [TAD] Matriz
## Motivação

O objetivo desta atividade é implementar um TAD chamado `Matrix` usando modularização e Classes, similar ao que foi feito no TAD Point e TAD Circle.

O TAD `Matrix` encapsula uma matriz com $m$ linhas e $n$ colunas, sobre a qual podemos fazer as seguintes operações:
* Criar matriz com $n$ linhas e $m$ colunas, alocada dinamicamente e com todos os elementos iguais a zero.
* Liberar (deletar) a matriz que foi alocada dinamicamente.
* Acessar valor na posição $(i, j)$ da matriz.
* Atribuir valor ao elemento na posição $(i, j)$ da matriz.
* Retornar o número de linhas da matriz.
* Retornar o número de colunas da matriz.
* Imprimir a matriz na tela.
* Multiplicar duas matrizes passadas como argumento e retornar a matriz resultante.
* Somar duas matrizes passadas por parâmetro e retornar a matriz resultante.

---

## Observações

Lembre-se que nem sempre é possível multiplicar ou somar duas matrizes:
* **Para a soma:** As duas matrizes devem ter as mesmas dimensões.
* **Para a multiplicação:** O número de colunas da primeira matriz deve ser igual ao número de linhas da segunda.

*Você pode assistir ao vídeo abaixo para relembrar a operação de multiplicação de matrizes.*

---

## Como implementar a estrutura de dados Matrix?

O TAD `Matrix` vai ter três atributos (dados):
* Um inteiro que guarda o número $m$ de linhas.
* Um inteiro que guarda o número $n$ de colunas.
* Um ponteiro para um vetor de inteiros. Esse vetor deve ser alocado dinamicamente e deve ter capacidade para $n \times m$ inteiros.

Podemos usar um vetor para implementar uma matriz conforme ilustrado abaixo:

> **Dica:** Supondo que temos um vetor `V[0...m*n-1]` contendo todos os elementos da matriz, acessamos o elemento na célula $(i, j)$ através do mapeamento: `V[j + i * n]`

---

## Requisitos

* O código do TAD `Matrix` deve ser dividido em dois arquivos: `Matrix.h` e `Matrix.cpp` como explicado em sala.
* O código do arquivo `Matrix.h` já foi escrito e foi fornecido com esta atividade.
* Você precisa apenas implementar as funções no arquivo `Matrix.cpp`, que está incompleto.
* Além disso, o código do programa cliente `main.cpp` já está feito. O programa principal lê comandos passados como entrada e manipula uma ou mais matrizes. Os comandos aceitos pelo menu principal estão listados abaixo.

