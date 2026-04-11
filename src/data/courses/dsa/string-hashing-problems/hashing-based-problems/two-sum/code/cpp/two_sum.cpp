// ============================================================
// Two Sum
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
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        // Try every possible pair (i, j) where i < j
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                // Check if this pair sums to target
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {}; // No solution found (shouldn't happen per constraints)
    }
};

// ============================================================
// Solution 2: Hash Map — One Pass (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map stores: value → index (for O(1) complement lookup)
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
            // For current number, compute what we need
            int complement = target - nums[i];

            // Check if complement was seen earlier
            if (seen.count(complement)) {
                return {seen[complement], i}; // Found! Return both indices
            }

            // Store current number for future lookups
            seen[nums[i]] = i;
        }

        return {};
    }
};
