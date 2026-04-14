#include <vector>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^(M+N)) Time
// ============================================================
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
};

// ============================================================
// Solution 2: DP — 1D array — O(M*N) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[j] += dp[j-1];
        return dp[n-1];
    }
};
