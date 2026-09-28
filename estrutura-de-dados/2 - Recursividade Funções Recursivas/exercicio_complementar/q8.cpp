//Fa ca uma fun ̧c ̃ao recursiva que receba um n ́umero inteiro positivo n e imprima todos
//os n ́umeros pares de 0 at ́e n em ordem decrescente
#include <iostream>
using namespace std;

void imprimir(int n){

    if (n==2){ // Caso base irei imprimir o primeiro primo 
        cout << n << endl;
        return;
    }

    if (n==3){ // Caso base irei imprimir o primeiro primo 
        cout << n << endl;
    }
    
    if (n==5){ // Caso base irei imprimir o primeiro primo 
        cout << n << endl;
    }
    
    if (n==7){// Caso base irei imprimir o primeiro primo 
        cout << n << endl;
    }

    if ((n%2 != 0) and (n%3 != 0) and (n%5 !=0 ) and (n%7 != 0)){
        cout << n << endl;
    }

    imprimir(n - 1);


}

int main(){
    int n;
    cout << "n: ";
    cin >> n;

    imprimir(n);


}