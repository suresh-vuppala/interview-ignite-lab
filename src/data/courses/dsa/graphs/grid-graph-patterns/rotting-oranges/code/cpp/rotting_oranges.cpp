// ============================================================
// Rotting Oranges
// ============================================================
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), fresh = 0, minutes = 0;
        queue<pair<int,int>> q;
        // Enqueue all rotten, count fresh
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                if (grid[i][j] == 1) fresh++;
            }
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty() && fresh > 0) {
            int size = q.size(); minutes++;
            for (int k = 0; k < size; k++) {
                auto [r, c] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nr = r+d[0], nc = c+d[1];
                    if (nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1) {
                        grid[nr][nc] = 2; fresh--; q.push({nr, nc});
                    }
                }
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};
