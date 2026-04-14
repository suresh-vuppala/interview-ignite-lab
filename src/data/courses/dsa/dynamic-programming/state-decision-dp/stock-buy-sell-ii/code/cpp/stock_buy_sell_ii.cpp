#include <vector>
#include <algorithm>
using namespace std;
// ============================================================
// Solution 1: Recursion — buy/sell/hold at each day — O(2^N)
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& p, int i, bool hold) {
        if (i >= (int)p.size()) return 0;
        int skip = solve(p, i+1, hold);
        if (hold) return max(skip, p[i] + solve(p, i+1, false));
        return max(skip, -p[i] + solve(p, i+1, true));
    }
    int maxProfit(vector<int>& prices) { return solve(prices, 0, false); }
};

// ============================================================
// Solution 2: Greedy — collect all upswings — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < (int)prices.size(); i++)
            if (prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
        return profit;
    }
};
