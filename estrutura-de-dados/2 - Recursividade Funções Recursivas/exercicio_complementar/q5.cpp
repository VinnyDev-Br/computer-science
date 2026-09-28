#include <iostream>
#include <string>
using namespace std;

void inverter(string &nome, char ini, char end){
    if (ini >= end){
        return;
    }

    char aux = nome[ini];
    nome[ini] = nome[end];
    nome[end] = aux;

    return inverter(nome, ++ini, --end);
}

int main(){
    string nome = "Vinicius";

    cout << nome << endl;

    inverter(nome, 0, nome.length() - 1);

    cout << nome << endl;

    return 0;
}
/*
faça uma função recursiva que inverta uma String
*/