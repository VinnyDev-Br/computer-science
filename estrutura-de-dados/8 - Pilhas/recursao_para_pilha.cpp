// =====================================================================
//  RECURSÃO -> PILHA: 22 EXERCÍCIOS DO BÁSICO AO AVANÇADO
// =====================================================================
//
//  COMO ESTE ARQUIVO FUNCIONA
//  --------------------------
//  Para cada exercício existem duas funções:
//     xxxRec    : versão RECURSIVA, já pronta (referência, não mexa).
//     xxxPilha  : versão com PILHA, com "// TODO". É a que você escreve.
//
//  O main roda testes automáticos e imprime [OK] ou [FALHOU] para cada
//  exercício. No começo tudo aparece FALHOU, porque as funções "Pilha"
//  retornam um valor provisório (só para o arquivo compilar). Apague o
//  "return" provisório quando implementar.
//
//  Para compilar:   g++ -std=c++17 -Wall -o rec_pilha recursao_para_pilha.cpp
//
//  A TÉCNICA GERAL
//  ---------------
//  Quando uma função recursiva se chama, o computador guarda numa pilha
//  (a pilha de chamadas) os parâmetros e o ponto onde a função parou.
//  Converter para pilha é fazer isso "na mão":
//
//     1. Crie uma struct "Frame" com os PARÂMETROS da função.
//     2. Se a função faz algo DEPOIS da chamada recursiva, o frame também
//        precisa guardar em que ETAPA parou (e resultados parciais).
//     3. Empilhe o frame inicial e repita:
//            while (!pilha.empty()) { pegue o topo; execute uma etapa; }
//     4. Uma "chamada recursiva" vira "empilhar um frame novo".
//        Um "return" vira "desempilhar".
//
//  Regra de ouro da ORDEM: a pilha é LIFO. O que você quer que seja
//  executado PRIMEIRO deve ser empilhado POR ÚLTIMO.
//
//  Como estudar cada exercício:
//     (a) leia a versão recursiva e entenda o que ela faz;
//     (b) desenhe a pilha com um exemplo pequeno;
//     (c) escreva a versão com pilha;
//     (d) rode e confira o [OK].
// =====================================================================

#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <cstdlib>
using namespace std;

// ---------------------------------------------------------------------
//  Utilitários de teste
// ---------------------------------------------------------------------
int acertos = 0, total = 0;

void conferir(const string& nome, bool ok) {
    total++;
    if (ok) acertos++;
    cout << (ok ? "[OK]     " : "[FALHOU] ") << nome << endl;
}

template <typename T>
vector<T> ordenado(vector<T> v) {
    sort(v.begin(), v.end());
    return v;
}

// ---------------------------------------------------------------------
//  Estruturas compartilhadas
// ---------------------------------------------------------------------

// Lista simplesmente encadeada (exercício 4)
struct No {
    int valor;
    No* proximo;
    No(int v, No* p = nullptr) : valor(v), proximo(p) {}
};

void inserirFim(No*& head, int x) {
    No* novo = new No(x);
    if (head == nullptr) { head = novo; return; }
    No* a = head;
    while (a->proximo != nullptr) a = a->proximo;
    a->proximo = novo;
}

vector<int> paraVetor(No* head) {
    vector<int> v;
    for (No* p = head; p != nullptr; p = p->proximo) v.push_back(p->valor);
    return v;
}

void liberar(No* head) {
    while (head != nullptr) {
        No* prox = head->proximo;
        delete head;
        head = prox;
    }
}

// Árvore binária (exercícios 5, 6, 10, 11)
struct NoA {
    int valor;
    NoA* esq;
    NoA* dir;
    NoA(int v) : valor(v), esq(nullptr), dir(nullptr) {}
};

void liberarArvore(NoA* r) {
    if (r == nullptr) return;
    liberarArvore(r->esq);
    liberarArvore(r->dir);
    delete r;
}

// Posição em matriz (exercícios 7, 8, 15)
struct Pos {
    int l;
    int c;
};

// esquerda, cima, direita, baixo (sem checar limites)
vector<Pos> get_vizinhos(Pos p) {
    return {{p.l, p.c - 1}, {p.l - 1, p.c}, {p.l, p.c + 1}, {p.l + 1, p.c}};
}

bool dentro(const vector<string>& m, Pos p) {
    return p.l >= 0 && p.l < (int)m.size() && p.c >= 0 && p.c < (int)m[p.l].size();
}

// =====================================================================
//  NÍVEL 1 — AQUECIMENTO (só entender o mecanismo)
// =====================================================================

// ---------------------------------------------------------------------
//  1. SOMA DE 1 A n
//  Recursiva: soma(n) = n + soma(n-1), com soma(0) = 0.
//  Com pilha: empilhe n, n-1, ..., 1 (a "descida" da recursão) e depois
//  desempilhe somando (a "volta"). Na prática um laço simples bastaria,
//  mas o objetivo é sentir a pilha fazendo o papel da recursão.
// ---------------------------------------------------------------------
int somaRec(int n) {
    if (n == 0) return 0;
    return n + somaRec(n - 1);
}

