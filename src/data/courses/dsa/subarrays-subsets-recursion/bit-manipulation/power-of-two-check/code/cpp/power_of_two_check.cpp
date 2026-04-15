using namespace std;
// ============================================================
// Solution 1: Divide by 2 repeatedly — O(log N)
// ============================================================
class Solution1 {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        while (n > 1) { if (n % 2 != 0) return false; n /= 2; }
        return true;
    }
};

// ============================================================
// Solution 2: Bit trick — n & (n-1) == 0 — O(1)
// ============================================================
class Solution2 {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
        // Power of 2 has exactly one set bit: 1000...0
        // n-1 flips all bits after: 0111...1
        // AND gives 0 only for powers of 2
    }
};
