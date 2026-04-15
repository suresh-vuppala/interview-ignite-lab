#include <vector>
using namespace std;
// ============================================================
// Solution 1: DFS — O(V+E) Time
// ============================================================
class Solution1 {
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& vis) {
        vis[u]=true; for(int v:adj[u]) if(!vis[v]) dfs(adj,v,vis);
    }
public:
    int countComponents(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V,false); int count=0;
        for(int i=0;i<V;i++) if(!vis[i]){dfs(adj,i,vis);count++;}
        return count;
    }
};

// ============================================================
// Solution 2: Union-Find — O(V+E*α(V)) Time
// ============================================================
class Solution2 {
    vector<int> par,rnk;
    int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
    void unite(int a,int b){int pa=find(a),pb=find(b);if(pa==pb)return;if(rnk[pa]<rnk[pb])swap(pa,pb);par[pb]=pa;if(rnk[pa]==rnk[pb])rnk[pa]++;}
public:
    int countComponents(int V, vector<vector<int>>& edges) {
        par.resize(V);rnk.resize(V,0);for(int i=0;i<V;i++)par[i]=i;
        for(auto&e:edges)unite(e[0],e[1]);
        int c=0;for(int i=0;i<V;i++)if(find(i)==i)c++;return c;
    }
};