int somaPilha(int n) {
    stack<int> pilha;
    int soma = 0;
    while(n > 0){
        pilha.push(n);
        n--;
    }

    while (!pilha.empty()){
        soma += pilha.top();
        pilha.pop();
    }
    
    return soma;    
    
}

// ---------------------------------------------------------------------
//  2. FATORIAL
//  Recursiva: fat(n) = n * fat(n-1), com fat(0) = 1.
//  A multiplicação acontece na VOLTA da recursão: primeiro desce
//  empilhando n, n-1, ..., 2, depois desempilha multiplicando.
// ---------------------------------------------------------------------
long long fatRec(int n) {
    if (n <= 1) return 1;
    return n * fatRec(n - 1);
}

long long fatPilha(int n) {
    // TODO
    return -1;
}

// ---------------------------------------------------------------------
//  3. DÍGITOS NA ORDEM CERTA
//  Extrair dígitos com n % 10 dá a ordem INVERSA (1234 -> 4, 3, 2, 1).
//  A recursiva resolve guardando o registro DEPOIS da chamada.
//  Com pilha: empilhe os dígitos conforme extrai (n % 10, n /= 10) e
//  depois desempilhe para registrar na ordem certa.
//  Retorna os dígitos em ordem: 1234 -> {1, 2, 3, 4}.  Caso 0 -> {0}.
// ---------------------------------------------------------------------
void digitosRec(int n, vector<int>& out) {
    if (n >= 10) digitosRec(n / 10, out);
    out.push_back(n % 10);
}

vector<int> digitosPilha(int n) {
    // TODO
    return {};
}

// ---------------------------------------------------------------------
//  4. INVERTER LISTA COM PILHA
//  No exercício 5a de listas você usou três ponteiros. Agora use uma
//  pilha: empilhe todos os nós; o topo é o último nó (novo head). Depois
//  vá desempilhando e religando: cada nó desempilhado vira o "proximo"
//  do anterior. Não esqueça de colocar nullptr no último.
//  Retorna o novo head.
// ---------------------------------------------------------------------
No* inverterRec(No* head) {
    if (head == nullptr || head->proximo == nullptr) return head;
    No* novoHead = inverterRec(head->proximo);
    head->proximo->proximo = head;
    head->proximo = nullptr;
    return novoHead;
}

No* inverterPilha(No* head) {
    // TODO
    return head;
}

// =====================================================================
//  NÍVEL 2 — UMA CHAMADA RECURSIVA, POUCO ESTADO
// =====================================================================

// ---------------------------------------------------------------------
//  5. PRÉ-ORDEM DE ÁRVORE BINÁRIA  (raiz, esquerda, direita)
//  Com pilha: empilhe a raiz. Enquanto a pilha não estiver vazia:
//  desempilhe, visite (registre o valor) e empilhe os filhos.
//  ATENÇÃO À ORDEM: para a ESQUERDA ser visitada primeiro, ela deve ser
//  empilhada por ÚLTIMO (ou seja, empilhe a direita antes da esquerda).
//  Lembre de não empilhar nullptr.
// ---------------------------------------------------------------------
void preRec(NoA* r, vector<int>& out) {
    if (r == nullptr) return;
    out.push_back(r->valor);
    preRec(r->esq, out);
    preRec(r->dir, out);
}

vector<int> prePilha(NoA* raiz) {
    // TODO
    return {};
}

// ---------------------------------------------------------------------
//  6. ALTURA DA ÁRVORE
//  Altura = número de nós do maior caminho da raiz até uma folha.
//  Árvore vazia = 0. Árvore com só a raiz = 1.
//  Com pilha: empilhe pares (nó, profundidade). A raiz tem profundidade
//  1. Ao desempilhar, atualize a maior profundidade vista e empilhe os
//  filhos com profundidade + 1.
// ---------------------------------------------------------------------
int alturaRec(NoA* r) {
    if (r == nullptr) return 0;
    return 1 + max(alturaRec(r->esq), alturaRec(r->dir));
}

int alturaPilha(NoA* raiz) {
    // TODO
    return -1;
}

// ---------------------------------------------------------------------
//  7. FLOOD FILL (BALDE DE TINTA)
//  Dada uma matriz de caracteres e uma posição (l, c), troque o
//  caractere dessa posição e de todas as posições CONECTADAS a ela
//  (cima, baixo, esquerda, direita) que tenham o mesmo caractere
//  original, pelo caractere "nova".
//  Com pilha: é quase o labirinto. Empilhe a posição inicial; ao
//  desempilhar, pinte e empilhe os vizinhos que ainda têm a cor antiga.
//  CUIDADO: se a cor antiga for igual à nova, retorne direto (senão fica
//  em loop infinito).
// ---------------------------------------------------------------------
void floodRecAux(vector<string>& m, int l, int c, char antiga, char nova) {
    if (!dentro(m, Pos{l, c})) return;
    if (m[l][c] != antiga) return;
    m[l][c] = nova;
    floodRecAux(m, l - 1, c, antiga, nova);
    floodRecAux(m, l + 1, c, antiga, nova);
    floodRecAux(m, l, c - 1, antiga, nova);
    floodRecAux(m, l, c + 1, antiga, nova);
}

