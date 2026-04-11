// ============================================================
// Spiral Matrix
// ============================================================

#include <vector>
using namespace std;

// ============================================================
// Solution 1: Simulation with Visited
// Time: O(M×N) | Space: O(M×N)
// ============================================================
class Solution1 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        int dir = 0, r = 0, c = 0;
        vector<int> result;

        for (int i = 0; i < m * n; i++) {
            result.push_back(matrix[r][c]);
            visited[r][c] = true;
            int nr = r + dirs[dir][0], nc = c + dirs[dir][1];
            if (nr<0 || nr>=m || nc<0 || nc>=n || visited[nr][nc]) {
                dir = (dir + 1) % 4;
                nr = r + dirs[dir][0]; nc = c + dirs[dir][1];
            }
            r = nr; c = nc;
        }
        return result;
    }
};

// ============================================================
// Solution 2: Shrinking Boundaries (Optimal)
// Time: O(M×N) | Space: O(1) extra
// ============================================================
class Solution2 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // Traverse right along top row
            for (int j = left; j <= right; j++)
                result.push_back(matrix[top][j]);
            top++;

            // Traverse down along right column
            for (int i = top; i <= bottom; i++)
                result.push_back(matrix[i][right]);
            right--;

            // Traverse left along bottom row (if rows remain)
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    result.push_back(matrix[bottom][j]);
                bottom--;
            }

            // Traverse up along left column (if columns remain)
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    result.push_back(matrix[i][left]);
                left++;
            }
        }

        return result;
    }
};
