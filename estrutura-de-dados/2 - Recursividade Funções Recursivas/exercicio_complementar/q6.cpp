//6. Façca uma funçao recursiva que receba um numero inteiro positivo n e imprima todos
//os n ́umeros naturais de 0 at ́e n em ordem decrescent
#include <iostream>
using namespace std;

void imprimir(int &n){
    if (n==0){
        cout << n << endl;
        return;
    }

    cout << n << endl;
    imprimir(--n);
    
}

int main(){
    int n;
    cout << "n: ";
    cin >> n;

    imprimir(n);


}