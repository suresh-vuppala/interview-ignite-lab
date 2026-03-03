#include <iostream>
#include <cmath>
using namespace std;
int trailingZeros(int n) { int c=0; while(n) { n/=5; c+=n; } return c; }
pair<long long,long long> fibFast(int n) { if(n==0) return {0,1}; auto p=fibFast(n/2); long long c=p.first*(2*p.second-p.first); long long d=p.first*p.first+p.second*p.second; return (n&1)?make_pair(d,c+d):make_pair(c,d); }
bool isPerfectSquare(int n) { int s=sqrt(n); return s*s==n; }
int digitSquareSum(int n) { int s=0; while(n) { int d=n%10; s+=d*d; n/=10; } return s; }
bool isHappy(int n) { int s=n,f=n; do { s=digitSquareSum(s); f=digitSquareSum(digitSquareSum(f)); } while(s!=f&&f!=1); return f==1; }
int main() { cout<<"Trailing zeros in 100!: "<<trailingZeros(100)<<endl; cout<<"Fib(10): "<<fibFast(10).first<<endl; cout<<"16 is perfect square: "<<isPerfectSquare(16)<<endl; cout<<"19 is happy: "<<isHappy(19)<<endl; return 0; }