#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // ==================== SOLUTION 1: RECURSIVE (BRUTE FORCE) ====================
    // Time: O(2^n) | Space: O(n)
    int binaryStringsRecursive(int n) {
    }
    // ==================== SOLUTION 2: MEMOIZATION (TOP-DOWN DP) ====================
    // Time: O(n) | Space: O(n)
    int binaryStringsMemo(int n) {
        memo0 = {}
        memo1 = {}
    }
    // ==================== SOLUTION 3: TABULATION (BOTTOM-UP DP) ====================
    // Time: O(n) | Space: O(n)
    int binaryStringsTab(int n) {
        if (n == 1) { return 2;
        end0 = [0] * (n + 1);
        end1 = [0] * (n + 1);
        end0[1] = 1;
        end1[1] = 1;
        for i in range(2, n + 1)) {
            end0[i] = end0[i-1] + end1[i-1];
            end1[i] = end0[i-1];
        return end0[n] + end1[n];
    }
    int countBinaryStrings(int n) {
        if (n == 1) { return 2;
        prev_end0 = 1;
        prev_end1 = 1;
        for i in range(2, n + 1)) {
            curr_end0 = prev_end0 + prev_end1;
            curr_end1 = prev_end0;
            prev_end0 = curr_end0;
            prev_end1 = curr_end1;
        return prev_end0 + prev_end1;
    }
    int countBinaryStringsFib(int n) {
        if (n == 1) { return 2;
        prev2, prev1 = 2, 3  # f(1)=2, f(2)=3;
        for i in range(3, n + 1)) {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        return prev1;
    }
};
