// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
    static const int MOD=1e9+7;
public:
    long solve(int n) {
        if(n<=0) return n==0;
        if(n==1) return 1;
        if(n==2) return 2;
        return (solve(n-1)+solve(n-2)+2*solve(n-3))%MOD;
    }
    int numTilings(int n) { return solve(n); }
};

// ============================================================
// Solution 2: DP — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
    static const int MOD=1e9+7;
public:
    int numTilings(int n) {
        if(n<=2) return n;
        long a=1, b=1, c=2;
        for(int i=3;i<=n;i++) {
            long d=(c+b+2*a)%MOD;
            a=b; b=c; c=d;
        }
        return c;
    }
};
