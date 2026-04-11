// ============================================================
// Detect Cycle Undirected
// ============================================================
import java.util.*;
class Solution {
    public boolean hasCycle(int n, List<List<Integer>> adj) {
        boolean[] visited = new boolean[n];
        for (int i = 0; i < n; i++)
            if (!visited[i] && dfs(i, -1, adj, visited)) return true;
        return false;
    }
    boolean dfs(int node, int parent, List<List<Integer>> adj, boolean[] visited) {
        visited[node] = true;
        for (int nb : adj.get(node)) {
            if (!visited[nb]) { if (dfs(nb, node, adj, visited)) return true; }
            else if (nb != parent) return true;
        }
        return false;
    }
}
