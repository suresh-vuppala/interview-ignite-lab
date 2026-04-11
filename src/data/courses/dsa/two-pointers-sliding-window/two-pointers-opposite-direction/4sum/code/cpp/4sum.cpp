// ============================================================
// 4Sum
// ============================================================

#include <vector>
#include <algorithm>
using namespace std;

// ============================================================
// Solution 1: Brute Force — All Quadruplets
// Time: O(N⁴) | Space: O(1)
// ============================================================
class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n-3; i++)
            for (int j = i+1; j < n-2; j++)
                for (int k = j+1; k < n-1; k++)
                    for (int l = k+1; l < n; l++)
                        if ((long)nums[i]+nums[j]+nums[k]+nums[l] == target)
                            result.insert({nums[i],nums[j],nums[k],nums[l]});

        return vector<vector<int>>(result.begin(), result.end());
    }
};

// ============================================================
// Solution 2: Sort + Two Nested Loops + Two Pointers (Optimal)
// Time: O(N³) | Space: O(1) extra
// ============================================================
class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n - 3; i++) {
            // Skip duplicate i
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < n - 2; j++) {
                // Skip duplicate j
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1, right = n - 1;

                while (left < right) {
                    // Use long to prevent integer overflow
                    long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        // Skip duplicates
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;

                        left++;
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }

        return result;
    }
};
