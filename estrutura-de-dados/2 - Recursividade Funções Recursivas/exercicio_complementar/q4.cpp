#include <iostream>
using namespace std;

int fibonacci(int n){
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }

    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n;
    cout << "Ok";
    cin >> n;

    cout << fibonacci(n);
}
/*
Fa ̧ca uma fun ̧c ̃ao recursiva que calcule e retorne o n- ́esimo termo da sequˆencia Fibo-
nacci. Alguns n ́umeros desta sequˆencia s ̃ao: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ..
                                              0  1  2  3  4  5
*/