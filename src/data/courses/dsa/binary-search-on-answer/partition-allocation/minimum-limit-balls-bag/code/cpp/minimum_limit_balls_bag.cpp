#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Try every penalty from 1 upward — O(max * N)
// ============================================================
class Solution1 {
public:
    int minimumSize(vector<int>& nums, int maxOps) {
        for (int penalty = 1; ; penalty++) {
            int ops = 0;
            for (int n : nums) ops += (n - 1) / penalty; // Splits needed
            if (ops <= maxOps) return penalty;
        }
    }
};

// ============================================================
// Solution 2: Binary Search on penalty — O(N log max)
// ============================================================
class Solution2 {
public:
    int minimumSize(vector<int>& nums, int maxOps) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long long ops = 0;
            for (int n : nums) ops += (n - 1) / mid;
            if (ops <= maxOps) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