void floodFillRec(vector<string>& m, int l, int c, char nova) {
    char antiga = m[l][c];
    if (antiga == nova) return;
    floodRecAux(m, l, c, antiga, nova);
}

void floodFillPilha(vector<string>& m, int l, int c, char nova) {
    // TODO
}

// ---------------------------------------------------------------------
//  8. CONTAR ILHAS
//  Matriz de '0' e '1'. Uma ilha é um grupo de '1' conectados por cima,
//  baixo, esquerda ou direita. Conte quantas ilhas existem.
//  Ideia: percorra a matriz; ao achar um '1', some 1 ao contador e
//  "apague" a ilha inteira (troque por '0') com o flood fill do
//  exercício 7, para não contar a mesma ilha duas vezes.
//  (Recebe a matriz por CÓPIA, então pode modificar à vontade.)
// ---------------------------------------------------------------------
int contarIlhasRec(vector<string> m) {
    int cont = 0;
    for (int l = 0; l < (int)m.size(); l++)
        for (int c = 0; c < (int)m[l].size(); c++)
            if (m[l][c] == '1') {
                cont++;
                floodFillRec(m, l, c, '0');
            }
    return cont;
}

int contarIlhasPilha(vector<string> m) {
    // TODO
    return -1;
}

// ---------------------------------------------------------------------
//  9. TORRE DE HANOI
//  Mova n discos da haste "o" (origem) para a haste "d" (destino) usando
//  "a" (auxiliar). Regra: nunca um disco maior sobre um menor.
//  Recursiva:  hanoi(n, o, d, a):
//        hanoi(n-1, o, a, d)     // move n-1 discos para a auxiliar
//        move o disco n: o -> d
//        hanoi(n-1, a, d, o)     // move n-1 discos para o destino
//  Retorna os movimentos como strings: "A->C", "A->B", ...
//
//  Com pilha: cada frame é uma TAREFA, que pode ser "resolver hanoi de
//  n discos" ou "registrar um movimento". Ao desempilhar uma tarefa
//  "resolver" com n > 0, empilhe as 3 tarefas em ORDEM INVERSA da
//  execução:  primeiro a última (hanoi n-1, a->d), depois o movimento,
//  depois a primeira (hanoi n-1, o->a). Assim a primeira sai primeiro.
//  Dica: no frame use um campo bool "ehMovimento".
// ---------------------------------------------------------------------
void hanoiRec(int n, char o, char d, char a, vector<string>& mov) {
    if (n == 0) return;
    hanoiRec(n - 1, o, a, d, mov);
    mov.push_back(string() + o + "->" + d);
    hanoiRec(n - 1, a, d, o, mov);
}

vector<string> hanoiPilha(int n, char o, char d, char a) {
    // TODO
    return {};
}

// =====================================================================
//  NÍVEL 3 — TRABALHO DEPOIS DA CHAMADA (frame com "etapa")
// =====================================================================
//
//  Aqui a função recursiva faz algo DEPOIS de voltar de uma chamada.
//  Duas formas de resolver:
//    - frame com campo "etapa": indica de onde continuar quando o frame
//      voltar a ser o topo;
//    - "tarefas na pilha": empilhar tarefas do tipo "visitar este nó",
//      como no exercício 9.

// ---------------------------------------------------------------------
//  10. EM ORDEM (IN-ORDER)  (esquerda, raiz, direita)
//  A raiz só pode ser visitada DEPOIS de toda a subárvore esquerda.
//  Versão clássica: ande para a esquerda empilhando os nós. Quando não
//  der mais, desempilhe, visite, e vá para a direita do nó desempilhado.
//      p = raiz
//      enquanto (p != nullptr OU pilha não vazia):
//          enquanto p != nullptr: empilha p; p = p->esq
//          p = topo; desempilha; visita p; p = p->dir
//  Desafio: faça também com frame + etapa.
// ---------------------------------------------------------------------
void emOrdemRec(NoA* r, vector<int>& out) {
    if (r == nullptr) return;
    emOrdemRec(r->esq, out);
    out.push_back(r->valor);
    emOrdemRec(r->dir, out);
}

vector<int> emOrdemPilha(NoA* raiz) {
    // TODO
    return {};
}

// ---------------------------------------------------------------------
//  11. PÓS-ORDEM  (esquerda, direita, raiz)
//  O mais difícil dos três percursos: a raiz só é visitada depois das
//  DUAS subárvores. Opções:
//    (a) frame com etapa 0, 1, 2: etapa 0 = ir para a esquerda;
//        etapa 1 = ir para a direita; etapa 2 = visitar a raiz.
//    (b) duas pilhas: faça um "raiz, direita, esquerda" com a pilha 1,
//        jogando os nós visitados na pilha 2; no fim, desempilhe a 2.
//    (c) tarefas: empilhe (nó, "visitar"), depois (dir, "explorar"),
//        depois (esq, "explorar").
// ---------------------------------------------------------------------
void posOrdemRec(NoA* r, vector<int>& out) {
    if (r == nullptr) return;
    posOrdemRec(r->esq, out);
    posOrdemRec(r->dir, out);
    out.push_back(r->valor);
}

