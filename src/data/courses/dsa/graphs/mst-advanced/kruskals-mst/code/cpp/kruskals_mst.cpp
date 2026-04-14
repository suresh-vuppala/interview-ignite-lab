#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — try all spanning trees (exponential)
// ============================================================
class Solution1 {
public:
    // Exponential — try all C(E, V-1) combinations of edges
    // Kruskal's IS the standard greedy approach — see Solution 2
    int mstWeight(int V, vector<vector<int>>& edges) {
        // Fallback: sort and greedily pick (this is already Kruskal's)
        sort(edges.begin(), edges.end(), [](auto& a, auto& b){ return a[2]<b[2]; });
        vector<int> par(V); for(int i=0;i<V;i++) par[i]=i;
        // Simple union-find without optimizations
        auto find = [&](int x) { while(par[x]!=x) x=par[x]; return x; };
        int weight=0, count=0;
        for(auto& e:edges) {
            int pu=find(e[0]), pv=find(e[1]);
            if(pu!=pv) { par[pu]=pv; weight+=e[2]; count++; }
            if(count==V-1) break;
        }
        return weight;
    }
};

// ============================================================
// Solution 2: Kruskal's with optimized DSU — O(E log E) Time
// ============================================================
class Solution2 {
    vector<int> par, rnk;
    int find(int x) { return par[x]==x ? x : par[x]=find(par[x]); }
    bool unite(int x, int y) {
        int px=find(x), py=find(y);
        if(px==py) return false;
        if(rnk[px]<rnk[py]) swap(px,py);
        par[py]=px; if(rnk[px]==rnk[py]) rnk[px]++;
        return true;
    }
public:
    int mstWeight(int V, vector<vector<int>>& edges) {
        par.resize(V); rnk.resize(V, 0);
        for(int i=0;i<V;i++) par[i]=i;
        sort(edges.begin(), edges.end(), [](auto& a, auto& b){ return a[2]<b[2]; });
        int weight=0, count=0;
        for(auto& e:edges) {
            if(unite(e[0], e[1])) { weight+=e[2]; count++; }
            if(count==V-1) break;
        }
        return weight;
    }
};
