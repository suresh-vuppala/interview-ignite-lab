// ============================================================
// Squares of a Sorted Array
// ============================================================

#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// ============================================================
// Solution 1: Square + Sort
// Time: O(N log N) | Space: O(1)
// ============================================================
class Solution1 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // Square all elements
        for (int& n : nums) n = n * n;

        // Sort
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// ============================================================
// Solution 2: Two Pointers from Ends (Optimal)
// Time: O(N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int left = 0, right = n - 1;
        int pos = n - 1; // Fill from the end

        while (left <= right) {
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];

            if (leftSq > rightSq) {
                result[pos] = leftSq;   // Left has larger square
                left++;
            } else {
                result[pos] = rightSq;  // Right has larger square
                right--;
            }
            pos--;
        }

        return result;
    }
};
