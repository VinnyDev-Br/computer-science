
#include <iostream>
#include <queue>
using namespace std;

queue<int> intercalar(queue<int> &l1, queue<int> &l2){
    queue<int> l3 = queue<int>();
    while (!l1.empty() || !l2.empty()){
        if (!l1.empty()){
            l3.push(l1.front());
            l1.pop();
        }

        if (!l2.empty()){
            l3.push(l2.front());
            l2.pop();
        }
    }
    return l3;
}