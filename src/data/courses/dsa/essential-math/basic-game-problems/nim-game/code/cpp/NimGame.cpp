#include <iostream>
using namespace std;
bool nimGame(int piles[], int n) { int xor_sum=0; for(int i=0;i<n;i++) xor_sum^=piles[i]; return xor_sum!=0; }
bool canWinStones(int n) { return n%3!=0; }
int main() { int piles[]={3,4,5}; cout<<"Nim [3,4,5]: "<<nimGame(piles,3)<<endl; cout<<"Can win with 4 stones: "<<canWinStones(4)<<endl; return 0; }