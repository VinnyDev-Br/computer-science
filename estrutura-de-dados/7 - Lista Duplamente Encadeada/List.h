// Aluno: Vinicius Macedo Freitas
// Matrícula: 585767
// Turma: ED 01A

#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {
private:
    Node* m_head;  // nó m_head (Nó Sentinela)
    int m_size;   // tamanho da lista 

public:
    List();                      // construtor
    List(const List& lst);       // construtor de cópia
    ~List();                     // destrutor

    void push_back(int key);
    int pop_back();
    void insertAfter(int key, int k);
    void remove(int key);
    void removeAll(int key);
    void print() const;
    void printReverse() const;
    bool empty() const;
    int size() const;
    void clear();
    void concat(List& lst);

    List operator=(const List& lst);
    bool operator==(const List& lst) const;
    bool operator!=(const List& lst) const;
};

#endif // LIST_H
