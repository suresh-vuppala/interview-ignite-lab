// O(2^(n/2) * log) — Split array, enumerate halves, binary search
#include <algorithm>
int closestSubsetSum(vector<int>& nums, int target) {
    int n = nums.size(), half = n / 2;
    // Enumerate all subset sums of first half
    vector<int> left, right;
    for (int mask = 0; mask < (1 << half); mask++) {
        int s = 0; for (int i = 0; i < half; i++) if (mask & (1<<i)) s += nums[i];
        left.push_back(s);
    }
    for (int mask = 0; mask < (1 << (n - half)); mask++) {
        int s = 0; for (int i = 0; i < n - half; i++) if (mask & (1<<i)) s += nums[half+i];
        right.push_back(s);
    }
    sort(right.begin(), right.end());
    int best = INT_MAX;
    for (int s : left) {
        int need = target - s;
        auto it = lower_bound(right.begin(), right.end(), need);
        if (it != right.end()) best = min(best, abs(s + *it - target));
        if (it != right.begin()) best = min(best, abs(s + *prev(it) - target));
    }
    return best;
}