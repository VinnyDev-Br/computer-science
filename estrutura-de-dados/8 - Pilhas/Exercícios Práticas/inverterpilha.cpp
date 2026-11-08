#include <stack>
#include <iostream>
#include <vector>
using namespace std;

/*
Inverter uma sequência.
Leia um inteiro n e, em seguida, n numeros inteiros. Imprima os 
numeros na ordem inversa da leitura, usando uma std::stack.

Entrada
5
10 20 30 40 50

Saída
50 40 30 20 10

*/
int main(){
    stack<int>  s;
    int tamanho;
    int x;
    cout << "Qual o tamanho da pilha: " << endl;
    cin >> tamanho;

    while (tamanho--){
        cin >> x;
        s.push(x);
    }

    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}