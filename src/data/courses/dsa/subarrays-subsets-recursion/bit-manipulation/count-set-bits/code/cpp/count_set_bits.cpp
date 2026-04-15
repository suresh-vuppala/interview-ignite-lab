using namespace std;
// ============================================================
// Solution 1: Loop through all bits — O(32) = O(1)
// ============================================================
class Solution1 {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n > 0) { count += n & 1; n >>= 1; }
        return count;
    }
};

// ============================================================
// Solution 2: Brian Kernighan's — O(number of set bits)
// ============================================================
class Solution2 {
public:
    int countSetBits(int n) {
        int count = 0;
        while (n) { n &= (n - 1); count++; } // Clears lowest set bit each iteration
        return count; // Only loops as many times as there are set bits!
    }
};
