#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // ============ MEMOIZATION (TOP-DOWN) ============
    int climbStairsMemo(int n) {
        unordered_map<int, int> memo;
        return dpMemo(n, memo);
    }
    
    int dpMemo(int n, unordered_map<int, int>& memo) {
        if (n <= 1) return 1;
        if (memo.count(n)) return memo[n];
        memo[n] = dpMemo(n-1, memo) + dpMemo(n-2, memo);
        return memo[n];
    }
    
    // ============ TABULATION (BOTTOM-UP) ============
    int climbStairsTab(int n) {
        if (n <= 1) return 1;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
    
    // ============ SPACE OPTIMIZED ============
    int climbStairs(int n) {
        if (n <= 1) return 1;
        int prev2 = 1, prev1 = 1;
        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};