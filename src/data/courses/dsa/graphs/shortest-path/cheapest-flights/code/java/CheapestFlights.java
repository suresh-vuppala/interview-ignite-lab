// ============================================================
// Cheapest Flights Within K Stops
// ============================================================
import java.util.*;
class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        int[] dist = new int[n]; Arrays.fill(dist, Integer.MAX_VALUE); dist[src] = 0;
        for (int i = 0; i <= k; i++) {
            int[] prev = dist.clone();
            for (int[] f : flights) {
                if (prev[f[0]] != Integer.MAX_VALUE && prev[f[0]]+f[2] < dist[f[1]])
                    dist[f[1]] = prev[f[0]]+f[2];
            }
        }
        return dist[dst] == Integer.MAX_VALUE ? -1 : dist[dst];
    }
}
