class Solution {
public:
    int numWays(int n, int k) {
        if (n == 1) return k;
        int prev2 = k, prev1 = k * k;
        for (int i = 3; i <= n; i++) {
            int curr = (k - 1) * (prev1 + prev2);
            prev2 = prev1; prev1 = curr;
        }
        return prev1;
    }
};
