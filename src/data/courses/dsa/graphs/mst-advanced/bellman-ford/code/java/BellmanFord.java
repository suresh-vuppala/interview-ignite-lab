// ============================================================
// Bellman-Ford
// ============================================================
import java.util.*;
class Solution {
    public int[] bellmanFord(int n, int[][] edges, int src) {
        int[] dist = new int[n]; Arrays.fill(dist, Integer.MAX_VALUE); dist[src] = 0;
        for (int i = 0; i < n-1; i++)
            for (int[] e : edges)
                if (dist[e[0]]!=Integer.MAX_VALUE && dist[e[0]]+e[2]<dist[e[1]])
                    dist[e[1]] = dist[e[0]]+e[2];
        for (int[] e : edges)
            if (dist[e[0]]!=Integer.MAX_VALUE && dist[e[0]]+e[2]<dist[e[1]]) return null;
        return dist;
    }
}
