// ============================================================
// Number of Provinces — DSU
// ============================================================
#include <vector>
using namespace std;
class Solution {
    vector<int> p, r;
    int find(int x) { return p[x]==x?x:p[x]=find(p[x]); }
    void unite(int x, int y) { int a=find(x),b=find(y); if(a==b) return;
        if(r[a]<r[b]) swap(a,b); p[b]=a; if(r[a]==r[b]) r[a]++; }
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(); p.resize(n); r.resize(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                if (M[i][j] == 1) unite(i, j);
        int count = 0;
        for (int i = 0; i < n; i++) if (find(i) == i) count++;
        return count;
    }
};
