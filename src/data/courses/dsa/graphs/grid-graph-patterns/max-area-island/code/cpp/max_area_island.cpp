#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: BFS — count cells per island — O(M*N)
// ============================================================
class Solution1 {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size(), maxA=0;
        int dirs[]={0,1,0,-1,0};
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(grid[i][j]==1) {
            int area=0;
            queue<pair<int,int>> q; q.push({i,j}); grid[i][j]=0;
            while(!q.empty()) {
                auto [r,c]=q.front(); q.pop(); area++;
                for(int d=0;d<4;d++) {
                    int nr=r+dirs[d],nc=c+dirs[d+1];
                    if(nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]==1) { grid[nr][nc]=0; q.push({nr,nc}); }
                }
            }
            maxA=max(maxA,area);
        }
        return maxA;
    }
};

// ============================================================
// Solution 2: DFS — recursive flood fill — O(M*N)
// ============================================================
class Solution2 {
    int dfs(vector<vector<int>>& g, int i, int j) {
        if(i<0||i>=(int)g.size()||j<0||j>=(int)g[0].size()||g[i][j]!=1) return 0;
        g[i][j]=0;
        return 1+dfs(g,i+1,j)+dfs(g,i-1,j)+dfs(g,i,j+1)+dfs(g,i,j-1);
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        for(int i=0;i<(int)grid.size();i++)
            for(int j=0;j<(int)grid[0].size();j++)
                if(grid[i][j]==1) res=max(res,dfs(grid,i,j));
        return res;
    }
};
