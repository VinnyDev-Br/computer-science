// Aluno: Vinicius Macedo Freitas
// Matrícula: 585767
// Turma: ED 01A

#include "List.h"
#include <iostream>
#include <stdexcept>
#include <utility>

// Construtor: cria a lista vazia. A cabeça aponta para si mesma
// nos dois sentidos (anterior e proximo) e m_size começa em 0.
List::List() {
    m_head = new Node(0, nullptr, nullptr); 
    m_head->proximo = m_head;  
    m_head->anterior = m_head; 
    m_size = 0;

    // Como o construtor inicializa com ele vazio o m_head proximo aponta para o
    // m_head e o anterior também, porque ao contrario da lista simplesmente encadeada
    // o ultimo elemento vai apontar para o m_head ao invés de nullptr e o m_head->anterior
    // vai apontar para o ultimo elemento da lista
}

// Construtor de cópia: cria uma lista nova com os mesmos valores
// de lst, na mesma ordem (percorre lst e faz push_back de cada valor).
List::List(const List& lst) {
    m_head = new Node(0, nullptr, nullptr); 
    m_head->proximo = m_head;  
    m_head->anterior = m_head; 
    m_size = 0;

    // Nó auxiliar que recebe o primeiro elemento da lista a ser copiada
    Node *aux = lst.m_head->proximo; 
    // Como o ultimo nó aponta para o lst.m_head essa será a condição de parada
    while (aux != lst.m_head){ 
        // Uso a função pushback para adicionar todos os nós
        push_back(aux->key);
        // aux avança para o proximo nó
        aux = aux->proximo;    
    }
}

// Destrutor: Desaloca todos os nós incluindo o nó sentinela
List::~List() {
    // Começa pelo último nó e anda para trás pra frente até chegar ao nó cabeça
    Node *ultimo = m_head->anterior;

    while (ultimo != m_head){
        // Guarda o nó a ser apagado
        Node *aux = ultimo; 
        // Atualiza o ultimo nó da lista para receber o penultimo
        ultimo = ultimo->anterior; 
        delete aux; 
    }

    delete m_head; 
}

// Insere um novo nó com o valor key no final da lista.
// O novo nó é ligado ao nó cabeça e, em seguida, a
// lista é percorrida até o último nó antigo, que passa a apontar para ele.
void List::push_back(int key) {

    // Vou criar o nó que vai ser adicionado a lista passando o valor de key pelo construtor
    Node *novo = new Node(key, nullptr,  nullptr); 

    // Sabendo que o ultimo elemento é apontado por m_head->anterior e
    // o proximo do ultimo nó aponta para m_head e sabendo que novo é o último
    // Nó a ser adicionado irei atualizar os valores
    m_head->anterior = novo; 
    novo->proximo = m_head;

    // Após isso terei que chegar no último elemento e atualizar para que
    // o seu proximo aponte para o novo e o anterior do novo aponte para ele
    // para isso irei criar um nó auxiliar para percorrer todas a lista
    Node *aux = m_head;

    while (aux->proximo != m_head){ // O Penúltimo nó aponta para m_head 
        aux = aux->proximo; // então farei um laço até a condição de parada seja essa
    }

    aux->proximo = novo; // O penúltimo aponta para o ultimo
    novo->anterior = aux; // e o novo->anterior recebe o penúltimo

    m_size++; 
}

// Insere um novo nó com valor key logo após o k-ésimo nó da lista.
// Percorre k nós a partir do primeiro e liga o novo nó depois dele
// (ajustando os 4 ponteiros). Incrementa m_size.
void List::insertAfter(int key, int k) {
    // Primeiro verifico se a posição é válida se não for lanço exceção
    if (k > m_size || k <= 0){
        throw std::out_of_range("Indice inválido");
    }

    Node *novo = new Node(key, nullptr, nullptr);
    
    int i = 0;
    Node *aux = m_head;

    while (i < k){
        aux = aux->proximo;
        i++;
    }

    novo->anterior = aux;
    novo->proximo = aux->proximo;
    aux->proximo->anterior = novo;
    aux->proximo = novo;
    m_size++;
}

// Remove o último nó (m_head->anterior), devolve o valor dele,
// ajusta os ponteiros, deleta o nó e decrementa m_size.
int List::pop_back() {
    // Verifico se a lista está vazia, se estiver lanço uma exceção
    if (m_size == 0){
        throw std::out_of_range("pop_back em lista vazia");    
    }

    // Crio um nó aux que recebe o último elemento da lista 
    Node *aux = m_head->anterior; 
    // Armazeno o key do ultimo para ser retornado
    int value = m_head->anterior->key;
    // O penúltimo passar a ser o último
    m_head->anterior = m_head->anterior->anterior; 
    m_head->anterior->proximo = m_head;
    // Desaloco a memória do último nó armazenado em aux
    delete aux;

    m_size--;

    // Retorno o valor armazenado do último elemento
    return value; 
}

// Remove a primeira ocorrência de key: percorre a lista, e ao
// achar o valor, religa anterior e proximo e deleta o nó. Para na primeira ocorrência.
void List::remove(int key) {
    // Nó auxiliar para armazenar o primeiro nó
    Node* aux = m_head->proximo;
    // Se a lista estiver vazia a condição do laço não executa
    // pois o aux é o primeiro nó e se estiver vázia o ultimo nó 
    // é o proprio m_head
    while (aux != m_head){
        // Faço a verificação se o valor procurada
        // Se estiver eu deleto e faço a ligação do seu anterior para o seu proximo
        // E o seu sucessor o anterior dele recebe o anterior do atual
        if (aux->key == key){ 
            aux->anterior->proximo = aux->proximo;
            aux->proximo->anterior = aux->anterior;
            delete aux;
            m_size--;
            return;
        }
        // Caso Contrário eu continuo a percorrer a lista
        aux = aux->proximo;
    }
}

