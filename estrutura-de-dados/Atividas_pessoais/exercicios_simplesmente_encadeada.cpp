// =====================================================================
//  EXERCÍCIOS DE LISTA SIMPLESMENTE ENCADEADA (5 a 9)
// =====================================================================
//
//  COMO A LISTA FUNCIONA
//  ---------------------
//  Cada nó guarda um valor e um ponteiro para o próximo nó.
//  A lista inteira é representada SÓ pelo ponteiro para o primeiro nó
//  (chamado de "head"). O último nó aponta para nullptr.
//
//      head
//       |
//       v
//      [1|•]--->[2|•]--->[3|•]--->nullptr
//
//  - Lista vazia: head == nullptr
//  - Andar na lista: p = p->proximo
//  - Fim da lista: p == nullptr
//
//  REGRAS GERAIS DOS EXERCÍCIOS
//  ----------------------------
//  - As funções NÃO criam nós novos (só religam ponteiros), exceto
//    onde o enunciado disser o contrário.
//  - Se a função pode mudar quem é o primeiro nó, ela DEVOLVE o novo
//    head, e quem chamou faz:  l = funcao(l);
//  - Sempre teste: lista vazia, 1 elemento e 2 elementos.
//  - Dica de ouro: desenhe a lista no papel e vá riscando as setas.
// =====================================================================

#include <iostream>
using namespace std;

struct No {
    int valor;
    No* proximo;
    No(int v, No* p = nullptr) : valor(v), proximo(p) {}
};

// ---------------------------------------------------------------------
//  AUXILIARES (já prontas, não precisa mexer)
// ---------------------------------------------------------------------

// Insere x no final da lista. Recebe head por REFERÊNCIA (No*&) porque,
// se a lista estiver vazia, o head muda para o novo nó.
void inserirFim(No*& head, int x) {
    No* novo = new No(x);
    if (head == nullptr) {
        head = novo;
        return;
    }
    No* atual = head;
    while (atual->proximo != nullptr) atual = atual->proximo;
    atual->proximo = novo;
}

// Imprime os valores separados por espaço.
void imprimir(No* head) {
    for (No* p = head; p != nullptr; p = p->proximo)
        cout << p->valor << " ";
    cout << endl;
}

// Libera todos os nós. Guarda o próximo ANTES de dar delete, senão
// você perderia o acesso ao resto da lista.
// ATENÇÃO: em lista com ciclo isso nunca termina.
void liberar(No* head) {
    while (head != nullptr) {
        No* prox = head->proximo;
        delete head;
        head = prox;
    }
}

// =====================================================================
//  EXERCÍCIO 5a — INVERTER A LISTA (ITERATIVO)
// =====================================================================
//
//  O QUE PEDE
//  Fazer todos os ponteiros "proximo" apontarem no sentido contrário.
//  Devolver o novo head (que é o antigo último nó).
//
//      antes:   1 --> 2 --> 3 --> nullptr
//      depois:  nullptr <-- 1 <-- 2 <-- 3     (head agora é o 3)
//                          ou seja:  3 --> 2 --> 1 --> nullptr
//
//  IDEIA
//  Percorra a lista UMA vez. Em cada nó, vire a seta para trás.
//  Problema: ao virar a seta do nó atual, você perde o caminho para o
//  próximo. Solução: GUARDE o próximo antes de virar.
//
//  Use 3 ponteiros:
//      anterior : nó que já foi virado (começa em nullptr)
//      atual    : nó que estamos virando agora (começa em head)
//      proximo  : guarda atual->proximo antes de mexer
//
//  CADA PASSO DO LAÇO (while atual != nullptr):
//      1) proximo = atual->proximo        // salva o caminho
//      2) atual->proximo = anterior       // vira a seta
//      3) anterior = atual                // anda "anterior"
//      4) atual = proximo                 // anda "atual"
//
//  Quando o laço termina, atual é nullptr e "anterior" é o último nó
//  visitado, que é o novo head. Retorne "anterior".
//
//  EXEMPLO PASSO A PASSO (lista 1 -> 2 -> 3)
//      início:   anterior=null  atual=1
//      passo 1:  proximo=2; 1->proximo=null; anterior=1; atual=2
//      passo 2:  proximo=3; 2->proximo=1;    anterior=2; atual=3
//      passo 3:  proximo=null; 3->proximo=2; anterior=3; atual=null
//      fim:      retorna 3      =>   3 -> 2 -> 1 -> null
//
//  CASOS DE BORDA
//  Lista vazia: o laço nem roda, anterior é nullptr, retorna nullptr. OK.
//  1 elemento: vira ele mesmo apontando para nullptr. OK.
//  Ou seja, não precisa de if especial.
// =====================================================================
No* inverterIterativo(No* head) {
    // TODO
    return head;  // (provisório, só para compilar; apague ao implementar)
}

