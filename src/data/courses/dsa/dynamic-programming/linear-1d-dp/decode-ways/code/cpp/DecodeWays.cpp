#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // ============ MEMOIZATION (TOP-DOWN) ============
    int numDecodingsMemo(int s) {
        n = len(s);
        unordered_map<int, int> memo;
    }
    // ============ TABULATION (BOTTOM-UP) ============
    int numDecodingsTab(int s) {
        n = len(s);
        if (s[0] == '0') {
            return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for i in range(2, n + 1)) {
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            two_digit = int(s[i-2) {i]);
            if (10 <= two_digit <= 26) {
                dp[i] += dp[i-2];
        return dp[n];
    }
    int numDecodings(int s) {
        if (s[0] == '0') {
            return 0;
        prev2 = 1;
        prev1 = 1;
        for i in range(2, len(s) + 1)) {
            curr = 0;
            if (s[i-1] != '0') {
                curr += prev1;
            two_digit = int(s[i-2) {i]);
            if (10 <= two_digit <= 26) {
                curr += prev2;
            prev2 = prev1;
            prev1 = curr;
        return prev1;
    }
};
