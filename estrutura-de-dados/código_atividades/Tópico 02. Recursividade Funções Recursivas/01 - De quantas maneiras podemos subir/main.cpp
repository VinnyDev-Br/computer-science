#include <iostream>
using namespace std;

int verificar_maneiras(int degraus){
    if(degraus == 1 || degraus == 2) 
        return 1;
    
    if(degraus == 3) 
        return 2;

    return verificar_maneiras(degraus - 1) + verificar_maneiras(degraus - 3);
}

int main(){
    int degraus = 0;
    cin >> degraus;
    
    cout << verificar_maneiras(degraus) << endl;
}