// ============================================================
// Shortest Path in Weighted Graph (with path reconstruction)
// ============================================================
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    pair<int, vector<int>> shortestPath(int n, vector<vector<pair<int,int>>>& adj, int src, int dst) {
        vector<int> dist(n, INT_MAX), parent(n, -1);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[src] = 0; pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    parent[v] = u;        // Track parent for path
                    pq.push({dist[v], v});
                }
            }
        }

        // Reconstruct path
        if (dist[dst] == INT_MAX) return {-1, {}};
        vector<int> path;
        for (int v = dst; v != -1; v = parent[v]) path.push_back(v);
        reverse(path.begin(), path.end());
        return {dist[dst], path};
    }
};
