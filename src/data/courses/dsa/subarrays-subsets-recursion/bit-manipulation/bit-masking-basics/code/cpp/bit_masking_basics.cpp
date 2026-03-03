#include <iostream>
using namespace std;

void basics() {
    int a = 5, b = 3;
    cout << (a & b) << endl;  // AND
    cout << (a | b) << endl;  // OR
    cout << (a ^ b) << endl;  // XOR
    cout << (~a) << endl;     // NOT
    cout << (a << 1) << endl; // Left shift
    cout << (a >> 1) << endl; // Right shift
}