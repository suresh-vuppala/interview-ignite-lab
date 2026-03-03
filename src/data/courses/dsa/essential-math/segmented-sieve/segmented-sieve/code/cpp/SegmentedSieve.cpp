#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> segmentedSieve(long long L, long long R) { int lim=sqrt(R); vector<bool> p(lim+1,true); p[0]=p[1]=false; for(int i=2;i*i<=lim;i++) if(p[i]) for(int j=i*i;j<=lim;j+=i) p[j]=false; vector<int> primes; for(int i=2;i<=lim;i++) if(p[i]) primes.push_back(i); vector<bool> seg(R-L+1,true); for(int prime:primes) { long long start=max((long long)prime*prime,(L+prime-1)/prime*prime); for(long long j=start;j<=R;j+=prime) seg[j-L]=false; } vector<int> res; for(long long i=L;i<=R;i++) if(seg[i-L]&&i>1) res.push_back(i); return res; }
int main() { auto r=segmentedSieve(10,30); cout<<"Primes in [10,30]: "; for(int p:r) cout<<p<<" "; cout<<endl; return 0; }