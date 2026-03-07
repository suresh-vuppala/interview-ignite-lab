// Time: O(N) | Space: O(N)

import java.util.*;

class Solution {
    private List<List<Integer>> graph;
    private int[] count, ans;
    private int n;
    
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
        n = N;
        graph = new ArrayList<>();
        for (int i = 0; i < n; i++) graph.add(new ArrayList<>());
        count = new int[n];
        ans = new int[n];
        Arrays.fill(count, 1);
        
        for (int[] e : edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
    
    private void dfs(int node, int parent) {
        for (int child : graph.get(node)) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }
    
    private void dfs2(int node, int parent) {
        for (int child : graph.get(node)) {
            if (child != parent) {
                ans[child] = ans[node] - count[child] + (n - count[child]);
                dfs2(child, node);
            }
        }
    }
}
