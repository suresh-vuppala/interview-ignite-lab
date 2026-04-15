#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
// ============================================================
// Solution 1: Generate all 2^N subset sums — O(2^N) — N ≤ 20
// ============================================================
class Solution1 {
public:
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int minDiff = INT_MAX;
        for (int mask = 0; mask < (1 << n); mask++) {
            long long sum = 0;
            for (int i = 0; i < n; i++) if (mask & (1 << i)) sum += nums[i];
            minDiff = min(minDiff, (int)abs(sum - goal));
        }
        return minDiff;
    }
};

// ============================================================
// Solution 2: Meet in the Middle + two-pointer — O(2^(N/2) * log)
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
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size(), mid = n / 2;
        vector<long long> left, right;
        genSums(nums, 0, mid, left);
        genSums(nums, mid, n, right);
        sort(right.begin(), right.end());
        long long best = LLONG_MAX;
        for (long long s : left) {
            long long need = goal - s;
            auto it = lower_bound(right.begin(), right.end(), need);
            if (it != right.end()) best = min(best, abs(s + *it - goal));
            if (it != right.begin()) { --it; best = min(best, abs(s + *it - goal)); }
        }
        return best;
    }
};
