#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestCommonSubstring(string s1, string s2) {
        int m=s1.size(),n=s2.size(),maxLen=0;
        vector<int> dp(n+1,0);
        for(int i=1;i<=m;i++){
            vector<int> ndp(n+1,0);
            for(int j=1;j<=n;j++){
                ndp[j]=s1[i-1]==s2[j-1]?dp[j-1]+1:0;
                maxLen=max(maxLen,ndp[j]);
            }
            dp=ndp;
        }
        return maxLen;
    }
};