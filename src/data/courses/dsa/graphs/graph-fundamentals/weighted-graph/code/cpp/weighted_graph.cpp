#include <vector>
using namespace std;
// ============================================================
// Solution 1: Adjacency Matrix (weighted) — O(V²) Space
// ============================================================
class Solution1 {
public:
    vector<vector<int>> build(int V, vector<vector<int>>& edges) {
        vector<vector<int>> matrix(V, vector<int>(V, 0));
        for (auto& e : edges) matrix[e[0]][e[1]] = e[2]; // u, v, weight
        return matrix;
    }
};

// ============================================================
// Solution 2: Adjacency List (weighted) — O(V+E) Space
// ============================================================
class Solution2 {
public:
    vector<vector<pair<int,int>>> build(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(V);
        for (auto& e : edges) adj[e[0]].push_back({e[1], e[2]});
        return adj;
    }
};
