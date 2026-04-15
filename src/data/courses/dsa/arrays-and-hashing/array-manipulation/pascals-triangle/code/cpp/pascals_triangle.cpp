#include <vector>
using namespace std;
// ============================================================
// Solution 1: Compute each cell using C(n,k) formula — O(N²) Time
// ============================================================
class Solution1 {
    long long comb(int n, int k) {
        if (k > n - k) k = n - k;  // Optimize
        long long res = 1;
        for (int i = 0; i < k; i++) { res *= (n - i); res /= (i + 1); }
        return res;
    }
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row;
            for (int j = 0; j <= i; j++) row.push_back(comb(i, j));
            result.push_back(row);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Build from previous row — O(N²) Time, O(1) extra Space
// ============================================================
class Solution2 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++)
                row[j] = result[i - 1][j - 1] + result[i - 1][j]; // Sum from prev row
            result.push_back(row);
        }
        return result;
    }
};
