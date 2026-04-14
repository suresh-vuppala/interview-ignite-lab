// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    long solve(int n) {
        if(n<=1) return 1-n; // D(0)=1, D(1)=0
        return (n-1)*(solve(n-1)+solve(n-2));
    }
    long countDerangements(int n) { return solve(n); }
};

// ============================================================
// Solution 2: DP — D(n)=(n-1)*(D(n-1)+D(n-2)) — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    long countDerangements(int n) {
        if(n<=1) return 1-n;
        long a=1, b=0; // D(0)=1, D(1)=0
        for(int i=2;i<=n;i++) { long c=(long)(i-1)*(a+b); a=b; b=c; }
        return b;
    }
};
