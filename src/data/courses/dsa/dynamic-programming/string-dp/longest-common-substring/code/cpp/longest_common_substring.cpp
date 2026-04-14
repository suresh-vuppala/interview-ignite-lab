#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — Check all substrings — O(M*N*min(M,N))
// ============================================================
class Solution1 {
public:
    int longestCommonSubstring(string a, string b) {
        int res = 0;
        for (int i = 0; i < (int)a.size(); i++)
            for (int j = 0; j < (int)b.size(); j++) {
                int len = 0;
                while (i+len < (int)a.size() && j+len < (int)b.size() && a[i+len]==b[j+len]) len++;
                res = max(res, len);
            }
        return res;
    }
};

// ============================================================
// Solution 2: DP — 2D table — O(M*N) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int longestCommonSubstring(string a, string b) {
        int m = a.size(), n = b.size(), res = 0;
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= m; i++) {
            int prev = 0;
            for (int j = 1; j <= n; j++) {
                int tmp = dp[j];
                dp[j] = (a[i-1]==b[j-1]) ? prev+1 : 0;
                res = max(res, dp[j]);
                prev = tmp;
            }
        }
        return res;
    }
};