// =====================================================================
//  EXERCÍCIO 5b — INVERTER A LISTA (RECURSIVO)
// =====================================================================
//
//  O QUE PEDE
//  O mesmo resultado do 5a, mas usando recursão.
//
//  IDEIA (pense assim: "confio que a recursão resolve o resto")
//  Lista = primeiro nó + resto da lista.
//      head -> [1] -> [2] -> [3] -> null
//                     \_____ resto _____/
//
//  1) CASO BASE: se head == nullptr ou head->proximo == nullptr,
//     a lista tem 0 ou 1 nó, já está invertida. Retorne head.
//
//  2) CASO RECURSIVO:
//     a) Inverta o resto:  novoHead = inverterRecursivo(head->proximo)
//        Depois disso, o resto ficou invertido: 3 -> 2 -> null
//        MAS o nó 1 ainda aponta para o 2, que agora é o ÚLTIMO
//        do resto invertido.
//     b) Faça o nó seguinte apontar de volta para head:
//        head->proximo->proximo = head      (o 2 passa a apontar pro 1)
//     c) Faça head ser o último:
//        head->proximo = nullptr
//     d) Retorne novoHead (o novo head é o mesmo que a chamada
//        recursiva devolveu; ele não muda ao longo da volta).
//
//  EXEMPLO (1 -> 2 -> 3)
//      inverter(1)
//        inverter(2)
//          inverter(3)  -> caso base, devolve 3
//        2->proximo = 1 ... (aqui head=2, 2->proximo(3)->proximo = 2)
//        2->proximo = null
//        devolve 3      (lista agora: 3 -> 2 -> null)
//      1->proximo(2)->proximo = 1
//      1->proximo = null
//      devolve 3        (lista final: 3 -> 2 -> 1 -> null)
//
//  Atenção na ordem de (b) e (c): se você fizer (c) antes de (b),
//  perde o acesso ao nó seguinte.
// =====================================================================
No* inverterRecursivo(No* head) {
    // TODO
    return head;  // (provisório)
}

// =====================================================================
//  EXERCÍCIO 6 — REMOVER DUPLICADOS
// =====================================================================
//
//  O QUE PEDE
//  Se um valor aparece mais de uma vez, mantenha só a PRIMEIRA
//  ocorrência e apague (delete) as outras.
//
//      antes:   1 -> 2 -> 2 -> 3 -> 1 -> 4 -> 4 -> null
//      depois:  1 -> 2 -> 3 -> 4 -> null
//
//  Não precisa devolver nada (void): o primeiro nó nunca é removido,
//  então o head não muda.
//
//  IDEIA (versão simples, O(n²))
//  Para cada nó "p", olhe todos os nós DEPOIS dele. Se algum tiver o
//  mesmo valor de p, remova.
//
//      for (p = head; p != nullptr; p = p->proximo) {
//          q = p;                              // q é o nó ANTES do candidato
//          while (q->proximo != nullptr) {
//              if (q->proximo->valor == p->valor) {
//                  // remove o candidato
//                  No* lixo = q->proximo;
//                  q->proximo = lixo->proximo; // "pula" o candidato
//                  delete lixo;
//              } else {
//                  q = q->proximo;             // só anda se NÃO removeu
//              }
//          }
//      }
//
//  PONTOS QUE CONFUNDEM
//  - Por que "q" olha para q->proximo e não para o próprio q? Para
//    remover um nó numa lista simplesmente encadeada você precisa do
//    nó ANTERIOR a ele, para poder religar a seta.
//  - Por que só anda quando NÃO remove? Depois de remover, o novo
//    q->proximo ainda não foi conferido. Se andasse, pularia ele.
//  - Lista vazia: o for não roda (p == nullptr). OK.
//
//  DESAFIO EXTRA (opcional)
//  Se a lista já estiver ORDENADA, os repetidos ficam lado a lado e
//  dá para fazer em O(n) com um único ponteiro: enquanto
//  p->proximo existir, se p->valor == p->proximo->valor remova o
//  próximo, senão avance p.
// =====================================================================
void removerDuplicados(No* head) {
    No* p = head;
    if (p == nullptr) return;
    while (p != nullptr){
        No* q = p->proximo;
        while (q != nullptr){
            if (p->valor == q->valor){
                No* aux = q;
                p->proximo = q->proximo;
                delete aux;
            }
            else{
                q = q->proximo;
            }
        }
        p = p->proximo;
    }
    
}

