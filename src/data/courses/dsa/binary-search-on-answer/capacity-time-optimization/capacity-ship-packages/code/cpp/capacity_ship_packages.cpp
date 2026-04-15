#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// ============================================================
// Solution 1: Try every capacity from max(w) to sum(w) — O(N * S)
// ============================================================
class Solution1 {
    int daysNeeded(vector<int>& weights, int cap) {
        int days = 1, cur = 0;
        for (int w : weights) { if (cur + w > cap) { days++; cur = w; } else cur += w; }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        for (int cap = lo; cap <= hi; cap++) // Linear scan!
            if (daysNeeded(weights, cap) <= days) return cap;
        return hi;
    }
};

// ============================================================
// Solution 2: Binary Search on capacity — O(N log S)
// ============================================================
class Solution2 {
    bool canShip(vector<int>& weights, int days, int cap) {
        int d = 1, cur = 0;
        for (int w : weights) { if (cur + w > cap) { d++; cur = w; } else cur += w; }
        return d <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0);
        while (lo < hi) { int mid = lo + (hi - lo) / 2; if (canShip(weights, days, mid)) hi = mid; else lo = mid + 1; }
        return lo;
    }
};
