public class DecimalBinary {
    String decToBin(int n) { return Integer.toBinaryString(n); }
    int binToDec(String s) { return Integer.parseInt(s,2); }
    boolean isPowerOfTwo(int n) { return n>0&&(n&(n-1))==0; }
    int countSetBits(int n) { int c=0; while(n>0) { n&=n-1; c++; } return c; }
    long fastPow(long a, long b) { long r=1; while(b>0) { if((b&1)==1) r*=a; a*=a; b>>=1; } return r; }
    public static void main(String[] args) { DecimalBinary d=new DecimalBinary(); System.out.println("13 to binary: "+d.decToBin(13)); System.out.println("1101 to decimal: "+d.binToDec("1101")); System.out.println("16 is power of 2: "+d.isPowerOfTwo(16)); System.out.println("Set bits in 13: "+d.countSetBits(13)); System.out.println("2^10: "+d.fastPow(2,10)); }
}