#include <vector>
using namespace std;
// ============================================================
// Solution 1: DFS — for each edge, check if path exists without it — O(N²)
// ============================================================
class Solution1 {
    bool hasPath(vector<vector<int>>&adj,int u,int target,int skip_u,int skip_v,vector<bool>&vis){
        if(u==target)return true;vis[u]=true;
        for(int v:adj[u]){if(vis[v])continue;if(u==skip_u&&v==skip_v)continue;if(u==skip_v&&v==skip_u)continue;
            if(hasPath(adj,v,target,skip_u,skip_v,vis))return true;}return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>&edges){
        int n=edges.size();vector<vector<int>>adj(n+1);
        for(auto&e:edges){adj[e[0]].push_back(e[1]);adj[e[1]].push_back(e[0]);}
        for(int i=n-1;i>=0;i--){vector<bool>vis(n+1,false);
            if(hasPath(adj,edges[i][0],edges[i][1],edges[i][0],edges[i][1],vis))return edges[i];}
        return {};
    }
};

// ============================================================
// Solution 2: Union-Find — first edge creating cycle — O(N * α(N))
// ============================================================
class Solution2 {
    vector<int>par,rnk;
    int find(int x){return par[x]==x?x:par[x]=find(par[x]);}
public:
    vector<int> findRedundantConnection(vector<vector<int>>&edges){
        int n=edges.size();par.resize(n+1);rnk.resize(n+1,0);for(int i=0;i<=n;i++)par[i]=i;
        for(auto&e:edges){int pu=find(e[0]),pv=find(e[1]);
            if(pu==pv)return e;
            if(rnk[pu]<rnk[pv])swap(pu,pv);par[pv]=pu;if(rnk[pu]==rnk[pv])rnk[pu]++;}
        return {};
    }
};
