#include <vector>
using namespace std;
// ============================================================
// Solution 1: Root at each node, compute answer — O(N²)
// ============================================================
class Solution1 {
    int dfs(vector<vector<int>>& adj, int u, int par) {
        int sum = 0;
        for (int v : adj[u]) if (v != par) sum += 1 + dfs(adj, v, u);
        return sum;
    }
public:
    vector<int> sumOfDistances(int n, vector<vector<int>>& adj) {
        vector<int> result(n);
        for (int i = 0; i < n; i++) result[i] = dfs(adj, i, -1); // O(N) per node
        return result; // O(N²) total
    }
};

// ============================================================
// Solution 2: Re-rooting DP — two DFS passes — O(N)
// ============================================================
class Solution2 {
    vector<int> sz, dist;
    void dfs1(vector<vector<int>>& adj, int u, int par) {
        sz[u] = 1;
        for (int v : adj[u]) if (v != par) { dfs1(adj, v, u); sz[u] += sz[v]; dist[u] += dist[v] + sz[v]; }
    }
    void dfs2(vector<vector<int>>& adj, int u, int par, int n) {
        for (int v : adj[u]) if (v != par) {
            dist[v] = dist[u] - sz[v] + (n - sz[v]); // Re-root from u to v
            dfs2(adj, v, u, n);
        }
    }
public:
    vector<int> sumOfDistances(int n, vector<vector<int>>& adj) {
        sz.assign(n, 0); dist.assign(n, 0);
        dfs1(adj, 0, -1);
        dfs2(adj, 0, -1, n);
        return dist;
    }
};
