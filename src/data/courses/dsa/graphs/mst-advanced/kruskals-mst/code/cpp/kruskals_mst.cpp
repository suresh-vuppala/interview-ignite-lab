// O(E log E) — Sort edges, add if no cycle (using DSU)
struct DSU {
    vector<int> parent, rank_;
    DSU(int n) : parent(n), rank_(n, 0) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return parent[x] == x ? x : parent[x] = find(parent[x]); }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false; // Cycle!
        if (rank_[a] < rank_[b]) swap(a, b);
        parent[b] = a;
        if (rank_[a] == rank_[b]) rank_[a]++;
        return true;
    }
};

int kruskalMST(int V, vector<vector<int>>& edges) {
    sort(edges.begin(), edges.end(), [](auto& a, auto& b) { return a[2] < b[2]; });
    DSU dsu(V);
    int mstWeight = 0, edgesUsed = 0;
    for (auto& e : edges) {
        if (dsu.unite(e[0], e[1])) {
            mstWeight += e[2];
            if (++edgesUsed == V - 1) break;
        }
    }
    return mstWeight;
}