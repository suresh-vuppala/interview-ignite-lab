// ============================================================
// Disjoint Set Union (Union-Find)
// ============================================================
#include <vector>
using namespace std;

class DSU {
    vector<int> parent, rank_;
public:
    DSU(int n) : parent(n), rank_(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i; // Each node is its own parent
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Point directly to root
        return parent[x];
    }

    // Union by rank
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false; // Already connected

        // Attach smaller rank tree under larger
        if (rank_[rx] < rank_[ry]) swap(rx, ry);
        parent[ry] = rx;
        if (rank_[rx] == rank_[ry]) rank_[rx]++;
        return true;
    }

    bool connected(int x, int y) { return find(x) == find(y); }
};
