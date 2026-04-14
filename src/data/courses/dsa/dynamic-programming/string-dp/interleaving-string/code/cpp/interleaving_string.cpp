#include <string>
#include <vector>
using namespace std;
// ============================================================
// Solution 1: Recursion — O(2^(M+N)) Time
// ============================================================
class Solution1 {
public:
    bool solve(string& s1, string& s2, string& s3, int i, int j) {
        int k=i+j;
        if(k==(int)s3.size()) return i==(int)s1.size()&&j==(int)s2.size();
        bool res=false;
        if(i<(int)s1.size()&&s1[i]==s3[k]) res=solve(s1,s2,s3,i+1,j);
        if(!res&&j<(int)s2.size()&&s2[j]==s3[k]) res=solve(s1,s2,s3,i,j+1);
        return res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size()) return false;
        return solve(s1,s2,s3,0,0);
    }
};

// ============================================================
// Solution 2: DP — 1D bottom-up — O(M*N) Time, O(N) Space
// ============================================================
class Solution2 {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m=s1.size(), n=s2.size();
        if(m+n!=(int)s3.size()) return false;
        vector<bool> dp(n+1,false); dp[0]=true;
        for(int j=1;j<=n;j++) dp[j]=dp[j-1]&&s2[j-1]==s3[j-1];
        for(int i=1;i<=m;i++) {
            dp[0]=dp[0]&&s1[i-1]==s3[i-1];
            for(int j=1;j<=n;j++)
                dp[j]=(dp[j]&&s1[i-1]==s3[i+j-1])||(dp[j-1]&&s2[j-1]==s3[i+j-1]);
        }
        return dp[n];
    }
};
