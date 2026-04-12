// ============================================================
// Shortest Path Weighted
// ============================================================
import java.util.*;
class Solution {
    public int[] shortestPath(int n, List<List<int[]>> adj, int src, int dst) {
        int[] dist = new int[n], parent = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE); Arrays.fill(parent, -1);
        dist[src] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[0]-b[0]);
        pq.offer(new int[]{0, src});
        while (!pq.isEmpty()) {
            int[] c = pq.poll(); if (c[0] > dist[c[1]]) continue;
            for (int[] e : adj.get(c[1])) {
                if (dist[c[1]]+e[1] < dist[e[0]]) {
                    dist[e[0]] = dist[c[1]]+e[1]; parent[e[0]] = c[1];
                    pq.offer(new int[]{dist[e[0]], e[0]});
                }
            }
        }
        // Reconstruct
        List<Integer> path = new ArrayList<>();
        for (int v = dst; v != -1; v = parent[v]) path.add(v);
        Collections.reverse(path);
        return path.stream().mapToInt(Integer::intValue).toArray();
    }
}
