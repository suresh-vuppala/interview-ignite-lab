#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Bellman-Ford — O(V*E)
// ============================================================
class Solution1 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1,INT_MAX); dist[k]=0;
        for(int i=0;i<n-1;i++)
            for(auto&t:times) if(dist[t[0]]!=INT_MAX) dist[t[1]]=min(dist[t[1]],dist[t[0]]+t[2]);
        int res=*max_element(dist.begin()+1,dist.end());
        return res==INT_MAX?-1:res;
    }
};

// ============================================================
// Solution 2: Dijkstra — O((V+E) log V)
// ============================================================
class Solution2 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto&t:times) adj[t[0]].push_back({t[1],t[2]});
        vector<int> dist(n+1,INT_MAX); dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k});
        while(!pq.empty()){auto [d,u]=pq.top();pq.pop();if(d>dist[u])continue;for(auto [v,w]:adj[u])if(dist[u]+w<dist[v]){dist[v]=dist[u]+w;pq.push({dist[v],v});}}
        int res=*max_element(dist.begin()+1,dist.end());
        return res==INT_MAX?-1:res;
    }
};
