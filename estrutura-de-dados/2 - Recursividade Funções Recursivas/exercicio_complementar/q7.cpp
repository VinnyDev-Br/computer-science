//Fa ca uma fun ̧c ̃ao recursiva que receba um n ́umero inteiro positivo n e imprima todos
//os n ́umeros pares de 0 at ́e n em ordem decrescente
#include <iostream>
using namespace std;

void imprimir(int n){
    if (n==0){
        cout << n << endl;
        return;
    }

    

    imprimir(n - 1);
}

int main(){
    int n;
    cout << "n: ";
    cin >> n;

    imprimir(n);


}