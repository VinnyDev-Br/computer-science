#include <iostream>
#include <vector>
using namespace std;

void booblesort(int A[],int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n -1 -i; j++){
            if (A[j] > A[j + 1]){
                int aux = A[j];
                A[j] = A[j+1];
                A[j+1] = aux;
            }
        }
    }
}

int find_Iterativo(int A[], int n, int alvo){
    int ini = 0;
    int fim = n -1;

    while (ini <=fim){
        int meio = (ini +fim) / 2;

        if (A[meio] == alvo){
            return meio;
        }
        else if(A[meio] > alvo){
            fim = meio - 1;
        }
        else{
            ini = meio +1;
        }
    }

    return -1;

}

int find_Recursivo(int A[], int ini, int end, int alvo){
    if (ini > end ){
        return -1;
    }


    int meio = (ini + end) / 2;


    if (A[meio] == alvo){
        return meio;
    }

    if (A[meio] > alvo){
        return find_Recursivo(A, ini, meio-1, alvo);
    }
  
    return find_Recursivo(A, meio+1, end, alvo);

}

int main(){
    int A[5] = {5, 4, 3, 2, 1};
    int n = 5;
    booblesort(A, n);

    for (int i = 0; i <= n-1; i++){
        if (i == 0){
            cout << A[i];
            continue;
        }
        cout  << ", " << A[i];
    }
    cout << endl;



    cout << "Valor encontrado = " << find_Iterativo(A, 5, 5);
}

//Objetivo: Implementar um algoritmo de ordenação de um vetor e um algoritmo para encontrar um 
//elemento nele de forma eficiente.