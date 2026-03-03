#include <iostream>
#include <string>
using namespace std;
string decToBin(int n) { string s=""; while(n) { s=(char)('0'+n%2)+s; n/=2; } return s.empty()?"0":s; }
int binToDec(string s) { int n=0; for(char c:s) n=n*2+(c-'0'); return n; }
bool isPowerOfTwo(int n) { return n>0&&(n&(n-1))==0; }
int countSetBits(int n) { int c=0; while(n) { n&=n-1; c++; } return c; }
long long fastPow(long long a, long long b) { long long r=1; while(b) { if(b&1) r*=a; a*=a; b>>=1; } return r; }
int main() { cout<<"13 to binary: "<<decToBin(13)<<endl; cout<<"1101 to decimal: "<<binToDec("1101")<<endl; cout<<"16 is power of 2: "<<isPowerOfTwo(16)<<endl; cout<<"Set bits in 13: "<<countSetBits(13)<<endl; cout<<"2^10: "<<fastPow(2,10)<<endl; return 0; }