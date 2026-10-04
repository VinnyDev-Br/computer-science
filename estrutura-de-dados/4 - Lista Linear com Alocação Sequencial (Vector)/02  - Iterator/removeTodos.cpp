    /*• Dado um vector de inteiros e um valor x, remova todas as ocorrências de
    x usando a função erase do vector.
    Exemplo:
    Entrada: v = {3, 5, 3, 3, 7, 3}, x = 3
    Saı́da: {5, 7}
    O protótipo da função deve ser:
    void removeTodos(std::vector<int>& v, int x);*/

    #include <iostream>
    #include <vector>
    using namespace std;

    void removeTodos(vector<int> &v, int x){
        for (auto it = v.begin(); it != v.end();){
            if (*it == x){
                v.erase(it);
            }
            else {it++;}
        }
    }

    int main(){
        vector <int> v {3, 5, 3, 3, 7, 3};
        int x = 3;
        

        removeTodos(v, x);

        for (int i = 0; i  < v.size(); i++){
            cout << v[i] << " ";
        }
        return 0;
    }
