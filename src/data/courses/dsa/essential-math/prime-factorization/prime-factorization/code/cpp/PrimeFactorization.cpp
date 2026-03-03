#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> factorize(int n) { vector<int> f; for(int i=2;i*i<=n;i++) while(n%i==0) { f.push_back(i); n/=i; } if(n>1) f.push_back(n); return f; }
int countDistinct(int n) { set<int> s; for(int i=2;i*i<=n;i++) { if(n%i==0) s.insert(i); while(n%i==0) n/=i; } if(n>1) s.insert(n); return s.size(); }
int countTotal(int n) { int c=0; for(int i=2;i*i<=n;i++) while(n%i==0) { c++; n/=i; } if(n>1) c++; return c; }
int main() { cout<<"Distinct factors of 60: "<<countDistinct(60)<<endl; cout<<"Total factors of 60: "<<countTotal(60)<<endl; return 0; }