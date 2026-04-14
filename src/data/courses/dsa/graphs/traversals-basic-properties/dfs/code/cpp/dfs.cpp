#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Recursive DFS — O(V+E) Time, O(V) Stack Space
// ============================================================
class Solution1 {
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& vis, vector<int>& order) {
        vis[u] = true;
        order.push_back(u);
        for (int v : adj[u])
            if (!vis[v]) dfs(adj, v, vis, order);
    }
public:
    vector<int> dfsTraversal(vector<vector<int>>& adj, int src) {
        vector<bool> vis(adj.size(), false);
        vector<int> order;
        dfs(adj, src, vis, order);
        return order;  // Risk: stack overflow on deep graphs
    }
};

// ============================================================
// Solution 2: Iterative DFS using stack — O(V+E) Time, O(V) Space
// ============================================================
class Solution2 {
public:
    vector<int> dfsTraversal(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        vector<bool> vis(V, false);
        vector<int> order;
        stack<int> st;
        st.push(src);
        while (!st.empty()) {
            int u = st.top(); st.pop();
            if (vis[u]) continue;
            vis[u] = true;
            order.push_back(u);
            for (int i = adj[u].size()-1; i >= 0; i--)  // Reverse for left-first order
                if (!vis[adj[u][i]]) st.push(adj[u][i]);
        }
        return order;  // No stack overflow risk
    }
};
