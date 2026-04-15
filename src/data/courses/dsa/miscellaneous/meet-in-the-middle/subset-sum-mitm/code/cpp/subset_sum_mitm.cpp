#include <vector>
#include <algorithm>
#include <set>
using namespace std;
// ============================================================
// Solution 1: Standard recursion — O(2^N) — works for N ≤ 20
// ============================================================
class Solution1 {
    bool solve(vector<int>& nums, int target, int i) {
        if (target == 0) return true;
        if (i >= (int)nums.size()) return false;
        return solve(nums, target - nums[i], i+1) || solve(nums, target, i+1);
    }
public:
    bool subsetSum(vector<int>& nums, int target) { return solve(nums, target, 0); }
};

// ============================================================
// Solution 2: Meet in the Middle — O(2^(N/2) * log) — works for N ≤ 40
// ============================================================
class Solution2 {
    void generateSums(vector<int>& nums, int lo, int hi, vector<long long>& sums) {
        int n = hi - lo;
        for (int mask = 0; mask < (1 << n); mask++) {
            long long s = 0;
            for (int i = 0; i < n; i++) if (mask & (1 << i)) s += nums[lo + i];
            sums.push_back(s);
        }
    }
public:
    bool subsetSum(vector<int>& nums, long long target) {
        int n = nums.size(), mid = n / 2;
        vector<long long> left, right;
        generateSums(nums, 0, mid, left);
        generateSums(nums, mid, n, right);
        sort(right.begin(), right.end());
        for (long long s : left)
            if (binary_search(right.begin(), right.end(), target - s)) return true;
        return false; // O(2^(N/2) * log(2^(N/2)))
    }
};
