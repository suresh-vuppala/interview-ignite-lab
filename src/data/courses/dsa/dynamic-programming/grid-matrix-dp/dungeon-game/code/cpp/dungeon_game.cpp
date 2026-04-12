#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int m=d.size(),n=d[0].size();
        vector<int> dp(n+1,INT_MAX); dp[n-1]=1;
        for(int i=m-1;i>=0;i--){
            vector<int> ndp(n+1,INT_MAX);
            for(int j=n-1;j>=0;j--)
                ndp[j]=max(1,min(dp[j],ndp[j+1])-d[i][j]);
            dp=ndp;
        }
        return dp[0];
    }
};