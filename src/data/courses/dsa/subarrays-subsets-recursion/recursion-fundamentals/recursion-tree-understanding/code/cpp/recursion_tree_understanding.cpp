#include <iostream>
#include <string>
using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);
}

void printTree(int n, string indent = "") {
    cout << indent << "fib(" << n << ")" << endl;
    if (n > 1) {
        printTree(n-1, indent + "  ");
        printTree(n-2, indent + "  ");
    }
}