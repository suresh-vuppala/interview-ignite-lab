#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int solve(string& s, int i, int j) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (s[i] == s[j]) return 2 + solve(s, i+1, j-1);
        return max(solve(s, i+1, j), solve(s, i, j-1));
    }
    int longestPalinSubseq(string s) { return solve(s, 0, s.size()-1); }
};

// ============================================================
// Solution 2: DP — LCS with reversed string — O(N²) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int longestPalinSubseq(string s) {
        string r(s.rbegin(), s.rend());
        int n = s.size();
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; i++) {
            int prev = 0;
            for (int j = 1; j <= n; j++) {
                int tmp = dp[j];
                dp[j] = (s[i-1]==r[j-1]) ? prev+1 : max(dp[j], dp[j-1]);
                prev = tmp;
            }
        }
        return dp[n];
    }
};
