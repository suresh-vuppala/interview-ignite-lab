#include <vector>
using namespace std;
// ============================================================
// Solution 1: Count from adjacency matrix — O(V²)
// ============================================================
class Solution1 {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int V = matrix.size();
        vector<int> deg(V, 0);
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) deg[i] += matrix[i][j];
        return deg;
    }
};

// ============================================================
// Solution 2: Count from adjacency list — O(V+E)
// ============================================================
class Solution2 {
public:
    vector<int> findDegrees(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> deg(V);
        for (int i = 0; i < V; i++) deg[i] = adj[i].size();
        return deg;
    }
};
