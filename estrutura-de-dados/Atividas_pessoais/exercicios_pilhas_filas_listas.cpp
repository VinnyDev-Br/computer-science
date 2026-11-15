// Exercícios - Pilhas, Filas e Listas (QXD0010 - Estrutura de Dados)
// Compilar: g++ -std=c++17 -Wall -Wextra exercicios_pilhas_filas_listas.cpp -o ex
// Executar: ./ex
//
// Resolva cada função no lugar indicado (// TODO).
// O main() no final já chama cada exercício com os exemplos dos slides.
// Lembrete (Ex. 11): dentro da classe Deque NÃO use std::deque, std::list,
// std::vector nem std::queue. Os includes abaixo são para os outros exercícios.

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <stdexcept>
#include <cctype>
#include <vector>

using namespace std;

// ---------------------------------------------------------------------------
// 1) Expressão bem formada (parênteses e colchetes)
//    Use uma pilha: ( e [ empilha; ) desempilha (; ] desempilha [.
//    Retorna true se a sequência for bem-formada (a vazia também é).
// ---------------------------------------------------------------------------
bool ex01_bemFormada(const string& str) {
    stack<char> pilha;

    for (int i = 0; i < (int)str.size(); i++){
        if (str[i] == '['|| str[i] == '('){
            pilha.push(str[i]);
        }
        else if (str[i] == ']' || str[i] == ')') {
            if (pilha.empty()) return false;
            char abre = pilha.top();
            if ((str[i] == ']' && abre != '[') || (str[i] == ')' && abre != '(')) return false;
            pilha.pop();
        }
    }
    
    return pilha.empty();
}

// ---------------------------------------------------------------------------
// 2) Avaliar expressão pós-fixa (notação polonesa reversa)
//    Inteiros e operadores + - * / separados por espaço.
//    Número: empilha. Operador: desempilha DOIS operandos
//    (o primeiro desempilhado é o operando da DIREITA), calcula e empilha.
//    Retorna o valor final.
// ---------------------------------------------------------------------------
int ex02_avaliarPosfixa(const string& str) {
    stack<int> pilha;
    istringstream entrada(str);
    string token;

    while (entrada >> token){
        if (isdigit(token[0])){
            int numero = stoi(token);
            pilha.push(numero);
        }
        else{
            char opc = token[0];
            int aux;
            if (pilha.size() < 2) return 0;

            switch (opc){
                case '*':
                    aux = pilha.top();
                    pilha.pop();
                    pilha.top() *= aux;
                    break;
                case '+':
                    aux = pilha.top();
                    pilha.pop();
                    pilha.top() += aux;
                    break;
                case '-':
                    aux = pilha.top();
                    pilha.pop();
                    pilha.top() -= aux;
                    break;
                case '/':
                    aux = pilha.top();
                    pilha.pop();
                    if (aux == 0) return 0;
                    pilha.top() /= aux;
                    break;
                default:
                    break;
            }
        }
    }
    
    if (pilha.empty()) return 0;
    return pilha.top();
}

// ---------------------------------------------------------------------------
// 3) Inversão de palavras
//    Inverte as letras de cada palavra, preservando a ordem das palavras.
//    Palavras separadas por espaço.
//    "AMU MEGASNEM ATERCES" -> "UMA MENSAGEM SECRETA"
// ---------------------------------------------------------------------------
string ex03_inverterPalavras(const string& sentenca) {
    stack<char> pilha;
    istringstream entrada(sentenca);
    string token;
    string r;
    
    while (entrada >> token){

        if (!r.empty()) r += ' ';
        
        for (char c : token){
            pilha.push(c);
        }

        while (!pilha.empty()){
            r+= pilha.top();
            pilha.pop();
        }

    }   

    return r;
}

// ---------------------------------------------------------------------------
// 4) Verificar se a string tem a forma str1 C str2
//    str1 só tem os caracteres 'A' e 'B'; str2 é o reverso de str1.
//    "ABABBACABBABA" -> true
//    "ABABBACABB", "ABA", "BBBBCAA", "ABBACBAABBBBAB" -> false
// ---------------------------------------------------------------------------
bool str1Cstr2(const string& str) {
    stack<char> pilha;
    bool viuC = false;
    for (char c : str){
        if (c != 'A' && c != 'B' && c != 'C'){
            return false; // Só aceita A, B ou C
        }
        else if (c == 'C'){ 
            if (viuC) return false;
            viuC = true;
        }
        else if (!viuC){
            pilha.push(c);
        }
        else{
            if (pilha.empty() || pilha.top() != c) return false;
            pilha.pop();
        }
    }
    return pilha.empty();
}

