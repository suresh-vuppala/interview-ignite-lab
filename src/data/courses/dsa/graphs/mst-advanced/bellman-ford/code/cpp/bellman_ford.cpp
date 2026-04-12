// ============================================================
// Bellman-Ford Algorithm
// ============================================================
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    vector<int> bellmanFord(int n, vector<vector<int>>& edges, int src) {
        vector<int> dist(n, INT_MAX); dist[src] = 0;
        // V-1 relaxation iterations
        for (int i = 0; i < n - 1; i++)
            for (auto& e : edges)
                if (dist[e[0]] != INT_MAX && dist[e[0]] + e[2] < dist[e[1]])
                    dist[e[1]] = dist[e[0]] + e[2];
        // Negative cycle check
        for (auto& e : edges)
            if (dist[e[0]] != INT_MAX && dist[e[0]] + e[2] < dist[e[1]])
                return {}; // Negative cycle exists
        return dist;
    }
};
