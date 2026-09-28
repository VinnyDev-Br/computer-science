/*4. Fa ca uma funcao MAX que recebe como entrada um inteiro n, uma matriz inteira
An×n e devolve três inteiros: k, l e c, tal que
•k  ́e o maior elemento de A e é igual a A[l][c].
Se o elemento m ́aximo ocorrer mais de uma vez, indique em l e c qualquer uma das
possíveis posições. Use ponteiros para os argumentos.
Escreva uma funçao main que use a func ̃ao MAX */
#include <iostream>
using namespace std;

void MAX(int **A, int n, int *k, int *l, int *c){
    *k = A[0][0];
    *l = 0;
    *c = 0;

    for (int i = 0; i<n; i++){
        for (int j = 0; j < n; j++){
            if (A[i][j] > *k){
                *k = A[i][j];
                *l = i;
                *c = j;
            }
        }
    }

}

int main(){
    int n;
    cout << "Digite o tamanho da Matriz Quadrada NxN: " << endl;
    cin >> n;
    int **A = new int*[n]();
    for (int i = 0; i < n; i++){
        A[i] = new int[n](); // Valores da Matriz iniciado em zero
    }

    int k,l,c;

    MAX(A, n, &k, &l, &c);

    cout << "Maior elemento: " << k << endl;
    cout << "Posição: linha " << l << ", coluna " << c << endl;

    for (int i = 0; i < n; i++){
        delete[] A[i];
    }

    delete []A;
}