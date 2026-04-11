// ============================================================
// Contains Duplicate
// ============================================================

#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

// ============================================================
// Solution 1: Brute Force — Check All Pairs
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Compare every pair (i, j)
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {

                // If any two elements match → duplicate exists
                if (nums[i] == nums[j]) return true;
            }
        }

        return false; // No duplicates found
    }
};

// ============================================================
// Solution 2: Sort + Adjacent Check
// Time: O(N log N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {

        // Sort brings duplicates adjacent to each other
        sort(nums.begin(), nums.end());

        // Single pass: check adjacent pairs
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) return true; // Adjacent match = duplicate
        }

        return false;
    }
};

// ============================================================
// Solution 3: Hash Set — O(1) Lookup (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution3 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int num : nums) {
            // Check if already seen before inserting
            if (seen.count(num)) return true; // Duplicate found!

            seen.insert(num); // Mark as seen
        }

        return false; // All elements unique
    }
};
