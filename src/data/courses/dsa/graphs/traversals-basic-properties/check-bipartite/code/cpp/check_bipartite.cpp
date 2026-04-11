// ============================================================
// Check Bipartite Graph
// ============================================================
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1); // -1 = uncolored

        for (int i = 0; i < n; i++) {
            if (color[i] != -1) continue; // Already colored
            // BFS 2-coloring
            queue<int> q;
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int node = q.front(); q.pop();
                for (int nb : adj[node]) {
                    if (color[nb] == -1) {
                        color[nb] = 1 - color[node]; // Opposite color
                        q.push(nb);
                    } else if (color[nb] == color[node]) {
                        return false; // Same color conflict!
                    }
                }
            }
        }
        return true;
    }
};
