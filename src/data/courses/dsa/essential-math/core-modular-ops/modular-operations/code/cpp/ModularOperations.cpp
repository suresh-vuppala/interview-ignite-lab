using namespace std;
// ============================================================
// Solution 1: Direct computation — risk of overflow
// ============================================================
class Solution1 {
public:
    int modAdd(int a, int b, int m) { return (a + b) % m; } // Overflow if a+b > INT_MAX!
    int modMul(int a, int b, int m) { return (a * b) % m; } // Overflow if a*b > INT_MAX!
    int modSub(int a, int b, int m) { return (a - b) % m; } // Negative result possible!
};

// ============================================================
// Solution 2: Safe modular arithmetic — handles overflow + negatives
// ============================================================
class Solution2 {
public:
    long long modAdd(long long a, long long b, long long m) {
        return ((a % m) + (b % m)) % m;
    }
    long long modMul(long long a, long long b, long long m) {
        return ((a % m) * (b % m)) % m; // Use long long to avoid overflow
    }
    long long modSub(long long a, long long b, long long m) {
        return ((a % m) - (b % m) + m) % m; // +m to handle negative
    }
    long long modPow(long long base, long long exp, long long m) {
        long long result = 1;
        base %= m;
        while (exp > 0) {
            if (exp & 1) result = result * base % m;
            base = base * base % m;
            exp >>= 1;
        }
        return result; // Fast exponentiation O(log exp)
    }
};
