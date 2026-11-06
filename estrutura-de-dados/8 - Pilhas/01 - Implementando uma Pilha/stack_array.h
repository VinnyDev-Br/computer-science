#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H


class Stack{
private:
    int const CAPACIDADE = 100;
    int dados[CAPACIDADE];
    int topo;

public:
    Stack(){
        topo = -1;
    }

    bool vazia const (){
        return topo == -1;
    }

    bool cheio const(){
        return topo == CAPACIDADE-1;
    }

    int tamanho const {
        return topo + 1;
    }

    void push(int x){
        if (!cheio())
            dados[++topo] = x;
    }

    void pop(){
        if (!vazia())
            topo--;
    }
}

#endif