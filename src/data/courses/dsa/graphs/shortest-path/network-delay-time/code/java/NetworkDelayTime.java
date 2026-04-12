// ============================================================
// Network Delay Time
// ============================================================
import java.util.*;
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) adj.add(new ArrayList<>());
        for (int[] t : times) adj.get(t[0]).add(new int[]{t[1], t[2]});
        int[] dist = new int[n+1]; Arrays.fill(dist, Integer.MAX_VALUE); dist[k] = 0;
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[0]-b[0]);
        pq.offer(new int[]{0, k});
        while (!pq.isEmpty()) {
            int[] c = pq.poll(); if (c[0] > dist[c[1]]) continue;
            for (int[] e : adj.get(c[1]))
                if (dist[c[1]]+e[1] < dist[e[0]]) { dist[e[0]]=dist[c[1]]+e[1]; pq.offer(new int[]{dist[e[0]],e[0]}); }
        }
        int max = 0;
        for (int i = 1; i <= n; i++) { if (dist[i]==Integer.MAX_VALUE) return -1; max = Math.max(max, dist[i]); }
        return max;
    }
}
