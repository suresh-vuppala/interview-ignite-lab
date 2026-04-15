#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: BFS using adjacency matrix — O(V²) Time, O(V²) Space
// ============================================================
class Solution1 {
public:
    vector<int> bfs(vector<vector<int>>& matrix, int src) {
        int V = matrix.size();
        vector<bool> visited(V, false);
        vector<int> order;
        queue<int> q;
        q.push(src); visited[src] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v = 0; v < V; v++) {  // O(V) per vertex — O(V²) total
                if (matrix[u][v] && !visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return order;
    }
};

// ============================================================
// Solution 2: BFS using adjacency list — O(V+E) Time, O(V+E) Space
// ============================================================
class Solution2 {
public:
    vector<int> bfs(vector<vector<int>>& adj, int src) {
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> order;
        queue<int> q;
        q.push(src); visited[src] = true;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            order.push_back(u);
            for (int v : adj[u]) {  // Only iterate neighbors — O(V+E) total
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return order;
    }
};
