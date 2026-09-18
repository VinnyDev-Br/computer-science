#include <iostream>
#include <vector>
using namespace std;

void imprimir_triangulo(vector <int> elementos){
    cout << "[";
    for (int i = 0; i < elementos.size(); i++){
        cout << elementos[i];
        if (i + 1 < elementos.size()) cout << ", ";
    }
    cout << "]" << endl;
}

vector<int> formar_triangulo(vector <int> elementos, int tam){
    if (tam <= 1){
        imprimir_triangulo(elementos);
        return elementos;
    }
    
    vector<int> proxima;
        
    for (int i = 0; i < tam - 1; i++){
        proxima.push_back(elementos[i] + elementos[i + 1]);
    }
    
    formar_triangulo(proxima, tam - 1);
    imprimir_triangulo(elementos);


    return elementos;
}

int main(){
    int tam = 0;
    cin >> tam;
    
    vector<int> elementos(tam);
    
    for (int i = 0; i < tam;  i++){
        cin >> elementos[i]; 
    }
    
    formar_triangulo(elementos, tam);
}