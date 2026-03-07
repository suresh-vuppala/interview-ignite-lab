// Time: O(N) | Space: O(N)

#include <vector>
using namespace std;

class Solution {
    vector<vector<int>> graph;
    vector<int> count, ans;
    int n;
    
    void dfs(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                dfs(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }
    
    void dfs2(int node, int parent) {
        for (int child : graph[node]) {
            if (child != parent) {
                ans[child] = ans[node] - count[child] + (n - count[child]);
                dfs2(child, node);
            }
        }
    }
    
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        n = N;
        graph.resize(n);
        count.assign(n, 1);
        ans.assign(n, 0);
        
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        dfs(0, -1);
        dfs2(0, -1);
        return ans;
    }
};
