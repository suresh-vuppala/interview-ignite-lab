// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int numWays(int n, int k) {
        if(n==0) return 0;
        if(n==1) return k;
        if(n==2) return k*k;
        return (k-1) * (numWays(n-1,k) + numWays(n-2,k));
    }
};

// ============================================================
// Solution 2: DP — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int numWays(int n, int k) {
        if(n==0) return 0;
        if(n==1) return k;
        int prev2=k, prev1=k*k;
        for(int i=3;i<=n;i++) {
            int curr=(k-1)*(prev1+prev2);
            prev2=prev1; prev1=curr;
        }
        return prev1;
    }
};
