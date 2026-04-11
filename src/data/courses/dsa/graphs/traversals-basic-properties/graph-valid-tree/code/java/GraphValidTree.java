// ============================================================
// Graph Valid Tree
// ============================================================
import java.util.*;
class Solution {
    public boolean validTree(int n, int[][] edges) {
        if (edges.length != n - 1) return false;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) { adj.get(e[0]).add(e[1]); adj.get(e[1]).add(e[0]); }
        boolean[] visited = new boolean[n];
        Queue<Integer> q = new LinkedList<>(); q.add(0); visited[0] = true; int count = 0;
        while (!q.isEmpty()) {
            int node = q.poll(); count++;
            for (int nb : adj.get(node)) if (!visited[nb]) { visited[nb] = true; q.add(nb); }
        }
        return count == n;
    }
}
