// ============================================================
// Move Zeroes
// ============================================================

#include <vector>
using namespace std;

// ============================================================
// Solution 1: Two-Pass (Copy then Fill)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;

        // Pass 1: Copy all non-zeros to front
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }

        // Pass 2: Fill remaining with zeros
        while (j < nums.size()) {
            nums[j++] = 0;
        }
    }
};

// ============================================================
// Solution 2: Single-Pass Swap (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // Next position for non-zero element

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // Swap non-zero to the front
                swap(nums[i], nums[j]);
                j++;
            }
            // If nums[i] is 0, skip — it will be swapped later
        }
    }
};
