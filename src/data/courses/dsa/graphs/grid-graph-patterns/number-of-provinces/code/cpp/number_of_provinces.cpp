// ============================================================
// Number of Provinces
// ============================================================
#include <vector>
using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
            if (!visited[i]) { count++; dfs(i, isConnected, visited); }
        return count;
    }
    void dfs(int city, vector<vector<int>>& mat, vector<bool>& visited) {
        visited[city] = true;
        for (int j = 0; j < (int)mat.size(); j++)
            if (mat[city][j] == 1 && !visited[j]) dfs(j, mat, visited);
    }
};
