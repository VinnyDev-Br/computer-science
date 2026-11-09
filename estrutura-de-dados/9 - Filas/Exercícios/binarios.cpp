#include <iostream>
#include <queue>
#include <string>

int main() {
    int n;
    std::cin >> n;

    std::queue<std::string> fila;
    fila.push("1");

    for (int i = 0; i < n; i++) {
        std::string s = fila.front();
        fila.pop();
        std::cout << s << "\n";
        fila.push(s + "0");
        fila.push(s + "1");
    }

    return 0;
}