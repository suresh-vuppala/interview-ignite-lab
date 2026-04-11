// ============================================================
// Next Permutation
// ============================================================

#include <vector>
#include <algorithm>
using namespace std;

// ============================================================
// Solution: Three-Step Algorithm (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the rightmost "dip" (nums[i] < nums[i+1])
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find rightmost element > nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }

            // Step 3: Swap the dip with its partner
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse suffix to get smallest arrangement
        // (If no dip found, this reverses entire array → smallest permutation)
        reverse(nums.begin() + i + 1, nums.end());
    }
};
