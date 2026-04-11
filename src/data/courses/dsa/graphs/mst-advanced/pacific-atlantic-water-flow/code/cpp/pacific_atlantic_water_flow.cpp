class Solution {
public:
    // O(m*n) — BFS/DFS from both oceans, find intersection
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n)), atl(m, vector<bool>(n));
        
        // BFS from Pacific edges (top + left) and Atlantic edges (bottom + right)
        for (int i = 0; i < m; i++) { dfs(heights, pac, i, 0); dfs(heights, atl, i, n-1); }
        for (int j = 0; j < n; j++) { dfs(heights, pac, 0, j); dfs(heights, atl, m-1, j); }
        
        vector<vector<int>> result;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (pac[i][j] && atl[i][j]) result.push_back({i, j});
        return result;
    }
    
    void dfs(vector<vector<int>>& h, vector<vector<bool>>& vis, int i, int j) {
        vis[i][j] = true;
        int dirs[] = {0,1,0,-1,0};
        for (int d = 0; d < 4; d++) {
            int ni = i+dirs[d], nj = j+dirs[d+1];
            if (ni>=0 && ni<h.size() && nj>=0 && nj<h[0].size() && !vis[ni][nj] && h[ni][nj]>=h[i][j])
                dfs(h, vis, ni, nj);
        }
    }
};