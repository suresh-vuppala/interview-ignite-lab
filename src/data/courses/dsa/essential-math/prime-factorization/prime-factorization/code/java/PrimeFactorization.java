import java.util.*;
public class PrimeFactorization {
    List<Integer> factorize(int n) { List<Integer> f=new ArrayList<>(); for(int i=2;i*i<=n;i++) while(n%i==0) { f.add(i); n/=i; } if(n>1) f.add(n); return f; }
    int countDistinct(int n) { Set<Integer> s=new HashSet<>(); for(int i=2;i*i<=n;i++) { if(n%i==0) s.add(i); while(n%i==0) n/=i; } if(n>1) s.add(n); return s.size(); }
    int countTotal(int n) { int c=0; for(int i=2;i*i<=n;i++) while(n%i==0) { c++; n/=i; } if(n>1) c++; return c; }
    public static void main(String[] a) { PrimeFactorization p=new PrimeFactorization(); System.out.println("Factors of 60: "+p.factorize(60)); System.out.println("Distinct factors of 60: "+p.countDistinct(60)); System.out.println("Total factors of 60: "+p.countTotal(60)); }
}