vector<int> posOrdemPilha(NoA* raiz) {
    // TODO
    return {};
}

// ---------------------------------------------------------------------
//  12. FIBONACCI
//  fib(n) = fib(n-1) + fib(n-2), com fib(0) = 0 e fib(1) = 1.
//  Duas chamadas recursivas, e a SOMA acontece depois das duas. Isso
//  exige guardar resultados parciais.
//  Sugestão: frame = (n, etapa, parcial).
//    etapa 0: se n < 2, o resultado é n; senão empilhe fib(n-1).
//    etapa 1: guarde o resultado de fib(n-1) em "parcial"; empilhe fib(n-2).
//    etapa 2: o resultado é parcial + resultado de fib(n-2).
//  Use uma variável "retorno" (fora da pilha) para passar o resultado de
//  um frame que terminou para o frame que o chamou.
// ---------------------------------------------------------------------
long long fibRec(int n) {
    if (n < 2) return n;
    return fibRec(n - 1) + fibRec(n - 2);
}

long long fibPilha(int n) {
    // TODO
    return -1;
}

// ---------------------------------------------------------------------
//  13. TODOS OS SUBCONJUNTOS
//  Para cada elemento, duas escolhas: NÃO entra ou entra no subconjunto.
//  Recursiva: sub(i, atual): se i == tamanho, registre "atual";
//     senão: sub(i+1) sem o elemento i; depois coloca v[i] em "atual",
//     sub(i+1), e REMOVE v[i] (desfaz a escolha).
//  Com pilha: o frame guarda (i, etapa) e o vetor "atual" fica fora da
//  pilha, sendo modificado e desfeito (push_back / pop_back) conforme a
//  etapa.
//  Para {1,2,3} saem 8 subconjuntos (incluindo o vazio).
// ---------------------------------------------------------------------
void subRec(const vector<int>& v, int i, vector<int>& atual,
            vector<vector<int>>& out) {
    if (i == (int)v.size()) { out.push_back(atual); return; }
    subRec(v, i + 1, atual, out);
    atual.push_back(v[i]);
    subRec(v, i + 1, atual, out);
    atual.pop_back();
}

vector<vector<int>> subconjuntosRec(const vector<int>& v) {
    vector<vector<int>> out;
    vector<int> atual;
    subRec(v, 0, atual, out);
    return out;
}

vector<vector<int>> subconjuntosPilha(const vector<int>& v) {
    // TODO
    return {};
}

// ---------------------------------------------------------------------
//  14. QUICKSORT ITERATIVO
//  A pilha guarda INTERVALOS (lo, hi) que ainda precisam ser ordenados.
//  Empilhe (0, n-1). Enquanto houver intervalos: desempilhe, se lo < hi
//  chame particionar (já pronto abaixo), e empilhe os dois lados:
//  (lo, p-1) e (p+1, hi).
//  Dica avançada: empilhar primeiro o lado MAIOR (assim o menor é
//  processado antes) mantém a pilha com tamanho O(log n).
// ---------------------------------------------------------------------
int particionar(vector<int>& v, int lo, int hi) {
    int pivo = v[hi];
    int i = lo;
    for (int j = lo; j < hi; j++)
        if (v[j] < pivo) swap(v[i++], v[j]);
    swap(v[i], v[hi]);
    return i;
}

void quicksortRec(vector<int>& v, int lo, int hi) {
    if (lo >= hi) return;
    int p = particionar(v, lo, hi);
    quicksortRec(v, lo, p - 1);
    quicksortRec(v, p + 1, hi);
}

void quicksortPilha(vector<int>& v) {
    // TODO
}

// =====================================================================
//  NÍVEL 4 — BACKTRACKING (desfazer o que foi feito)
// =====================================================================
//
//  Diferença para o labirinto que você já fez: lá a matriz "visitado"
//  nunca era desmarcada. No backtracking de verdade, ao VOLTAR de uma
//  tentativa, você DESFAZ a escolha, para que outros caminhos possam
//  usar aquela posição.
//  Padrão do frame:  (estado da decisão, próxima opção a tentar).
//  Quando as opções de um frame acabam: desfaça a escolha e desempilhe.

// ---------------------------------------------------------------------
//  15. TODOS OS CAMINHOS DO LABIRINTO
//  Num labirinto que NÃO é perfeito existem vários caminhos de "inicio"
//  até "fim" (sem repetir posição). Conte quantos.
//  Matriz: ' ' é corredor, '#' é parede.
//  Frame: (posição, índice do próximo vizinho a tentar, de 0 a 3).
//  - Ao empilhar uma posição: marque como visitada.
//  - Ao desempilhar (acabaram os vizinhos): DESMARQUE.
//  - Se a posição empilhada for o "fim": some 1 ao contador e desempilhe
//    (desmarcando), sem explorar os vizinhos do fim.
//  Teste: grade 3x3 toda livre, de (0,0) a (2,2): 12 caminhos.
// ---------------------------------------------------------------------
long long caminhosRec(const vector<string>& m, vector<vector<bool>>& vis,
                      Pos p, Pos fim) {
    if (p.l == fim.l && p.c == fim.c) return 1;
    vis[p.l][p.c] = true;
    long long total = 0;
    for (Pos v : get_vizinhos(p)) {
        if (!dentro(m, v)) continue;
        if (m[v.l][v.c] != ' ' || vis[v.l][v.c]) continue;
        total += caminhosRec(m, vis, v, fim);
    }
    vis[p.l][p.c] = false;
    return total;
}

