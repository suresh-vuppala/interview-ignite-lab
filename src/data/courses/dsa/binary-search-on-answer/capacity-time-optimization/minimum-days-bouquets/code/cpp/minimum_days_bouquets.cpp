class Solution {
public:
    // O(n log max) — Binary search on days
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long)m * k > bloomDay.size()) return -1;
        int lo = 1, hi = *max_element(bloomDay.begin(), bloomDay.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int bouquets = 0, flowers = 0;
            for (int d : bloomDay) {
                if (d <= mid) { if (++flowers == k) { bouquets++; flowers = 0; } }
                else flowers = 0;
            }
            if (bouquets >= m) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};