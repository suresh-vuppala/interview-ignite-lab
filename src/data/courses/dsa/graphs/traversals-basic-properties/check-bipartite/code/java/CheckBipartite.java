// ============================================================
// Check Bipartite
// ============================================================
import java.util.*;
class Solution {
    public boolean isBipartite(int[][] adj) {
        int n = adj.length;
        int[] color = new int[n]; Arrays.fill(color, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] != -1) continue;
            Queue<Integer> q = new LinkedList<>();
            q.add(i); color[i] = 0;
            while (!q.isEmpty()) {
                int node = q.poll();
                for (int nb : adj[node]) {
                    if (color[nb] == -1) { color[nb] = 1-color[node]; q.add(nb); }
                    else if (color[nb] == color[node]) return false;
                }
            }
        }
        return true;
    }
}
