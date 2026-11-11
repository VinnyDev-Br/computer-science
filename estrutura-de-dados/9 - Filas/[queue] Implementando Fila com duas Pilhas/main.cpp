#include <iostream>
#include "queue.h"
using namespace std;

int main(){
    int n;
    cin >> n;
    Queue fila;
    
    while (n--){
        int opc;
        cin >> opc;
        switch (opc){
           case 1: 
                int x; 
                cin >> x;
                fila.push(x);
                break;
            case 2:
                fila.pop();
                break;
            case 3:
                cout << fila.front() << endl;
                break;
            default:
                break;
        }
    }
}