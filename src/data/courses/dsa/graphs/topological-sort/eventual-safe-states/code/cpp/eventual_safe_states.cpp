// ============================================================
// Find Eventual Safe States
// ============================================================
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); // 0=white, 1=gray, 2=black(safe)
        vector<int> result;
        for (int i = 0; i < n; i++)
            if (isSafe(i, graph, color)) result.push_back(i);
        return result;
    }
    bool isSafe(int node, vector<vector<int>>& graph, vector<int>& color) {
        if (color[node] != 0) return color[node] == 2; // Already determined
        color[node] = 1; // Gray — being processed
        for (int nb : graph[node])
            if (!isSafe(nb, graph, color)) return false; // Unsafe neighbor
        color[node] = 2; // All paths lead to terminal → safe
        return true;
    }
};
