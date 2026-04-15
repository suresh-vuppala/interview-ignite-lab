using namespace std;
// ============================================================
// Solution 1: String conversion — check character at position
// ============================================================
#include <string>
#include <algorithm>
class Solution1 {
public:
    bool isBitSet(int n, int k) {
        string bin; while(n>0){bin+=(n%2)+'0';n/=2;}
        return k<(int)bin.size() && bin[k]=='1';
    }
};

// ============================================================
// Solution 2: Bitwise — O(1)
// ============================================================
class Solution2 {
public:
    bool isBitSet(int n, int k) { return (n >> k) & 1; }
    int setBit(int n, int k) { return n | (1 << k); }
    int unsetBit(int n, int k) { return n & ~(1 << k); }
    int toggleBit(int n, int k) { return n ^ (1 << k); }
};
