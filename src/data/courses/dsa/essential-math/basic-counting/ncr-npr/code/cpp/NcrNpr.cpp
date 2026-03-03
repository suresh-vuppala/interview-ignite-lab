#include <iostream>
#include <vector>
using namespace std;
long long nCr(int n, int r) { if(r>n-r) r=n-r; long long res=1; for(int i=0;i<r;i++) { res*=(n-i); res/=(i+1); } return res; }
long long nPr(int n, int r) { long long res=1; for(int i=0;i<r;i++) res*=(n-i); return res; }
vector<vector<long long>> pascal(int n) { vector<vector<long long>> c(n+1,vector<long long>(n+1)); for(int i=0;i<=n;i++) { c[i][0]=1; for(int j=1;j<=i;j++) c[i][j]=c[i-1][j-1]+c[i-1][j]; } return c; }
int main() { cout<<"C(5,2): "<<nCr(5,2)<<endl; cout<<"P(5,2): "<<nPr(5,2)<<endl; return 0; }