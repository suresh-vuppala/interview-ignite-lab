#include <iostream>
#include <vector>
using namespace std;
vector<bool> sieve(int n) { vector<bool> p(n+1,true); p[0]=p[1]=false; for(int i=2;i*i<=n;i++) if(p[i]) for(int j=i*i;j<=n;j+=i) p[j]=false; return p; }
int countPrimes(int n) { auto p=sieve(n); int c=0; for(bool b:p) if(b) c++; return c; }
vector<int> spfArray(int n) { vector<int> spf(n+1); for(int i=0;i<=n;i++) spf[i]=i; for(int i=2;i*i<=n;i++) if(spf[i]==i) for(int j=i*i;j<=n;j+=i) if(spf[j]==j) spf[j]=i; return spf; }
int main() { cout<<"Primes up to 30: "<<countPrimes(30)<<endl; return 0; }