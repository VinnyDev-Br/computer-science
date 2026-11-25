#include <iostream>

class ArvoreBinaria {
private:
    struct No {
        int chave;
        No* esq;
        No* dir;
        No(int c, No* e = nullptr, No* d = nullptr) : chave(c), esq(e), dir(d) {}
    };

    No* raiz;

    // Funções auxiliares recursivas
    static void imprimir(const No* n) {
        if (n == nullptr) return;
        imprimir(n->esq);
        std::cout << n->chave << " ";
        imprimir(n->dir);
    }

    static bool contem(const No* n, int chave) {
        if (n == nullptr) return false;
        return n->chave == chave || contem(n->esq, chave) || contem(n->dir, chave);
    }

    static int contar(const No* n) {
        if (n == nullptr) return 0;
        return 1 + contar(n->esq) + contar(n->dir);
    }

    static void destruir(No* n) {
        if (n == nullptr) return;
        destruir(n->esq);
        destruir(n->dir);
        delete n;
    }

    static int contar_h(No* n){
        if (n == nullptr) return 0;

        contar(n->esq);


    }

public:
    // Cria árvore vazia
    ArvoreBinaria() : raiz(nullptr) {}

    // Cria árvore com a chave na raiz e as outras duas como subárvores.
    // Os nós são transferidos: após a chamada, 'esq' e 'dir' ficam vazias.
    ArvoreBinaria(int chave, ArvoreBinaria& esq, ArvoreBinaria& dir) {
        No* e = esq.raiz;
        No* d = dir.raiz;
        esq.raiz = nullptr;
        dir.raiz = nullptr;
        if (&esq == &dir) d = nullptr;  // mesma árvore passada duas vezes: evita nós compartilhados
        raiz = new No(chave, e, d);
    }

    // Cópia e atribuição proibidas
    ArvoreBinaria(const ArvoreBinaria&) = delete;
    ArvoreBinaria& operator=(const ArvoreBinaria&) = delete;

    // Libera toda a memória
    ~ArvoreBinaria() { limpar(); }

    bool vazia() const { return raiz == nullptr; }

    void imprimir() const {
        imprimir(raiz);
        std::cout << "\n";
    }

    bool contem(int chave) const { return contem(raiz, chave); }

    // Remove todos os nós e deixa a árvore vazia
    void limpar() {
        destruir(raiz);
        raiz = nullptr;
    }

    //Escreva uma função que calcula o número de nos de uma arvore.
    int numeroDeNos() const { return contar(raiz); }


    //Escreva uma função que calcula a altura de uma arvore.
    int bt_height(No* no) const { return contar_h(raiz); }
};

int main() {
    ArvoreBinaria vazia1, vazia2;
    ArvoreBinaria folha1(1, vazia1, vazia2);   // árvore com 1 nó
    ArvoreBinaria folha3(3, vazia1, vazia2);   // vazia1 e vazia2 continuam vazias
    ArvoreBinaria t(2, folha1, folha3);        // 2 com filhos 1 e 3

    std::cout << "Vazia? " << t.vazia() << "\n";
    std::cout << "Chaves: ";
    t.imprimir();
    std::cout << "Contém 3? " << t.contem(3) << "\n";
    std::cout << "Contém 9? " << t.contem(9) << "\n";
    std::cout << "Nós: " << t.numeroDeNos() << "\n";

    t.limpar();
    std::cout << "Após limpar, vazia? " << t.vazia() << ", nós: " << t.numeroDeNos() << "\n";
    return 0;
}
