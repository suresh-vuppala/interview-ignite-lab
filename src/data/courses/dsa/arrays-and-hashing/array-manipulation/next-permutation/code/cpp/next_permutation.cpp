#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Find all permutations, return next — O(N! * N)
// ============================================================
class Solution1 {
public:
    void nextPermutation(vector<int>& nums) {
        // Brute: generate all sorted permutations, find current, return next
        // Too slow — O(N!) — see Solution 2 for O(N) approach
        // Using STL as a simple brute alternative:
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<vector<int>> allPerms;
        do { allPerms.push_back(sorted_nums); } while (next_permutation(sorted_nums.begin(), sorted_nums.end()));
        for (int i = 0; i < (int)allPerms.size(); i++) {
            if (allPerms[i] == nums) {
                nums = allPerms[(i + 1) % allPerms.size()];
                return;
            }
        }
    }
};

// ============================================================
// Solution 2: Find rightmost ascent, swap, reverse suffix — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i = n - 2;
        // Step 1: Find rightmost i where nums[i] < nums[i+1]
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i >= 0) {
            // Step 2: Find rightmost j where nums[j] > nums[i]
            int j = n - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        // Step 3: Reverse suffix after i
        reverse(nums.begin() + i + 1, nums.end());
    }
};
