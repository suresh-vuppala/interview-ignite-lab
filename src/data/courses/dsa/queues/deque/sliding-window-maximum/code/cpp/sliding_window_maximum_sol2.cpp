class Solution {
public:
    // Optimal: O(n) — Monotonic decreasing deque
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Stores indices, front = current max
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            // Remove expired indices from front
            while (!dq.empty() && dq.front() < i - k + 1) dq.pop_front();
            // Remove smaller elements from back (they'll never be max)
            while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) result.push_back(nums[dq.front()]); // Front = max
        }
        return result;
    }
};