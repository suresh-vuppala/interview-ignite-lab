#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^N) | Space: O(N)
    int maxProfitRecursive(vector<int>& prices) {
        return solve(prices, 0, false);
    }
    
private:
    int solve(vector<int>& prices, int i, bool holding) {
        if (i == prices.size()) return 0;
        if (holding) {
            int sell = prices[i] + solve(prices, i + 1, false);
            int hold = solve(prices, i + 1, true);
            return max(sell, hold);
        } else {
            int buy = -prices[i] + solve(prices, i + 1, true);
            int skip = solve(prices, i + 1, false);
            return max(buy, skip);
        }
    }
    
public:
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(N) | Space: O(N)
    int maxProfitMemo(vector<int>& prices) {
        unordered_map<string, int> memo;
        return solveMemo(prices, 0, false, memo);
    }
    
private:
    int solveMemo(vector<int>& prices, int i, bool holding, unordered_map<string, int>& memo) {
        if (i == prices.size()) return 0;
        string key = to_string(i) + "," + to_string(holding);
        if (memo.count(key)) return memo[key];
        if (holding) {
            int sell = prices[i] + solveMemo(prices, i + 1, false, memo);
            int hold = solveMemo(prices, i + 1, true, memo);
            memo[key] = max(sell, hold);
        } else {
            int buy = -prices[i] + solveMemo(prices, i + 1, true, memo);
            int skip = solveMemo(prices, i + 1, false, memo);
            memo[key] = max(buy, skip);
        }
        return memo[key];
    }
    
public:
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(N) | Space: O(N)
    int maxProfitTab(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][0] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);
            dp[i][1] = max(prices[i] + dp[i + 1][0], dp[i + 1][1]);
        }
        return dp[0][0];
    }
    
    // ==================== SOLUTION 4: SPACE OPTIMIZED ====================
    // Time: O(N) | Space: O(1)
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};
