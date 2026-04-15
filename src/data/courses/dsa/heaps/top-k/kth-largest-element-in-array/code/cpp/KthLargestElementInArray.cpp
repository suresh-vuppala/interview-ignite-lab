#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Sort — O(N log N)
// ============================================================
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
};

// ============================================================
// Solution 2: Min-heap of size K — O(N log K)
// ============================================================
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<>> minH;
        for (int x : nums) {
            minH.push(x);
            if ((int)minH.size() > k) minH.pop(); // Evict smallest
        }
        return minH.top(); // Kth largest remains at top
    }
};
