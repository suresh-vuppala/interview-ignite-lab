// ============================================================
// Pascal's Triangle
// ============================================================

#include <vector>
using namespace std;

// ============================================================
// Solution: Row-by-Row Construction (Optimal)
// Time: O(N²) | Space: O(1) extra
// ============================================================
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;

        for (int i = 0; i < numRows; i++) {
            // Create row with all 1s
            vector<int> row(i + 1, 1);

            // Fill interior elements: sum of two above
            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }

            result.push_back(row);
        }

        return result;
    }
};
