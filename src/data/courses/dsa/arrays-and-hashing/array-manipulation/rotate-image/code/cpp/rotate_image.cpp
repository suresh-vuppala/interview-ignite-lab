// ============================================================
// Rotate Image (Matrix 90°)
// ============================================================

#include <vector>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Use Extra Matrix
// Time: O(N²) | Space: O(N²)
// ============================================================
class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> copy = matrix;

        // Place (i,j) at (j, n-1-i) in rotated position
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[j][n - 1 - i] = copy[i][j];
    }
};

// ============================================================
// Solution 2: Transpose + Reverse Rows (Optimal)
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose — swap (i,j) with (j,i)
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};
