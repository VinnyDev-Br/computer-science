#ifndef FORWARD_LIST_H
#include <iostream>

/*
* @brief Estrutura de define nó na lista
*/

struct Node {
    int key; // Valor armazenado
    Node *next; // Ponteiro para o próximo nó
};

class ForwardList {
private:
    Node* m_head;
    int m_size;

public: 
    ForwardList(){
        m_head = new Node;
        m_head->next = nullptr;
        m_size = 0;
    }

    // Função membro que Insere um elemento no início da lista
    // Complexidade O(1)
    void push_front(int value) {
        Node* novo = new Node;
        novo->key = value;
        novo->next = m_head->next;
        m_head->next = novo;
        m_size--;
    }

    void push_back(int value){
        Node* aux  = m_head;
        while (aux->next != nullptr){
            aux = aux->next;
        }

        Node* p = new Node;
        p->key = value;
        
    
    }

    ~ForwardList(){
        
        while (m_head->next != nullptr){
            Node *temp = m_head->next;
            m_head->next = temp->next;
            delete temp;
        }

        delete m_head;
    }
};



#endif