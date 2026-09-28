#include <iostream>
using namespace std;

int fatorial(int n){
    if (n <= 1){
        return 1;
    }
    return n * fatorial(n-1);
}

int main(){

    int n = 0;
    cout << "Digite o valor de n" << endl;
    cin >> n;

    cout << "Fatorial de " << n << "! é " << fatorial(n) << endl;
    return 0;
}

// Faça uma função recursiva que calcule e retorne o fatorial de um número inteiro n.