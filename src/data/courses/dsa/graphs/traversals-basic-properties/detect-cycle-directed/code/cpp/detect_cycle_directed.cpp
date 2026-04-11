// ============================================================
// Detect Cycle in Directed Graph
// ============================================================
#include <vector>
#include <queue>
using namespace std;

// DFS with 3 colors
class Solution1 {
public:
    bool hasCycle(int n, vector<vector<int>>& adj) {
        vector<int> color(n, 0); // 0=white, 1=gray, 2=black
        for (int i = 0; i < n; i++)
            if (color[i] == 0 && dfs(i, adj, color)) return true;
        return false;
    }
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& color) {
        color[node] = 1; // Gray — in current path
        for (int nb : adj[node]) {
            if (color[nb] == 1) return true;  // Back edge → CYCLE
            if (color[nb] == 0 && dfs(nb, adj, color)) return true;
        }
        color[node] = 2; // Black — fully processed
        return false;
    }
};

// Kahn's BFS
class Solution2 {
public:
    bool hasCycle(int n, vector<vector<int>>& adj) {
        vector<int> inDeg(n, 0);
        for (int u = 0; u < n; u++)
            for (int v : adj[u]) inDeg[v]++;
        queue<int> q;
        for (int i = 0; i < n; i++) if (inDeg[i] == 0) q.push(i);
        int processed = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop(); processed++;
            for (int nb : adj[node])
                if (--inDeg[nb] == 0) q.push(nb);
        }
        return processed < n; // Not all processed → cycle exists
    }
};
