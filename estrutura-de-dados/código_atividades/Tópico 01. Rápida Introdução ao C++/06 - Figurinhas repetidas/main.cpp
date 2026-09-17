#include <iostream>
#include <vector>
using namespace std;



int main (){
    int total_album = 0;
    int total_baruel = 0;
    vector<int> album;
    vector<int> repetidas;
    
    
    
    cin >> total_album; // Recebe os valores
    cin >> total_baruel; // Recebe os valores
    
    //Recolhe e Percorre o vetor de cartas 
    for(int i = 0; i < total_baruel ; i++){
        
        int figurinha = 0;
        
        cin >> figurinha; // Recebe os valores
        
        album.push_back(figurinha); // Coloca a figurinha no vetor

        
        if (i > 0){  //Após primeiro termo comparar com o anterior
        
            int atual = album[i];  
            int anterior = album[i - 1];
            
            if (atual == anterior){
                repetidas.push_back(atual);
            }
        }
    }
    
    if (repetidas.empty()){
        cout << "N";
    }
    else{
        for (int i = 0; i < repetidas.size(); i++){
            (i == repetidas.size() - 1) ? cout << repetidas[i] : cout << repetidas[i] << " ";
        }
    }
    
    int contador = 0;

    cout << endl; // Quebra a linha para mostrar as faltantes do album
    
    for (int n = 1; n <= total_album; n++){
        
        bool achou = false;
        
        for (int i = 0; i < album.size(); i++){
            if (n == album[i]){
                achou = true;
                break;
            }
        }
                
        
        if (!achou){
            if (contador == 0){
                cout << n;
                contador += 1;
            }
            else{
                cout << " "<< n;
                contador += 1;
            }
            
        }

    }
    
    
    
    if (contador == 0)
        cout << "N" << endl;
    else
        cout << endl;

}   
