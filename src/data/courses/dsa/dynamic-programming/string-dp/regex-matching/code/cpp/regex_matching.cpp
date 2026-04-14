#include <string>
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^(M+N)) Time
// ============================================================
class Solution1 {
public:
    bool solve(string& s, string& p, int i, int j) {
        if(j==(int)p.size()) return i==(int)s.size();
        bool first = i<(int)s.size() && (p[j]=='.'||s[i]==p[j]);
        if(j+1<(int)p.size()&&p[j+1]=='*')
            return solve(s,p,i,j+2) || (first && solve(s,p,i+1,j));
        return first && solve(s,p,i+1,j+1);
    }
    bool isMatch(string s, string p) { return solve(s,p,0,0); }
};

// ============================================================
// Solution 2: DP — 2D bottom-up — O(M*N) Time
// ============================================================
class Solution2 {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false)); dp[0][0]=true;
        for(int j=2;j<=n;j++) if(p[j-1]=='*') dp[0][j]=dp[0][j-2];
        for(int i=1;i<=m;i++) for(int j=1;j<=n;j++) {
            if(p[j-1]=='*') {
                dp[i][j]=dp[i][j-2];
                if(p[j-2]=='.'||p[j-2]==s[i-1]) dp[i][j]=dp[i][j]||dp[i-1][j];
            } else if(p[j-1]=='.'||p[j-1]==s[i-1]) dp[i][j]=dp[i-1][j-1];
        }
        return dp[m][n];
    }
};
