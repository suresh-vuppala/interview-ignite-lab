#include <vector>
using namespace std;
// ============================================================
// Solution 1: Direct formula computation — various patterns
// ============================================================
class Solution1 {
public:
    // Catalan numbers: C(n) = C(2n,n)/(n+1) — recursive
    long long catalan(int n) {
        if (n <= 1) return 1;
        long long res = 0;
        for (int i = 0; i < n; i++) res += catalan(i) * catalan(n - 1 - i);
        return res; // O(2^N) without memoization!
    }
    // Fibonacci — naive recursion
    long long fib(int n) {
        if (n <= 1) return n;
        return fib(n - 1) + fib(n - 2); // O(2^N)
    }
};

// ============================================================
// Solution 2: DP / Matrix exponentiation — O(N) or O(log N)
// ============================================================
class Solution2 {
    static const long long MOD = 1e9 + 7;
public:
    // Catalan DP — O(N²)
    long long catalan(int n) {
        vector<long long> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++)
            for (int j = 0; j < i; j++)
                dp[i] = (dp[i] + dp[j] * dp[i - 1 - j]) % MOD;
        return dp[n];
    }
    // Fibonacci DP — O(N)
    long long fib(int n) {
        if (n <= 1) return n;
        long long a = 0, b = 1;
        for (int i = 2; i <= n; i++) { long long c = (a + b) % MOD; a = b; b = c; }
        return b;
    }
    // Fast power: a^n mod m — O(log N)
    long long power(long long base, long long exp, long long mod) {
        long long r = 1; base %= mod;
        while (exp > 0) { if (exp & 1) r = r * base % mod; base = base * base % mod; exp >>= 1; }
        return r;
    }
};
