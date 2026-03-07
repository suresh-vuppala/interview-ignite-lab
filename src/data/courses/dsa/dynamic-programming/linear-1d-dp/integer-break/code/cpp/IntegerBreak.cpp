#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // ============ MEMOIZATION (TOP-DOWN) ============
    int integerBreakMemo(int n) {
        unordered_map<int, int> memo;
    }
    // ============ TABULATION (BOTTOM-UP) ============
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for i in range(2, n + 1)) {
            for j in range(1, i)) {
                dp[i] = max(dp[i], j * (i - j), j * dp[i - j]);
        return dp[n];
    }
    int integerBreakOptimized(int n) {
        if (n <= 3) {
            return n - 1;
        product = 1;
        while n > 4) {
            product *= 3;
            n -= 3;
        return product * n;
    }
};
