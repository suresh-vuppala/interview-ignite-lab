// ============================================================
// Max Consecutive Ones III
// ============================================================

#include <vector>
using namespace std;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            int zeros = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == 0) zeros++;
                if (zeros > k) break;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

// ============================================================
// Solution 2: Sliding Window — Count Zeros (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, zeros = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++; // Track zeros in window

            // Shrink window while too many zeros
            while (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
