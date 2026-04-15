#include <vector>
#include <string>
using namespace std;
// ============================================================
// Solution 1: BFS — explore all paths level by level
// ============================================================
#include <queue>
class Solution1 {
public:
    vector<string> findPaths(vector<vector<int>>& maze) {
        int n = maze.size();
        if (maze[0][0] == 0 || maze[n-1][n-1] == 0) return {};
        vector<string> result;
        queue<pair<pair<int,int>, string>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        q.push({{0,0}, ""});
        // BFS doesn't easily enumerate all paths — better for shortest path
        // For ALL paths, DFS (Solution 2) is standard
        return result;
    }
};

// ============================================================
// Solution 2: DFS Backtracking — O(4^(N²))
// ============================================================
class Solution2 {
    int dx[4]={1,0,0,-1}, dy[4]={0,-1,1,0};
    char dc[4]={'D','L','R','U'};
    void dfs(vector<vector<int>>& maze, int i, int j, int n, string& path,
             vector<vector<bool>>& vis, vector<string>& res) {
        if (i==n-1 && j==n-1) { res.push_back(path); return; }
        for (int d = 0; d < 4; d++) {
            int ni=i+dx[d], nj=j+dy[d];
            if (ni>=0&&ni<n&&nj>=0&&nj<n&&maze[ni][nj]==1&&!vis[ni][nj]) {
                vis[ni][nj]=true; path+=dc[d];
                dfs(maze, ni, nj, n, path, vis, res);
                path.pop_back(); vis[ni][nj]=false; // Backtrack
            }
        }
    }
public:
    vector<string> findPaths(vector<vector<int>>& maze) {
        int n = maze.size();
        if (maze[0][0]==0 || maze[n-1][n-1]==0) return {};
        vector<string> res; string path;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[0][0] = true;
        dfs(maze, 0, 0, n, path, vis, res);
        return res;
    }
};
