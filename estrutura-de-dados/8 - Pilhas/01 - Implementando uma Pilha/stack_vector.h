#ifndef STACK_VECTOR_H
#define STACK_VECTOR_H

#include <vector>
#include <stdexcept>

class Stack {
private:
    std::vector<int> dados;

public:
    bool vazia() const {
        return dados.empty();
    }

    int tamanho() const {
        return dados.size();
    }

    void push(int x) {
        dados.push_back(x);
    }

    void pop() {
        if (vazia()) throw std::underflow_error("Pilha vazia");
        dados.pop_back();
    }

    int top() const {
        if (vazia()) throw std::underflow_error("Pilha vazia");
        return dados.back();
    }
};

#endif