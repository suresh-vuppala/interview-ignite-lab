// ============================================================
// Remove Duplicates from Sorted Array
// ============================================================

#include <vector>
using namespace std;

// ============================================================
// Solution 1: Extra Array
// Time: O(N) | Space: O(N)
// ============================================================
class Solution1 {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> unique;
        unique.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            // Only add if different from last unique
            if (nums[i] != unique.back()) {
                unique.push_back(nums[i]);
            }
        }

        // Copy back
        for (int i = 0; i < unique.size(); i++) nums[i] = unique[i];
        return unique.size();
    }
};

// ============================================================
// Solution 2: Slow/Fast Two Pointers (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int j = 0; // j = position of last unique element

        for (int i = 1; i < nums.size(); i++) {
            // Found a new unique value
            if (nums[i] != nums[j]) {
                j++;                // Advance write position
                nums[j] = nums[i]; // Write the new unique value
            }
        }

        return j + 1; // Length = last index + 1
    }
};
