#include <iostream>
using namespace std;

int fatorial(int n){
    if (n <= 1){
        return 1;
    }
    return n * fatorial(n-2);
}

int main(){
    int n;
    cout << "Ok" << endl;
    cin >> n;

    cout << fatorial(n);
}
/*
A função fatorial duplo  ́e definida como o produto de todos os n ́umeros naturais de 1
at ́e algum n ́umero natural  ́ımpar n. Assim, o fatorial duplo de 5  ́e: 5!! = 1 ∗3 ∗5 = 15.
Fa ̧ca uma fun ̧c ̃ao que receba um n ́umero inteiro positivo  ́ımpar n e retorne o fatorial
duplo desse n ́umero.
*/