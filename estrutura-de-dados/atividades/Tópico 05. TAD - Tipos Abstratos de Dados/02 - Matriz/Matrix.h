// ------------------------------------------------
// ESTE ARQUIVO JA ESTA FINALIZADO, NAO MEXA NELE
// ------------------------------------------------
#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
private:
    int rows;     // número de linhas
    int columns;  // número de colunas
    int *array;   // ponteiro para o array de inteiros

public:    
    /**
     * Construtor: aloca dinamicamente uma matriz de inteiros 
     * com m linhas e n colunas.
     * Função supõe que m > 0 e n > 0.
     */
    Matrix(int m, int n);

    /**
     * Destrutor: Libera a memória que foi alocada
     */
    ~Matrix();

    /**
     * getter: retorna o número de linhas da matriz 
     */
    int get_rows();

    /**
     * getter: retorna o número de colunas da matriz 
     */
    int get_columns();

    /**
     * Retorna o valor inteiro contido na celula [i][j] da matriz. 
     */
    int get_value(int i, int j);

    /**
     * Atribui o valor 'newValue' para a celula [i][j] da matriz.
     */
    void set_value(int i, int j, int newValue);

    /**
     * Imprime a matriz na tela
     */
    void print();

};


// ---------------------------------------------------------------------
// Funções definidas fora da classe
// ---------------------------------------------------------------------

// Recebe como entrada referências para 3 matrizes: a, b e c.
// Essa função soma a matriz 'a' e a matrix 'b' e
// coloca o resultado da soma na matriz 'c'.
// A matriz 'c' já foi criada fora da função.
// Se não for possível somar por causa de incompatibilidade
// nas dimensões das matrizes a, b e c, então a função imprime
// mensagem de erro na tela: "nao foi possivel somar".
void matrix_sum(Matrix& a, Matrix& b, Matrix& c);

// Recebe como entrada referências para 3 matrizes: a, b e c.
// Essa função multiplica a matriz 'a' pela matrix 'b' e
// coloca o resultado da multiplicação na matriz 'c'.
// A matriz 'c' já foi criada fora da função.
// Se não for possível multiplicar por causa de incompatibilidade
// nas dimensões das matrizes a, b e c, então a função imprime
// mensagem de erro na tela: "nao foi possivel multiplicar".
void matrix_multiply(Matrix& a, Matrix& b, Matrix& c);


#endif