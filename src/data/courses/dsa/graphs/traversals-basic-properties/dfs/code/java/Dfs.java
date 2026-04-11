// ============================================================
// DFS
// ============================================================
import java.util.*;
class Solution {
    public List<Integer> dfs(int n, List<List<Integer>> adj, int start) {
        List<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[n];
        dfsHelper(start, adj, visited, result);
        return result;
    }
    void dfsHelper(int node, List<List<Integer>> adj, boolean[] visited, List<Integer> result) {
        visited[node] = true; result.add(node);
        for (int nb : adj.get(node))
            if (!visited[nb]) dfsHelper(nb, adj, visited, result);
    }
}
