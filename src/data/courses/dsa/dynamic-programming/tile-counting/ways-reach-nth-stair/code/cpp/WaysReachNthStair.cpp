#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(3^n) | Space: O(n)
    int waysRecursive(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        return waysRecursive(n-1) + waysRecursive(n-2) + waysRecursive(n-3);
    }
    
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(n) | Space: O(n)
    int waysMemo(int n) {
        unordered_map<int, int> memo;
        return solve(n, memo);
    }
    
private:
    int solve(int i, unordered_map<int, int>& memo) {
        if (i == 0) return 1;
        if (i == 1) return 1;
        if (i == 2) return 2;
        if (memo.count(i)) return memo[i];
        memo[i] = solve(i-1, memo) + solve(i-2, memo) + solve(i-3, memo);
        return memo[i];
    }
    
public:
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(n) | Space: O(n)
    int waysTab(int n) {
        if (n <= 1) return 1;
        if (n == 2) return 2;
        vector<int> dp(n + 1);
        dp[0] = 1; dp[1] = 1; dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        return dp[n];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(n) | Space: O(1)
    int waysToReachNthStair(int n) {
        if (n <= 1) return 1;
        if (n == 2) return 2;
        int prev3 = 1, prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2 + prev3;
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
