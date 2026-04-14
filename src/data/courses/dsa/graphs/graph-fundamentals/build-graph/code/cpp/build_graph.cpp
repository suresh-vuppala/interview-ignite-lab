#include <vector>
#include <list>
using namespace std;
// ============================================================
// Solution 1: Adjacency Matrix — O(V²) Space
// ============================================================
class Solution1 {
public:
    vector<vector<int>> buildGraph(int V, vector<pair<int,int>>& edges) {
        vector<vector<int>> matrix(V, vector<int>(V, 0));
        for (auto [u, v] : edges) { matrix[u][v] = 1; matrix[v][u] = 1; }
        return matrix;  // O(V²) space — wasteful for sparse graphs
    }
};

// ============================================================
// Solution 2: Adjacency List — O(V+E) Space
// ============================================================
class Solution2 {
public:
    vector<vector<int>> buildGraph(int V, vector<pair<int,int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto [u, v] : edges) { adj[u].push_back(v); adj[v].push_back(u); }
        return adj;  // O(V+E) space — efficient for sparse graphs
    }
};
