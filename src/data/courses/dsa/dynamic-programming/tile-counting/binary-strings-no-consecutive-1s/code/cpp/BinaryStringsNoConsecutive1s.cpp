// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int solve(int n, int last) {
        if(n==0) return 1;
        int res=solve(n-1,0); // place 0
        if(last!=1) res+=solve(n-1,1); // place 1 if last wasn't 1
        return res;
    }
    int countStrings(int n) { return solve(n,0); }
};

// ============================================================
// Solution 2: DP — Fibonacci variant — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int countStrings(int n) {
        // end0[i]=strings of len i ending in 0, end1[i]=ending in 1
        int end0=1, end1=1;
        for(int i=2;i<=n;i++) {
            int new0=end0+end1;
            int new1=end0;
            end0=new0; end1=new1;
        }
        return end0+end1;
    }
};
