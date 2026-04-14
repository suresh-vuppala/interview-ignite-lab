#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^(M+N)) Time
// ============================================================
class Solution1 {
public:
    int lcs(string& a, string& b, int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (a[i] == b[j]) return 1 + lcs(a, b, i-1, j-1);
        return max(lcs(a, b, i-1, j), lcs(a, b, i, j-1));
    }
    int longestCommonSubsequence(string a, string b) { return lcs(a, b, a.size()-1, b.size()-1); }
};

// ============================================================
// Solution 2: DP — 1D space optimization — O(M*N) Time, O(min(M,N)) Space
// ============================================================
class Solution2 {
public:
    int longestCommonSubsequence(string a, string b) {
        if (a.size() < b.size()) swap(a, b);
        int m = a.size(), n = b.size();
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= m; i++) {
            int prev = 0;
            for (int j = 1; j <= n; j++) {
                int tmp = dp[j];
                dp[j] = (a[i-1]==b[j-1]) ? prev+1 : max(dp[j], dp[j-1]);
                prev = tmp;
            }
        }
        return dp[n];
    }
};
