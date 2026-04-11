// ============================================================
// Eventual Safe States
// ============================================================
import java.util.*;
class Solution {
    public List<Integer> eventualSafeNodes(int[][] graph) {
        int n = graph.length; int[] color = new int[n];
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < n; i++) if (isSafe(i, graph, color)) result.add(i);
        return result;
    }
    boolean isSafe(int node, int[][] graph, int[] color) {
        if (color[node] != 0) return color[node] == 2;
        color[node] = 1;
        for (int nb : graph[node]) if (!isSafe(nb, graph, color)) return false;
        color[node] = 2; return true;
    }
}
