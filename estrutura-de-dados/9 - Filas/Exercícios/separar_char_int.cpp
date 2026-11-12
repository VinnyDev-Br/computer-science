#include <queue>
#include <stack>
#include <iostream>
#include<string>
using namespace std;

int main(){
    stack<char> p;
    queue<char> f;
    string caracteres = "A1E5T7W8G";

    for (int i = 0; i < (int)caracteres.size(); i++){
        if (isdigit(caracteres[i])){
            p.push(caracteres[i]);
        }
        else{
            f.push(caracteres[i]);
        }
    }

    while (!f.empty()){
        cout << f.front();
        f.pop();
    }

    while(!p.empty()){
        cout << p.top();
        p.pop();
    }
}