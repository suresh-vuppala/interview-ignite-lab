#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// ============================================================
// Solution 1: Linear search from speed 1 upward — O(max(piles) * N)
// ============================================================
class Solution1 {
    long long hoursNeeded(vector<int>& piles, int speed) {
        long long h = 0;
        for (int p : piles) h += (p + speed - 1) / speed; // ceil division
        return h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        for (int speed = 1; ; speed++)
            if (hoursNeeded(piles, speed) <= h) return speed;
        return -1; // O(max * N)
    }
};

// ============================================================
// Solution 2: Binary Search on speed — O(N log max)
// ============================================================
class Solution2 {
    long long hours(vector<int>& piles, int speed) {
        long long h = 0;
        for (int p : piles) h += (p + speed - 1) / speed;
        return h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (hours(piles, mid) <= h) hi = mid; else lo = mid + 1;
        }
        return lo;
    }
};
