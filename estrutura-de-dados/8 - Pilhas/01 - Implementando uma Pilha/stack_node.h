#ifndef STACK_NO_H
#define STACK_NO_H

#include <stdexcept>

class Stack {
private:
    struct No {
        int dado;
        No* proximo;
        No(int d, No* p) {
            dado = d;
            proximo = p;
        }
    };

    No* topo;
    int qtd;

public:
    Stack() {
        topo = nullptr;
        qtd = 0;
    }

    ~Stack() {
        while (!vazia()) pop();
    }

    Stack(const Stack&) = delete;
    Stack& operator=(const Stack&) = delete;

    bool vazia() const {
        return topo == nullptr;
    }

    int tamanho() const {
        return qtd;
    }

    void push(int x) {
        topo = new No(x, topo);
        qtd++;
    }

    void pop() {
        if (vazia()) throw std::underflow_error("Pilha vazia");
        No* temp = topo;
        topo = topo->proximo;
        delete temp;
        qtd--;
    }

    int top() const {
        if (vazia()) throw std::underflow_error("Pilha vazia");
        return topo->dado;
    }
};

#endif