long long contarCaminhosRec(const vector<string>& m, Pos inicio, Pos fim) {
    vector<vector<bool>> vis(m.size(), vector<bool>(m[0].size(), false));
    return caminhosRec(m, vis, inicio, fim);
}

long long contarCaminhosPilha(const vector<string>& m, Pos inicio, Pos fim) {
    // TODO
    return -1;
}

// ---------------------------------------------------------------------
//  16. PERMUTAÇÕES
//  Gere todas as permutações de {1, 2, ..., n}.
//  Recursiva: em cada posição, tente cada número ainda não usado;
//  marque "usado", recurse, desmarque.
//  Com pilha: frame = (próximo número a tentar nesta posição). O vetor
//  "atual" e o vetor "usado" ficam fora. Cada frame empilhado
//  corresponde a UMA posição preenchida.
//  n=3 -> 6 permutações; n=4 -> 24.
// ---------------------------------------------------------------------
void permRec(int n, vector<int>& atual, vector<bool>& usado,
             vector<vector<int>>& out) {
    if ((int)atual.size() == n) { out.push_back(atual); return; }
    for (int x = 1; x <= n; x++) {
        if (usado[x]) continue;
        usado[x] = true;
        atual.push_back(x);
        permRec(n, atual, usado, out);
        atual.pop_back();
        usado[x] = false;
    }
}

vector<vector<int>> permutacoesRec(int n) {
    vector<vector<int>> out;
    vector<int> atual;
    vector<bool> usado(n + 1, false);
    permRec(n, atual, usado, out);
    return out;
}

vector<vector<int>> permutacoesPilha(int n) {
    // TODO
    return {};
}

// ---------------------------------------------------------------------
//  17. N-RAINHAS
//  Coloque N rainhas num tabuleiro N x N sem que duas se ataquem (mesma
//  linha, coluna ou diagonal). Conte as soluções.
//  Representação: col[linha] = coluna da rainha daquela linha. Assim já
//  não há duas na mesma linha. A função "seguro" (pronta) confere
//  coluna e diagonais contra as linhas já preenchidas.
//  Frame: (linha, próxima coluna a tentar).
//    - se linha == n: achou solução, some 1 e desempilhe;
//    - senão tente colunas c a partir de "próxima coluna": se seguro,
//      coloque col[linha] = c, guarde c+1 no frame atual e empilhe o
//      frame da linha seguinte;
//    - se as colunas acabaram: desempilhe.
//  Resultados: N=4 -> 2, N=6 -> 4, N=8 -> 92.
// ---------------------------------------------------------------------
bool seguro(const vector<int>& col, int linha, int c) {
    for (int i = 0; i < linha; i++)
        if (col[i] == c || abs(col[i] - c) == linha - i) return false;
    return true;
}

void rainhasRec(int n, int linha, vector<int>& col, int& cont) {
    if (linha == n) { cont++; return; }
    for (int c = 0; c < n; c++)
        if (seguro(col, linha, c)) {
            col[linha] = c;
            rainhasRec(n, linha + 1, col, cont);
        }
}

int contarRainhasRec(int n) {
    vector<int> col(n, -1);
    int cont = 0;
    rainhasRec(n, 0, col, cont);
    return cont;
}

int contarRainhasPilha(int n) {
    // TODO
    return -1;
}

// ---------------------------------------------------------------------
//  18. PARÊNTESES BALANCEADOS
//  Gere todas as strings de n pares de parênteses bem formadas.
//  n=3 -> "((()))", "(()())", "(())()", "()(())", "()()()".
//  Regras: pode abrir "(" se abertos < n; pode fechar ")" se
//  fechados < abertos.
//  Frame: (string atual, abertos, fechados). Como cada frame já carrega
//  a string, não há nada a desfazer: ao desempilhar um frame, se a
//  string tem tamanho 2n guarde-a, senão empilhe os frames filhos.
// ---------------------------------------------------------------------
void parRec(int n, int ab, int fe, string s, vector<string>& out) {
    if ((int)s.size() == 2 * n) { out.push_back(s); return; }
    if (ab < n) parRec(n, ab + 1, fe, s + '(', out);
    if (fe < ab) parRec(n, ab, fe + 1, s + ')', out);
}

vector<string> parentesesRec(int n) {
    vector<string> out;
    parRec(n, 0, 0, "", out);
    return out;
}

vector<string> parentesesPilha(int n) {
    // TODO
    return {};
}

// =====================================================================
//  NÍVEL 5 — DESAFIOS
// =====================================================================

