#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r(s.rbegin(),s.rend());
        int n=s.size(); vector<int> dp(n+1,0);
        for(int i=1;i<=n;i++){int prev=0;
            for(int j=1;j<=n;j++){int t=dp[j];dp[j]=s[i-1]==r[j-1]?prev+1:max(dp[j],dp[j-1]);prev=t;}}
        return dp[n];
    }
};