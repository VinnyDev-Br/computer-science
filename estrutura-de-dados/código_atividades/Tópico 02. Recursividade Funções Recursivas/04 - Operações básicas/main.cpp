#include <sstream> //cabeçalho que contém o tipo de dado stringstream
#include <vector>  //cabeçalho que contém a estrutura de dados vector
#include <string>
#include <iostream>
using namespace std;

void imprimir(vector<int>& vet, int init, int end){
    if (init > end)
        return;
    else{
        cout << " " << vet[init];
        return imprimir(vet, init + 1, end);
    }
}

void imprimir_invertido(vector<int>& vet, int init, int end){
    if (init > end)
        return;
    else{
        cout << " " << vet[end];
        return imprimir_invertido(vet, init, end - 1);
    }
}

int sum(vector<int>& vet, int init, int end){
    if (init > end){
        return 0;
    }
    return vet[init] + sum(vet, init + 1, end);
}

int mult(vector<int>& vet, int init, int end){
    if (init >= end){
        return vet[init];
    }
    return vet[init] * mult(vet, init + 1, end);
}

int min(vector<int> &vet, int init, int end, int menor){
    if (init > end){
        return menor;
    }
    else{
        if (vet[init] < menor){
            menor = vet[init];
            return min(vet, init + 1, end, menor);
        }
        else{
            return min(vet, init + 1, end, menor);
        }
    }
}

vector<int> inverter(vector<int>&vet, int init, int end, int aux){
    if (init >= end){
        return vet;
    }
    else{
        aux = vet[init];
        vet[init] = vet[end];
        vet[end] = aux;
        return inverter(vet, init + 1, end - 1, 0);
    }
}

int main(){
    string linha;
    getline(cin, linha);
    
    stringstream ss(linha);
    vector<int> vet;
    
    int value = 0;
    
    while(ss >> value)
        vet.push_back(value);
    
    
    cout << "vet : ";   
    cout << "[";
    imprimir(vet, 0, vet.size() - 1);
    cout << " ]" << endl;
    
    cout << "rvet: ";   
    cout << "[";
    imprimir_invertido(vet, 0, vet.size() - 1);
    cout << " ]" << endl;
    
    cout << "sum : ";   
    cout << sum(vet, 0, vet.size() - 1);
    cout << endl;   
    
    cout << "mult: ";   
    cout << mult(vet, 0, vet.size() - 1);
    cout << endl; 
    
    cout << "min : ";   
    cout << min(vet, 0, vet.size() - 1, 999);
    cout << endl;
    
    cout << "inv : [";   
    vector<int> invertido = inverter(vet, 0, vet.size() - 1, 0);
    imprimir(invertido, 0, invertido.size() - 1);
    cout << " ]" << endl;
    
    
    
    
    
    return 0;
}