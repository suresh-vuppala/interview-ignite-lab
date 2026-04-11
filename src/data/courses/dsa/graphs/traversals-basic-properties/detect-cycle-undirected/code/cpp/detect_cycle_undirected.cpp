// ============================================================
// Detect Cycle in Undirected Graph
// ============================================================
#include <vector>
using namespace std;

class Solution {
public:
    bool hasCycle(int n, vector<vector<int>>& adj) {
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
            if (!visited[i] && dfs(i, -1, adj, visited)) return true;
        return false;
    }
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int nb : adj[node]) {
            if (!visited[nb]) {
                if (dfs(nb, node, adj, visited)) return true;
            } else if (nb != parent) {
                return true; // Visited neighbor that's NOT parent = CYCLE
            }
        }
        return false;
    }
};
