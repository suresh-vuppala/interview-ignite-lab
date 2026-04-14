#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — try all partition points — O(2^N)
// ============================================================
class Solution1 {
    bool isPalin(string& s, int l, int r) { while(l<r) if(s[l++]!=s[r--]) return false; return true; }
public:
    int solve(string& s, int i) {
        if(i>=(int)s.size()) return -1;
        int res=s.size();
        for(int j=i;j<(int)s.size();j++)
            if(isPalin(s,i,j)) res=min(res, 1+solve(s,j+1));
        return res;
    }
    int minCut(string s) { return solve(s,0); }
};

// ============================================================
// Solution 2: DP — precompute palindromes + 1D cut DP — O(N²)
// ============================================================
class Solution2 {
public:
    int minCut(string s) {
        int n=s.size();
        vector<vector<bool>> pal(n,vector<bool>(n,false));
        for(int i=n-1;i>=0;i--)
            for(int j=i;j<n;j++)
                pal[i][j]=(s[i]==s[j])&&(j-i<3||pal[i+1][j-1]);
        vector<int> dp(n,n);
        for(int i=0;i<n;i++) {
            if(pal[0][i]) dp[i]=0;
            else for(int j=1;j<=i;j++)
                if(pal[j][i]) dp[i]=min(dp[i],dp[j-1]+1);
        }
        return dp[n-1];
    }
};
