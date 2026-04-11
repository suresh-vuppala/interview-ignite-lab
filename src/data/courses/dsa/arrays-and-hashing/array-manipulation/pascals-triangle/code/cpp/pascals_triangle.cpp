class Solution {
public:
    // O(n²) time — Each element = sum of two elements above
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1); // Start and end with 1
            for (int j = 1; j < i; j++) {
                row[j] = result[i-1][j-1] + result[i-1][j]; // Sum of two above
            }
            result.push_back(row);
        }
        return result;
    }
};