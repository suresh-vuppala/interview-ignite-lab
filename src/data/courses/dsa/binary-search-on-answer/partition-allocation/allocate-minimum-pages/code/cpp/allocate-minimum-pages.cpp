#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
// ============================================================
// Solution 1: Recursion — try all partition points — O(N^M)
// ============================================================
class Solution1 {
    int solve(vector<int>& books, int i, int m) {
        if (m == 1) { int s = 0; for (int j = i; j < (int)books.size(); j++) s += books[j]; return s; }
        if (i >= (int)books.size()) return INT_MAX;
        int res = INT_MAX, sum = 0;
        for (int j = i; j < (int)books.size() - m + 1; j++) {
            sum += books[j];
            res = min(res, max(sum, solve(books, j + 1, m - 1)));
        }
        return res;
    }
public:
    int allocatePages(vector<int>& books, int m) {
        if (m > (int)books.size()) return -1;
        return solve(books, 0, m);
    }
};

// ============================================================
// Solution 2: Binary Search on Answer — O(N log S) where S = sum
// ============================================================
class Solution2 {
    bool canAllocate(vector<int>& books, int m, int maxPages) {
        int students = 1, curPages = 0;
        for (int b : books) {
            if (b > maxPages) return false;
            if (curPages + b > maxPages) { students++; curPages = b; }
            else curPages += b;
        }
        return students <= m;
    }
public:
    int allocatePages(vector<int>& books, int m) {
        if (m > (int)books.size()) return -1;
        int lo = *max_element(books.begin(), books.end());
        int hi = accumulate(books.begin(), books.end(), 0);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canAllocate(books, m, mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
