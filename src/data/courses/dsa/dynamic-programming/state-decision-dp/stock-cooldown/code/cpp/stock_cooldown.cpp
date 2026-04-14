#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Recursion with cooldown state — O(3^N)
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& p, int i, int state) { // 0=buy, 1=sell, 2=cooldown
        if (i >= (int)p.size()) return 0;
        if (state == 2) return solve(p, i+1, 0); // must cool down
        int skip = solve(p, i+1, state);
        if (state == 0) return max(skip, -p[i] + solve(p, i+1, 1)); // buy
        return max(skip, p[i] + solve(p, i+1, 2)); // sell
    }
    int maxProfit(vector<int>& prices) { return solve(prices, 0, 0); }
};

// ============================================================
// Solution 2: DP — Three states (sold, held, rest) — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0, held = INT_MIN, rest = 0;
        for (int p : prices) {
            int ps = sold;
            sold = held + p;
            held = max(held, rest - p);
            rest = max(rest, ps);
        }
        return max(sold, rest);
    }
};