// ---------------------------------------------------------------------
//  19. DFS EM GRAFO, NA MESMA ORDEM DA RECURSIVA
//  Se você simplesmente empilhar TODOS os vizinhos de uma vez, a ordem
//  de visita muda. Para igualar à recursiva, o frame guarda
//  (vértice, índice do próximo vizinho a olhar).
//    - ao empilhar um vértice: marque visitado e registre na "ordem";
//    - no topo: ande pelos vizinhos a partir do índice guardado; no
//      primeiro não visitado, avance o índice do frame e empilhe esse
//      vizinho; se os vizinhos acabaram, desempilhe.
//  Grafo de teste (lista de adjacência):
//      0: 1 2   1: 3   2: 3 4   3: 5   4: 5   5: (nenhum)
//  Ordem esperada a partir do 0:  0 1 3 5 2 4
// ---------------------------------------------------------------------
void dfsRecAux(const vector<vector<int>>& g, int v, vector<bool>& vis,
               vector<int>& ordem) {
    vis[v] = true;
    ordem.push_back(v);
    for (int u : g[v])
        if (!vis[u]) dfsRecAux(g, u, vis, ordem);
}

vector<int> dfsRec(const vector<vector<int>>& g, int inicio) {
    vector<bool> vis(g.size(), false);
    vector<int> ordem;
    dfsRecAux(g, inicio, vis, ordem);
    return ordem;
}

vector<int> dfsPilha(const vector<vector<int>>& g, int inicio) {
    // TODO
    return {};
}

// ---------------------------------------------------------------------
//  20. AVALIADOR DE EXPRESSÕES
//  Calcule expressões com inteiros, + - * / e parênteses, SEM espaços.
//  Ex.: "3+4*(2-1)" = 7.   "10-2-3" = 5 (esquerda para direita).
//  A versão recursiva (descida recursiva) usa três funções:
//  expr -> termo -> fator, que se chamam mutuamente.
//  Com pilha: algoritmo de duas pilhas (Dijkstra / shunting-yard):
//    - pilha de NÚMEROS e pilha de OPERADORES;
//    - número: empilhe na pilha de números;
//    - '(' : empilhe na de operadores;
//    - ')' : aplique operadores até achar o '(' e descarte-o;
//    - operador: enquanto o topo dos operadores tiver precedência
//      MAIOR OU IGUAL, aplique-o; depois empilhe o operador novo;
//    - ao fim, aplique os operadores que restaram.
//  "Aplicar" = tirar dois números, calcular, empilhar o resultado.
//  (Cuidado com a ordem dos operandos em - e /: o segundo a sair da
//  pilha é o da ESQUERDA.)
// ---------------------------------------------------------------------
struct Parser {
    string s;
    size_t i = 0;
    long long expr() {
        long long v = termo();
        while (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            char op = s[i++];
            long long t = termo();
            v = (op == '+') ? v + t : v - t;
        }
        return v;
    }
    long long termo() {
        long long v = fator();
        while (i < s.size() && (s[i] == '*' || s[i] == '/')) {
            char op = s[i++];
            long long f = fator();
            v = (op == '*') ? v * f : v / f;
        }
        return v;
    }
    long long fator() {
        if (s[i] == '(') {
            i++;
            long long v = expr();
            i++;  // pula ')'
            return v;
        }
        long long v = 0;
        while (i < s.size() && isdigit(s[i])) v = v * 10 + (s[i++] - '0');
        return v;
    }
};

long long avaliarRec(const string& s) {
    Parser p;
    p.s = s;
    return p.expr();
}

long long avaliarPilha(const string& s) {
    // TODO
    return -1;
}

// ---------------------------------------------------------------------
//  21. SUDOKU COM BACKTRACKING
//  Preencha uma grade 9x9 (0 = vazio) respeitando linha, coluna e bloco
//  3x3. Retorna true se resolveu (e a grade fica preenchida).
//  Frame: (linha, coluna, próximo número a tentar de 1 a 9) da célula
//  vazia em que se está.
//    - ao empilhar uma célula, procure a PRÓXIMA célula vazia;
//    - tente números a partir do guardado: se "podeColocar", coloque,
//      atualize o frame e empilhe a próxima célula vazia;
//    - se os números acabaram: ponha 0 na célula (desfaz) e desempilhe;
//    - se não há mais células vazias: resolvido, retorne true;
//    - se a pilha esvaziar: não tem solução, retorne false.
// ---------------------------------------------------------------------
using Grade = vector<vector<int>>;

bool podeColocar(const Grade& g, int l, int c, int n) {
    for (int i = 0; i < 9; i++)
        if (g[l][i] == n || g[i][c] == n) return false;
    int bl = l / 3 * 3, bc = c / 3 * 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (g[bl + i][bc + j] == n) return false;
    return true;
}

bool sudokuRec(Grade& g) {
    for (int l = 0; l < 9; l++)
        for (int c = 0; c < 9; c++)
            if (g[l][c] == 0) {
                for (int n = 1; n <= 9; n++)
                    if (podeColocar(g, l, c, n)) {
                        g[l][c] = n;
                        if (sudokuRec(g)) return true;
                        g[l][c] = 0;
                    }
                return false;
            }
    return true;
}

