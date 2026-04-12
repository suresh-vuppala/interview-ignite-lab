class Solution {
    public int waysToReach(int n) {
        if (n<=1) return 1; if (n==2) return 2;
        int a=1,b=1,c=2;
        for (int i=3;i<=n;i++){int d=a+b+c;a=b;b=c;c=d;} return c;
    }
}