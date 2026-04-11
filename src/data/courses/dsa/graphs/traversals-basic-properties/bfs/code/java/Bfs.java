// ============================================================
// BFS
// ============================================================
import java.util.*;
class Solution {
    public List<Integer> bfs(int n, List<List<Integer>> adj, int start) {
        List<Integer> result = new ArrayList<>();
        boolean[] visited = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        visited[start] = true; q.add(start);
        while (!q.isEmpty()) {
            int node = q.poll(); result.add(node);
            for (int nb : adj.get(node))
                if (!visited[nb]) { visited[nb] = true; q.add(nb); }
        }
        return result;
    }
}
