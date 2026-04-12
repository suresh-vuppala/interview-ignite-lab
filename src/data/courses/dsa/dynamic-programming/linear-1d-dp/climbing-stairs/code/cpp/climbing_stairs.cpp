// ============================================================
// Climbing Stairs
// ============================================================
class Solution {
public:
    // Recursion — O(2^N)
    int climbStairsRec(int n) {
        if (n <= 2) return n;
        return climbStairsRec(n-1) + climbStairsRec(n-2);
    }

    // DP — O(N) time, O(1) space
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev2 = 1, prev1 = 2;
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
