#include <iostream>
using namespace std;


int eh_casado(int, int, int[]);


int main(){
    int n = 0;
    cin >> n;
    
    
    int casou = 0;
    int animais[50] = {0};
    int descasados[50] = {0};
    
    for (int i = 0; i < n; i++){
        
        cin >> animais[i];
        
        int posi = eh_casado(animais[i], n, descasados);
        
        if (posi == -1){
            descasados[i] = animais[i];
        }
        
        else{
            casou += 1;
            descasados[posi] = 0;
        }
    }        
    
    
    cout << casou << endl;    
    return 0;
}
    
    
int eh_casado(int alvo, int n, int descasados[]){
    for (int i = 0; i < n; i++){
        if (descasados[i] == -alvo){
            return i;
        }
    }
    
    return -1;
}
    
    