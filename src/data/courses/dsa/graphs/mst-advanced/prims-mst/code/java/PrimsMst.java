// ============================================================
// Prim's MST
// ============================================================
import java.util.*;
class Solution {
    public int primMST(int n, List<List<int[]>> adj) {
        boolean[] inMST = new boolean[n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[0]-b[0]);
        pq.offer(new int[]{0, 0}); int total = 0, edges = 0;
        while (!pq.isEmpty() && edges < n) {
            int[] curr = pq.poll();
            if (inMST[curr[1]]) continue;
            inMST[curr[1]] = true; total += curr[0]; edges++;
            for (int[] e : adj.get(curr[1]))
                if (!inMST[e[0]]) pq.offer(new int[]{e[1], e[0]});
        }
        return total;
    }
}
