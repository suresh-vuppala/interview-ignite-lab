// ============================================================
// First Missing Positive
// ============================================================

#include <vector>
#include <unordered_set>
using namespace std;

// ============================================================
// Solution 1: Hash Set
// Time: O(N) | Space: O(N)
// ============================================================
class Solution1 {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        // Check 1, 2, 3, ... until missing found
        for (int i = 1; i <= (int)nums.size() + 1; i++) {
            if (!numSet.count(i)) return i;
        }

        return nums.size() + 1;
    }
};

// ============================================================
// Solution 2: Cyclic Sort — Array as Hash Map (Optimal)
// Time: O(N) | Space: O(1)
// ============================================================
class Solution2 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Cyclic sort: place each value at index (value - 1)
        for (int i = 0; i < n; i++) {
            // Keep swapping until nums[i] is in correct position or out of range
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // First index where nums[i] ≠ i+1 is the answer
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }

        // All 1..N present → answer is N+1
        return n + 1;
    }
};
