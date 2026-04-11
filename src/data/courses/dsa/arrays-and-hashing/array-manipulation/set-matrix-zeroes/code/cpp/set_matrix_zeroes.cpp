// ============================================================
// Set Matrix Zeroes
// ============================================================

#include <vector>
#include <unordered_set>
using namespace std;

// ============================================================
// Solution 1: Extra Sets for Rows & Columns
// Time: O(M×N) | Space: O(M+N)
// ============================================================
class Solution1 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        unordered_set<int> rows, cols;

        // Pass 1: Record which rows and cols have zeros
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) { rows.insert(i); cols.insert(j); }

        // Pass 2: Zero out marked rows and columns
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (rows.count(i) || cols.count(j)) matrix[i][j] = 0;
    }
};

// ============================================================
// Solution 2: First Row/Column as Markers (Optimal)
// Time: O(M×N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRow = false, firstCol = false;

        // Step 1-2: Check if first row/col have zeros
        for (int j = 0; j < n; j++) if (matrix[0][j] == 0) firstRow = true;
        for (int i = 0; i < m; i++) if (matrix[i][0] == 0) firstCol = true;

        // Step 3: Mark using first row/col
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0) { matrix[i][0] = 0; matrix[0][j] = 0; }

        // Step 4: Zero based on markers
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;

        // Step 5-6: Handle first row and column
        if (firstRow) for (int j = 0; j < n; j++) matrix[0][j] = 0;
        if (firstCol) for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
};