// =====================================================================
//  EXERCÍCIO 7 — ELEMENTO DO MEIO
// =====================================================================
//
//  O QUE PEDE
//  Devolver o ponteiro para o nó do meio, sem contar o tamanho antes.
//  Se o tamanho for par, devolva o SEGUNDO dos dois do meio.
//
//      1 -> 2 -> 3 -> 4 -> 5        meio = 3
//      1 -> 2 -> 3 -> 4             meio = 3
//
//  IDEIA: dois ponteiros com velocidades diferentes
//      lento  : anda 1 nó por vez
//      rapido : anda 2 nós por vez
//  Quando o rapido chega no fim, o lento está na metade do caminho.
//
//  Ambos começam em head. Enquanto o rapido puder dar 2 passos:
//      while (rapido != nullptr && rapido->proximo != nullptr) {
//          lento  = lento->proximo;
//          rapido = rapido->proximo->proximo;
//      }
//      return lento;
//
//  POR QUE A CONDIÇÃO TEM DOIS TESTES?
//  Para dar 2 passos, o rapido precisa ter um próximo. Se testar só
//  "rapido != nullptr" e depois fizer rapido->proximo->proximo num nó
//  que é o último, você acessa nullptr->proximo e o programa quebra.
//  Importante: a ORDEM do && importa (testa o primeiro; se falhar,
//  nem avalia o segundo).
//
//  EXEMPLO (1 -> 2 -> 3 -> 4 -> 5)
//      início:  lento=1  rapido=1
//      volta 1: lento=2  rapido=3
//      volta 2: lento=3  rapido=5
//      rapido->proximo == nullptr, para. Retorna 3.
//
//  EXEMPLO PAR (1 -> 2 -> 3 -> 4)
//      início:  lento=1  rapido=1
//      volta 1: lento=2  rapido=3
//      volta 2: lento=3  rapido=nullptr (4->proximo->proximo)
//      rapido == nullptr, para. Retorna 3 (o segundo do meio).
//
//  Lista vazia: retorna head, que é nullptr. Cuidado no main ao usar
//  meio(l)->valor: só faça isso se a lista não for vazia.
// =====================================================================
No* meio(No* head) {
    // TODO
    return head;  // (provisório)
}

// =====================================================================
//  EXERCÍCIO 8 — DETECTAR CICLO
// =====================================================================
//
//  O QUE PEDE
//  Dizer se a lista tem ciclo, isto é, se algum nó aponta de volta para
//  um nó anterior, de modo que a lista nunca chega em nullptr.
//
//      1 -> 2 -> 3 -> 4
//                 ^    |
//                 |____|        (4 aponta de volta para 3)
//
//  Sem ciclo, andar na lista sempre termina em nullptr.
//  Com ciclo, quem andar pela lista fica rodando em círculo para sempre.
//
//  IDEIA: algoritmo da tartaruga e da lebre (Floyd)
//      tartaruga : anda 1 nó por vez
//      lebre     : anda 2 nós por vez
//
//  - SEM ciclo: a lebre chega em nullptr. Retorne false.
//  - COM ciclo: os dois entram no círculo e a lebre vai ganhando 1 nó
//    de distância por volta, então eles inevitavelmente se encontram
//    no mesmo nó. Retorne true.
//
//      while (lebre != nullptr && lebre->proximo != nullptr) {
//          tartaruga = tartaruga->proximo;
//          lebre = lebre->proximo->proximo;
//          if (tartaruga == lebre) return true;   // compare os PONTEIROS
//      }
//      return false;
//
//  PONTOS QUE CONFUNDEM
//  - Compare os ENDEREÇOS (tartaruga == lebre), não os valores. Dois
//    nós diferentes podem ter o mesmo valor.
//  - O teste do encontro vem DEPOIS de andar. Se vier antes, os dois
//    começam no mesmo nó (head) e você retornaria true sempre.
//  - É a mesma estrutura do exercício 7, só que com um return no meio.
//
//  Lista vazia ou com 1 nó sem ciclo: o laço não roda, retorna false.
// =====================================================================
bool temCiclo(No* head) {
    // TODO
    return false;  // (provisório)
}

