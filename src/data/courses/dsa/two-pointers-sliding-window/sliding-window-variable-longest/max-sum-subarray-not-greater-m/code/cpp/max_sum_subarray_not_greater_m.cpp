// ============================================================
// Max Sum Subarray Not Greater Than M
// ============================================================

#include <vector>
#include <set>
#include <climits>
using namespace std;

// ============================================================
// Solution 1: Brute Force
// Time: O(N²) | Space: O(1)
// ============================================================
class Solution1 {
public:
    int maxSumNotGreater(vector<int>& nums, int M) {
        int maxSum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
                if (sum <= M) maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};

// ============================================================
// Solution 2: Prefix Sum + Ordered Set (Optimal)
// Time: O(N log N) | Space: O(N)
// ============================================================
class Solution2 {
public:
    int maxSumNotGreater(vector<int>& nums, int M) {
        set<long> prefixSet;
        prefixSet.insert(0); // Empty prefix sum

        long prefix = 0;
        long maxSum = LONG_MIN;

        for (int num : nums) {
            prefix += num;

            // Find smallest prefix sum ≥ (prefix - M)
            // So that prefix - val ≤ M
            auto it = prefixSet.lower_bound(prefix - M);

            if (it != prefixSet.end()) {
                // Subarray sum = prefix - *it, guaranteed ≤ M
                maxSum = max(maxSum, prefix - *it);
            }

            prefixSet.insert(prefix);
        }

        return (int)maxSum;
    }
};
