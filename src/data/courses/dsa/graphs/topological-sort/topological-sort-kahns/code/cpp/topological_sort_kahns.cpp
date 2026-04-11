// ============================================================
// Topological Sort — Kahn's Algorithm (BFS)
// ============================================================
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& adj) {
        vector<int> inDeg(n, 0);
        for (int u = 0; u < n; u++)
            for (int v : adj[u]) inDeg[v]++;
        queue<int> q;
        for (int i = 0; i < n; i++) if (inDeg[i] == 0) q.push(i);
        vector<int> result;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            result.push_back(node);
            for (int nb : adj[node])
                if (--inDeg[nb] == 0) q.push(nb);
        }
        // result.size() < n → cycle exists
        return result;
    }
};
