#include <iostream>
using namespace std;
const long long MOD=1000000007;
long long add(long long a, long long b) { return ((a%MOD)+(b%MOD))%MOD; }
long long sub(long long a, long long b) { return ((a%MOD)-(b%MOD)+MOD)%MOD; }
long long mul(long long a, long long b) { return ((a%MOD)*(b%MOD))%MOD; }
long long pow(long long a, long long b) { long long r=1; a%=MOD; while(b) { if(b&1) r=(r*a)%MOD; a=(a*a)%MOD; b>>=1; } return r; }
int main() { cout<<"(10+20)%MOD: "<<add(10,20)<<endl; cout<<"2^10%MOD: "<<pow(2,10)<<endl; return 0; }