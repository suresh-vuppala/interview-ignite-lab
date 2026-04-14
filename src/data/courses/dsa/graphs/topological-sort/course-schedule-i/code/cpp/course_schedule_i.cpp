#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: DFS cycle detection — O(V+E) Time
// ============================================================
class Solution1 {
    bool hasCycle(vector<vector<int>>& adj, int u, vector<int>& state) {
        state[u] = 1; // visiting
        for (int v : adj[u]) {
            if (state[v] == 1) return true;  // Back edge = cycle!
            if (state[v] == 0 && hasCycle(adj, v, state)) return true;
        }
        state[u] = 2; // done
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prereqs) {
        vector<vector<int>> adj(n);
        for (auto& p : prereqs) adj[p[1]].push_back(p[0]);
        vector<int> state(n, 0); // 0=unvisited, 1=visiting, 2=done
        for (int i = 0; i < n; i++)
            if (state[i] == 0 && hasCycle(adj, i, state)) return false;
        return true;
    }
};

// ============================================================
// Solution 2: Kahn's BFS — topological sort — O(V+E) Time
// ============================================================
class Solution2 {
public:
    bool canFinish(int n, vector<vector<int>>& prereqs) {
        vector<vector<int>> adj(n);
        vector<int> inDeg(n, 0);
        for (auto& p : prereqs) { adj[p[1]].push_back(p[0]); inDeg[p[0]]++; }
        queue<int> q;
        for (int i = 0; i < n; i++) if (inDeg[i] == 0) q.push(i);
        int count = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop(); count++;
            for (int v : adj[u]) if (--inDeg[v] == 0) q.push(v);
        }
        return count == n;  // All courses processed = no cycle
    }
};
