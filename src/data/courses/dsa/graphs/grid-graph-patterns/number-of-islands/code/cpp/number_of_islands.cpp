#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: BFS flood fill — O(M*N) Time, O(min(M,N)) Space
// ============================================================
class Solution1 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), count = 0;
        int dirs[] = {0,1,0,-1,0};
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    count++;
                    queue<pair<int,int>> q;
                    q.push({i,j}); grid[i][j] = '0';
                    while (!q.empty()) {
                        auto [r,c] = q.front(); q.pop();
                        for (int d = 0; d < 4; d++) {
                            int nr=r+dirs[d], nc=c+dirs[d+1];
                            if (nr>=0&&nr<m&&nc>=0&&nc<n&&grid[nr][nc]=='1') {
                                grid[nr][nc]='0'; q.push({nr,nc});
                            }
                        }
                    }
                }
        return count;
    }
};

// ============================================================
// Solution 2: DFS flood fill — O(M*N) Time, O(M*N) Stack worst case
// ============================================================
class Solution2 {
    int m, n;
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i<0||i>=m||j<0||j>=n||grid[i][j]!='1') return;
        grid[i][j] = '0';
        dfs(grid,i+1,j); dfs(grid,i-1,j); dfs(grid,i,j+1); dfs(grid,i,j-1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(); n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') { count++; dfs(grid,i,j); }
        return count;
    }
};
