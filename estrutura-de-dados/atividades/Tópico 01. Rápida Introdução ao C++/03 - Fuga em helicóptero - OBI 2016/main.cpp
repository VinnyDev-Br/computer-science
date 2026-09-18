estrutura-de-dados/código_atividades/Tópico 01. Rápida Introdução ao C++/03 - Fuga em helicóptero - OBI 2016/main.cpp#include <iostream>
using namespace std;


int main (){
    int h, p, f, d = 0;
    cin >> h >> p >> f >> d;
    
    if (d == 1){ 
        while ((f != h) && (f != p)){ // Enquanto não encontra pelo menos um dos dois ele segue.
            
            f++; // Fugitivo anda
            
            if (f > 15) // Se exceder o valor máximo volta para zero.
                f = 0;
            
            if (f == h)
                cout << "S\n";
            
            if (f == p)
                cout << "N\n";
            
            
            
        }
    }
    
    else{
        while ((f != h) && (f != p)){ // Enquanto não encontra pelo menos um dos dois ele segue.
            
            f--; // Fugitivo anda direção contrária
            
            if (f < 0) // Se exceder o valor mínimo volta para quinze.
                f = 15;
            
            if (f == h)
                cout << "S\n";
            
            if (f == p)
                cout << "N\n";
            
            
        }
        
    }
    
    
    return 0;
}