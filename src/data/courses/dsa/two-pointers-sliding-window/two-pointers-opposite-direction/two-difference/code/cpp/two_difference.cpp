// ============================================================
// Two Difference
// ============================================================

#include <vector>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Brute Force — All Pairs
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    bool findPair(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) == k) return true;
            }
        }
        return false;
    }
};

// ============================================================
// Solution 2: Sort + Two Pointers (Optimal)
// Time: O(N log N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    bool findPair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int i = 0, j = 1;
        while (i < nums.size() && j < nums.size()) {
            // Can't use the same element
            if (i == j) { j++; continue; }

            int diff = nums[j] - nums[i];

            if (diff == k) return true;   // Found!
            if (diff < k) j++;             // Difference too small — advance right
            else i++;                       // Difference too large — advance left
        }

        return false;
    }
};
