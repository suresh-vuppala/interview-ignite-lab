#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: DFS — parent tracking — O(V+E) Time
// ============================================================
class Solution1 {
    bool dfs(vector<vector<int>>& adj, int u, int parent, vector<bool>& vis) {
        vis[u] = true;
        for (int v : adj[u]) {
            if (!vis[v]) { if (dfs(adj, v, u, vis)) return true; }
            else if (v != parent) return true;  // Back edge = cycle!
        }
        return false;
    }
public:
    bool hasCycle(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
            if (!vis[i] && dfs(adj, i, -1, vis)) return true;
        return false;
    }
};

// ============================================================
// Solution 2: BFS — parent tracking — O(V+E) Time
// ============================================================
class Solution2 {
public:
    bool hasCycle(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        for (int start = 0; start < V; start++) {
            if (vis[start]) continue;
            queue<pair<int,int>> q; // {node, parent}
            q.push({start, -1}); vis[start] = true;
            while (!q.empty()) {
                auto [u, par] = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (!vis[v]) { vis[v] = true; q.push({v, u}); }
                    else if (v != par) return true;
                }
            }
        }
        return false;
    }
};
