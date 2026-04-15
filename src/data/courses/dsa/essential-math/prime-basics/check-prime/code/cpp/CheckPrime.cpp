#include <cmath>
using namespace std;
// ============================================================
// Solution 1: Check all divisors from 2 to N-1 — O(N)
// ============================================================
class Solution1 {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i < n; i++)
            if (n % i == 0) return false;
        return true;
    }
};

// ============================================================
// Solution 2: Check up to √N with 6k±1 optimization — O(√N)
// ============================================================
class Solution2 {
public:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; (long long)i * i <= n; i += 6) // 6k±1 pattern
            if (n % i == 0 || n % (i + 2) == 0) return false;
        return true;
    }
};
