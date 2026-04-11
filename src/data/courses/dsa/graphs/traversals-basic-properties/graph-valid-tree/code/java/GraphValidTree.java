class Solution {
    public boolean validTree(int n, int[][] edges) {
        if (edges.length != n - 1) return false;
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) { adj.get(e[0]).add(e[1]); adj.get(e[1]).add(e[0]); }
        boolean[] vis = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        q.offer(0); vis[0] = true; int count = 0;
        while (!q.isEmpty()) { int node = q.poll(); count++; for (int nb : adj.get(node)) if (!vis[nb]) { vis[nb]=true; q.offer(nb); } }
        return count == n;
    }
}