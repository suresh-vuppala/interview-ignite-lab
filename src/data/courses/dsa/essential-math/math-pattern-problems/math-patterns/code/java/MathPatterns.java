public class MathPatterns {
    int trailingZeros(int n) { int c=0; while(n>0) { n/=5; c+=n; } return c; }
    long[] fibFast(int n) { if(n==0) return new long[]{0,1}; long[] p=fibFast(n/2); long c=p[0]*(2*p[1]-p[0]); long d=p[0]*p[0]+p[1]*p[1]; return (n&1)==0?new long[]{c,d}:new long[]{d,c+d}; }
    boolean isPerfectSquare(int n) { int s=(int)Math.sqrt(n); return s*s==n; }
    boolean isHappy(int n) { int s=n,f=n; do { s=digitSquareSum(s); f=digitSquareSum(digitSquareSum(f)); } while(s!=f&&f!=1); return f==1; }
    int digitSquareSum(int n) { int s=0; while(n>0) { int d=n%10; s+=d*d; n/=10; } return s; }
    public static void main(String[] a) { MathPatterns m=new MathPatterns(); System.out.println("Trailing zeros in 100!: "+m.trailingZeros(100)); System.out.println("Fib(10): "+m.fibFast(10)[0]); System.out.println("16 is perfect square: "+m.isPerfectSquare(16)); System.out.println("19 is happy: "+m.isHappy(19)); }
}