#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// ============================================================
// Solution 1: Standard DP — O(N * S) — N ≤ 20
// ============================================================
class Solution1 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0; for (int x : nums) sum += x;
        if (sum % 2) return false;
        int target = sum / 2;
        vector<bool> dp(target + 1, false); dp[0] = true;
        for (int x : nums)
            for (int t = target; t >= x; t--)
                dp[t] = dp[t] || dp[t - x];
        return dp[target];
    }
};

// ============================================================
// Solution 2: Meet in the Middle — O(2^(N/2)) — N ≤ 40
// ============================================================
class Solution2 {
    void genSums(vector<int>& nums, int lo, int hi, vector<long long>& sums) {
        int n = hi - lo;
        for (int mask = 0; mask < (1 << n); mask++) {
            long long s = 0;
            for (int i = 0; i < n; i++) if (mask & (1 << i)) s += nums[lo + i];
            sums.push_back(s);
        }
    }
public:
    bool canPartition(vector<int>& nums) {
        long long sum = 0; for (int x : nums) sum += x;
        if (sum % 2) return false;
        long long target = sum / 2;
        int n = nums.size(), mid = n / 2;
        vector<long long> left, right;
        genSums(nums, 0, mid, left);
        genSums(nums, mid, n, right);
        unordered_set<long long> rightSet(right.begin(), right.end());
        for (long long s : left)
            if (rightSet.count(target - s)) return true;
        return false;
    }
};
