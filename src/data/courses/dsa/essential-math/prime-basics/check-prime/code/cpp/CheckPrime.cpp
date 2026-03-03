#include <iostream>
using namespace std;
bool isPrime(int n) { if(n<2) return false; for(int i=2;i*i<=n;i++) if(n%i==0) return false; return true; }
int countPrimes(int n) { int c=0; for(int i=2;i<n;i++) if(isPrime(i)) c++; return c; }
int nthPrime(int n) { int c=0,num=2; while(c<n) { if(isPrime(num)) c++; if(c<n) num++; } return num; }
int main() { cout<<"17 is prime: "<<isPrime(17)<<endl; cout<<"Primes up to 20: "<<countPrimes(20)<<endl; cout<<"10th prime: "<<nthPrime(10)<<endl; return 0; }