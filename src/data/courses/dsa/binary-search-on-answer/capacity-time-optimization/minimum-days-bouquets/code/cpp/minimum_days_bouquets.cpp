#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Simulate day by day — O(maxDay * N)
// ============================================================
class Solution1 {
    bool canMake(vector<int>& bloom, int day, int m, int k) {
        int bouquets = 0, consecutive = 0;
        for (int b : bloom) {
            if (b <= day) { consecutive++; if (consecutive == k) { bouquets++; consecutive = 0; } }
            else consecutive = 0;
        }
        return bouquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > (int)bloomDay.size()) return -1;
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());
        for (int day = 1; day <= maxDay; day++) // Linear scan!
            if (canMake(bloomDay, day, m, k)) return day;
        return -1;
    }
};

// ============================================================
// Solution 2: Binary Search on day — O(N log maxDay)
// ============================================================
class Solution2 {
    bool canMake(vector<int>& bloom, int day, int m, int k) {
        int bouquets = 0, consec = 0;
        for (int b : bloom) {
            if (b <= day) { consec++; if (consec == k) { bouquets++; consec = 0; } }
            else consec = 0;
        }
        return bouquets >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > (int)bloomDay.size()) return -1;
        int lo = 1, hi = *max_element(bloomDay.begin(), bloomDay.end());
        while (lo < hi) { int mid = lo + (hi - lo) / 2; if (canMake(bloomDay, mid, m, k)) hi = mid; else lo = mid + 1; }
        return lo;
    }
};
