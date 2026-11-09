#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<char> times;

    // De A até P são 16 letras
    for (int i = 0; i < 16; i++){ 
        // 65 Representa a letra A na tabela ASCII e soma i para ir para proxima letra
        int codigo = 65+i; 
        char letra = codigo; 
        times.push(codigo); 
    }
    
    
    for (int i = 0; i < 15; i++){
        int gol1, gol2;
        cin >> gol1 >> gol2;
        
        if (gol1 > gol2){
            times.push(times.front());
            times.pop();
            times.pop();
        }
        else{
            times.pop();
            times.push(times.front());
            times.pop();
        }
        
    }
    
    cout << times.front() << endl;
    
    return 0;
}