bool sudokuPilha(Grade& g) {
    // TODO
    return false;
}

Grade lerGrade(const vector<string>& linhas) {
    Grade g(9, vector<int>(9, 0));
    for (int l = 0; l < 9; l++)
        for (int c = 0; c < 9; c++) g[l][c] = linhas[l][c] - '0';
    return g;
}

// ---------------------------------------------------------------------
//  22. FUNÇÃO DE ACKERMANN
//  A(m, n) = n + 1                    se m == 0
//  A(m, n) = A(m-1, 1)                se m > 0 e n == 0
//  A(m, n) = A(m-1, A(m, n-1))        se m > 0 e n > 0
//  Cresce tão rápido que a recursão estoura a pilha do sistema com
//  valores pequenos. Por isso a versão com pilha explícita é a que
//  realmente roda.
//  Dica: a chamada de dentro A(m, n-1) é o ARGUMENTO da de fora. Isso
//  permite guardar na pilha só os valores de "m" que ainda estão
//  pendentes, e manter "n" numa variável:
//     empilhe m;
//     enquanto a pilha não estiver vazia:
//        m = topo; desempilhe;
//        caso m == 0:           n = n + 1
//        caso n == 0:           empilhe m-1; n = 1
//        caso contrário:        empilhe m-1; empilhe m; n = n - 1
//     retorne n
//  Tente primeiro entender POR QUE isso funciona, desenhando A(1, 1).
// ---------------------------------------------------------------------
long long ackRec(long long m, long long n) {
    if (m == 0) return n + 1;
    if (n == 0) return ackRec(m - 1, 1);
    return ackRec(m - 1, ackRec(m, n - 1));
}

long long ackPilha(long long m, long long n) {
    // TODO
    return -1;
}

// =====================================================================
//  TESTES
// =====================================================================

