// ============================================================
// Find Degree of Nodes
// ============================================================
#include <vector>
using namespace std;

class Solution {
public:
    // Undirected graph degree
    vector<int> findDegree(int n, vector<vector<int>>& edges) {
        vector<int> degree(n, 0);
        for (auto& e : edges) {
            degree[e[0]]++;
            degree[e[1]]++;
        }
        return degree;
    }

    // Directed: in-degree and out-degree
    pair<vector<int>,vector<int>> findDirectedDegree(int n, vector<vector<int>>& edges) {
        vector<int> inDeg(n, 0), outDeg(n, 0);
        for (auto& e : edges) {
            outDeg[e[0]]++;
            inDeg[e[1]]++;
        }
        return {inDeg, outDeg};
    }
};
