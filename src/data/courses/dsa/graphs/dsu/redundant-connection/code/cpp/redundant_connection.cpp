// ============================================================
// Redundant Connection
// ============================================================
#include <vector>
using namespace std;
class Solution {
    vector<int> p, r;
    int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
    bool unite(int x,int y){int a=find(x),b=find(y);if(a==b)return false;if(r[a]<r[b])swap(a,b);p[b]=a;if(r[a]==r[b])r[a]++;return true;}
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); p.resize(n+1); r.resize(n+1, 0);
        for (int i = 0; i <= n; i++) p[i] = i;
        for (auto& e : edges)
            if (!unite(e[0], e[1])) return e; // Redundant!
        return {};
    }
};
