#include <vector>
#include <queue>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: BFS with K+1 levels — O(N * E)
// ============================================================
class Solution1 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto&f:flights) adj[f[0]].push_back({f[1],f[2]});
        vector<int> dist(n,INT_MAX); dist[src]=0;
        queue<pair<int,int>> q; q.push({src,0});
        int stops=0;
        while(!q.empty()&&stops<=k){
            int sz=q.size();
            vector<int> ndist(dist);
            while(sz--){auto [u,cost]=q.front();q.pop();for(auto [v,w]:adj[u])if(cost+w<ndist[v]){ndist[v]=cost+w;q.push({v,cost+w});}}
            dist=ndist;stops++;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};

// ============================================================
// Solution 2: Bellman-Ford with K+1 iterations — O(K * E)
// ============================================================
class Solution2 {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n,INT_MAX); dist[src]=0;
        for(int i=0;i<=k;i++){
            vector<int> ndist(dist);
            for(auto&f:flights)
                if(dist[f[0]]!=INT_MAX) ndist[f[1]]=min(ndist[f[1]],dist[f[0]]+f[2]);
            dist=ndist;
        }
        return dist[dst]==INT_MAX?-1:dist[dst];
    }
};
