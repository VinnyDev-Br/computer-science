#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H
#include <iostream>

/**
 * @brief Estrutura que define um nó da lista 
 */
struct Node {
    int key;    // valor armazenado
    Node *next; // ponteiro para o próximo nó

    ~Node() {
        std::cout << "nó " << key << " deletado.\n";
    }
};

/**
 * @brief Classe que define uma lista simplesmente encadeada.
 * Essa lista tem nó sentinela.
 */
class ForwardList {
private:
    Node* m_head; // ponteiro para o nó sentinela
    int m_size;

public:
    // Construtor default: cria lista vazia
    ForwardList() {
        m_head = new Node;
        m_head->next = nullptr;
        m_size = 0;
    }

    // Função-membro que insere um elemento no início da lista
    // Complexidade: O(1)
    void push_front(int value) {
        Node* novo = new Node;
        novo->key = value;
        novo->next = m_head->next;
        m_head->next = novo;
        m_size++;
    }

    // Função-membro que insere um elemento ao final da lista
    // Complexidade: O(n)
    void push_back(int value) {
        Node *aux = m_head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        Node *p = new Node;
        p->key = value;
        p->next = nullptr;
        aux->next = p;
        m_size++;        
    }

    // Retorna o tamanho atual da lista
    int size() {
        return m_size;
    }

    // Imprimir os elementos da lista na tela
    void print() {
        Node *aux = m_head;
        while (aux->next != nullptr) {
            aux = aux->next;
            std::cout << aux->key << " ";
        }
        std::cout << "\n";
    }
    // destrutor: libera toda a memória que foi alocada
    ~ForwardList() {
        while(m_head->next != nullptr) {
            Node *temp = m_head->next;
            m_head->next = temp->next;
            delete temp;
        }
    }

    // Remove um elemento do final da lista
    // complexidade: O(n)
    void pop_back() {
        if (m_head->next == nullptr) {
            return;
        }

        Node* current = m_head;
        while (current->next->next != nullptr) {
            current = m_head->next;
        }

        delete current->next;
        current->next = nullptr;
        m_size--;
    }

    //Remove todos os elementos da lista
    void clear(){

        while(m_head->next != nullptr){
            Node *temp = m_head->next;
            m_head->next = temp->next;
            delete temp;
        }

        m_size = 0;
    }

    // Remove o primeiro elemento da lista
    // Complexidade: O(1)
    void pop_front() {
        if (m_head->next == nullptr) {
            return;
        }
        Node* temp = m_head->next;
        m_head->next = temp->next;
        delete temp;
        m_size--;
    }

    // Inverte a ordem dos elementos da lista
    // Complexidade: O(n)
    void reverse() {
        Node* prev = nullptr;
        Node* curr = m_head->next;
        while (curr != nullptr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        m_head->next = prev;
    }

    // Remove todas as ocorrências de value
    // Complexidade: O(n)
    void remove_all(int value) {
        Node* aux = m_head;
        while (aux->next != nullptr) {
            if (aux->next->key == value) {
                Node* temp = aux->next;
                aux->next = temp->next;
                delete temp;
                m_size--;
            } else {
                aux = aux->next;
            }
        }
    }

    // Remove a primeira ocorrência de value. Retorna true se removeu
    // Complexidade: O(n)
    bool remove(int value) {
        Node* aux = m_head;
        while (aux->next != nullptr) {
            if (aux->next->key == value) {
                Node* temp = aux->next;
                aux->next = temp->next;
                delete temp;
                m_size--;
                return true;
            }
            aux = aux->next;
        }
    }
    
    // Remove o elemento da posição index (0 até size - 1)
    // Complexidade: O(n)
    void remove_at(int index) {
        if (index < 0 || index >= m_size) {
            return;
        }
        Node* aux = m_head;
        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }
        Node* temp = aux->next;
        aux->next = temp->next;
        delete temp;
        m_size--;
    }
    
    // Insere um elemento na posição index (0 até size)
    // Complexidade: O(n)
    void insert_at(int value, int index) {
        if (index < 0 || index > m_size) {
            return;
        }
        Node* aux = m_head;
        for (int i = 0; i < index; i++) {
            aux = aux->next;
        }
        Node* novo = new Node;
        novo->key = value;
        novo->next = aux->next;
        aux->next = novo;
        m_size++;
    }
};

#endif