// =====================================================================
//  EXERCÍCIO 9 — JUNTAR DUAS LISTAS ORDENADAS
// =====================================================================
//
//  O QUE PEDE
//  Receber duas listas já em ordem crescente e devolver UMA lista
//  ordenada com todos os nós, reaproveitando os nós existentes (sem
//  usar new).
//
//      a: 1 -> 4 -> 7
//      b: 2 -> 3 -> 8 -> 9
//      resultado: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9
//
//  Depois da junção, a e b não valem mais como listas separadas: os
//  nós agora pertencem ao resultado. Por isso o main só libera "c".
//
//  IDEIA: parecido com juntar duas pilhas de cartas já ordenadas.
//  Olhe a carta de cima de cada pilha, pegue a menor, coloque no
//  resultado, e repita.
//
//  O NÓ FALSO (sentinela)
//  O difícil é o primeiro nó do resultado: ele pode vir de a ou de b,
//  e você não tem ainda um "último nó do resultado" para ligar nele.
//  Truque: crie um nó falso no começo, só para ter onde ligar. No fim,
//  o resultado verdadeiro é falso.proximo.
//
//      No falso(0);          // nó na pilha (não precisa de new/delete)
//      No* cauda = &falso;   // cauda = último nó do resultado até agora
//
//      while (a != nullptr && b != nullptr) {
//          if (a->valor <= b->valor) {
//              cauda->proximo = a;     // liga o nó de a no resultado
//              a = a->proximo;         // avança em a
//          } else {
//              cauda->proximo = b;
//              b = b->proximo;
//          }
//          cauda = cauda->proximo;     // cauda agora é o nó recém-ligado
//      }
//
//      // Uma das listas acabou. A outra já está ordenada, então é só
//      // pendurar o que sobrou inteiro (sem laço):
//      cauda->proximo = (a != nullptr) ? a : b;
//
//      return falso.proximo;
//
//  EXEMPLO (a: 1,4,7  b: 2,3,8,9)
//      compara 1 e 2 -> pega 1     resultado: 1
//      compara 4 e 2 -> pega 2     resultado: 1 2
//      compara 4 e 3 -> pega 3     resultado: 1 2 3
//      compara 4 e 8 -> pega 4     resultado: 1 2 3 4
//      compara 7 e 8 -> pega 7     resultado: 1 2 3 4 7
//      a acabou; pendura b inteiro (8 -> 9): 1 2 3 4 7 8 9
//
//  PONTOS QUE CONFUNDEM
//  - Usar "<=" (e não "<") mantém a ordem original quando há valores
//    iguais (a junção fica "estável").
//  - Se uma das listas for vazia, o laço nem roda e o resultado é a
//    outra lista. Funciona sem caso especial.
// =====================================================================
No* juntarOrdenadas(No* a, No* b) {
    No* m_head3;
    return nullptr;  // (provisório)
}

// =====================================================================
//  TESTES
// =====================================================================

int main() {
    // ---- 5. Inverter ----
    No* l1 = nullptr;
    for (int x : {1, 2, 3, 4, 5}) inserirFim(l1, x);
    l1 = inverterIterativo(l1);
    imprimir(l1);               // esperado: 5 4 3 2 1
    l1 = inverterRecursivo(l1);
    imprimir(l1);               // esperado: 1 2 3 4 5

    // ---- 6. Duplicados ----
    No* l2 = nullptr;
    for (int x : {1, 2, 2, 3, 1, 4, 4}) inserirFim(l2, x);
    removerDuplicados(l2);
    imprimir(l2);               // esperado: 1 2 3 4

    // ---- 7. Meio ----
    cout << meio(l1)->valor << endl;   // esperado: 3

    // ---- 8. Ciclo ----
    cout << temCiclo(l1) << endl;      // esperado: 0
    No* ultimo = l1;
    while (ultimo->proximo != nullptr) ultimo = ultimo->proximo;
    ultimo->proximo = l1->proximo;     // cria ciclo (último aponta para o 2)
    cout << temCiclo(l1) << endl;      // esperado: 1
    ultimo->proximo = nullptr;         // desfaz o ciclo antes de liberar

    // ---- 9. Juntar ordenadas ----
    No* a = nullptr;
    No* b = nullptr;
    for (int x : {1, 4, 7}) inserirFim(a, x);
    for (int x : {2, 3, 8, 9}) inserirFim(b, x);
    No* c = juntarOrdenadas(a, b);
    imprimir(c);                // esperado: 1 2 3 4 7 8 9

    liberar(l1);
    liberar(l2);
    liberar(c);                 // a e b foram reaproveitados em c
}
