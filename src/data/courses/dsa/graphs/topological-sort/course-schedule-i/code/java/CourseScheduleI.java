// ============================================================
// Course Schedule I
// ============================================================
import java.util.*;
class Solution {
    public boolean canFinish(int n, int[][] prereqs) {
        List<List<Integer>> adj = new ArrayList<>();
        int[] inDeg = new int[n];
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] p : prereqs) { adj.get(p[1]).add(p[0]); inDeg[p[0]]++; }
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) if (inDeg[i]==0) q.add(i);
        int count = 0;
        while (!q.isEmpty()) { int node = q.poll(); count++;
            for (int nb : adj.get(node)) if (--inDeg[nb]==0) q.add(nb); }
        return count == n;
    }
}
