#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    // ============ MEMOIZATION (TOP-DOWN) ============
    int minCostClimbingStairsMemo(vector<int>& cost) {
        unordered_map<int, int> memo;
        return min(dpMemo(0, cost, memo), dpMemo(1, cost, memo));
    }
    
    int dpMemo(int i, vector<int>& cost, unordered_map<int, int>& memo) {
        if (i >= cost.size()) return 0;
        if (memo.count(i)) return memo[i];
        memo[i] = cost[i] + min(dpMemo(i+1, cost, memo), dpMemo(i+2, cost, memo));
        return memo[i];
    }
    
    // ============ TABULATION (BOTTOM-UP) ============
    int minCostClimbingStairsTab(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }
        return dp[n];
    }
    
    // ============ SPACE OPTIMIZED ============
    int minCostClimbingStairs(vector<int>& cost) {
        int prev2 = 0, prev1 = 0;
        
        for (int i = 2; i <= cost.size(); i++) {
            int curr = min(prev1 + cost[i-1], prev2 + cost[i-2]);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
