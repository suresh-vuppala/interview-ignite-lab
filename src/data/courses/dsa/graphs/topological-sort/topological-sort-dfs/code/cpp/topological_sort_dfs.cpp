#include <vector>
#include <stack>
using namespace std;
// ============================================================
// Solution 1: Kahn's BFS — O(V+E)
// ============================================================
class Solution1 {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> inDeg(V,0); for(int u=0;u<V;u++) for(int v:adj[u]) inDeg[v]++;
        queue<int> q; for(int i=0;i<V;i++) if(!inDeg[i]) q.push(i);
        vector<int> order;
        while(!q.empty()){int u=q.front();q.pop();order.push_back(u);for(int v:adj[u])if(--inDeg[v]==0)q.push(v);}
        return order;
    }
};

// ============================================================
// Solution 2: DFS post-order reverse — O(V+E)
// ============================================================
class Solution2 {
    void dfs(vector<vector<int>>& adj,int u,vector<bool>& vis,vector<int>& order){
        vis[u]=true;for(int v:adj[u])if(!vis[v])dfs(adj,v,vis,order);
        order.push_back(u);
    }
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<bool> vis(V,false);vector<int> order;
        for(int i=0;i<V;i++)if(!vis[i])dfs(adj,i,vis,order);
        reverse(order.begin(),order.end());return order;
    }
};
