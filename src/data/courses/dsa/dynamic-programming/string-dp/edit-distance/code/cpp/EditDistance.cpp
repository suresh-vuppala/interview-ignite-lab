#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(3^(M+N)) Time
// ============================================================
class Solution1 {
public:
    int solve(string& a, string& b, int i, int j) {
        if (i < 0) return j+1;
        if (j < 0) return i+1;
        if (a[i] == b[j]) return solve(a, b, i-1, j-1);
        return 1 + min({solve(a,b,i-1,j), solve(a,b,i,j-1), solve(a,b,i-1,j-1)});
    }
    int minDistance(string a, string b) { return solve(a, b, a.size()-1, b.size()-1); }
};

// ============================================================
// Solution 2: DP — Bottom-up 2D — O(M*N) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int minDistance(string a, string b) {
        int m = a.size(), n = b.size();
        vector<int> dp(n+1);
        for (int j = 0; j <= n; j++) dp[j] = j;
        for (int i = 1; i <= m; i++) {
            int prev = dp[0]; dp[0] = i;
            for (int j = 1; j <= n; j++) {
                int tmp = dp[j];
                if (a[i-1]==b[j-1]) dp[j] = prev;
                else dp[j] = 1 + min({prev, dp[j], dp[j-1]});
                prev = tmp;
            }
        }
        return dp[n];
    }
};
