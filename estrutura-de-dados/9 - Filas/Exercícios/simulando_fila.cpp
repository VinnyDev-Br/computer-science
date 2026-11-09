#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<int> fila;
    std::string cmd;

    while (std::cin >> cmd) {
        if (cmd == "E"){
            int x;
            std::cin >> x;
            fila.push(x);
        }
        else if (cmd == "D"){
            if (fila.empty()){
                std::cout << "vazia" << "\n";
            }
            else{
                std::cout << fila.front() << "\n";
                fila.pop();
            }
        }
        else if(cmd == "T"){
            std::cout << fila.size() << "\n";
        }
    }

    return 0;
}