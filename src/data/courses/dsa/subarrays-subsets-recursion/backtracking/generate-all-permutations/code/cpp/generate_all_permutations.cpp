#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Insert at all positions — O(N! * N)
// ============================================================
class Solution1 {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result = {{}};
        for (int num : nums) {
            vector<vector<int>> next;
            for (auto& perm : result)
                for (int i = 0; i <= (int)perm.size(); i++) {
                    vector<int> p = perm;
                    p.insert(p.begin() + i, num);
                    next.push_back(p);
                }
            result = next;
        }
        return result; // Iterative insertion approach
    }
};

// ============================================================
// Solution 2: Swap-Based Backtracking — O(N! * N), in-place
// ============================================================
class Solution2 {
    void bt(vector<int>& nums, int start, vector<vector<int>>& res) {
        if (start == (int)nums.size()) { res.push_back(nums); return; }
        for (int i = start; i < (int)nums.size(); i++) {
            swap(nums[start], nums[i]);
            bt(nums, start + 1, res);
            swap(nums[start], nums[i]); // Backtrack
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res; bt(nums, 0, res); return res;
    }
};
