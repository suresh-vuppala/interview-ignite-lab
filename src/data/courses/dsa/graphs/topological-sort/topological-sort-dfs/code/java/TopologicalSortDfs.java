// ============================================================
// Topological Sort — DFS
// ============================================================
import java.util.*;
class Solution {
    public List<Integer> topologicalSort(int n, List<List<Integer>> adj) {
        boolean[] visited = new boolean[n];
        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < n; i++)
            if (!visited[i]) dfs(i, adj, visited, stack);
        return new ArrayList<>(stack);
    }
    void dfs(int node, List<List<Integer>> adj, boolean[] visited, Deque<Integer> stack) {
        visited[node] = true;
        for (int nb : adj.get(node)) if (!visited[nb]) dfs(nb, adj, visited, stack);
        stack.push(node);
    }
}
