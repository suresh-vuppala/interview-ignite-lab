#include <vector>
#include <queue>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Prim's with adjacency matrix — O(V²) Time
// ============================================================
class Solution1 {
public:
    int mstWeight(int V, vector<vector<int>>& matrix) {
        vector<int> key(V, INT_MAX);
        vector<bool> inMST(V, false);
        key[0] = 0;
        int weight = 0;
        for (int count = 0; count < V; count++) {
            // Pick minimum key vertex not in MST — O(V) scan
            int u = -1;
            for (int v = 0; v < V; v++)
                if (!inMST[v] && (u == -1 || key[v] < key[u])) u = v;
            inMST[u] = true; weight += key[u];
            for (int v = 0; v < V; v++)
                if (!inMST[v] && matrix[u][v] && matrix[u][v] < key[v])
                    key[v] = matrix[u][v];
        }
        return weight;  // O(V²) — good for dense graphs
    }
};

// ============================================================
// Solution 2: Prim's with priority queue — O(E log V) Time
// ============================================================
class Solution2 {
public:
    int mstWeight(int V, vector<vector<pair<int,int>>>& adj) {
        vector<bool> inMST(V, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0, 0}); // {weight, vertex}
        int weight = 0, count = 0;
        while (!pq.empty() && count < V) {
            auto [w, u] = pq.top(); pq.pop();
            if (inMST[u]) continue;
            inMST[u] = true; weight += w; count++;
            for (auto [v, wt] : adj[u])
                if (!inMST[v]) pq.push({wt, v});
        }
        return weight;  // O(E log V) — good for sparse graphs
    }
};
