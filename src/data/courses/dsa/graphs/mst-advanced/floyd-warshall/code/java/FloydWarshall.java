class Solution {
    public int[][] floydWarshall(int V, int[][] edges) {
        int INF = (int)1e9;
        int[][] dist = new int[V][V];
        for (int[] r : dist) Arrays.fill(r, INF);
        for (int i = 0; i < V; i++) dist[i][i] = 0;
        for (int[] e : edges) dist[e[0]][e[1]] = e[2];
        for (int k = 0; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    if (dist[i][k] != INF && dist[k][j] != INF)
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
        return dist;
    }
}