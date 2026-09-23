![Brasão da Universidade Federal do Ceará](https://www.ufc.br/brasao-vertical.svg)



As listas lineares estão entre os tipos abstratos de dados de manipulação mais simples. Como vimos em aula, o tipo de armazenamento de uma lista linear pode ser classificado de acordo com a posição relativa na memória de dois nós consecutivos na lista. O caso em que cada dois nós da lista estão em posições contı́guas de memória corresponde à alocação sequencial de memória. Já o caso em que não é garantido que cada dois nós consecutivos estejam em posições contı́guas de memória corresponde à alocação encadeada. A escolha de um ou outro tipo depende essencialmente das operações que serão executadas sobre a lista, do número de listas envolvidas na operação, bem como das caracterı́sticas particulares dessas listas.

A maneira mais simples de manter uma lista linear na memória do computador é alocar seus nós em posições contı́guas (alocação sequencial). Nesse caso, o endereço real do _(j + 1)_\-ésimo nó da lista se encontra _C_ unidades adiante daquele correspondente ao _j_\-ésimo elemento. A constante _C_ é o número de bytes de memória que cada nó ocupa. A correspondência entre o ı́ndice do array e o endereço real é feita automaticamente pela linguagem de programação quando da tradução do programa.

Em aula, estudamos uma implementação de lista linear usando alocação sequencial (lista sequencial). Na implementação que estudamos, a estrutura de dados (o vetor) é encapsulada na classe Vector por meio da utilização do modificador `private`, enquanto as interfaces das funções tornam-se visı́veis por meio do modificador `public`. Deste modo, graças ao encapsulamento, o programador pode modificar tanto a estrutura de dados quanto a implementação das operações sem provocar alterações nos programas que utilizam a classe Vector, desde que as interfaces das funções sejam preservadas.

A implementação de listas lineares por meio de vetores tem como vantagem a economia de memória, já que não gasta-se bytes com ponteiros. Uma segunda vantagem consiste no tempo constante para acessar um nó da lista, dado que sua posição seja conhecida. Porém, como desvantagem citamos o custo para inserir ou retirar itens da lista, que pode causar um deslocamento de todos os itens, no pior caso. Além disso, em aplicações em que não existe previsão sobre o crescimento da lista, a utilização de vetores pode exigir realocação de memória. Essa é uma operação de alto custo em termos de tempo e memória, pois é preciso alocar uma nova área com mais posições do que a atual e copiar todos os itens para ela. Apesar dessa desvantagem, listas sequenciais apresentam melhor performance no caso em que operações de acesso a um nó são frequentemente executadas.

 @017 L2 - Construa um Vetor dinâmico I - Orientado a Objetos

## Problema

Em sala de aula, iniciamos a implementação de uma lista sequencial redimensionável (classe Vector), ou seja, sempre que inserimos um novo dado na lista, ela se ajusta e aumenta de tamanho a fim de poder abrigar o novo valor que foi passado. Na verdade, implementamos essa lógica apenas para a função push\_back(). Mas existem diversas outras funções de inserção e remoção a serem programadas naquela lista.

## Atividade

Implementar sete funções adicionais na classe Vector que foi iniciada em sala de aula. As funções adicionais estão explicitadas abaixo.
```cpp
// funcao front

// Retorna uma referencia (reference) para o primeiro elemento na lista.

// Se nao existir primeiro elemento, o comportamento dessa funcao eh indeterminado.

// Complexidade: O(1)

**int& front();**

// versao const da funcao front

// Retorna uma 'const reference' para o primeiro elemento na lista.

// Se nao existir primeiro elemento, o comportamento dessa funcao eh indeterminado.

// Complexidade: O(1)

**const int& front() const;**

// funcao back

// Retorna uma referencia (reference) para o ultimo elemento na lista.

// Se nao existir ultimo elemento, o comportamento dessa funcao eh indeterminado.

// Complexidade: O(1)

**int& back();**

// versao const da funcao back

// Retorna uma 'const reference' para o ultimo elemento na lista.

// Se nao existir ultimo elemento, o comportamento dessa funcao eh indeterminado.

// Complexidade: O(1)

**const int& back() const;**

// funcao remove\_all

// Essa funcao remove todas as ocorrencias do elemento 'elem' da lista

// Nao esqueca de decrementar o valor do atributo m\_size sempre

// que um elem for removido da lista

// Complexidade: O(n) no pior caso

**void remove\_all(int elem);**

// funcao insert\_at

// Esta funcao adiciona o elemento 'elem' no indice 'index' (somente se 0 <= index <= m\_size).

// Se o 'index' estiver fora do intervalo especificado acima, esta funcao lanca uma excecao

// do tipo std::out\_of\_range com a mensagem "indice fora do intervalo".

// Antes de fazer a insercao, todos os elementos posicionado a partir

// do indice k em diante sao deslocados uma posicao para a direita.

// Cuidado com a alocacao de memoria.

// Complexidade: O(n) no pior caso

**void insert\_at(int elem, unsigned int index);**

// Funcao remove\_at

// Essa funcao remove o elemento posicionado no indice 'index' da lista.

// O 'index' deve estar dentro do intervalo: 0 <= index <= m\_size-1

// Se o 'index' estiver fora do intervalo especificado acima, esta funcao lanca uma excecao

// do tipo std::out\_of\_range com a mensagem "indice fora do intervalo".

// Ao remover um elemento, pode ser necessario deslocar elementos para a esquerda.

// Complexidade: O(n) no pior caso

**void remove\_at(unsigned int index);**
```
## Help

A atividade já possui alguns arquivos prontos. O arquivo main.cpp já está programado e possui comandos que serão utilizados pelos testes do Moodle a fim de avaliar se as funções foram implementadas corretamente.

O outro arquivo que vai junto com esta atividade é o arquivo Vector.h. Ele contém a declaração da classe e também a implementação de algumas das funções-membros da classe. Nesse arquivo que você deve implementar as 

funções que foram pedidas nessa atividade. As funções podem ser implementadas dentro ou fora da classe, você escolhe o que achar melhor.

## Exemplo

```
#__case remover todos os elementos com valor 6
$pushback 
```

```
#__case remover o primeiro e o ultimo da lista
```

```
$print
22 33 4 5 1 0 -2 -5 67 89 213 23 44 14 15 16 76 75 74 87 16 12 13 14
$removeat 0
$print
33 4 5 1 0 -2 -5 67 89 213 23 44 14 15 16 76 75 74 87 16 12 13 14
$removeat 22
$print
33 4 5 1 0 -2 -5 67 89 213 23 44 14 15 16 76 75 74 87 16 12 13
$exit
```

## Arquivos requeridos

#### main.cpp
```cpp
/**
 * NAO MEXA NESSE ARQUIVO, ELE JA ESTA FINALIZADO
 */
#include <iostream>
#include <sstream>
#include <string>
#include "Vector.h"
using namespace std;

int main()
{
	Vector myvec;
	
	while(true) {
		string line;
		string comando;
		
		getline(cin, line);
		stringstream ss { line };
		ss >> comando;

		if(comando == "exit") {
            cout << "$exit\n";
			return 0;
		}
		// front
		else if(comando == "front") {
            cout << "$front\n";
			cout << myvec.front() << '\n';
            const Vector cvec(myvec);
            cout << "front of const copy vector: " << cvec.front() << '\n';
		}
        // back
		else if(comando == "back") {
			cout << "$back\n";
			cout << myvec.back() << '\n';
            const Vector cvec(myvec);
            cout << "back of const copy vector: " << cvec.back() << '\n';
		}
		// removeall [v]
        // remove todos os elementos com valor v
		else if(comando == "removeall") {
			int v;
			ss >> v;
			cout << "$removeall " << v << '\n';
            myvec.remove_all(v);
		}
        // insertat [v] [k]
        // insere o elemento v no indice k
		else if(comando == "insertat") {
			int v, k;
            ss >> v;
			ss >> k;
            cout << "$insertat " << v << " " << k << '\n';
            try{
                myvec.insert_at(v, k);
            }
            catch(const std::out_of_range& e) {
                cout << "fail: " << e.what() << '\n';
            }
		}
        // removeat [v]
        // remove o elemento no indice k
		else if(comando == "removeat") {
			int k;
			ss >> k;
			cout << "$removeat " << k << '\n';
            try {
                myvec.remove_at(k);
            }
            catch(const std::out_of_range& e) {
                cout << "fail: " << e.what() << '\n';
            }
		}
        // pushback v1 v2 ... vk
		else if(comando == "pushback") {
            int v;
            cout << "$pushback ";
			while(ss >> v) {
                cout << v << " ";
                myvec.push_back(v);
            }
            cout << "\n";
		}
		// print
		else if(comando == "print") {
            cout << "$print\n";
            for(size_t i{}; i< myvec.size(); ++i) {
                cout << myvec[i] << " ";
            }
            cout << endl;
		}
        // size 
		else if(comando == "size") {
            cout << "$size\n";
            cout << myvec.size() << endl;
		}
		else {
			cout << "comando inexistente" << endl;
		}
	}
	return 0;
}
```

#### Vector.h
```cpp
/**
 * @file Vector.h
 * @author Atilio G. Luiz
 * @date 26-09-2023
 * @brief Classe que implementa uma lista linear sequencial de inteiros
 */
#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>

class Vector {
private:
    unsigned int m_size{};      // numero de elementos atualmente na lista
    unsigned int m_capacity{};  // capacidade atual da lista: o tamanho real do vetor interno
    int *m_vet{};               // ponteiro para o vetor de inteiros

public:
    // Construtor default: cria lista vazia e com capacidade zero
    // Complexidade: O(1)
    Vector() = default;
    // Construtor que recebe a capacidade
    // Complexidade: O(1)
    Vector(unsigned int cap);
    // Construtor de copia (copy constructor)
    // Foi preciso implementar nossa propria versao desse construtor
    // para que ele funcione da forma correta
    // Complexidade: O(1)
    Vector(const Vector& v);
    // Funcao que recebe um valor inteiro newCap 
    // que sera a nova capacidade.
    // Se m_capacity >= newCap, a funcao faz nada.
    // Caso contrario, a funcao aumenta a capacidade
    // do Vector para um valor maior ou igual a newCap
    // Complexidade: O(n)
    void reserve(unsigned int newCap);
    // Funcao que insere um elemento no final
    // da lista. Se a lista ficar cheia, ele
    // primeiro aumenta a capacidade da lista
    // e somente depois insere no final.
    // Complexidade: O(n) no pior caso
    void push_back(int val);
    // Funcao que recebe um índice i e retorna
    // o elemento que esta no índice i.
    // Se o indice nao existir na lista, essa funcao
    // vai lancar uma excecao.
    // Complexidade: O(1)
    int& at(unsigned int i);
    // Versao const da funcao at()
    // Complexidade: O(1)
    const int& at(unsigned int i) const;
    // Destrutor: libera memoria alocada
    // Complexidade: O(1)
    ~Vector();
    // Funcao const que retorna o numero de elementos na lista
    // Complexidade: O(1)
    unsigned int size() const;
    // Funcao const que retorna a capacidade total da lista
    // Complexidade: O(1)
    unsigned int capacity() const;
    // Funcao const que retorna true se e somente se a lista estiver vazia
    // Complexidade: O(1)
    bool empty() const;
    // sobrecarga do operador de indexacao
    // recebe um indice i e retorna o elemento no indice i
    // Se o indice não estiver dentro do intervalo, 
    // o comportamento dessa funcao é indeterminado.
    // Complexidade: O(1)
    int& operator[](unsigned int i);
    // versao const do operador[]
    // Complexidade: O(1)
    const int& operator[](unsigned int i) const;
    // Funcao que remove o ultimo elemento da lista, se a lista nao estiver vazia.
    // Se a lista estiver vazia, entao essa funcao nao faz nada.
    // O que essa funcao faz de fato eh apenas decrementar o atributo m_size.
    // Complexidade: O(1)
    void pop_back();
    // Deletei o operador de atribuicao
    Vector& operator=(const Vector& v) = delete;


    // ***********************************************************************
    // FUNCOES A SEREM IMPLEMENTADAS
    // Tarefa: implemente as funcoes abaixo.
    // Cada funcao ja vem acompanhada de uma explicacao de como deve ser
    // o seu funcionamento.
    // ***********************************************************************

    // funcao front
    // Retorna uma referencia (reference) para o primeiro elemento na lista.
    // Se nao existir primeiro elemento, o comportamento dessa funcao eh indeterminado.
    // Complexidade: O(1)
    int& front();

    // versao const da funcao front
    // Retorna uma 'const reference' para o primeiro elemento na lista.
    // Se nao existir primeiro elemento, o comportamento dessa funcao eh indeterminado.
    // Complexidade: O(1)
    const int& front() const;

    // funcao back
    // Retorna uma referencia (reference) para o ultimo elemento na lista.
    // Se nao existir ultimo elemento, o comportamento dessa funcao eh indeterminado.
    // Complexidade: O(1)
    int& back();

    // versao const da funcao back
    // Retorna uma 'const reference' para o ultimo elemento na lista.
    // Se nao existir ultimo elemento, o comportamento dessa funcao eh indeterminado.
    // Complexidade: O(1)
    const int& back() const;

    // funcao remove_all
    // Essa funcao remove todas as ocorrencias do elemento 'elem' da lista
    // Nao esqueca de decrementar o valor do atributo m_size sempre 
    // que um elem for removido da lista
    // Complexidade: O(n) no pior caso
    void remove_all(int elem);

    // funcao insert_at
    // Esta funcao adiciona o elemento 'elem' no indice 'index' (somente se 0 <= index <= m_size). 
    // Se o 'index' estiver fora do intervalo especificado acima, esta funcao lanca uma excecao 
    // do tipo std::out_of_range com a mensagem "indice fora do intervalo".
    // Antes de fazer a insercao, todos os elementos posicionado a partir 
    // do indice k em diante sao deslocados uma posicao para a direita.
    // Cuidado com a alocacao de memoria.
    // Complexidade: O(n) no pior caso
    void insert_at(int elem, unsigned int index);

    // Funcao remove_at
    // Essa funcao remove o elemento posicionado no indice 'index' da lista.
    // O 'index' deve estar dentro do intervalo: 0 <= index <= m_size-1
    // Se o 'index' estiver fora do intervalo especificado acima, esta funcao lanca uma excecao 
    // do tipo std::out_of_range com a mensagem "indice fora do intervalo".
    // Ao remover um elemento, pode ser necessario deslocar elementos para a esquerda.
    // Complexidade: O(n) no pior caso
    void remove_at(unsigned int index);
};


// ----------------------------------------------------------
// Implementacao das funcoes-membro da classe Vector
// ----------------------------------------------------------
Vector::Vector(unsigned int cap) 
    : m_size{0}, m_capacity{cap}
{
    m_vet = new int[m_capacity];
}

Vector::Vector(const Vector& v) {
    m_size = v.m_size;
    m_capacity = v.m_capacity;
    m_vet = new int[m_capacity];
    for(unsigned int i = 0; i < m_size; ++i) {
        m_vet[i] = v.m_vet[i];
    }
}

void Vector::reserve(unsigned int newCap) {
    if(m_capacity < newCap) {
        m_capacity = newCap;
        int *aux = new int[m_capacity];
        for(unsigned int i = 0; i < m_size; ++i) {
            aux[i] = m_vet[i];
        }
        delete[] m_vet;
        m_vet = aux;
    }
}

void Vector::push_back(int val) {
    if(m_size == m_capacity) {  // aumenta de precisar
        reserve(2 * (m_capacity + 1));
    }
    m_vet[m_size] = val; // insere
    m_size++;            // incrementa m_size
}

int& Vector::at(unsigned int i) {
    if(i < m_size) {
        return m_vet[i];
    }
    else {
        throw std::out_of_range("erro no indice");
    }
}

const int& Vector::at(unsigned int i) const {
    if(i < m_size) {
        return m_vet[i];
    }
    else {
        throw std::out_of_range("erro no indice");
    }
}

Vector::~Vector() {
    delete[] m_vet;
}

unsigned int Vector::size() const {
    return m_size;
}

unsigned int Vector::capacity() const {
    return m_capacity;
}

bool Vector::empty() const {
    return m_size == 0;
}

int& Vector::operator[](unsigned int i) {
    return m_vet[i];
}
   
const int& Vector::operator[](unsigned int i) const {
    return m_vet[i];
}

void Vector::pop_back() {
    if(m_size > 0) {
        m_size--;
    }
}

#endif // VECTOR_H
```