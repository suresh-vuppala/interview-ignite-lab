// ============================================================
// Solution 1: Recursion — O(3^N) Time (1,2,3 steps)
// ============================================================
class Solution1 {
public:
    int countWays(int n) {
        if(n<0) return 0;
        if(n<=1) return 1;
        return countWays(n-1)+countWays(n-2)+countWays(n-3);
    }
};

// ============================================================
// Solution 2: DP — O(N) Time, O(1) Space
// ============================================================
class Solution2 {
public:
    int countWays(int n) {
        if(n<=1) return 1;
        int a=1, b=1, c=2;
        for(int i=3;i<=n;i++) { int d=a+b+c; a=b; b=c; c=d; }
        return c;
    }
};