// ---------------------------------------------------------------------------
// 5) Pilha usando EXATAMENTE DUAS filas (números inteiros)
//    Só filas podem ser usadas como estrutura de dados.
//    Operações obrigatórias: construtor, destrutor, push e pop.
// ---------------------------------------------------------------------------
class PilhaComDuasFilas {
private:
    queue<int> fila1;
    queue<int> fila2;

public:
    PilhaComDuasFilas() {}

    ~PilhaComDuasFilas() {
        while (!fila1.empty()) {  fila1.pop(); }
        while (!fila2.empty()) {  fila2.pop(); }
    }

    void push(int x) {
        fila1.push(x);
    }

    int pop() {
        if (fila1.empty()){
            throw runtime_error("pilha vazia");
        }
        while (fila1.size() != 1){
            fila2.push(fila1.front());
            fila1.pop();
        }

        int valor = fila1.front();
        fila1.pop();
        
        swap(fila1, fila2);

        return valor;
    }
};

// ---------------------------------------------------------------------------
// 6) Problema de Josephus
//    n pessoas (1..n) em círculo; conta-se de 1 a k e a k-ésima é eliminada;
//    a contagem recomeça na seguinte. Imprima a ordem de eliminação (em uma
//    linha, separada por espaço) e, na linha seguinte, o sobrevivente.
//    n=5, k=2  ->  "2 4 1 5" e "3"
// ---------------------------------------------------------------------------
void ex06_josephus(int n, int k) {
    queue<int> fila;

    for (int i = 1; i <= n; ++i){
        fila.push(i);
    }

    while (!fila.empty()){
        for (int i = 1; i <  k; i++){
            int valor = fila.front();
            fila.pop();
            fila.push(valor);
        }   

        cout << fila.front() << " ";
        fila.pop();
    }

    cout << endl; 

}

// ---------------------------------------------------------------------------
// 7) Fila de atendimento com senhas
//    Lê comandos (um por linha) até o fim da entrada:
//      CHEGOU  -> novo cliente pega a próxima senha (começa em 1)
//      ATENDER -> imprime a senha atendida (ou "Fila vazia")
//      TAMANHO -> imprime quantos clientes aguardam
// ---------------------------------------------------------------------------
void ex07_filaDeSenhas(istream& in) {
    // TODO
}

// ---------------------------------------------------------------------------
// 8) Primeiro caractere não repetido em um fluxo
//    Letras minúsculas chegam uma de cada vez. Após cada chegada, imprima o
//    primeiro caractere não repetido visto até o momento, ou '#' se não houver.
//    Sem percorrer a string inteira a cada chegada
//    (dica: fila de candidatos + vetor de contagem com 26 posições).
//    "aabc"  -> "a#bb"
//    "abacb" -> "aabbc"
// ---------------------------------------------------------------------------
void ex08_primeiroNaoRepetido(const string& fluxo) {
    // TODO
}

// ---------------------------------------------------------------------------
// 9) Remover todas as ocorrências de um valor de uma list<int>
//    Sem usar remove nem remove_if. Percorra com iterador e use erase.
//    Lembre: it = l.erase(it) e, nesse caso, não incrementar.
//    x = 1: {3 1 4 1 5 9 2 6 1} -> {3 4 5 9 2 6}
// ---------------------------------------------------------------------------
void removerTodos(list<int>& l, int x) {
    // TODO
}

// ---------------------------------------------------------------------------
// 10) Editor de texto com cursor
//    Começa vazio, cursor no final. O cursor fica ENTRE dois caracteres.
//    Comandos (um por linha) até o fim da entrada:
//      I c -> insere o caractere c à esquerda do cursor
//      E   -> move o cursor para a esquerda (se possível)
//      D   -> move o cursor para a direita (se possível)
//      B   -> apaga o caractere à esquerda do cursor (se existir)
//    Ao final, imprime o texto.
// ---------------------------------------------------------------------------
void ex10_editorComCursor(istream& in) {
    // TODO
}

// ---------------------------------------------------------------------------
// 11) Deque (fila dupla) de inteiros com lista duplamente encadeada
//    - Alocação dinâmica própria (new/delete).
//    - NÃO usar std::deque, std::list, std::vector nem std::queue aqui.
//    - Todas as operações em O(1); destrutor sem vazamento de memória.
//    - Dica: nó sentinela circular elimina os casos especiais de lista
//      vazia e de lista com um único elemento.
// ---------------------------------------------------------------------------
class Deque {
private:
    struct No {
        int valor;
        No* anterior;
        No* proximo;
    };

    // TODO: atributos (sentinela, tamanho...)

public:
    Deque() {
        // TODO
    }

    ~Deque() {
        // TODO
    }

