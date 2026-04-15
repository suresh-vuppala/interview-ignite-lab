#include <vector>
#include <string>
using namespace std;
// ============================================================
// Solution 1: Try all partitions, check each substring — O(N * 2^N)
// ============================================================
class Solution1 {
    bool isPalin(string& s, int l, int r) { while (l<r) if (s[l++]!=s[r--]) return false; return true; }
    void bt(string& s, int start, vector<string>& cur, vector<vector<string>>& res) {
        if (start == (int)s.size()) { res.push_back(cur); return; }
        for (int end = start; end < (int)s.size(); end++) {
            string sub = s.substr(start, end - start + 1);
            // Check palindrome AFTER generating substring
            if (isPalin(s, start, end)) {
                cur.push_back(sub);
                bt(s, end + 1, cur, res);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res; vector<string> cur;
        bt(s, 0, cur, res); return res;
    }
};

// ============================================================
// Solution 2: Precompute palindrome table + backtrack — O(N * 2^N)
// ============================================================
class Solution2 {
    void bt(string& s, int start, vector<vector<bool>>& dp, vector<string>& cur, vector<vector<string>>& res) {
        if (start == (int)s.size()) { res.push_back(cur); return; }
        for (int end = start; end < (int)s.size(); end++) {
            if (dp[start][end]) { // O(1) palindrome check!
                cur.push_back(s.substr(start, end - start + 1));
                bt(s, end + 1, dp, cur, res);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n-1; i >= 0; i--)
            for (int j = i; j < n; j++)
                dp[i][j] = (s[i]==s[j]) && (j-i < 3 || dp[i+1][j-1]);
        vector<vector<string>> res; vector<string> cur;
        bt(s, 0, dp, cur, res); return res;
    }
};
