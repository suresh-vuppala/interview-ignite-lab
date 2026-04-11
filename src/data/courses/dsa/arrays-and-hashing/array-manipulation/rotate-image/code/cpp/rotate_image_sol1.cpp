class Solution {
public:
    // Extra Matrix: O(n²) space — Copy to new matrix
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> copy = matrix;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matrix[j][n-1-i] = copy[i][j]; // Place at rotated position
    }
};