#include <queue>
#include <iostream>
using namespace std;

int main(){
    int n, k;
    queue<int> fila;
    cin >> n >> k;

    
    for (int i = 1; i <= n; i++){
        fila.push(i);
    }
    
    if (!fila.empty()){
        while (fila.size() != 1){
            for (int i = 0; i < k-1; i++){
                fila.push(fila.front());
                fila.pop();
            }
            cout << fila.front() << " ";
            fila.pop();
        }
        cout << endl << fila.front();
    }


}