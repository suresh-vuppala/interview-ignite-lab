class Solution {
public:
    long long countDerangements(int n) {
        if (n == 1) return 0;
        if (n == 2) return 1;
        long long a = 0, b = 1, MOD = 1e9 + 7;
        for (int i = 3; i <= n; i++) {
            long long c = ((i - 1) * ((a + b) % MOD)) % MOD;
            a = b; b = c;
        }
        return b;
    }
};
