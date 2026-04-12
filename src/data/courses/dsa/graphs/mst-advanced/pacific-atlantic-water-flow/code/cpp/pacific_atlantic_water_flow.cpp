// ============================================================
// Pacific Atlantic Water Flow
// ============================================================
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        // DFS from Pacific border (top + left)
        for (int i = 0; i < m; i++) { dfs(heights, pac, i, 0); dfs(heights, atl, i, n-1); }
        for (int j = 0; j < n; j++) { dfs(heights, pac, 0, j); dfs(heights, atl, m-1, j); }

        // Intersection
        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j]) result.push_back({i, j});
        return result;
    }
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& visited, int i, int j) {
        visited[i][j] = true;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto& d : dirs) {
            int ni = i+d[0], nj = j+d[1];
            if (ni>=0 && ni<(int)h.size() && nj>=0 && nj<(int)h[0].size()
                && !visited[ni][nj] && h[ni][nj] >= h[i][j]) // Uphill (reverse flow)
                dfs(h, visited, ni, nj);
        }
    }
};
