#include <vector>
#include <algorithm>
using namespace std;

// Time: O(N³), Space: O(1)
class MaxConsecutiveOnesIii {
public:
    int longestOnesBruteForce(vector<int>& nums, int k) {
        int n = nums.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int zeros = 0;
                for (int p = i; p <= j; p++) if (nums[p] == 0) zeros++;
                if (zeros <= k) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N²), Space: O(1)
    int longestOnesBruteOptimized(vector<int>& nums, int k) {
        int n = nums.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) zeros++;
                if (zeros <= k) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N²), Space: O(1)
    int longestOnesTwoPointerShrink(vector<int>& nums, int k) {
        int n = nums.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            int zeros = 0, j = i;
            while (j < n) {
                if (nums[j] == 0) zeros++;
                if (zeros <= k) {
                    maxLen = max(maxLen, j - i + 1);
                    j++;
                } else break;
            }
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(1)
    int longestOnesSlidingWindow(vector<int>& nums, int k) {
        int left = 0, zeros = 0, maxLen = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;
            while (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    // ============================================================

    // Time: O(N), Space: O(1)
    int longestOnesSlidingWindowOptimized(vector<int>& nums, int k) {
        int left = 0, zeros = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;
            if (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }
        }
        return nums.size() - left;
    }
};
