// ============================================================
// Sliding Window Maximum
// ============================================================

#include <vector>
#include <deque>
using namespace std;

// ============================================================
// Solution 1: Brute Force — Scan Each Window
// Time: O(N×K) | Space: O(1)
// ============================================================
class Solution1 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i <= (int)nums.size() - k; i++) {
            int maxVal = nums[i];
            for (int j = i + 1; j < i + k; j++)
                maxVal = max(maxVal, nums[j]);
            result.push_back(maxVal);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Monotonic Decreasing Deque (Optimal)
// Time: O(N) | Space: O(K)
// ============================================================
class Solution2 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Stores indices; front = current max
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Remove expired indices from front
            while (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();

            // Remove smaller elements from back
            // (they'll never be max while nums[i] is in the window)
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();

            // Add current index
            dq.push_back(i);

            // Window is full — front is the max
            if (i >= k - 1)
                result.push_back(nums[dq.front()]);
        }

        return result;
    }
};
