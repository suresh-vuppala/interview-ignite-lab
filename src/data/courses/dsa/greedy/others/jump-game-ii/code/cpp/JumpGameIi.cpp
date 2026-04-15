#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: BFS — level = jumps — O(N²) worst case
// ============================================================
class Solution1 {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        vector<int> dp(n, n); dp[0] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 1; j <= nums[i] && i+j < n; j++)
                dp[i+j] = min(dp[i+j], dp[i] + 1);
        return dp[n-1];
    }
};

// ============================================================
// Solution 2: Greedy — BFS-style with range tracking — O(N)
// ============================================================
class Solution2 {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, curEnd = 0, farthest = 0;
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == curEnd) { jumps++; curEnd = farthest; }
        }
        return jumps;
    }
};
