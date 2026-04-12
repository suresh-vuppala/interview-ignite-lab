// ============================================================
// Cheapest Flights Within K Stops
// ============================================================
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Bellman-Ford: k+1 iterations (k stops = k+1 edges)
        for (int i = 0; i <= k; i++) {
            vector<int> prev = dist; // Copy — use previous round's distances
            for (auto& f : flights) {
                int u = f[0], v = f[1], w = f[2];
                if (prev[u] != INT_MAX && prev[u] + w < dist[v]) {
                    dist[v] = prev[u] + w;
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
