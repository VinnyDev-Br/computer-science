#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int contaCaracteres(string str, int n, char c)
{
    // fazer
    if (str.length() == 0){
        return n;
    }
    
    int ultimo = str.length() - 1;
    
    if (str[ultimo] == c){
        n += 1;
    }
    
    str.pop_back();
    
    return contaCaracteres(str, n, c);
}

int main() 
{
   // fazer
   string str;
   char caractere;
   int n = 0;
   
   getline(cin, str);
   cin >> caractere;
   
   cout << contaCaracteres(str, n, caractere);
}