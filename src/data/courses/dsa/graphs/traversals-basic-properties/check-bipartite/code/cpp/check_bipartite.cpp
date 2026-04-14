#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: DFS — 2-coloring — O(V+E) Time
// ============================================================
class Solution1 {
    bool dfs(vector<vector<int>>& adj, int u, vector<int>& color, int c) {
        color[u] = c;
        for (int v : adj[u]) {
            if (color[v] == -1) { if (!dfs(adj, v, color, 1-c)) return false; }
            else if (color[v] == c) return false;  // Same color = not bipartite
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);
        for (int i = 0; i < V; i++)
            if (color[i] == -1 && !dfs(adj, i, color, 0)) return false;
        return true;
    }
};

// ============================================================
// Solution 2: BFS — 2-coloring — O(V+E) Time
// ============================================================
class Solution2 {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> color(V, -1);
        for (int start = 0; start < V; start++) {
            if (color[start] != -1) continue;
            queue<int> q; q.push(start); color[start] = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v : adj[u]) {
                    if (color[v] == -1) { color[v] = 1 - color[u]; q.push(v); }
                    else if (color[v] == color[u]) return false;
                }
            }
        }
        return true;
    }
};
