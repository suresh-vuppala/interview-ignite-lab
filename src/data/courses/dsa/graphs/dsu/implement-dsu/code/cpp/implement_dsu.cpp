// ============================================================
// Solution 1: Naive DSU — no optimizations — O(N) find worst case
// ============================================================
#include <vector>
using namespace std;
class Solution1 {
    vector<int> parent;
public:
    Solution1(int n) : parent(n) { for(int i=0;i<n;i++) parent[i]=i; }
    int find(int x) {
        while(parent[x] != x) x = parent[x];  // O(N) worst case!
        return x;
    }
    void unite(int x, int y) { parent[find(x)] = find(y); }
};

// ============================================================
// Solution 2: DSU with path compression + union by rank — O(α(N)) amortized
// ============================================================
class Solution2 {
    vector<int> parent, rank_;
public:
    Solution2(int n) : parent(n), rank_(n, 0) { for(int i=0;i<n;i++) parent[i]=i; }
    int find(int x) { return parent[x]==x ? x : parent[x]=find(parent[x]); } // Path compression!
    void unite(int x, int y) {
        int px=find(x), py=find(y);
        if(px==py) return;
        if(rank_[px]<rank_[py]) swap(px,py);  // Union by rank
        parent[py]=px;
        if(rank_[px]==rank_[py]) rank_[px]++;
    }
    bool connected(int x, int y) { return find(x)==find(y); }
};
