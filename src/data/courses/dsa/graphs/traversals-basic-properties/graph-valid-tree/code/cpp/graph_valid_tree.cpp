#include <vector>
using namespace std;
// ============================================================
// Solution 1: DFS — check connected + no cycle + E == V-1 — O(V+E)
// ============================================================
class Solution1 {
    bool dfs(vector<vector<int>>& adj, int u, int par, vector<bool>& vis) {
        vis[u]=true;
        for(int v:adj[u]){
            if(!vis[v]){if(!dfs(adj,v,u,vis))return false;}
            else if(v!=par) return false;
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if((int)edges.size()!=n-1) return false;
        vector<vector<int>> adj(n);
        for(auto&e:edges){adj[e[0]].push_back(e[1]);adj[e[1]].push_back(e[0]);}
        vector<bool> vis(n,false);
        if(!dfs(adj,0,-1,vis)) return false;
        for(int i=0;i<n;i++) if(!vis[i]) return false;
        return true;
    }
};

// ============================================================
// Solution 2: Union-Find — O(E * α(N))
// ============================================================
class Solution2 {
    vector<int> par,rnk;
    int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if((int)edges.size()!=n-1) return false;
        par.resize(n);rnk.resize(n,0);for(int i=0;i<n;i++)par[i]=i;
        for(auto&e:edges){
            int pa=find(e[0]),pb=find(e[1]);
            if(pa==pb) return false; // cycle!
            if(rnk[pa]<rnk[pb])swap(pa,pb);par[pb]=pa;if(rnk[pa]==rnk[pb])rnk[pa]++;
        }
        return true;
    }
};
