#include <vector>
using namespace std;
// ============================================================
// Solution 1: DFS parent tracking — O(V+E)
// ============================================================
class Solution1 {
    bool dfs(vector<vector<int>>&adj,int u,int par,vector<bool>&vis){
        vis[u]=true;for(int v:adj[u]){if(!vis[v]){if(dfs(adj,v,u,vis))return true;}else if(v!=par)return true;}return false;
    }
public:
    bool hasCycle(int V,vector<vector<int>>&edges){
        vector<vector<int>>adj(V);for(auto&e:edges){adj[e[0]].push_back(e[1]);adj[e[1]].push_back(e[0]);}
        vector<bool>vis(V,false);for(int i=0;i<V;i++)if(!vis[i]&&dfs(adj,i,-1,vis))return true;return false;
    }
};

// ============================================================
// Solution 2: Union-Find — O(E * α(V))
// ============================================================
class Solution2 {
    vector<int>par,rnk;
    int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
public:
    bool hasCycle(int V,vector<vector<int>>&edges){
        par.resize(V);rnk.resize(V,0);for(int i=0;i<V;i++)par[i]=i;
        for(auto&e:edges){
            int pu=find(e[0]),pv=find(e[1]);
            if(pu==pv) return true; // Same component → cycle!
            if(rnk[pu]<rnk[pv])swap(pu,pv);par[pv]=pu;if(rnk[pu]==rnk[pv])rnk[pu]++;
        }
        return false;
    }
};
