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
        if(p[j]=='*') return solve(s,p,i,j+1) || (i<(int)s.size()&&solve(s,p,i+1,j));
        if(i<(int)s.size()&&(p[j]=='?'||s[i]==p[j])) return solve(s,p,i+1,j+1);
        return false;
    }
    bool isMatch(string s, string p) { return solve(s,p,0,0); }
};

// ============================================================
// Solution 2: DP — 1D bottom-up — O(M*N) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        vector<bool> dp(n+1,false); dp[0]=true;
        for(int j=1;j<=n;j++) if(p[j-1]=='*') dp[j]=dp[j-1];
        for(int i=1;i<=m;i++) {
            bool prev=dp[0]; dp[0]=false;
            for(int j=1;j<=n;j++) {
                bool tmp=dp[j];
                if(p[j-1]=='*') dp[j]=dp[j]||dp[j-1];
                else if(p[j-1]=='?'||s[i-1]==p[j-1]) dp[j]=prev;
                else dp[j]=false;
                prev=tmp;
            }
        }
        return dp[n];
    }
};
