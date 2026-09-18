#include "Matrix.h"
#include <iostream>
#include <iomanip>
using namespace std;

//imprimir a matriz na tela
void Matrix::print() {
    int val;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            val = array[j + i*columns];
            cout << setw(5) << val;
        }
        cout << "\n";
    }
}

/*
criar matriz com n linhas e m colunas, 
alocada dinamicamente e com todos os 
elementos iguais a zero
*/
Matrix::Matrix(int m, int n){
    rows = m;         
    columns = n;
    array = new int[m*n]();
}

/*
liberar (deletar) a matriz que 
foi alocada dinamicamente
*/
Matrix::~Matrix(){
    delete[] array;
    array = nullptr;
}
   
/*
acessar valor na 
posição (i, j) da matriz
*/
int Matrix::get_value(int i, int j){
    return array[j + i*columns];
}

// retornar o número de linhas da matriz
int Matrix::get_rows(){
    return rows;
}

//retornar o número de colunas da matriz
int Matrix::get_columns(){
    return columns;
}

/*
atribuir valor ao elemento na 
posição (i, j) da matriz
*/

void Matrix::set_value(int i, int j, int newValue){
    array[i*columns + j] = newValue;
}

/*
somar duas matrizes passadas por parâmetro e 
retornar a matriz resultante
*/

void matrix_sum(Matrix& a, Matrix& b, Matrix& c){
    
    for (int i = 0; i < c.get_rows(); i++){
        for (int j = 0; j < c.get_columns(); j++){
            int soma = 0;
            soma = a.get_value(i, j) + b.get_value(i, j);
            c.set_value(i, j, soma);
        }
    }
}

void matrix_multiply(Matrix& a, Matrix& b, Matrix& c){
    for (int i = 0; i < c.get_rows(); i++){
        for (int j = 0; j < c.get_columns(); j++){
            int somatorio = 0;
            for (int k = 0; k < a.get_columns(); k++){
                somatorio += a.get_value(i, k) * b.get_value(k,j);
            }
            c.set_value(i, j, somatorio);
        }
    }    
}

