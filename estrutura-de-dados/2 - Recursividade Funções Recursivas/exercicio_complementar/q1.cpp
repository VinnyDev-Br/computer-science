#include <iostream>
#include <vector>
using namespace std;

void preencherArray(vector <int> &v){
    for (int i = 0; i < v.size(); i++){
        cout << "Digite o valor da posição de V =[" << i <<"]" << endl;
        cin >> v[i];
    }
}

void imprimirArray(vector <int> &v){
    cout << "V = [";
    for (int i  = 0; i < v.size(); i++){
        if (i == v.size() -1){
            cout << v[i] <<  "]" << endl;
        }
        else
            cout << v[i] << ", ";
    }
}

void swap(int& a, int& b){
    int aux = a;
    a = b;
    b = aux;
}

void InverterArray(vector <int> &v, int ini, int end){
/*Crie um programa em C++ que receba um vetor de números reais com n elementos.
Escreva uma função recursiva que inverta a ordem dos elementos presentes no vetor.*/

    if(ini >= end){
        return;
    }
    swap(v[ini], v[end]);
    
    return InverterArray(v, ini+1, end-1);
}

int main(){
    int n =0;
    cout << "Digite o tamanho do vetor: " << endl;
    cin >> n;
    vector<int> v(n);

    preencherArray(v);
    imprimirArray(v);
    InverterArray(v, 0, v.size()-1);
    cout << " Array Invertido: " << imprimirArray;

    return 0;
}

/*Crie um programa em C++ que receba um vetor de números reais com n elementos.
Escreva uma função recursiva que inverta a ordem dos elementos presentes no vetor.*/