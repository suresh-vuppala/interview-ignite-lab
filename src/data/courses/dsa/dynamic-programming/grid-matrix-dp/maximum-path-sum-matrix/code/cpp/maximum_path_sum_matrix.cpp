#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int maxPathSum(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int> dp=mat[0];
        for (int i=1;i<m;i++){
            vector<int> ndp(n);
            for(int j=0;j<n;j++){
                int best=dp[j];
                if(j>0) best=max(best,dp[j-1]);
                if(j<n-1) best=max(best,dp[j+1]);
                ndp[j]=mat[i][j]+best;
            }
            dp=ndp;
        }
        return *max_element(dp.begin(),dp.end());
    }
};