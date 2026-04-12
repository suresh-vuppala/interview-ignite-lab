#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int m=t1.size(),n=t2.size();
        vector<int> dp(n+1,0);
        for(int i=1;i<=m;i++){
            int prev=0;
            for(int j=1;j<=n;j++){
                int temp=dp[j];
                dp[j]=t1[i-1]==t2[j-1]?prev+1:max(dp[j],dp[j-1]);
                prev=temp;
            }
        }
        return dp[n];
    }
};