#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int main(){
    stack<int, vector<int>> sv;
    stack<int> sq;

    sv.push(5);
    sv.push(10);
    sq.push(10);
    cout << sv.top() << endl;
    cout << sq.top() << endl;
}