// ============================================================
// Prim's MST
// ============================================================
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int primMST(int n, vector<vector<pair<int,int>>>& adj) {
        vector<bool> inMST(n, false);
        // Min-heap: (weight, node)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0}); // Start from node 0
        int totalWeight = 0, edges = 0;

        while (!pq.empty() && edges < n) {
            auto [w, u] = pq.top(); pq.pop();
            if (inMST[u]) continue; // Already included — skip

            inMST[u] = true;
            totalWeight += w;
            edges++;

            // Push all edges from u to non-MST vertices
            for (auto& [v, weight] : adj[u])
                if (!inMST[v]) pq.push({weight, v});
        }

        return totalWeight;
    }
};
