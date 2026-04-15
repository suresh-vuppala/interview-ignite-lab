using namespace std;
// ============================================================
// Solution 1: Build reversed number bit by bit — O(32)
// ============================================================
class Solution1 {
public:
    unsigned int reverseBits(unsigned int n) {
        unsigned int result = 0;
        for (int i = 0; i < 32; i++) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }
};

// ============================================================
// Solution 2: Divide and conquer — swap halves — O(1) with 5 ops
// ============================================================
class Solution2 {
public:
    unsigned int reverseBits(unsigned int n) {
        n = (n >> 16) | (n << 16);                           // Swap 16-bit halves
        n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8); // Swap 8-bit pairs
        n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4); // Swap 4-bit nibbles
        n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2); // Swap 2-bit pairs
        n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1); // Swap adjacent bits
        return n;
    }
};
