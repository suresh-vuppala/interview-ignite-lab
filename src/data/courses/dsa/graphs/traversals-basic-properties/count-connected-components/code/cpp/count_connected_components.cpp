// ============================================================
// Count Connected Components
// ============================================================
#include <vector>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& adj) {
        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count++;               // New component found
                dfs(i, adj, visited);  // Visit entire component
            }
        }
        return count;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int nb : adj[node])
            if (!visited[nb]) dfs(nb, adj, visited);
    }
};
