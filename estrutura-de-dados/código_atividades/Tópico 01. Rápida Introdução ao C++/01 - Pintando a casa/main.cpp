#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


double area(double a, double b, double c){
    double area, p = 0;
    p = (a + b + c) / 2;
    area = sqrt(p * (p-a) * (p-b) * (p-c));
    return area;
    }

int main(int argc, char** argv) {
    double lado1 = 0;
    double lado2 = 0;
    double lado3 = 0;
    cin >> lado1 >> lado2 >> lado3;
    
    double resultado = area(lado1, lado2, lado3);
    
    cout << fixed << setprecision(2) << resultado << "\n";
    return 0;
}
  