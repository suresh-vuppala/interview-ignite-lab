#include <vector>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Brute Force — check all subarrays — O(N²)
// ============================================================
class Solution1 {
public:
    int maxSumNotGreaterM(vector<int>& nums, int m) {
        int n = nums.size(), maxSum = INT_MIN;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                if (sum <= m) maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

// ============================================================
// Solution 2: Prefix sum + ordered set (lower_bound) — O(N log N)
// ============================================================
class Solution2 {
public:
    int maxSumNotGreaterM(vector<int>& nums, int m) {
        int n = nums.size(), maxSum = INT_MIN;
        long prefix = 0;
        set<long> prefixSet;
        prefixSet.insert(0);
        for (int i = 0; i < n; i++) {
            prefix += nums[i];
            // Want prefix - prev >= 0 and prefix - prev <= m
            // So prev >= prefix - m
            auto it = prefixSet.lower_bound(prefix - m);
            if (it != prefixSet.end())
                maxSum = max(maxSum, (int)(prefix - *it));
            prefixSet.insert(prefix);
        }
        return maxSum;
    }
};
