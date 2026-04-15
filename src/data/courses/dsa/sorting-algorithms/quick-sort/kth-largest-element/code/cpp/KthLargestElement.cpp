#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: Sort descending, return k-1 index — O(N log N)
// ============================================================
class Solution1 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};

// ============================================================
// Solution 2: Min-heap of size K — O(N log K) Time, O(K) Space
// ============================================================
class Solution2 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // Min-heap
        for(int x : nums) {
            pq.push(x);
            if((int)pq.size() > k) pq.pop(); // Keep only K largest
        }
        return pq.top(); // Kth largest = smallest in the K-heap
    }
};
