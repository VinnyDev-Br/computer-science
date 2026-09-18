#include <iostream>
using namespace std;

int main(){
    int n = 0;
    cin >> n;
    
    int melhor_pontuacao = 999;
    int indice_vencedor = -1;
    
    
    for (int i = 0; i < n; i++){
        
        int a, b = 0;
        cin >> a >> b;
        
        int pontuacao = abs(a - b);
        
        if (a < 10 || b < 10)
            continue;
            
        
        if (pontuacao < melhor_pontuacao){
            melhor_pontuacao = pontuacao;
            indice_vencedor = i;
        }
    }
    
    if (indice_vencedor == -1){
        cout << "sem ganhador" << endl;
    }
    else{
        cout << indice_vencedor << endl;
    }
    
    
    
}