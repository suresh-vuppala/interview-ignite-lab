using namespace std;
// ============================================================
// Solution 1: Convert to string, manual addition (no + operator)
// ============================================================
class Solution1 {
public:
    int getSum(int a, int b) {
        // Simulate addition using repeated increment/decrement
        // Not practical — just for demonstration
        if (b == 0) return a;
        if (b > 0) { while (b-- > 0) a++; } // Increment a, b times
        else { while (b++ < 0) a--; }        // Decrement a, |b| times
        return a; // O(|b|) — very slow
    }
};

// ============================================================
// Solution 2: Bit manipulation — carry + XOR — O(32) = O(1)
// ============================================================
class Solution2 {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int carry = a & b;       // Bits where both are 1
            a = a ^ b;               // Sum without carry
            b = (unsigned)carry << 1; // Shift carry left
        }
        return a;
    }
};
