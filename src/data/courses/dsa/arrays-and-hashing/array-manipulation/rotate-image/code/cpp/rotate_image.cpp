class Solution {
public:
    // O(n²) time, O(1) space — Transpose + reverse each row
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Step 1: Transpose (swap matrix[i][j] with matrix[j][i])
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
        
        // Step 2: Reverse each row
        for (int i = 0; i < n; i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};