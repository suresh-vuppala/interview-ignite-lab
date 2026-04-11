class Solution {
public:
    // O(V+E) — Valid tree: n-1 edges + all connected (no cycle)
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false; // Must have exactly n-1 edges
        vector<vector<int>> adj(n);
        for (auto& e : edges) { adj[e[0]].push_back(e[1]); adj[e[1]].push_back(e[0]); }
        
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0); visited[0] = true;
        int count = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop(); count++;
            for (int nb : adj[node])
                if (!visited[nb]) { visited[nb] = true; q.push(nb); }
        }
        return count == n; // All nodes reachable
    }
};