// ============================================================
// Kruskal's MST
// ============================================================
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    vector<int> p, r;
    int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
    bool unite(int x,int y){int a=find(x),b=find(y);if(a==b)return false;if(r[a]<r[b])swap(a,b);p[b]=a;if(r[a]==r[b])r[a]++;return true;}
public:
    int kruskalMST(int n, vector<vector<int>>& edges) {
        p.resize(n); r.resize(n, 0);
        for (int i = 0; i < n; i++) p[i] = i;

        // Sort edges by weight
        sort(edges.begin(), edges.end(), [](auto& a, auto& b){ return a[2] < b[2]; });

        int totalWeight = 0, edgeCount = 0;
        for (auto& e : edges) {
            if (unite(e[0], e[1])) {         // No cycle → add to MST
                totalWeight += e[2];
                edgeCount++;
                if (edgeCount == n - 1) break; // MST complete
            }
        }
        return totalWeight;
    }
};
