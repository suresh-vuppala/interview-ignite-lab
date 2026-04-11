// ============================================================
// Find All Duplicates in Array
// ============================================================

#include <vector>
#include <unordered_set>
#include <cmath>
using namespace std;

// ============================================================
// Solution 1: Hash Set
// Time: O(N) | Space: O(N)
// ============================================================
class Solution1 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> result;

        for (int num : nums) {
            if (seen.count(num)) {
                result.push_back(num); // Already seen → duplicate
            } else {
                seen.insert(num);
            }
        }

        return result;
    }
};

// ============================================================
// Solution 2: Index Marking — Negate to Flag (Optimal)
// Time: O(N) | Space: O(1) extra
// ============================================================
class Solution2 {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            // Map value to 0-indexed position
            int idx = abs(nums[i]) - 1;

            if (nums[idx] < 0) {
                // Already negative → this value was seen before → duplicate
                result.push_back(idx + 1);
            } else {
                // Mark visited by negating
                nums[idx] = -nums[idx];
            }
        }

        return result;
    }
};
