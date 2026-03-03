#include <vector>
#include <queue>
using namespace std;

class KthSmallestElementInSortedMatrix {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        auto cmp = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);
        
        for (int i = 0; i < min(n, k); i++) {
            minHeap.push({matrix[i][0], i, 0});
        }
        
        int result = 0;
        for (int i = 0; i < k; i++) {
            auto curr = minHeap.top();
            minHeap.pop();
            result = curr[0];
            int row = curr[1], col = curr[2];
            
            if (col + 1 < n) {
                minHeap.push({matrix[row][col + 1], row, col + 1});
            }
        }
        
        return result;
    }
};