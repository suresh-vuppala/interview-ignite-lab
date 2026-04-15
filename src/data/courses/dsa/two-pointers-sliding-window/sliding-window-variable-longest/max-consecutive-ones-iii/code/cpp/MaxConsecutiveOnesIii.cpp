#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Brute Force — try all subarrays, count zeros — O(N²)
// ============================================================
class Solution1 {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), maxLen = 0;
        for (int i = 0; i < n; i++) {
            int zeros = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) zeros++;
                if (zeros > k) break;
                maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

// ============================================================
// Solution 2: Sliding Window — expand right, shrink left when zeros > K — O(N)
// ============================================================
class Solution2 {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, zeros = 0, maxLen = 0;
        for (int right = 0; right < (int)nums.size(); right++) {
            if (nums[right] == 0) zeros++;
            while (zeros > k) { if (nums[left] == 0) zeros--; left++; }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
