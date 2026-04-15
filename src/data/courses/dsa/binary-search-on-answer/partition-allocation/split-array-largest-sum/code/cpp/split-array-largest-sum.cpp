#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// ============================================================
// Solution 1: DP — O(N² * K) Time
// ============================================================
class Solution1 {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i + 1] = prefix[i] + nums[i];
        // dp[i][j] = min largest sum splitting first i elements into j groups
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INT_MAX));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= min(i, k); j++)
                for (int p = j - 1; p < i; p++)
                    dp[i][j] = min(dp[i][j], max(dp[p][j - 1], prefix[i] - prefix[p]));
        return dp[n][k];
    }
};

// ============================================================
// Solution 2: Binary Search on Answer — O(N log S)
// ============================================================
class Solution2 {
    bool canSplit(vector<int>& nums, int k, int maxSum) {
        int groups = 1, cur = 0;
        for (int x : nums) {
            if (x > maxSum) return false;
            if (cur + x > maxSum) { groups++; cur = x; }
            else cur += x;
        }
        return groups <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0);
        while (lo < hi) { int mid = lo + (hi - lo) / 2; if (canSplit(nums, k, mid)) hi = mid; else lo = mid + 1; }
        return lo;
    }
};
