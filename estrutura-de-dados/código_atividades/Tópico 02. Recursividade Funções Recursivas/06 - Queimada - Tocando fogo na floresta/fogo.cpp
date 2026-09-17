#include "fogo.hpp"
using namespace std;

void tocar_fogo(vector<string> &mat, int l, int c) {
    int nl = mat.size();     // numero de linhas
    int nc = mat[0].size();  // numero de colunas

    // Caso Base:
    // Se a posicao for fora da matriz
    if (l >= nl || c >= nc || c < 0 || l < 0)
        return;
    
    // Se a posicção for uma arvore .
    if (mat[l][c] != '#')
        return;
    
    
    mat[l][c] = 'o'; // Queima a arvore
    
    tocar_fogo(mat, l, c + 1); // Direita
    tocar_fogo(mat, l + 1, c); // Cima
    tocar_fogo(mat, l, c - 1); // Esquerda
    tocar_fogo(mat, l - 1, c); // Baixo
}