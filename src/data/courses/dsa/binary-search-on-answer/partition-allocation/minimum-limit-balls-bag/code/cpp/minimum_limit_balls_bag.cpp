class Solution {
public:
    // O(n log max) — Binary search on max balls per bag after splitting
    int minimumSize(vector<int>& nums, int maxOperations) {
        int lo = 1, hi = *max_element(nums.begin(), nums.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int ops = 0;
            for (int n : nums) ops += (n - 1) / mid; // Splits needed to get all ≤ mid
            if (ops <= maxOperations) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};