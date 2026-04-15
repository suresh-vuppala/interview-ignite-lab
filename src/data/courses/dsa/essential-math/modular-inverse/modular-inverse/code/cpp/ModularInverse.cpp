using namespace std;
// ============================================================
// Solution 1: Brute Force — try all x from 1 to M-1 — O(M)
// ============================================================
class Solution1 {
public:
    int modInverse(int a, int m) {
        a %= m;
        for (int x = 1; x < m; x++)
            if ((long long)a * x % m == 1) return x;
        return -1; // No inverse exists (gcd(a,m) != 1)
    }
};

// ============================================================
// Solution 2: Fermat's Little Theorem (M prime) — O(log M)
// ============================================================
class Solution2 {
    long long power(long long base, long long exp, long long mod) {
        long long result = 1; base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }
public:
    // When M is prime: a^(-1) ≡ a^(M-2) (mod M)
    long long modInverse(long long a, long long m) {
        return power(a, m - 2, m); // O(log M) — requires M is prime!
    }
    // Extended Euclidean (works for any M where gcd(a,M)=1)
    long long modInverseExt(long long a, long long m) {
        long long g, x, y;
        // Extended GCD
        auto extGcd = [](auto self, long long a, long long b, long long& x, long long& y) -> long long {
            if (a == 0) { x = 0; y = 1; return b; }
            long long x1, y1;
            long long g = self(self, b % a, a, x1, y1);
            x = y1 - (b / a) * x1;
            y = x1;
            return g;
        };
        g = extGcd(extGcd, a, m, x, y);
        if (g != 1) return -1;
        return (x % m + m) % m;
    }
};
