#include <iostream>
using namespace std;
long long extGcd(long long a, long long b, long long& x, long long& y) { if(b==0) { x=1; y=0; return a; } long long x1,y1; long long g=extGcd(b,a%b,x1,y1); x=y1; y=x1-a/b*y1; return g; }
long long modInvEuclid(long long a, long long m) { long long x,y; long long g=extGcd(a,m,x,y); return g==1?(x%m+m)%m:-1; }
long long pow(long long a, long long b, long long m) { long long r=1; a%=m; while(b) { if(b&1) r=(r*a)%m; a=(a*a)%m; b>>=1; } return r; }
long long modInvFermat(long long a, long long m) { return pow(a,m-2,m); }
int main() { long long MOD=1000000007; cout<<"Inverse of 3 mod "<<MOD<<": "<<modInvFermat(3,MOD)<<endl; return 0; }