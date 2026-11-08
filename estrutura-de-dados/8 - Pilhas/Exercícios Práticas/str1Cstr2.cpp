#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
Verifica se a string tem o formato str1 C str2, em que:
  - str1 é composta apenas por 'A' e 'B';
  - 'C' aparece uma única vez, separando as duas partes;
  - str2 é o inverso de str1.

Exemplos:
  ABABBACABBABA   -> true  (str1 = ABABBA, str2 = ABBABA)
  ABABBACABB      -> false (str2 é menor que o inverso de str1)
  ABA             -> false (não tem 'C')
  BBBBCAA         -> false (o inverso de BBBB não é AA)
  ABBACBAABBBBAB  -> false (str2 diferente do inverso de str1)

Ideia: a pilha guarda str1. O topo dela é o último caractere de str1,
que precisa ser igual ao primeiro caractere de str2, e assim por diante.
Cada caractere que casa com o topo é desempilhado. Se tudo casar e a
pilha ficar vazia no final, a string tem o formato correto.
*/
bool str1Cstr2(string str) {
    stack<char> s;

    for (size_t i = 0; i < str.size(); i++) {
        // Qualquer caractere que não seja A, B ou C invalida a string
        if (str[i] != 'A' && str[i] != 'B' && str[i] != 'C') {
            return false;
        }

        if (str[i] == 'C') {
            // Fase 2: o que vem depois do 'C' (str2) precisa ser o inverso de str1.
            // Compara cada caractere com o topo da pilha.
            for (size_t k = i + 1; k < str.size(); k++) {
                if (!s.empty() && str[k] == s.top()) {
                    s.pop();  // casou: remove o caractere de str1 já conferido
                } else {
                    // Não casou, ou a pilha acabou (str2 maior que str1).
                    // Também cai aqui se aparecer outro 'C', que nunca é igual ao topo.
                    return false;
                }
            }

            // Se a pilha esvaziou, str2 tem o mesmo tamanho de str1 e é o inverso dela.
            // Se sobrou algo, str2 é menor que str1.
            return s.empty();
        } else {
            // Fase 1: ainda estamos em str1, então guarda o caractere na pilha
            s.push(str[i]);
        }
    }

    // Chegou ao fim sem encontrar o 'C'
    return false;
}
