#ifndef QUEUE_H
#define QUEUE_H

#include <stack>

class Queue {
private:
    std::stack<int> pilha1;
    std::stack<int> pilha2;
public:
    bool empty() const;
    int size() const;
    void push(const int& x);
    void pop();
    int front();
};

#endif