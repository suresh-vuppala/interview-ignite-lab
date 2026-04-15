#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Run Dijkstra from each vertex — O(V*(V+E)*logV)
// ============================================================
class Solution1 {
public:
    vector<vector<int>> allPairs(int V, vector<vector<pair<int,int>>>& adj) {
        vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
        for (int i = 0; i < V; i++) dist[i][i] = 0;
        // Dijkstra from each source — better for sparse graphs
        // but doesn't handle negative edges
        for (int src = 0; src < V; src++) {
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
            pq.push({0,src});
            while (!pq.empty()) {
                auto [d,u] = pq.top(); pq.pop();
                if (d > dist[src][u]) continue;
                for (auto [v,w] : adj[u])
                    if (dist[src][u]+w < dist[src][v]) { dist[src][v]=dist[src][u]+w; pq.push({dist[src][v],v}); }
            }
        }
        return dist;
    }
};

// ============================================================
// Solution 2: Floyd-Warshall — O(V³) Time, O(V²) Space
// ============================================================
class Solution2 {
public:
    vector<vector<int>> allPairs(int V, vector<vector<int>>& dist) {
        // dist[i][j] initialized with edge weights, INT_MAX if no edge, 0 if i==j
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        return dist;  // Handles negative edges! O(V³) always.
    }
};
