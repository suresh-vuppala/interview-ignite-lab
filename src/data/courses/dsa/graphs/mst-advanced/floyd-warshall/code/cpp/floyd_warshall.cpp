// O(V³) — All-pairs shortest paths
vector<vector<int>> floydWarshall(int V, vector<vector<int>>& edges) {
    const int INF = 1e9;
    vector<vector<int>> dist(V, vector<int>(V, INF));
    for (int i = 0; i < V; i++) dist[i][i] = 0;
    for (auto& e : edges) dist[e[0]][e[1]] = e[2];
    
    // DP: try every vertex k as intermediate
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    // Negative cycle: dist[i][i] < 0
    for (int i = 0; i < V; i++)
        if (dist[i][i] < 0) return {}; // Negative cycle
    return dist;
}