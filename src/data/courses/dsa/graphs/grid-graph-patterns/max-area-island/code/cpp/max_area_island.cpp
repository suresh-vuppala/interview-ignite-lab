// ============================================================
// Max Area of Island
// ============================================================
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), maxArea = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) maxArea = max(maxArea, dfs(grid, i, j));
        return maxArea;
    }
    int dfs(vector<vector<int>>& g, int i, int j) {
        if (i<0||i>=(int)g.size()||j<0||j>=(int)g[0].size()||g[i][j]==0) return 0;
        g[i][j] = 0; // Sink
        return 1 + dfs(g,i+1,j) + dfs(g,i-1,j) + dfs(g,i,j+1) + dfs(g,i,j-1);
    }
};
