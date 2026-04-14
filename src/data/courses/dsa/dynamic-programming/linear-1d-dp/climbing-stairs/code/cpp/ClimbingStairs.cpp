// ============================================================
// Solution 1: Recursion — O(2^N) Time, O(N) Space
// ============================================================
class Solution1 {
public:
    int climbStairs(int n) {
        if (n <= 1) return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

// ============================================================
// Solution 2: DP — Bottom-up with two variables — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
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
