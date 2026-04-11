class Solution {
public:
    // O(n log m) — Binary search on eating speed
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long hours = 0;
            for (int p : piles) hours += (p + mid - 1) / mid; // ceil(p/mid)
            if (hours <= h) hi = mid;   // Can eat slower
            else lo = mid + 1;          // Need to eat faster
        }
        return lo;
    }
};