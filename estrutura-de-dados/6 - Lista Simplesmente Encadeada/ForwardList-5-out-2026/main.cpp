#include <iostream>
#include "ForwardList.h"
using namespace std;

int main() {
    ForwardList lst; 

    lst.push_back(9);
    lst.push_back(10);

    lst.print();
    cout << lst.size() << endl;
    
    lst.pop_back();
    lst.print();
    
    return 0;
}