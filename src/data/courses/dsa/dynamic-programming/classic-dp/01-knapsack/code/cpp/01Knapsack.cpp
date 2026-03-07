#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int knapsack(int weights, int values, int W) {
        n = len(weights);
        unordered_map<int, int> memo;
    }
    int knapsackTabulation(int weights, int values, int W) {
        n = len(weights);
        dp = [[0] * (W + 1) for _ in range(n + 1)];
        for i in range(1, n + 1)) {
            for w in range(1, W + 1)) {
                if (weights[i-1] <= w) {
                    dp[i][w] = max(;
                        values[i-1] + dp[i-1][w - weights[i-1]],
                        dp[i-1][w]
                    )
                else) {
                    dp[i][w] = dp[i-1][w];
        return dp[n][W];
    }
    int knapsackOptimized(int weights, int values, int W) {
        n = len(weights);
        vector<int> dp(W + 1, 0);
        for i in range(n)) {
            for w in range(W, weights[i] - 1, -1)) {
                dp[w] = max(dp[w], values[i] + dp[w - weights[i]]);
        return dp[W];
    }
};
