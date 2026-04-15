#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: DFS — 3-color marking — O(V+E) Time
// ============================================================
class Solution1 {
    bool dfs(vector<vector<int>>& adj, int u, vector<int>& color) {
        color[u] = 1; // Gray — in current path
        for (int v : adj[u]) {
            if (color[v] == 1) return true;  // Back edge = cycle!
            if (color[v] == 0 && dfs(adj, v, color)) return true;
        }
        color[u] = 2; // Black — fully processed
        return false;
    }
public:
    bool hasCycle(int V, vector<vector<int>>& adj) {
        vector<int> color(V, 0); // 0=white, 1=gray, 2=black
        for (int i = 0; i < V; i++)
            if (color[i] == 0 && dfs(adj, i, color)) return true;
        return false;
    }
};

// ============================================================
// Solution 2: Kahn's BFS — if topo sort incomplete → cycle — O(V+E)
// ============================================================
class Solution2 {
public:
    bool hasCycle(int V, vector<vector<int>>& adj) {
        vector<int> inDeg(V, 0);
        for (int u = 0; u < V; u++) for (int v : adj[u]) inDeg[v]++;
        queue<int> q;
        for (int i = 0; i < V; i++) if (inDeg[i] == 0) q.push(i);
        int count = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop(); count++;
            for (int v : adj[u]) if (--inDeg[v] == 0) q.push(v);
        }
        return count != V;  // If not all processed → cycle exists
    }
};
