// ============================================================
// Topological Sort — DFS
// ============================================================
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> topologicalSort(int n, vector<vector<int>>& adj) {
        vector<bool> visited(n, false);
        stack<int> st;
        for (int i = 0; i < n; i++)
            if (!visited[i]) dfs(i, adj, visited, st);
        // Stack order = topological order
        vector<int> result;
        while (!st.empty()) { result.push_back(st.top()); st.pop(); }
        return result;
    }
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
        visited[node] = true;
        for (int nb : adj[node])
            if (!visited[nb]) dfs(nb, adj, visited, st);
        st.push(node); // Postorder: push AFTER all children processed
    }
};
