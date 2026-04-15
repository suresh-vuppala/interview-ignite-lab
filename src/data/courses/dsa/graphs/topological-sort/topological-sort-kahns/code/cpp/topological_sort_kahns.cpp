#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: DFS-based topological sort — O(V+E)
// ============================================================
class Solution1 {
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& vis, vector<int>& order) {
        vis[u] = true;
        for (int v : adj[u]) if (!vis[v]) dfs(adj, v, vis, order);
        order.push_back(u);  // Add AFTER all descendants processed
    }
public:
    vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V, false);
        vector<int> order;
        for (int i = 0; i < V; i++) if (!vis[i]) dfs(adj, i, vis, order);
        reverse(order.begin(), order.end());  // Reverse finish order
        return order;
    }
};

// ============================================================
// Solution 2: Kahn's BFS — in-degree counting — O(V+E)
// ============================================================
class Solution2 {
public:
    vector<int> topologicalSort(int V, vector<vector<int>>& adj) {
        vector<int> inDeg(V, 0);
        for (int u = 0; u < V; u++) for (int v : adj[u]) inDeg[v]++;
        queue<int> q;
        for (int i = 0; i < V; i++) if (inDeg[i] == 0) q.push(i);
        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) if (--inDeg[v] == 0) q.push(v);
        }
        // If order.size() != V → cycle exists!
        return order;
    }
};
