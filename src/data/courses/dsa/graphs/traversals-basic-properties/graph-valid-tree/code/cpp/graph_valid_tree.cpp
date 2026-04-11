// ============================================================
// Graph Valid Tree
// ============================================================
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if ((int)edges.size() != n - 1) return false; // Must have n-1 edges

        // Build adjacency list
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // BFS to check connectivity
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0); visited[0] = true;
        int count = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop(); count++;
            for (int nb : adj[node])
                if (!visited[nb]) { visited[nb] = true; q.push(nb); }
        }

        return count == n; // All nodes reachable → connected → valid tree
    }
};
