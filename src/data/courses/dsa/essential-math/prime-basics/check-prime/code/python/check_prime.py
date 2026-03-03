def is_prime(n): return n>1 and all(n%i for i in range(2,int(n**0.5)+1))
def count_primes(n): return sum(is_prime(i) for i in range(2,n))
def nth_prime(n): c,num=0,2; [(c:=c+1) if is_prime(num) else None or (num:=num+1) for _ in iter(lambda:c<n,False)]; return num
print(f"17 is prime: {is_prime(17)}"); print(f"Primes up to 20: {count_primes(20)}"); print(f"10th prime: {nth_prime(10)}")