// ============================================================
// 0-1 BFS
// ============================================================
#include <vector>
#include <deque>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> zeroOneBFS(int n, vector<vector<pair<int,int>>>& adj, int src) {
        vector<int> dist(n, INT_MAX);
        deque<int> dq;

        dist[src] = 0;
        dq.push_front(src);

        while (!dq.empty()) {
            int u = dq.front(); dq.pop_front();

            for (auto& [v, w] : adj[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    if (w == 0) dq.push_front(v); // Same distance → front
                    else dq.push_back(v);          // +1 distance → back
                }
            }
        }

        return dist;
    }
};