// Remove todas as ocorrências de key da lista.
void List::removeAll(int key) {
    Node* aux = m_head->proximo;

    while (aux != m_head){
        // Guarda o próximo nó antes de um possível delete,
        // senão perderíamos o caminho para continuar o percurso
        Node* proximo = aux->proximo;

        if (aux->key == key){
            // Mesma lógica do remove: o anterior e o próximo passam a
            // apontar um para o outro, "pulando" o nó que será apagado
            aux->anterior->proximo = aux->proximo;
            aux->proximo->anterior = aux->anterior;
            delete aux;
            m_size--;
        }

        aux = proximo;
    }
}

// Remove todos os nós, deixando só a cabeça apontando para si
//  m_size volta a 0.
void List::clear() {
    // Quando a lista está vazia o m_head->anterior aponta para m_head
    // Faço um loop com essa condição de parada até que a condição seja cumprida 
    while (m_head->anterior != m_head){
        //Armazeno o último nó para desalocar
        Node *aux = m_head->anterior; 
        // Atualizo os valores pois o ultimo passar ser o penultimo
        // e o penultimo nao aponta mais para o ultimo e sim para cabeça
        // que é o m_head.
        m_head->anterior = m_head->anterior->anterior;
        m_head->anterior->proximo = m_head;
        delete aux;
    }
    m_size = 0;
}

// Imprime os valores do primeiro ao último (segue os "proximo"
// a partir de m_head->proximo até voltar à cabeça).
void List::print() const {
    // Irei armazenar o primeiro nó 
    Node *aux = m_head->proximo;
    // Com um laço irei percorrer a lista até que aux seja igual a m_head
    // a lista terá chegado ao fim quando o ultimo nó seu proximo aponta para m_head
    while (aux != m_head){
        std::cout << aux->key << " ";
        aux = aux->proximo;
    }
}

// Imprime os valores do último ao primeiro
// a partir de m_head->anterior até voltar à cabeça).
void List::printReverse const() {
    // Mesma lógica do print mas partindo do último e percorrendo com o laço
    // de trás pra frente até o ultimo ser m_head
    Node *aux = m_head->anterior;
    while (aux != m_head){
        std::cout << aux->key << " ";
        aux = aux->anterior;
    }
}

// Retorna true se a lista está vazia ou seja se m_size for igual a 0.
bool List::empty const() {
    return m_size == 0;
}

// Retorna o tamanho da lista.
int List::size const() {
    return m_size;
}

// Concatena lst ao final da lista atual, sem criar nós novos.
void List::concat(List& lst){
    // Verifico Se lst está vazia ou são iguais, se sim não há nada para concatenar
    if (lst.empty() || this == &lst){ 
        return;
    }

    // Guarda o último nó desta lista antes de alterar qualquer ponteiro
    Node *ultimo = m_head->anterior;

    // Liga o último desta lista ao primeiro de lst (nos dois sentidos)
    ultimo->proximo = lst.m_head->proximo;
    lst.m_head->proximo->anterior = ultimo;

    // O último de lst passa a ser o último desta lista e aponta
    // para o m_head, mantendo a lista circular
    m_head->anterior = lst.m_head->anterior;
    lst.m_head->anterior->proximo = m_head;

    m_size += lst.m_size;

    lst.m_head->proximo = lst.m_head;
    lst.m_head->anterior = lst.m_head;
    lst.m_size = 0; 
}

// Atribuição: limpa esta lista e copia todos os valores de lst.
List List::operator=(const List& lst){
    // Verifico se já são iguais, se for não há nada a fazer
    if (this == &lst){
        return *this;
    }
    // Uso o construtor de cópia para criar uma lista nova com os valores de lst
    List copia(lst);

    // Troca o nó m_head e o tamanho desta lista com os da cópia.
    // Agora esta lista tem os valores de lst, e a cópia ficou com os nós antigos.
    std::swap(m_head, copia.m_head);
    std::swap(m_size, copia.m_size);

    // Ao sair da função, o destrutor de copia libera os nós antigos
    // inclusive o nó m_head antigo, sem vazamento de memória.
    return *this;
}   

// Retorna true se as listas têm o mesmo tamanho e o k-ésimo
// valor de uma é igual ao k-ésimo da outra.
bool List::operator==(const List& lst) const{
    // Verifico se o tamanho das listas são iguais se não for já retorno false
    if (lst.m_size != m_size){
        return false;
    }

    // Sabendo que o tamanho é igual irei percorrer os dois ao mesmo tempo
    // Definindo duas auxiliares para cada e verificando se possui algum valor diferente
    // se houver return false, caso contrário o aux anda até sair do laço e retornar true
    Node *aux = m_head->proximo;
    Node *auxlst = lst.m_head->proximo;

    while (aux != m_head && auxlst != lst.m_head){
        if (aux->key != auxlst->key){
            return false;
        }
        else{
            aux = aux->proximo;
            auxlst = auxlst->proximo;
        }
    }

    return true;
}

// Retorna true se as listas são diferentes (o contrário do ==).
bool List::operator!=(const List& lst) const{
    return !(*this == lst);
}