#include <vector>
using namespace std;
// ============================================================
// Solution 1: Count 1s in each row linearly — O(M*N)
// ============================================================
class Solution1 {
public:
    int rowWithMax1s(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxOnes = 0, row = -1;
        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) count += matrix[i][j];
            if (count > maxOnes) { maxOnes = count; row = i; }
        }
        return row;
    }
};

// ============================================================
// Solution 2: Binary search first 1 in each row — O(M * log N)
// Or staircase from top-right — O(M + N)
// ============================================================
class Solution2 {
public:
    int rowWithMax1s(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int row = -1, c = n - 1;
        for (int r = 0; r < m; r++) {
            while (c >= 0 && matrix[r][c] == 1) { c--; row = r; }
            // Move left as long as 1s found — each row only improves
        }
        return row; // O(M + N) — never goes right, only left or down
    }
};
