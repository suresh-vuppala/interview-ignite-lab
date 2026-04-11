// ============================================================
// Weighted Graph — Adjacency List
// ============================================================
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<pair<int,int>>> buildWeightedGraph(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n); // adj[u] = {(v, weight)}
        for (auto& e : edges) {
            adj[e[0]].push_back({e[1], e[2]}); // u → (v, w)
            adj[e[1]].push_back({e[0], e[2]}); // v → (u, w) undirected
        }
        return adj;
    }
};
