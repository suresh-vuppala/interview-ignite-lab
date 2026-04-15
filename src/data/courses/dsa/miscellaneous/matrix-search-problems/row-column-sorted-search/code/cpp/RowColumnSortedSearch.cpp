#include <vector>
using namespace std;
// ============================================================
// Solution 1: Binary search each row — O(M * log N)
// ============================================================
#include <algorithm>
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& row : matrix)
            if (binary_search(row.begin(), row.end(), target)) return true;
        return false;
    }
};

// ============================================================
// Solution 2: Staircase search — start top-right — O(M+N)
// ============================================================
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int r = 0, c = n - 1; // Start top-right corner
        while (r < m && c >= 0) {
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] > target) c--; // Eliminate column
            else r++;                        // Eliminate row
        }
        return false; // O(M+N) — eliminates one row or column each step
    }
};
