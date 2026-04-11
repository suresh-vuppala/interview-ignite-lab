// ============================================================
// Remove Element
// ============================================================

#include <vector>
using namespace std;

// ============================================================
// Solution 1: Fast/Slow — Copy Non-Val Forward
// Time: O(N) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0; // Write position

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[j] = nums[i]; // Copy non-val forward
                j++;
            }
        }

        return j;
    }
};

// ============================================================
// Solution 2: Swap with End — Fewer Writes
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;

        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1]; // Replace with last element
                n--;                     // Shrink array
                // Don't advance i — need to check swapped element
            } else {
                i++;
            }
        }

        return n;
    }
};
