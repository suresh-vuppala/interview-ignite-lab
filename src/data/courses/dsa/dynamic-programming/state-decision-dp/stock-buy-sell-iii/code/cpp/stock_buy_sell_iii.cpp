#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
// ============================================================
// Solution 1: Brute Force — split array, max profit on each half — O(N²)
// ============================================================
class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int left = 0, mn = INT_MAX;
            for (int j = 0; j <= i; j++) { mn = min(mn, prices[j]); left = max(left, prices[j]-mn); }
            int right = 0, mx = 0;
            for (int j = n-1; j >= i; j--) { mx = max(mx, prices[j]); right = max(right, mx-prices[j]); }
            ans = max(ans, left+right);
        }
        return ans;
    }
};

// ============================================================
// Solution 2: DP — Two transactions with 4 states — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int buy1=INT_MAX, buy2=INT_MAX, prof1=0, prof2=0;
        for (int p : prices) {
            buy1 = min(buy1, p);       prof1 = max(prof1, p-buy1);
            buy2 = min(buy2, p-prof1); prof2 = max(prof2, p-buy2);
        }
        return prof2;
    }
};
