#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — scan each window for max — O(N*K)
// ============================================================
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        for (int i = 0; i <= n - k; i++) {
            int mx = nums[i];
            for (int j = i + 1; j < i + k; j++) mx = max(mx, nums[j]);
            result.push_back(mx);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Monotonic Decreasing Deque — O(N) Time
// ============================================================
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq; // Indices in decreasing value order
        vector<int> result;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && dq.front() <= i - k) dq.pop_front(); // Expire
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back(); // Remove smaller
            dq.push_back(i);
            if (i >= k - 1) result.push_back(nums[dq.front()]); // Front = max
        }
        return result;
    }
};
