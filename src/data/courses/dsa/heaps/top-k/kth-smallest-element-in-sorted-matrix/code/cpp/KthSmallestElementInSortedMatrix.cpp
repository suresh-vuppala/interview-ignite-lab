#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Flatten + sort — O(N² log N²)
// ============================================================
class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> flat;
        for (auto& row : matrix) for (int x : row) flat.push_back(x);
        sort(flat.begin(), flat.end());
        return flat[k-1];
    }
};

// ============================================================
// Solution 2: Min-heap — merge sorted rows — O(K log N)
// ============================================================
class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;
        for (int i = 0; i < n; i++) pq.push({matrix[i][0], i, 0});
        int result = 0;
        while (k-- > 0) {
            auto [val, r, c] = pq.top(); pq.pop();
            result = val;
            if (c + 1 < n) pq.push({matrix[r][c+1], r, c+1});
        }
        return result;
    }
};
