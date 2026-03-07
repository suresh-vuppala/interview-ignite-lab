// Time: O(N * 2^N) | Space: O(N * 2^N)

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> subset;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    subset.push_back(nums[i]);
            }
            result.push_back(subset);
        }
        return result;
    }
};