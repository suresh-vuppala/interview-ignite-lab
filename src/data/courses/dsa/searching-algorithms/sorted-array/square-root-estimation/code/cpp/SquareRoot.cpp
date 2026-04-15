using namespace std;
// ============================================================
// Solution 1: Linear scan from 1 — O(√N) Time
// ============================================================
class Solution1 {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        long i = 1;
        while (i * i <= x) i++;
        return i - 1;
    }
};

// ============================================================
// Solution 2: Binary search — O(log N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        long lo = 1, hi = x / 2, ans = 0;
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            if (mid * mid <= x) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        return ans;
    }
};
