public class CheckPrime {
    boolean isPrime(int n) { if(n<2) return false; for(int i=2;i*i<=n;i++) if(n%i==0) return false; return true; }
    int countPrimes(int n) { int c=0; for(int i=2;i<n;i++) if(isPrime(i)) c++; return c; }
    int nthPrime(int n) { int c=0,num=2; while(c<n) { if(isPrime(num)) c++; if(c<n) num++; } return num; }
    public static void main(String[] a) { CheckPrime p=new CheckPrime(); System.out.println("17 is prime: "+p.isPrime(17)); System.out.println("Primes up to 20: "+p.countPrimes(20)); System.out.println("10th prime: "+p.nthPrime(10)); }
}