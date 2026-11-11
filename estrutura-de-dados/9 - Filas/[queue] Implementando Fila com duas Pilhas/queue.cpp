#include "queue.h"
#include <stdexcept>

bool Queue::empty() const{
   return pilha1.empty();
}

int Queue::size() const{
    return pilha1.size();
}
void Queue::push(const int& x){ // Função 1 Enfileirar o elemento no final da fila
    pilha1.push(x);
}
void Queue::pop(){ // Função 2 Retirar da fila o elemento da frente
    if (pilha1.empty()){
        throw std::runtime_error("fila vazia");
    }
    
    while (pilha1.size() > 1){
        pilha2.push(pilha1.top());
        pilha1.pop();
    }
    
    pilha1.pop();
    
    while (!pilha2.empty()){
        pilha1.push(pilha2.top());
        pilha2.pop();
    }
}

    int Queue::front() { // Função 3 mostrar o elemento da frente da fila
    if (pilha1.empty()){
        throw std::runtime_error("fila vazia");
    }
    
    while (pilha1.size() > 1){
        pilha2.push(pilha1.top());
        pilha1.pop();
    }
    
    int frente = pilha1.top();
    
    while (!pilha2.empty()){
        pilha1.push(pilha2.top());
        pilha2.pop();
    }
    
    return frente;
}