int main() {
    cout << "===== NIVEL 1 =====" << endl;
    conferir("1  soma(5) = 15", somaPilha(5) == 15 && somaRec(5) == 15);
    conferir("1  soma(0) = 0", somaPilha(0) == 0);
    conferir("2  fatorial(5) = 120", fatPilha(5) == 120 && fatRec(5) == 120);
    conferir("2  fatorial(0) = 1", fatPilha(0) == 1);
    {
        vector<int> esperado = {1, 2, 3, 4};
        vector<int> r;
        digitosRec(1234, r);
        conferir("3  digitos de 1234 = 1 2 3 4",
                 digitosPilha(1234) == esperado && r == esperado);
        conferir("3  digitos de 0 = 0", digitosPilha(0) == vector<int>{0});
    }
    {
        No* l = nullptr;
        for (int x : {1, 2, 3, 4}) inserirFim(l, x);
        No* inv = inverterPilha(l);
        conferir("4  inverter lista com pilha", paraVetor(inv) == vector<int>({4, 3, 2, 1}));
        liberar(inv);
        conferir("4  inverter lista vazia", inverterPilha(nullptr) == nullptr);
    }

    /* Árvore de teste:
                4
              /   \
             2     6
            / \   / \
           1   3 5   7
          /
         8
    */
    NoA* t = new NoA(4);
    t->esq = new NoA(2);
    t->dir = new NoA(6);
    t->esq->esq = new NoA(1);
    t->esq->dir = new NoA(3);
    t->dir->esq = new NoA(5);
    t->dir->dir = new NoA(7);
    t->esq->esq->esq = new NoA(8);

    cout << "\n===== NIVEL 2 =====" << endl;
    {
        vector<int> esperado = {4, 2, 1, 8, 3, 6, 5, 7};
        vector<int> r;
        preRec(t, r);
        conferir("5  pre-ordem", prePilha(t) == esperado && r == esperado);
        conferir("5  pre-ordem de arvore vazia", prePilha(nullptr).empty());
    }
    conferir("6  altura = 4", alturaPilha(t) == 4 && alturaRec(t) == 4);
    conferir("6  altura de arvore vazia = 0", alturaPilha(nullptr) == 0);
    {
        vector<string> m = {"..#..", "..#..", "###..", "....."};
        vector<string> esperado = {"xx#..", "xx#..", "###..", "....."};
        vector<string> a = m, b = m;
        floodFillRec(a, 0, 0, 'x');
        floodFillPilha(b, 0, 0, 'x');
        conferir("7  flood fill", a == esperado && b == esperado);
        vector<string> c = m;
        floodFillPilha(c, 0, 0, '.');  // cor igual: não pode travar
        conferir("7  flood fill com mesma cor (sem loop infinito)", c == m);
    }
    {
        vector<string> m = {"11000", "11000", "00100", "00011"};
        conferir("8  contar ilhas = 3",
                 contarIlhasPilha(m) == 3 && contarIlhasRec(m) == 3);
    }
    {
        vector<string> a, esperado;
        hanoiRec(3, 'A', 'C', 'B', esperado);
        a = hanoiPilha(3, 'A', 'C', 'B');
        conferir("9  hanoi com 3 discos (7 movimentos, mesma ordem)",
                 a == esperado && esperado.size() == 7);
    }

    cout << "\n===== NIVEL 3 =====" << endl;
    {
        vector<int> esperado = {8, 1, 2, 3, 4, 5, 6, 7};
        vector<int> r;
        emOrdemRec(t, r);
        conferir("10 em ordem", emOrdemPilha(t) == esperado && r == esperado);
    }
    {
        vector<int> esperado = {8, 1, 3, 2, 5, 7, 6, 4};
        vector<int> r;
        posOrdemRec(t, r);
        conferir("11 pos-ordem", posOrdemPilha(t) == esperado && r == esperado);
    }
    conferir("12 fib(10) = 55", fibPilha(10) == 55 && fibRec(10) == 55);
    conferir("12 fib(20) = 6765", fibPilha(20) == 6765);
    {
        vector<int> v = {1, 2, 3};
        auto a = ordenado(subconjuntosRec(v));
        auto b = ordenado(subconjuntosPilha(v));
        conferir("13 subconjuntos de {1,2,3} (8 no total)",
                 a.size() == 8 && a == b);
    }
    {
        vector<int> a = {5, 2, 9, 1, 5, 6, 0, 3};
        vector<int> b = a, esperado = ordenado(a);
        quicksortRec(a, 0, (int)a.size() - 1);
        quicksortPilha(b);
        conferir("14 quicksort iterativo", a == esperado && b == esperado);
        vector<int> vazio;
        quicksortPilha(vazio);
        conferir("14 quicksort de vetor vazio (nao pode quebrar)", vazio.empty());
    }

    cout << "\n===== NIVEL 4 =====" << endl;
    {
        vector<string> livre = {"   ", "   ", "   "};
        conferir("15 caminhos em grade 3x3 livre = 12",
                 contarCaminhosPilha(livre, Pos{0, 0}, Pos{2, 2}) == 12 &&
                     contarCaminhosRec(livre, Pos{0, 0}, Pos{2, 2}) == 12);
        vector<string> anel = {"   ", " # ", "   "};
        conferir("15 caminhos ao redor de uma parede = 2",
                 contarCaminhosPilha(anel, Pos{0, 0}, Pos{2, 2}) == 2);
    }
    {
        auto a = ordenado(permutacoesRec(3));
        auto b = ordenado(permutacoesPilha(3));
        conferir("16 permutacoes de 3 (6 no total)", a.size() == 6 && a == b);
        conferir("16 permutacoes de 4 (24 no total)",
                 ordenado(permutacoesRec(4)) == ordenado(permutacoesPilha(4)));
    }
    conferir("17 rainhas N=4 -> 2", contarRainhasPilha(4) == 2 && contarRainhasRec(4) == 2);
    conferir("17 rainhas N=6 -> 4", contarRainhasPilha(6) == 4);
    conferir("17 rainhas N=8 -> 92", contarRainhasPilha(8) == 92);
    {
        auto a = ordenado(parentesesRec(3));
        auto b = ordenado(parentesesPilha(3));
        conferir("18 parenteses n=3 (5 no total)", a.size() == 5 && a == b);
        conferir("18 parenteses n=4 (14 no total)",
                 ordenado(parentesesPilha(4)).size() == 14);
    }

    cout << "\n===== NIVEL 5 =====" << endl;
    {
        vector<vector<int>> g = {{1, 2}, {3}, {3, 4}, {5}, {5}, {}};
        vector<int> esperado = {0, 1, 3, 5, 2, 4};
        conferir("19 DFS na mesma ordem da recursiva",
                 dfsRec(g, 0) == esperado && dfsPilha(g, 0) == esperado);
    }
    conferir("20 3+4*(2-1) = 7", avaliarPilha("3+4*(2-1)") == 7 && avaliarRec("3+4*(2-1)") == 7);
    conferir("20 2*(3+4)*5 = 70", avaliarPilha("2*(3+4)*5") == 70);
    conferir("20 10-2-3 = 5 (esquerda para direita)", avaliarPilha("10-2-3") == 5);
    conferir("20 100/5/2 = 10", avaliarPilha("100/5/2") == 10);
    conferir("20 ((2)) = 2", avaliarPilha("((2))") == 2);
    {
        vector<string> puzzle = {
            "530070000", "600195000", "098000060",
            "800060003", "400803001", "700020006",
            "060000280", "000419005", "000080079"};
        Grade a = lerGrade(puzzle), b = lerGrade(puzzle);
        bool okRec = sudokuRec(a);
        bool okPilha = sudokuPilha(b);
        conferir("21 sudoku resolvido igual ao recursivo", okRec && okPilha && a == b);
    }
    conferir("22 A(1,1) = 3", ackPilha(1, 1) == 3 && ackRec(1, 1) == 3);
    conferir("22 A(2,3) = 9", ackPilha(2, 3) == 9);
    conferir("22 A(3,3) = 61", ackPilha(3, 3) == 61);
    conferir("22 A(3,6) = 509", ackPilha(3, 6) == 509);

    liberarArvore(t);

    cout << "\nResultado: " << acertos << " de " << total << " testes." << endl;
    return 0;
}
