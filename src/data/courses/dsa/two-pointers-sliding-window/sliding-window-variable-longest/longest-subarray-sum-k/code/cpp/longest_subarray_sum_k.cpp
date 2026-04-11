// ============================================================
// Longest Subarray with Sum K
// ============================================================

#include <vector>
#include <unordered_map>
using namespace std;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum == k) maxLen = max(maxLen, j - i + 1);
            }
        }
        return maxLen;
    }
};

// ============================================================
// Solution 2: Prefix Sum + Hash Map (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    int longestSubarray(vector<int>& nums, int k) {
        unordered_map<long, int> firstOccurrence;
        firstOccurrence[0] = -1; // prefix sum 0 at index -1

        long prefixSum = 0;
        int maxLen = 0;

        for (int j = 0; j < nums.size(); j++) {
            prefixSum += nums[j];

            // Check if (prefixSum - k) was seen before
            if (firstOccurrence.count(prefixSum - k)) {
                maxLen = max(maxLen, j - firstOccurrence[prefixSum - k]);
            }

            // Store FIRST occurrence only (for maximum length)
            if (!firstOccurrence.count(prefixSum)) {
                firstOccurrence[prefixSum] = j;
            }
        }

        return maxLen;
    }
};
