#include <vector>
#include <queue>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: BFS (unweighted only) — O(V+E)
// ============================================================
class Solution1 {
public:
    vector<int> shortestPath(int V, vector<vector<int>>& adj, int src) {
        vector<int> dist(V,-1); dist[src]=0;
        queue<int> q; q.push(src);
        while(!q.empty()){int u=q.front();q.pop();for(int v:adj[u])if(dist[v]==-1){dist[v]=dist[u]+1;q.push(v);}}
        return dist; // Only works for unweighted! For weighted → Solution 2
    }
};

// ============================================================
// Solution 2: Dijkstra — O((V+E) log V)
// ============================================================
class Solution2 {
public:
    vector<int> shortestPath(int V, vector<vector<pair<int,int>>>& adj, int src) {
        vector<int> dist(V,INT_MAX); dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,src});
        while(!pq.empty()){auto [d,u]=pq.top();pq.pop();if(d>dist[u])continue;for(auto [v,w]:adj[u])if(dist[u]+w<dist[v]){dist[v]=dist[u]+w;pq.push({dist[v],v});}}
        return dist;
    }
};
