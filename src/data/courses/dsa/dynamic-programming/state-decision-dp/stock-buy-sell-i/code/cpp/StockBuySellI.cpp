#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Brute Force — All buy-sell pairs — O(N²) Time
// ============================================================
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0, n = prices.size();
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++)
                maxP = max(maxP, prices[j] - prices[i]);
        return maxP;
    }
};

// ============================================================
// Solution 2: Track minimum price — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int minP = INT_MAX, maxProf = 0;
        for (int p : prices) { minP = min(minP, p); maxProf = max(maxProf, p - minP); }
        return maxProf;
    }
};
