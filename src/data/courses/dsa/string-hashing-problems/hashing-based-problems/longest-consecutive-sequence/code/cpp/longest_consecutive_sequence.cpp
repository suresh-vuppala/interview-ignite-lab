// ============================================================
// Longest Consecutive Sequence
// ============================================================

#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// ============================================================
// Solution 1: Sort + Linear Scan
// Time: O(N log N) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int maxLen = 1, curLen = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) continue;          // Skip duplicates
            if (nums[i] == nums[i - 1] + 1) curLen++;      // Extend streak
            else curLen = 1;                                 // Reset streak
            maxLen = max(maxLen, curLen);
        }

        return maxLen;
    }
};

// ============================================================
// Solution 2: Hash Set — Count from Beginnings (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        // Build hash set for O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : numSet) {
            // Only start counting from sequence BEGINNINGS
            // A number is a beginning if (num - 1) is NOT in the set
            if (!numSet.count(num - 1)) {
                int current = num;
                int length = 1;

                // Count forward: num, num+1, num+2, ...
                while (numSet.count(current + 1)) {
                    current++;
                    length++;
                }

                maxLen = max(maxLen, length);
            }
        }

        return maxLen;
    }
};
