class Solution {
public:
    // O(n log sum) — Binary search on ship capacity
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int d = 1, load = 0;
            for (int w : weights) {
                if (load + w > mid) { d++; load = 0; }
                load += w;
            }
            if (d <= days) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};