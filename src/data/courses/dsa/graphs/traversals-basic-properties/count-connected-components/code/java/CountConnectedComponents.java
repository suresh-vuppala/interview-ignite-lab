// ============================================================
// Count Connected Components
// ============================================================
import java.util.*;
class Solution {
    public int countComponents(int n, List<List<Integer>> adj) {
        boolean[] visited = new boolean[n]; int count = 0;
        for (int i = 0; i < n; i++)
            if (!visited[i]) { count++; dfs(i, adj, visited); }
        return count;
    }
    void dfs(int node, List<List<Integer>> adj, boolean[] visited) {
        visited[node] = true;
        for (int nb : adj.get(node)) if (!visited[nb]) dfs(nb, adj, visited);
    }
}
