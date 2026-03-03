#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int countDivisors(int n) { int c=0; for(int i=1;i*i<=n;i++) if(n%i==0) c+=i*i==n?1:2; return c; }
int sumDivisors(int n) { int s=0; for(int i=1;i*i<=n;i++) if(n%i==0) s+=i*i==n?i:i+n/i; return s; }
vector<int> allFactors(int n) { vector<int> f; for(int i=1;i*i<=n;i++) if(n%i==0) { f.push_back(i); if(i*i!=n) f.push_back(n/i); } sort(f.begin(),f.end()); return f; }
int main() { cout<<"Divisors of 36: "<<countDivisors(36)<<endl; cout<<"Sum of divisors of 36: "<<sumDivisors(36)<<endl; return 0; }