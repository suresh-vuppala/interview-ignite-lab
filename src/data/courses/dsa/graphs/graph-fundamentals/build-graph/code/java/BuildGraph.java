// ============================================================
// Build Graph — Adjacency List
// ============================================================
import java.util.*;
class Solution {
    public List<List<Integer>> buildGraph(int n, int[][] edges) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]); // Undirected
        }
        return adj;
    }
}
