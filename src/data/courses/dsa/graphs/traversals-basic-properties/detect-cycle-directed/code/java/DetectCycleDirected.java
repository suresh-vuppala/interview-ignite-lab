// ============================================================
// Detect Cycle Directed
// ============================================================
import java.util.*;
class Solution {
    public boolean hasCycle(int n, List<List<Integer>> adj) {
        int[] color = new int[n];
        for (int i = 0; i < n; i++)
            if (color[i] == 0 && dfs(i, adj, color)) return true;
        return false;
    }
    boolean dfs(int node, List<List<Integer>> adj, int[] color) {
        color[node] = 1;
        for (int nb : adj.get(node)) {
            if (color[nb] == 1) return true;
            if (color[nb] == 0 && dfs(nb, adj, color)) return true;
        }
        color[node] = 2;
        return false;
    }
}
