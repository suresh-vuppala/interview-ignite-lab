#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Recursion — state (day, txns_left, holding) — O(2^N)
// ============================================================
class Solution1 {
public:
    int solve(vector<int>& p, int i, int k, bool hold) {
        if (i >= (int)p.size() || k == 0) return 0;
        int skip = solve(p, i+1, k, hold);
        if (hold) return max(skip, p[i] + solve(p, i+1, k-1, false));
        return max(skip, -p[i] + solve(p, i+1, k, true));
    }
    int maxProfit(int k, vector<int>& prices) { return solve(prices, 0, k, false); }
};

// ============================================================
// Solution 2: DP — Generalized K transactions — O(N*K) Time
// ============================================================
class Solution2 {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n/2) { int s=0; for(int i=1;i<n;i++) s+=max(0,prices[i]-prices[i-1]); return s; }
        vector<int> buy(k+1, INT_MAX), prof(k+1, 0);
        for (int p : prices)
            for (int i=1; i<=k; i++) { buy[i]=min(buy[i],p-prof[i-1]); prof[i]=max(prof[i],p-buy[i]); }
        return prof[k];
    }
};
