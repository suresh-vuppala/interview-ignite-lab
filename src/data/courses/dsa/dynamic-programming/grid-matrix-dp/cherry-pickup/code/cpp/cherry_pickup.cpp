#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(n,-1)));
        dp[0][0][0]=grid[0][0];
        for(int r1=0;r1<n;r1++) for(int c1=0;c1<n;c1++) for(int r2=0;r2<n;r2++){
            int c2=r1+c1-r2;
            if(c2<0||c2>=n||grid[r1][c1]==-1||grid[r2][c2]==-1) continue;
            int val=grid[r1][c1]; if(r1!=r2) val+=grid[r2][c2];
            int best=-1;
            for(auto [pr1,pc1]:vector<pair<int,int>>{{r1-1,c1},{r1,c1-1}})
                for(auto [pr2,pc2]:vector<pair<int,int>>{{r2-1,c2},{r2,c2-1}})
                    if(pr1>=0&&pc1>=0&&pr2>=0&&pc2>=0&&dp[pr1][pc1][pr2]>=0)
                        best=max(best,dp[pr1][pc1][pr2]);
            if(best>=0||(!r1&&!c1&&!r2)) dp[r1][c1][r2]=val+max(0,best);
        }
        return max(0,dp[n-1][n-1][n-1]);
    }
};