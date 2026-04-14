#include <vector>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Naive — try all paths (exponential for negative cycles)
// ============================================================
class Solution1 {
public:
    // For graphs with negative edges, no simple brute force exists
    // Bellman-Ford IS the standard approach — see Solution 2
    vector<int> shortestPath(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, INT_MAX); dist[src] = 0;
        // Relax all edges V-1 times (this IS Bellman-Ford)
        for (int i = 0; i < V-1; i++)
            for (auto& e : edges)
                if (dist[e[0]] != INT_MAX && dist[e[0]]+e[2] < dist[e[1]])
                    dist[e[1]] = dist[e[0]] + e[2];
        return dist;
    }
};

// ============================================================
// Solution 2: Bellman-Ford with negative cycle detection — O(V*E) Time
// ============================================================
class Solution2 {
public:
    vector<int> shortestPath(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, INT_MAX); dist[src] = 0;
        // Relax all edges V-1 times
        for (int i = 0; i < V-1; i++)
            for (auto& e : edges)
                if (dist[e[0]] != INT_MAX && dist[e[0]]+e[2] < dist[e[1]])
                    dist[e[1]] = dist[e[0]] + e[2];
        // Check for negative weight cycle (Vth iteration)
        for (auto& e : edges)
            if (dist[e[0]] != INT_MAX && dist[e[0]]+e[2] < dist[e[1]])
                return {};  // Negative cycle detected!
        return dist;
    }
};
