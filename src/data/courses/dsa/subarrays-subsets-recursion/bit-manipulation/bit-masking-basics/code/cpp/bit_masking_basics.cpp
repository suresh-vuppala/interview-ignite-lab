using namespace std;
// ============================================================
// Solution 1: Arithmetic approach — division/modulo
// ============================================================
class Solution1 {
public:
    int getBit(int n, int k) { return (n / (1 << k)) % 2; }
    int setBit(int n, int k) { if (getBit(n,k)==0) n += (1<<k); return n; }
    int clearBit(int n, int k) { if (getBit(n,k)==1) n -= (1<<k); return n; }
};

// ============================================================
// Solution 2: Bitwise operators — O(1) each
// ============================================================
class Solution2 {
public:
    int getBit(int n, int k) { return (n >> k) & 1; }
    int setBit(int n, int k) { return n | (1 << k); }
    int clearBit(int n, int k) { return n & ~(1 << k); }
    int toggleBit(int n, int k) { return n ^ (1 << k); }
    int clearLSB(int n) { return n & (n - 1); } // Clear lowest set bit
    int isolateLSB(int n) { return n & (-n); }   // Get lowest set bit
};
