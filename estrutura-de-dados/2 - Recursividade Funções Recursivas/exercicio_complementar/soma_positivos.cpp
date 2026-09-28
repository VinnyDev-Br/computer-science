#include <iostream>
#include <vector>
using namespace std;

int soma(vector <int> &v, int ini, int end){
    if (ini > end){
        return 0;
    }

    if (v[ini] >= 0){
        return v[ini] + soma(v, ini+1, end);
    }

    return soma(v, ini+1, end);
}

int main(){
    vector <int> v = {3,-1, -9, 0, 7, -987};
    cout << soma(v, 0, v.size()-1) << endl;
}

/*
Escreva uma função recursiva em C++ que receba como uma das entradas um vetor de inteiros A e
retorne a soma dos inteiros positivos contidos em A. Por exemplo, dado o vetor A = [3, −1, −9, 0, 7, −987]
com n = 6 elementos, sua função deve retornar o número 10.
Atenção: Deixe bem claro quem é o caso base da sua função recursiva e quem é o caso geral. Cheque
se cada caso está sendo adequadamente resolvido.*/