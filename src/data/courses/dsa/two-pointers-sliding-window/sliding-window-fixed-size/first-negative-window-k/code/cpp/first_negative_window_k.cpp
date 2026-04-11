// ============================================================
// First Negative in Every Window of Size K
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
    vector<int> firstNegative(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i <= (int)nums.size() - k; i++) {
            int found = 0;
            for (int j = i; j < i + k; j++) {
                if (nums[j] < 0) { found = nums[j]; break; }
            }
            result.push_back(found);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Deque of Negative Indices (Optimal)
// Time: O(N) | Space: O(K)
// ============================================================
class Solution2 {
public:
    vector<int> firstNegative(vector<int>& nums, int k) {
        deque<int> negIdx; // Indices of negative numbers
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Track negative numbers
            if (nums[i] < 0) negIdx.push_back(i);

            // Window is full — produce result
            if (i >= k - 1) {
                // Remove expired indices
                while (!negIdx.empty() && negIdx.front() < i - k + 1)
                    negIdx.pop_front();

                // Front of deque = first negative in window
                result.push_back(negIdx.empty() ? 0 : nums[negIdx.front()]);
            }
        }

        return result;
    }
};
