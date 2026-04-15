#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Sort entire array — O(N log N)
// ============================================================
class Solution1 {
public:
    int kthSmallest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[k-1];
    }
    int kthLargest(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        return nums[k-1];
    }
};

// ============================================================
// Solution 2: Min/Max heap of size K — O(N log K)
// ============================================================
class Solution2 {
public:
    int kthSmallest(vector<int>& nums, int k) {
        priority_queue<int> maxH; // Max-heap of size k
        for (int x : nums) { maxH.push(x); if ((int)maxH.size() > k) maxH.pop(); }
        return maxH.top();
    }
    int kthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<>> minH;
        for (int x : nums) { minH.push(x); if ((int)minH.size() > k) minH.pop(); }
        return minH.top();
    }
};
