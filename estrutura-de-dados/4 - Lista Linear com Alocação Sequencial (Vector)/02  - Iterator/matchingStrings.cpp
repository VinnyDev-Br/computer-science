#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> matchingStrings(const vector<string>& v_consulta, const vector<string>& v_busca) {
    vector<int> resultado;
    for (int i = 0; i < v_busca.size(); i++) {
        resultado.push_back(count(v_consulta.begin(), v_consulta.end(), v_busca[i]));
    }
    return resultado;
}

int main() {
    int tam_consulta;
    cin >> tam_consulta;

    vector<string> v_consulta(tam_consulta);
    for (int i = 0; i < tam_consulta; i++) {
        cin >> v_consulta[i];
    }

    int tam_busca;
    cin >> tam_busca;

    vector<string> v_busca(tam_busca);
    for (int i = 0; i < tam_busca; i++) {
        cin >> v_busca[i];
    }

    vector<int> res = matchingStrings(v_consulta, v_busca);

    for (int i = 0; i < res.size(); i++) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
    cout << endl;

    return 0;
}