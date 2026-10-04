/*• Rotacione um vector k posições para a esquerda.
Entrada: {1, 2, 3, 4, 5}, k = 2
Saída: {3, 4, 5, 1, 2}
Faça de duas formas:
(a) com push_back + erase do primeiro elemento, repetindo k vezes;
(b) construindo um novo vector com operator[] e aritmética modular.
Compare as duas.
Funções: erase, push_back, front, operator[]
O protótipo da função deve ser:
void rotacionarVector(vector<int>& v, int k);*/

#include <iostream>
#include <vector>
using namespace std;

// (a) push_back + erase do primeiro elemento, repetindo k vezes
void rotacionarVectorA(vector<int>& v, int k){
    if (v.empty()) return;
    k %= v.size();                    // evita voltas completas desnecessárias
    for (int i = 0; i < k; i++){
        v.push_back(v.front());       // copia o primeiro para o final
        v.erase(v.begin());           // remove o primeiro
    }
}

// (b) novo vector com operator[] e aritmética modular
void rotacionarVectorB(vector<int>& v, int k){
    int n = v.size();
    if (n == 0) return;
    k %= n;
    vector<int> novo(n);
    for (int i = 0; i < n; i++){
        novo[i] = v[(i + k) % n];     // o elemento da posição i vem de i+k
    }
    v = novo;                         // copia de volta para o original
}

void imprimir(const vector<int>& v){
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    int k = 2;

    vector<int> a {1, 2, 3, 4, 5};
    vector<int> b {1, 2, 3, 4, 5};

    cout << "Original:        ";
    imprimir(a);

    rotacionarVectorA(a, k);
    cout << "(a) push+erase:  ";
    imprimir(a);

    rotacionarVectorB(b, k);
    cout << "(b) modular:     ";
    imprimir(b);

    return 0;
}