    void pushFront(int x) {
        // TODO
    }

    void pushBack(int x) {
        // TODO
    }

    void popFront() {
        // TODO
    }

    void popBack() {
        // TODO
    }

    int front() const {
        // TODO
        return 0;
    }

    int back() const {
        // TODO
        return 0;
    }

    int size() const {
        // TODO
        return 0;
    }

    bool empty() const {
        // TODO
        return true;
    }
};

// 11) main do deque: lê comandos (um por linha) e executa.
//     PUSH_FRONT x, PUSH_BACK x, POP_FRONT, POP_BACK, FRONT, BACK, SIZE.
//     POP_FRONT, POP_BACK, FRONT e BACK imprimem o valor (ou "Deque vazio");
//     SIZE imprime o tamanho.
void ex11_executarComandos(istream& in) {
    // TODO
}

// 11) Desafio extra: palíndromo usando o deque
//     Compare front() com back() e remova as duas pontas a cada passo.
bool ex11_palindromoComDeque(const string& palavra) {
    // TODO
    return false;
}

// ===========================================================================
// MAIN: testes com os exemplos dos slides (a saída esperada está nos comentários)
// ===========================================================================
int main() {
    cout << "--- Ex 1 (esperado: 1 1 0 0 0) ---\n";
    cout << ex01_bemFormada("[[]]") << " "
         << ex01_bemFormada("([()([])])") << " "
         << ex01_bemFormada("([]") << " "
         << ex01_bemFormada("[[))") << " "
         << ex01_bemFormada("([)]") << "\n";

    cout << "--- Ex 2 (esperado: 14 14) ---\n";
    cout << ex02_avaliarPosfixa("3 4 + 2 *") << "\n";
    cout << ex02_avaliarPosfixa("5 1 2 + 4 * + 3 -") << "\n";

    cout << "--- Ex 3 (esperado: UMA MENSAGEM SECRETA) ---\n";
    cout << ex03_inverterPalavras("AMU MEGASNEM ATERCES") << "\n";

    cout << "--- Ex 4 (esperado: 1 0 0 0 0) ---\n";
    string t1 = "ABABBACABBABA", t2 = "ABABBACABB", t3 = "ABA",
           t4 = "BBBBCAA", t5 = "ABBACBAABBBBAB";
    cout << str1Cstr2(t1) << " " << str1Cstr2(t2) << " " << str1Cstr2(t3) << " "
         << str1Cstr2(t4) << " " << str1Cstr2(t5) << "\n";

    cout << "--- Ex 5 (esperado: 3 2 1) ---\n";
    {
        PilhaComDuasFilas p;
        p.push(1);
        p.push(2);
        p.push(3);
        cout << p.pop() << " " << p.pop() << " " << p.pop() << "\n";
    }

    cout << "--- Ex 6 (esperado: 2 4 1 5 / 3) ---\n";
    ex06_josephus(5, 2);

    cout << "--- Ex 7 (esperado: 1 / 2 / 2 / 3 / Fila vazia) ---\n";
    {
        istringstream in("CHEGOU\nCHEGOU\nATENDER\nCHEGOU\nTAMANHO\n"
                         "ATENDER\nATENDER\nATENDER\n");
        ex07_filaDeSenhas(in);
    }

    cout << "--- Ex 8 (esperado: a#bb / aabbc) ---\n";
    ex08_primeiroNaoRepetido("aabc");
    cout << "\n";
    ex08_primeiroNaoRepetido("abacb");
    cout << "\n";

    cout << "--- Ex 9 (esperado: 3 4 5 9 2 6) ---\n";
    {
        list<int> l = {3, 1, 4, 1, 5, 9, 2, 6, 1};
        removerTodos(l, 1);
        for (auto it = l.begin(); it != l.end(); ++it) cout << *it << " ";
        cout << "\n";
    }

    cout << "--- Ex 10 (esperado: axbc) ---\n";
    {
        istringstream in("I a\nI b\nI c\nE\nE\nI x\nD\nI y\nB\n");
        ex10_editorComCursor(in);
    }

    cout << "--- Ex 11 (esperado: 3 / 2 / 3 / 2 / 2 / 1 / Deque vazio) ---\n";
    {
        istringstream in("PUSH_BACK 1\nPUSH_BACK 2\nPUSH_FRONT 3\nFRONT\nBACK\n"
                         "POP_FRONT\nSIZE\nPOP_BACK\nPOP_BACK\nPOP_BACK\n");
        ex11_executarComandos(in);
    }
    cout << "Palindromo (esperado: 1 0): "
         << ex11_palindromoComDeque("arara") << " "
         << ex11_palindromoComDeque("casa") << "\n";

    return 0;
}
