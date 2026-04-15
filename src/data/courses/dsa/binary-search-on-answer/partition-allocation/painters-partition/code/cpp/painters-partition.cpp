#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// ============================================================
// Solution 1: Recursion — try all partitions — O(N^K)
// ============================================================
class Solution1 {
    int solve(vector<int>& boards, int i, int k) {
        if (k == 1) { int s = 0; for (int j = i; j < (int)boards.size(); j++) s += boards[j]; return s; }
        int res = INT_MAX, sum = 0;
        for (int j = i; j < (int)boards.size() - k + 1; j++) {
            sum += boards[j];
            res = min(res, max(sum, solve(boards, j + 1, k - 1)));
        }
        return res;
    }
public:
    int minTime(vector<int>& boards, int k) { return solve(boards, 0, k); }
};

// ============================================================
// Solution 2: Binary Search on Answer — O(N log S)
// ============================================================
class Solution2 {
    bool canPaint(vector<int>& boards, int k, int maxLen) {
        int painters = 1, cur = 0;
        for (int b : boards) {
            if (b > maxLen) return false;
            if (cur + b > maxLen) { painters++; cur = b; }
            else cur += b;
        }
        return painters <= k;
    }
public:
    int minTime(vector<int>& boards, int k) {
        int lo = *max_element(boards.begin(), boards.end());
        int hi = accumulate(boards.begin(), boards.end(), 0);
        while (lo < hi) { int mid = lo + (hi - lo) / 2; if (canPaint(boards, k, mid)) hi = mid; else lo = mid + 1; }
        return lo;
    }
};
