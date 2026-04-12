// ============================================================
// 0-1 BFS
// ============================================================
import java.util.*;
class Solution {
    public int[] zeroOneBFS(int n, List<List<int[]>> adj, int src) {
        int[] dist = new int[n]; Arrays.fill(dist, Integer.MAX_VALUE);
        dist[src] = 0;
        Deque<Integer> dq = new ArrayDeque<>(); dq.addFirst(src);
        while (!dq.isEmpty()) {
            int u = dq.pollFirst();
            for (int[] e : adj.get(u)) {
                int v = e[0], w = e[1];
                if (dist[u]+w < dist[v]) {
                    dist[v] = dist[u]+w;
                    if (w == 0) dq.addFirst(v); else dq.addLast(v);
                }
            }
        }
        return dist;
    }
}
