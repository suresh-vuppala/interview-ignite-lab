// ============================================================
// Build Graph — Adjacency List
// ============================================================
#include <vector>
using namespace std;

class Solution {
public:
    // Undirected graph from edge list
    vector<vector<int>> buildGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]); // u → v
            adj[e[1]].push_back(e[0]); // v → u (undirected)
        }
        return adj;
    }

    // Directed graph from edge list
    vector<vector<int>> buildDirectedGraph(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]); // u → v only
        }
        return adj;
    }
};
