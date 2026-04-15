#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: DFS — post-order + reverse — O(V+E) Time
// ============================================================
class Solution1 {
    bool dfs(vector<vector<int>>& adj, int u, vector<int>& state, vector<int>& order) {
        state[u] = 1;
        for (int v : adj[u]) {
            if (state[v] == 1) return false; // cycle
            if (state[v] == 0 && !dfs(adj, v, state, order)) return false;
        }
        state[u] = 2;
        order.push_back(u);
        return true;
    }
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereqs) {
        vector<vector<int>> adj(n);
        for (auto& p : prereqs) adj[p[1]].push_back(p[0]);
        vector<int> state(n, 0), order;
        for (int i = 0; i < n; i++)
            if (state[i] == 0 && !dfs(adj, i, state, order)) return {};
        reverse(order.begin(), order.end());
        return order;
    }
};

// ============================================================
// Solution 2: Kahn's BFS — O(V+E) Time
// ============================================================
class Solution2 {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prereqs) {
        vector<vector<int>> adj(n);
        vector<int> inDeg(n, 0);
        for (auto& p : prereqs) { adj[p[1]].push_back(p[0]); inDeg[p[0]]++; }
        queue<int> q;
        for (int i = 0; i < n; i++) if (inDeg[i] == 0) q.push(i);
        vector<int> order;
        while (!q.empty()) {
            int u = q.front(); q.pop(); order.push_back(u);
            for (int v : adj[u]) if (--inDeg[v] == 0) q.push(v);
        }
        return order.size() == n ? order : vector<int>{};
    }
};
