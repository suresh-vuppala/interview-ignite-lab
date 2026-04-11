// ============================================================
// Course Schedule II
// ============================================================
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> inDeg(numCourses, 0);
        for (auto& p : prerequisites) { adj[p[1]].push_back(p[0]); inDeg[p[0]]++; }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) if (inDeg[i]==0) q.push(i);
        vector<int> order;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            order.push_back(node);
            for (int nb : adj[node]) if (--inDeg[nb]==0) q.push(nb);
        }
        return order.size()==numCourses ? order : vector<int>{}; // Empty if cycle
    }
};
