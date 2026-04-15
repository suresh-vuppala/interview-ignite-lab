#include <vector>
#include <queue>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Naive — relax all edges V times — O(V*E) Time
// ============================================================
class Solution1 {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        for (int iter = 0; iter < V; iter++) {  // V iterations
            for (int u = 0; u < V; u++) {
                if (dist[u] == INT_MAX) continue;
                for (auto [v, w] : adj[u])
                    dist[v] = min(dist[v], dist[u] + w);
            }
        }
        return dist;  // O(V*E) — same as Bellman-Ford without priority queue
    }
};

// ============================================================
// Solution 2: Min-heap priority queue — O((V+E) log V) Time
// ============================================================
class Solution2 {
public:
    vector<int> dijkstra(int V, vector<vector<pair<int,int>>>& adj, int src) {
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        dist[src] = 0; pq.push({0, src});
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;  // Skip outdated entries
            for (auto [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};
