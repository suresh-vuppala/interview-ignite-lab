// ============================================================
// Find Degree
// ============================================================
import java.util.*;
class Solution {
    public int[] findDegree(int n, int[][] edges) {
        int[] deg = new int[n];
        for (int[] e : edges) { deg[e[0]]++; deg[e[1]]++; }
        return deg;
    }
}
