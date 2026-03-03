#include <iostream>
#include <set>
using namespace std;
int mex(set<int>& s) { int m=0; while(s.count(m)) m++; return m; }
int grundy(int n, int moves[], int sz) { if(n==0) return 0; set<int> s; for(int i=0;i<sz;i++) if(n>=moves[i]) s.insert(grundy(n-moves[i],moves,sz)); return mex(s); }
int main() { int moves[]={1,2,3}; cout<<"Grundy(5): "<<grundy(5,moves,3)<<endl; return 0; }