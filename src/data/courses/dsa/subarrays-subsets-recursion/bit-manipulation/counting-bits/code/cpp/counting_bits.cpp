#include <vector>
using namespace std;
// ============================================================
// Solution 1: Count bits for each number individually — O(N * 32)
// ============================================================
class Solution1 {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for (int i = 0; i <= n; i++) {
            int x = i, count = 0;
            while (x) { count += x & 1; x >>= 1; }
            res[i] = count;
        }
        return res;
    }
};

// ============================================================
// Solution 2: DP — dp[i] = dp[i >> 1] + (i & 1) — O(N)
// ============================================================
class Solution2 {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; i++)
            dp[i] = dp[i >> 1] + (i & 1); // Half the bits of i/2, plus last bit
        return dp; // O(N) — no inner loop!
    }
};
