#include <vector>
#include <deque>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Dijkstra — O((V+E) log V) — overkill for 0/1 weights
// ============================================================
class Solution1 {
public:
    vector<int> shortestPath(int V, vector<vector<pair<int,int>>>& adj, int src) {
        vector<int> dist(V,INT_MAX); dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,src});
        while(!pq.empty()){auto [d,u]=pq.top();pq.pop();if(d>dist[u])continue;for(auto [v,w]:adj[u])if(dist[u]+w<dist[v]){dist[v]=dist[u]+w;pq.push({dist[v],v});}}
        return dist;
    }
};

// ============================================================
// Solution 2: 0-1 BFS with deque — O(V+E) Time!
// ============================================================
class Solution2 {
public:
    vector<int> shortestPath(int V, vector<vector<pair<int,int>>>& adj, int src) {
        vector<int> dist(V,INT_MAX); dist[src]=0;
        deque<int> dq; dq.push_back(src);
        while(!dq.empty()){
            int u=dq.front(); dq.pop_front();
            for(auto [v,w]:adj[u])
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    if(w==0) dq.push_front(v); // 0-weight → front
                    else dq.push_back(v);       // 1-weight → back
                }
        }
        return dist;
    }
};
