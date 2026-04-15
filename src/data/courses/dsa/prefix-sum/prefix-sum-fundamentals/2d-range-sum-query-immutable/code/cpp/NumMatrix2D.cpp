#include <vector>
using namespace std;
// ============================================================
// Solution 1: Brute Force — sum cells each query — O(M*N) per query
// ============================================================
class Solution1 {
    vector<vector<int>> matrix;
public:
    Solution1(vector<vector<int>>& m) : matrix(m) {}
    int sumRegion(int r1, int c1, int r2, int c2) {
        int sum = 0;
        for (int i = r1; i <= r2; i++) for (int j = c1; j <= c2; j++) sum += matrix[i][j];
        return sum;
    }
};

// ============================================================
// Solution 2: 2D Prefix Sum — O(1) per query, O(M*N) preprocess
// ============================================================
class Solution2 {
    vector<vector<int>> prefix;
public:
    Solution2(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        prefix.assign(m+1, vector<int>(n+1, 0));
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                prefix[i][j] = matrix[i-1][j-1] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
    }
    int sumRegion(int r1, int c1, int r2, int c2) {
        return prefix[r2+1][c2+1] - prefix[r1][c2+1] - prefix[r2+1][c1] + prefix[r1][c1];
    }
};
