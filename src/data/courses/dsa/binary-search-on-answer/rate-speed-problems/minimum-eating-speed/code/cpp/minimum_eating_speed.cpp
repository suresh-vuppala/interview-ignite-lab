class Solution {
public:
    // Same as Koko Eating Bananas
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            long hours = 0;
            for (int p : piles) hours += (p + mid - 1) / mid;
            if (hours <= h) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};