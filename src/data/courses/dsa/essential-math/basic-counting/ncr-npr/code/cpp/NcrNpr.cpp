#include <vector>
using namespace std;
// ============================================================
// Solution 1: Direct formula with factorial — O(N), overflow risk
// ============================================================
class Solution1 {
public:
    long long factorial(int n) { long long r = 1; for (int i = 2; i <= n; i++) r *= i; return r; }
    long long nCr(int n, int r) {
        if (r > n) return 0;
        return factorial(n) / (factorial(r) * factorial(n - r)); // Overflow for large N!
    }
    long long nPr(int n, int r) {
        if (r > n) return 0;
        return factorial(n) / factorial(n - r);
    }
};

// ============================================================
// Solution 2: Pascal's Triangle / Multiplicative formula + modular — O(R)
// ============================================================
class Solution2 {
    static const long long MOD = 1e9 + 7;
    long long power(long long base, long long exp, long long mod) {
        long long r = 1; base %= mod;
        while (exp > 0) { if (exp & 1) r = r * base % mod; base = base * base % mod; exp >>= 1; }
        return r;
    }
public:
    // Multiplicative formula: C(n,r) = n*(n-1)*...*(n-r+1) / r!
    long long nCr(int n, int r) {
        if (r > n) return 0;
        if (r > n - r) r = n - r; // Optimization: C(n,r) = C(n,n-r)
        long long num = 1, den = 1;
        for (int i = 0; i < r; i++) {
            num = num * ((n - i) % MOD) % MOD;
            den = den * ((i + 1) % MOD) % MOD;
        }
        return num % MOD * power(den, MOD - 2, MOD) % MOD; // Modular inverse
    }
    // C(n,r) via Pascal's triangle — O(N*R) but no overflow
    vector<vector<long long>> pascalTriangle(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; i++) { dp[i][0] = 1; for (int j = 1; j <= i; j++) dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD; }
        return dp;
    }
};
