// ============================================================
// Floyd-Warshall All-Pairs Shortest Path
// ============================================================
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    vector<vector<int>> floydWarshall(int n, vector<vector<int>>& dist) {
        // dist[i][j] = weight of edge i→j, or INF if no direct edge
        // k MUST be outermost loop
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        return dist;
    }
};
