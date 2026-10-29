// Aluno: Vinicius Macedo Freitas
// Matrícula: 585767
// Turma: ED 01A

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "List.h"
using namespace std;

// Programa principal: interage com o usuário pelo terminal por meio de
// comandos e permite testar todas as operações da classe List.
// Mantém um vector de listas; cada comando indica a lista pelo seu índice
// (a primeira lista criada tem índice 0, a segunda 1, e assim por diante).
//
// Comandos disponíveis:
//   create                  cria uma nova lista vazia
//   size l                  mostra o tamanho da lista l
//   empty l                 mostra se a lista l está vazia
//   push_back l a1 ... an   insere os valores no final da lista l
//   pop_back l              remove e mostra o último elemento de l
//   insertAfter l k v       insere v após o k-ésimo nó de l (k de 1 a size)
//   remove l v              remove a primeira ocorrência de v em l
//   removeAll l v           remove todas as ocorrências de v em l
//   print l                 imprime a lista l
//   printReverse l          imprime a lista l em ordem reversa
//   clear l                 remove todos os elementos de l
//   concat l1 l2            concatena l2 ao final de l1 (l2 fica vazia)
//   assign l1 l2            l1 passa a ser uma cópia de l2
//   equal l1 l2             mostra se l1 == l2
//   notequal l1 l2          mostra se l1 != l2
//   show                    imprime todas as listas
//   exit                    encerra o programa

// Verifica se o índice informado corresponde a uma lista existente
bool indiceValido(const vector<List>& listas, int l) {
    return l >= 0 && l < (int)listas.size();
}

int main() {
    vector<List> listas; 

    while (true) {
        string comando, token;
        if (!getline(cin, comando)) {
            break; // fim da entrada
        }
        stringstream ss{comando};
        ss >> token;

        // Mostra o comando lido, no mesmo estilo das atividades do Moodle
        cout << "$" << ss.str() << endl;

        // exit
        if (token == "exit") {
            break;
        }
        // create
        else if (token == "create") {
            listas.push_back(List());
        }
        // show
        else if (token == "show") {
            for (unsigned i = 0; i < listas.size(); ++i) {
                cout << "lista " << i << ": [ ";
                listas[i].print();
                cout << "]" << endl;
            }
        }
        // concat l1 l2 / assign l1 l2 / equal l1 l2 / notequal l1 l2
        // (comandos que recebem duas listas)
        else if (token == "concat" || token == "assign" ||
                 token == "equal" || token == "notequal") {
            int l1, l2;
            ss >> l1 >> l2;
            if (!indiceValido(listas, l1) || !indiceValido(listas, l2)) {
                cout << "lista inexistente" << endl;
            }
            else if (token == "concat") {
                listas[l1].concat(listas[l2]);
            }
            else if (token == "assign") {
                listas[l1] = listas[l2];
            }
            else if (token == "equal") {
                cout << (listas[l1] == listas[l2] ? "true" : "false") << endl;
            }
            else {
                cout << (listas[l1] != listas[l2] ? "true" : "false") << endl;
            }
        }
        // comandos que recebem o índice de uma lista (e talvez mais valores)
        else if (token == "size" || token == "empty" || token == "push_back" ||
                 token == "pop_back" || token == "insertAfter" ||
                 token == "remove" || token == "removeAll" ||
                 token == "print" || token == "printReverse" || token == "clear") {
            int l;
            ss >> l;
            if (!indiceValido(listas, l)) {
                cout << "lista inexistente" << endl;
                continue;
            }

            if (token == "size") {
                cout << "size list " << l << ": " << listas[l].size() << endl;
            }
            else if (token == "empty") {
                cout << (listas[l].empty() ? "true" : "false") << endl;
            }
            else if (token == "push_back") {
                int valor;
                while (ss >> valor) {
                    listas[l].push_back(valor);
                }
            }
            else if (token == "pop_back") {
                // pop_back lança exceção se a lista estiver vazia
                try {
                    cout << listas[l].pop_back() << endl;
                } catch (const out_of_range& e) {
                    cout << "erro: " << e.what() << endl;
                }
            }
            else if (token == "insertAfter") {
                int k, v;
                ss >> k >> v;
                // insertAfter lança exceção se k for inválido
                try {
                    listas[l].insertAfter(v, k);
                } catch (const out_of_range& e) {
                    cout << "erro: " << e.what() << endl;
                }
            }
            else if (token == "remove") {
                int v;
                ss >> v;
                listas[l].remove(v);
            }
            else if (token == "removeAll") {
                int v;
                ss >> v;
                listas[l].removeAll(v);
            }
            else if (token == "print") {
                cout << "[ ";
                listas[l].print();
                cout << "]" << endl;
            }
            else if (token == "printReverse") {
                cout << "[ ";
                listas[l].printReverse();
                cout << "]" << endl;
            }
            else if (token == "clear") {
                listas[l].clear();
            }
        }
        else {
            cout << "comando inexistente" << endl;
        }
    }
    return 0;
}