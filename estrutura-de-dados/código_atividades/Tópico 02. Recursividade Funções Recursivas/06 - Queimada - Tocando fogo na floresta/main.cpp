#include <iostream>
#include <string>
#include <vector>
#include "fogo.hpp"

using namespace std;

void show_mat(vector<string> mat);
void read_mat(vector<string> &mat, int nl);

int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    cin >> nl >> nc >> lfire >> cfire;
    vector<string> mat;
    read_mat(mat, nl);

    tocar_fogo(mat, lfire, cfire);
    
    show_mat(mat);
}

void show_mat(vector<string> mat){
    for(int l = 0; l < (int) mat.size(); l++) {
        cout << mat[l] << "\n";
    }
}

void read_mat(vector<string> &mat, int nl){
    for(int l = 0; l < nl; l++) {
        string linha;
        cin >> linha;
        mat.push_back(linha);
    }
}