def count_divisors(n): return sum(2 if i*i!=n else 1 for i in range(1,int(n**0.5)+1) if n%i==0)
def sum_divisors(n): return sum(i+n//i if i*i!=n else i for i in range(1,int(n**0.5)+1) if n%i==0)
def all_factors(n): f=[]; [f.extend([i,n//i] if i*i!=n else [i]) for i in range(1,int(n**0.5)+1) if n%i==0]; return sorted(f)
print(f"Divisors of 36: {count_divisors(36)}"); print(f"Sum of divisors of 36: {sum_divisors(36)}"); print(f"All factors of 36: {all_factors(36)}")