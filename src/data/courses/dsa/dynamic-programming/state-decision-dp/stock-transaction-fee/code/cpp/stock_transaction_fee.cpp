#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — buy/sell/hold with fee — O(2^N)
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& p, int fee, int i, bool hold) {
        if (i >= (int)p.size()) return 0;
        int skip = solve(p, fee, i+1, hold);
        if (hold) return max(skip, p[i]-fee + solve(p, fee, i+1, false));
        return max(skip, -p[i] + solve(p, fee, i+1, true));
    }
    int maxProfit(vector<int>& prices, int fee) { return solve(prices, fee, 0, false); }
};

// ============================================================
// Solution 2: DP — cash/hold states — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int cash = 0, hold = -prices[0];
        for (int i = 1; i < (int)prices.size(); i++) {
            cash = max(cash, hold + prices[i] - fee);
            hold = max(hold, cash - prices[i]);
        }
        return cash;
    }
};
