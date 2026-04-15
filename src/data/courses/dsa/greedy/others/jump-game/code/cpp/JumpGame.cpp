#include <vector>
using namespace std;
// ============================================================
// Solution 1: Recursion — try all jumps from each position — O(2^N)
// ============================================================
class Solution1 {
    bool canReach(vector<int>& nums, int i) {
        if (i >= (int)nums.size() - 1) return true;
        for (int j = 1; j <= nums[i]; j++)
            if (canReach(nums, i + j)) return true;
        return false;
    }
public:
    bool canJump(vector<int>& nums) { return canReach(nums, 0); }
};

// ============================================================
// Solution 2: Greedy — track farthest reachable — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > farthest) return false; // Can't reach here
            farthest = max(farthest, i + nums[i]);
        }
        return true;
    }
};
