// ============================================================
// DSU (Union-Find)
// ============================================================
class DSU {
    int[] parent, rank;
    DSU(int n) { parent = new int[n]; rank = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i; }
    int find(int x) { if (parent[x] != x) parent[x] = find(parent[x]); return parent[x]; }
    boolean unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) { int t = rx; rx = ry; ry = t; }
        parent[ry] = rx;
        if (rank[rx] == rank[ry]) rank[rx]++;
        return true;
    }
    boolean connected(int x, int y) { return find(x) == find(y); }
}
