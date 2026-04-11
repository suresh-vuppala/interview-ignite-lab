// ============================================================
// 3Sum
// ============================================================

#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// ============================================================
// Solution 1: Brute Force — All Triplets
// Time: O(N³) | Space: O(1)
// ============================================================
class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;

        for (int i = 0; i < (int)nums.size() - 2; i++)
            for (int j = i + 1; j < (int)nums.size() - 1; j++)
                for (int k = j + 1; k < (int)nums.size(); k++)
                    if (nums[i] + nums[j] + nums[k] == 0)
                        result.insert({nums[i], nums[j], nums[k]});

        return vector<vector<int>>(result.begin(), result.end());
    }
};

// ============================================================
// Solution 2: Sort + Two Pointers (Optimal)
// Time: O(N²) | Space: O(1) extra
// ============================================================
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < (int)nums.size() - 2; i++) {
            // Skip duplicate first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Early termination: if smallest is positive, no triplet possible
            if (nums[i] > 0) break;

            int left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left and right
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;
                } else if (sum < 0) {
                    left++;   // Need larger sum
                } else {
                    right--;  // Need smaller sum
                }
            }
        }

        return result;
    }
};
