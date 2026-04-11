// O(E log V) — Greedy: always add cheapest edge from MST to non-MST vertex
int primMST(int V, vector<vector<pair<int,int>>>& adj) {
    vector<bool> inMST(V, false);
    // Min-heap: {weight, vertex}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, 0}); // Start from vertex 0
    int mstWeight = 0;
    
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        mstWeight += w;
        
        for (auto [v, wt] : adj[u])
            if (!inMST[v]) pq.push({wt, v});
    }
    return mstWeight;
}