// ============================================================
// Kahn's Topological Sort
// ============================================================
import java.util.*;
class Solution {
    public List<Integer> topologicalSort(int n, List<List<Integer>> adj) {
        int[] inDeg = new int[n];
        for (int u = 0; u < n; u++) for (int v : adj.get(u)) inDeg[v]++;
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) if (inDeg[i] == 0) q.add(i);
        List<Integer> result = new ArrayList<>();
        while (!q.isEmpty()) {
            int node = q.poll(); result.add(node);
            for (int nb : adj.get(node)) if (--inDeg[nb] == 0) q.add(nb);
        }
        return result;
    }
}
