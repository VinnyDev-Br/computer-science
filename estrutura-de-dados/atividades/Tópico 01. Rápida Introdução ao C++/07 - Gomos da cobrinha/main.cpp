#include <iostream>
#include <vector>
using namespace std;

struct posicao{
    int x,y;
};

void atualizar_cobra(vector<posicao> posicoes_cobra, int size, char direcao){
    /* 
    X aumenta para "R"
    X diminui para "L"
    Y aumenta para "D"3
    Y diminui para "U"
    */ 
    for (int i = size - 1; i > 0; i--){
        posicoes_cobra[i] = posicoes_cobra[i - 1];
    }
    
        switch (direcao){
            case 'D':
                posicoes_cobra[0].y += 1;
                break;
            case 'L':
                posicoes_cobra[0].x -= 1;
                break;
            case 'R':
                posicoes_cobra[0].x += 1;
                break;
            case 'U': // UP
                posicoes_cobra[0].y -= 1;
                break;
        }


    for (int i = 0; i < size; i++){
        cout << posicoes_cobra[i].x << " " << posicoes_cobra[i].y << endl;
    
    }
}

int main(){
    int gomos = 0;
    cin >> gomos;
    
    char direcao;
    cin >> direcao;
    
    
    vector<posicao> posicoes_cobra;
    
    for (int i = 0; i < gomos; i++){
        posicao gomo;
        
        cin >> gomo.x;
        cin >> gomo.y;
        
        posicoes_cobra.push_back(gomo);
    }

    atualizar_cobra(posicoes_cobra, gomos, direcao);

}