#include <string>
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^M) Time
// ============================================================
class Solution1 {
public:
    int solve(string& s, string& t, int i, int j) {
        if(j<0) return 1;
        if(i<0) return 0;
        int res = solve(s,t,i-1,j);
        if(s[i]==t[j]) res += solve(s,t,i-1,j-1);
        return res;
    }
    int numDistinct(string s, string t) { return solve(s,t,s.size()-1,t.size()-1); }
};

// ============================================================
// Solution 2: DP — 1D bottom-up — O(M*N) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    int numDistinct(string s, string t) {
        int m=s.size(), n=t.size();
        vector<long> dp(n+1, 0); dp[0]=1;
        for(int i=1;i<=m;i++)
            for(int j=n;j>=1;j--)
                if(s[i-1]==t[j-1]) dp[j]+=dp[j-1];
        return dp[n];
    }
};
