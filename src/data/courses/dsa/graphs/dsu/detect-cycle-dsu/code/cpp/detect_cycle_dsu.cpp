// ============================================================
// Detect Cycle Using DSU
// ============================================================
#include <vector>
using namespace std;
class DSU { public: vector<int> p, r; DSU(int n):p(n),r(n,0){ for(int i=0;i<n;i++) p[i]=i; }
    int find(int x){ return p[x]==x?x:p[x]=find(p[x]); }
    bool unite(int x,int y){ int a=find(x),b=find(y); if(a==b) return false;
        if(r[a]<r[b]) swap(a,b); p[b]=a; if(r[a]==r[b]) r[a]++; return true; }};

class Solution {
public:
    bool hasCycle(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        for (auto& e : edges) {
            // If already connected → adding this edge creates cycle
            if (!dsu.unite(e[0], e[1])) return true;
        }
        return false;
    }
};
