def sieve(n): p=[True]*(n+1); p[0]=p[1]=False; [[(p.__setitem__(j,False)) for j in range(i*i,n+1,i)] for i in range(2,int(n**0.5)+1) if p[i]]; return p
def count_primes(n): return sum(sieve(n))
def spf_array(n): spf=list(range(n+1)); [[spf.__setitem__(j,i) for j in range(i*i,n+1,i) if spf[j]==j] for i in range(2,int(n**0.5)+1) if spf[i]==i]; return spf
print(f"Primes up to 30: {count_primes(30)}")