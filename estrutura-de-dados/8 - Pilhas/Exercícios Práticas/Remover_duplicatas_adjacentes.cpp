#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
Remove pares adjacentes iguais usando pilha.

Dada uma string, remove repetidamente pares de caracteres iguais e
adjacentes até que não seja mais possível. Imprime a string resultante.

Entrada
abbaca

Saída
ca

Explicação: remove-se "bb", obtendo "aaca"; depois "aa", obtendo "ca".

Ideia: percorre a string e compara cada caractere com o topo da pilha.
  - Se for igual ao topo, forma um par adjacente: desempilha (remove o par).
  - Se for diferente (ou a pilha estiver vazia), empilha.
Ao final, a pilha guarda o resultado, mas de trás para frente.
*/

int main() {
    stack<char> s;
    string palavra;

    getline(cin, palavra);

    for (char c : palavra) {
        // Checa s.empty() primeiro: chamar top() em pilha vazia é indefinido
        if (s.empty() || c != s.top()) {
            s.push(c);  // não forma par: guarda o caractere
        } else {
            s.pop();    // forma par com o topo: remove os dois
        }
    }

    // A pilha entrega os caracteres do último para o primeiro.
    // Passar tudo para uma pilha auxiliar inverte a ordem.
    stack<char> aux;
    while (!s.empty()) {
        aux.push(s.top());
        s.pop();
    }

    // Agora o topo de aux é o primeiro caractere do resultado
    string resultado;
    while (!aux.empty()) {
        resultado += aux.top();
        aux.pop();
    }

    cout << resultado << "\n";
    return 0;
}