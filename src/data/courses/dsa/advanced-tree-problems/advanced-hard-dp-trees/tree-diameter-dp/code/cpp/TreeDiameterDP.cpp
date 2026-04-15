#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: BFS from arbitrary node, BFS from farthest — O(N)
// ============================================================
#include <queue>
class Solution1 {
    pair<int,int> bfs(vector<vector<int>>& adj, int start) {
        int n = adj.size();
        vector<int> dist(n, -1); dist[start] = 0;
        queue<int> q; q.push(start);
        int farthest = start;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) if (dist[v] == -1) { dist[v] = dist[u]+1; q.push(v); if (dist[v] > dist[farthest]) farthest = v; }
        }
        return {farthest, dist[farthest]};
    }
public:
    int treeDiameter(vector<vector<int>>& adj) {
        auto [far1, _] = bfs(adj, 0);
        auto [far2, diam] = bfs(adj, far1);
        return diam; // Two BFS: O(N)
    }
};

// ============================================================
// Solution 2: DFS — track two longest paths from each node — O(N)
// ============================================================
class Solution2 {
    int diameter = 0;
    int dfs(vector<vector<int>>& adj, int u, int par) {
        int max1 = 0, max2 = 0; // Two longest paths down
        for (int v : adj[u]) {
            if (v == par) continue;
            int d = 1 + dfs(adj, v, u);
            if (d > max1) { max2 = max1; max1 = d; }
            else if (d > max2) max2 = d;
        }
        diameter = max(diameter, max1 + max2);
        return max1;
    }
public:
    int treeDiameter(vector<vector<int>>& adj) { diameter = 0; dfs(adj, 0, -1); return diameter; }
};
