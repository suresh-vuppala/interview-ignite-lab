#include <vector>
using namespace std;
// ============================================================
// Solution 1: Linear scan — O(M*N)
// ============================================================
class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (auto& row : matrix)
            for (int x : row)
                if (x == target) return true;
        return false;
    }
};

// ============================================================
// Solution 2: Treat as sorted 1D array — binary search — O(log(M*N))
// ============================================================
class Solution2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int lo = 0, hi = m * n - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int val = matrix[mid / n][mid % n]; // Convert 1D index to 2D
            if (val == target) return true;
            if (val < target) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }
};
