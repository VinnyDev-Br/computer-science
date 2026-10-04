/*•   Leia números um a um e mantenha o vector sempre ordenado, inserindo
        cada novo número na posição correta com a função insert do vector. 
        Ao  final, imprima o vector.
        Funções: insert, begin, size
        O protótipo das funções devem ser:
        void inserirOrdenado(std::vector& v);
        void imprimirVector(std::vector& v);    
*/

    #include <iostream>
    #include <vector>
    using namespace std;

    void inserirOrdenado(vector<int> &v){
        int n;
        cin >> n;

        auto it = v.begin();
        while (it != v.end() && *it < n){
            it++;
        }

        v.insert(it, n);
    }

    void imprimirVector(vector<int> const &v){        
        auto it = v.begin();
        for (it; it != v.end(); it++){
            cout << *it << " ";
        }
    }

    int main(){
        vector <int> v;
        int qtd;
        cout << "Qual o tamanho do vetor: " << endl;
        cin >> qtd;

        for (int i = 0; i < qtd; i++){
            inserirOrdenado(v);
        }

        imprimirVector(v);


        return 0;
    }
