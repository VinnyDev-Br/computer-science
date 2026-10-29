// Aluno: Vinicius Macedo Freitas
// Matrícula: 585767
// Turma: ED 01A

#ifndef NODE_H
#define NODE_H

struct Node {
    int key;   // valor a ser guardado
    Node* anterior;  // ponteiro para o nó anterior (previous)
    Node* proximo;  // ponteiro para o próximo nó (next)

    // Construtor 
    Node(int key, Node* anterior, Node* proximo){
        this->key = key;
        this->anterior = anterior;
        this->proximo = proximo;
    }
};



#endif // END of NODE.h