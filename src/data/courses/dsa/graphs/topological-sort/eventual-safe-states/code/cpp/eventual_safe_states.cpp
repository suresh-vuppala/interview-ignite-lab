#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: DFS with 3-color — O(V+E)
// ============================================================
class Solution1 {
    bool isSafe(vector<vector<int>>& adj, int u, vector<int>& color) {
        color[u]=1;
        for(int v:adj[u]){
            if(color[v]==1) return false;
            if(color[v]==0&&!isSafe(adj,v,color)) return false;
        }
        color[u]=2; return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size(); vector<int> color(n,0),result;
        for(int i=0;i<n;i++) if(color[i]==0) isSafe(graph,i,color);
        for(int i=0;i<n;i++) if(color[i]==2) result.push_back(i);
        return result;
    }
};

// ============================================================
// Solution 2: Reverse graph + Kahn's BFS — O(V+E)
// ============================================================
class Solution2 {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> rev(n); vector<int> outDeg(n,0);
        for(int u=0;u<n;u++){outDeg[u]=graph[u].size();for(int v:graph[u])rev[v].push_back(u);}
        queue<int> q;
        for(int i=0;i<n;i++) if(outDeg[i]==0) q.push(i);
        vector<bool> safe(n,false);
        while(!q.empty()){int u=q.front();q.pop();safe[u]=true;for(int v:rev[u])if(--outDeg[v]==0)q.push(v);}
        vector<int> result; for(int i=0;i<n;i++) if(safe[i]) result.push_back(i);
        return result;
    }
};
