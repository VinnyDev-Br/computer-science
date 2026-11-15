// Exercícios de iteradores em C++
// Compilar: g++ -std=c++17 -Wall -Wextra exercicios_iteradores.cpp -o exercicios
// Executar: ./exercicios
//
// Como usar: implemente o corpo de cada função onde está "TODO".
// Use auto nos iteradores. Descomente a chamada no main() ao terminar.

#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;

// ============================================================
// NÍVEL 1: Básico
// ============================================================

// 1) Imprimir o vector do início ao fim com begin()/end()
void ex01_imprimir(const vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it){
        cout << *it << " ";
    }
}

// 2) Imprimir ao contrário com rbegin()/rend()
void ex02_imprimir_reverso(const vector<int>& v) {
    for (auto it = v.rbegin(); it != v.rend(); ++it){
        cout << *it << " ";
    }
}

// 3) Somar todos os elementos usando iterador (sem for por intervalo)
int ex03_soma(const vector<int>& v) {
    int soma = 0;

    for (auto it = v.begin(); it != v.end(); ++it){
        soma += *it;
    }

    return soma;
}

// 4) Achar o maior e o menor valor (assuma v não vazio)
void ex04_maior_menor(const vector<int>& v, int& maior, int& menor) {
    maior = menor = *v.begin();
    for (auto it = v.begin(); it != v.end(); ++it){
        if (*it > maior){
            maior = *it;
        }

        if (*it < menor){
            menor = *it;
        }
    }
}

// 5) Dobrar cada elemento modificando via *it
void ex05_dobrar(vector<int>& v) {
    for (auto it = v.begin(); it != v.end(); ++it){
        *it *= 2;
    }
}

// ============================================================
// NÍVEL 2: Intermediário
// ============================================================

// 6) Contar quantos números pares existem
int ex06_contar_pares(const vector<int>& v) {
    int contador = 0;
    for (auto it = v.begin(); it != v.end(); ++it){
        if (*it % 2 == 0){
            ++contador;
        }
    }
    return contador;
}

// 7) Retornar a posição (índice) de um valor, ou -1 se não existir.
//    Dica: std::find + std::distance
int ex07_posicao(const vector<int>& v, int valor) {

    auto it1 = v.begin();

    for (; it1 != v.end(); ++it1){
        if (*it1 == valor){
            break;
        }
    }

    if (it1 == v.end()){
        return -1;
    }

    return distance(v.begin(), it1);
}
// 8) Remover todos os negativos com erase dentro do laço
//    Lembre: it = v.erase(it) e não incrementar nesse caso
void ex08_remover_negativos(vector<int>& v) {
    for (auto it = v.begin(); it != v.end()){
        if (*it < 0){
            it = v.erase(it);
        }
        else{
            ++it;
        }
    }
}

// 9) Inserir um valor no meio do vector com insert
void ex09_inserir_meio(vector<int>& v, int valor) {
    
}

// 10) Verificar palíndromo com dois iteradores (um no início, outro no fim)
bool ex10_palindromo(const string& s) {
    if (s.empty()) return true;

    auto fim = s.end() - 1;
    auto inicio = s.begin();

    while (inicio <= fim){
        if (*inicio != *fim){
            return false;
        }
        ++inicio;
        --fim;
    }   
    return true;
}

// ============================================================
// NÍVEL 3: Outros contêineres
// ============================================================

// 11) Imprimir um map<string,int> no formato "nome: nota"
void ex11_imprimir_map(const map<string, int>& notas) {
    // TODO: it->first e it->second
}

// 12) Calcular a média das notas do map (0 se vazio)
double ex12_media(const map<string, int>& notas) {
    // TODO
    return 0.0;
}

// 13) Remover duplicados usando set e devolver um vector ordenado
vector<int> ex13_sem_duplicados(const vector<int>& v) {
    // TODO
    return {};
}

// 14) Inverter uma list sem std::reverse (dois iteradores trocando valores)
//     Dica: list não tem it + n; use std::prev(), ++ e --
void ex14_inverter_list(list<int>& l) {
    // TODO
}

// ============================================================
// NÍVEL 4: Com a STL
// ============================================================

// 15) Ordenar tudo e, em outro vector, ordenar só os 3 primeiros
void ex15_ordenar(vector<int>& v) {
    // TODO: std::sort(v.begin(), v.end());
}

// 16) Retornar o primeiro número maior que 50, ou -1 se não houver
//     Dica: std::find_if com lambda
int ex16_primeiro_maior_50(const vector<int>& v) {
    // TODO
    return -1;
}

// 17) Somar com std::accumulate e contar os maiores que 10 com std::count_if
void ex17_stl(const vector<int>& v, int& soma, int& maiores_que_10) {
    // TODO
}

// 18) Função template que imprime qualquer contêiner (vector, list, set)
template <typename It>
void ex18_imprimir(It inicio, It fim) {
    // TODO
}

// ============================================================
// NÍVEL 5: Desafio (sem copiar código pronto)
// ============================================================

// 19) Crie sua própria lista encadeada com iterador (begin/end, *, ++, ==, !=)
//     e faça funcionar com for por intervalo e std::find.
// template <typename T>
// class MinhaLista { ... };

// 20) Transforme em lista duplamente encadeada e adicione operator--

// ============================================================
// MAIN: descomente os testes conforme for terminando
// ============================================================
int main() {
    vector<int> v = {10, -5, 20, 7, 30, -2, 40, 55, 8};
    map<string, int> notas = {{"Ana", 9}, {"Beto", 7}, {"Carla", 8}};
    list<int> lst = {1, 2, 3, 4, 5};

    // --- Nível 1 ---
    // ex01_imprimir(v);                 // esperado: 10 -5 20 7 30 -2 40 55 8
    // ex02_imprimir_reverso(v);         // esperado: 8 55 40 -2 30 7 20 -5 10
    // cout << ex03_soma(v) << "\n";     // esperado: 163
    // int maior, menor;
    // ex04_maior_menor(v, maior, menor);
    // cout << maior << " " << menor << "\n";   // esperado: 55 -5
    // ex05_dobrar(v);  ex01_imprimir(v);

    // --- Nível 2 ---
    // cout << ex06_contar_pares(v) << "\n";
    // cout << ex07_posicao(v, 30) << "\n";     // esperado: 4
    // ex08_remover_negativos(v);  ex01_imprimir(v);
    // ex09_inserir_meio(v, 99);   ex01_imprimir(v);
    // cout << ex10_palindromo("arara") << ex10_palindromo("casa") << "\n";  // esperado: 10

    // --- Nível 3 ---
    // ex11_imprimir_map(notas);
    // cout << ex12_media(notas) << "\n";        // esperado: 8
    // auto sem_dup = ex13_sem_duplicados({3, 1, 3, 2, 1});
    // ex18_imprimir(sem_dup.begin(), sem_dup.end());   // esperado: 1 2 3
    // ex14_inverter_list(lst);
    // ex18_imprimir(lst.begin(), lst.end());           // esperado: 5 4 3 2 1

    // --- Nível 4 ---
    // ex15_ordenar(v);  ex01_imprimir(v);
    // cout << ex16_primeiro_maior_50(v) << "\n";
    // int soma, qtd;
    // ex17_stl(v, soma, qtd);
    // cout << soma << " " << qtd << "\n";

    (void)v; (void)notas; (void)lst;  // remove avisos enquanto tudo está comentado
    return 0;
}
