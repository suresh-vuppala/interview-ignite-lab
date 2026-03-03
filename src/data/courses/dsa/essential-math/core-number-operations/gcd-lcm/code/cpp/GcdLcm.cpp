#include <iostream>
using namespace std;
int gcd(int a, int b) { return b?gcd(b,a%b):a; }
long long lcm(int a, int b) { return (long long)a*b/gcd(a,b); }
bool coprime(int a, int b) { return gcd(a,b)==1; }
int main() { cout<<"GCD(12,18): "<<gcd(12,18)<<endl; cout<<"LCM(12,18): "<<lcm(12,18)<<endl; return 0; }