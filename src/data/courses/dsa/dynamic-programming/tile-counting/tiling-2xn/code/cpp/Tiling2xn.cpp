// ============================================================
// Solution 1: Recursion — O(2^N) Time
// ============================================================
class Solution1 {
public:
    int numTilings(int n) {
        if(n<=1) return 1;
        return numTilings(n-1)+numTilings(n-2);
    }
};

// ============================================================
// Solution 2: DP — Fibonacci — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int numTilings(int n) {
        if(n<=1) return 1;
        int a=1, b=1;
        for(int i=2;i<=n;i++) { int c=a+b; a=b; b=c; }
        return b;
    }
};
