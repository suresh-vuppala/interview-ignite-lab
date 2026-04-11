// O(V*E) — Relaxes all edges V-1 times, detects negative cycles
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    
    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    
    // Check for negative weight cycles (one more relaxation)
    for (auto& e : edges) {
        if (dist[e[0]] != INT_MAX && dist[e[0]] + e[2] < dist[e[1]])
            return {}; // Negative cycle detected
    }
    return dist;
}