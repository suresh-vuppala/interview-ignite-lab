class Solution {
public:
    // O(n²) — Build each row from previous row
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);           // Fill with 1s
            for (int j = 1; j < i; j++)
                row[j] = result[i-1][j-1] + result[i-1][j]; // Sum of two above
            result.push_back(row);
        }
        return result;
    }
};