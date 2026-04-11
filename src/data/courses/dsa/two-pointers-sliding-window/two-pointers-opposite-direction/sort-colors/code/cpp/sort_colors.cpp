// ============================================================
// Sort Colors (Dutch National Flag)
// ============================================================

#include <vector>
using namespace std;

// ============================================================
// Solution 1: Counting Sort — Two Pass
// Time: O(N) | Space: O(1)
// ============================================================
class Solution1 {
public:
    void sortColors(vector<int>& nums) {
        int count[3] = {};

        // Pass 1: Count each color
        for (int n : nums) count[n]++;

        // Pass 2: Fill array
        int idx = 0;
        for (int c = 0; c < 3; c++)
            for (int i = 0; i < count[c]; i++)
                nums[idx++] = c;
    }
};

// ============================================================
// Solution 2: Dutch National Flag — Single Pass (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int lo = 0;              // Boundary: next position for 0
        int mid = 0;             // Current element being examined
        int hi = nums.size() - 1; // Boundary: next position for 2

        while (mid <= hi) {
            if (nums[mid] == 0) {
                swap(nums[lo], nums[mid]); // Move 0 to front
                lo++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++; // 1 is already in correct zone
            } else { // nums[mid] == 2
                swap(nums[mid], nums[hi]); // Move 2 to back
                hi--;
                // Don't advance mid — swapped element needs checking
            }
        }
    }
};
