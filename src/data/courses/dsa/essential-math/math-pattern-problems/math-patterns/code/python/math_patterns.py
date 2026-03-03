def trailing_zeros(n): c=0; [(c:=c+n) or (n:=n//5) for _ in iter(lambda:n,0)]; return c
def fib_fast(n): return (0,1) if n==0 else (lambda p: ((c:=p[0]*(2*p[1]-p[0])), (d:=p[0]**2+p[1]**2), (d,c+d) if n&1 else (c,d))[-1])(*[fib_fast(n//2)])
def is_perfect_square(n): s=int(n**0.5); return s*s==n
def digit_square_sum(n): s=0; [(s:=s+d*d) or (n:=n//10) for d in iter(lambda:n%10 if n else None,None)]; return s
def is_happy(n): s,f=n,n; [(s:=digit_square_sum(s)) or (f:=digit_square_sum(digit_square_sum(f))) for _ in iter(lambda:s!=f and f!=1,False)]; return f==1
print(f"Trailing zeros in 100!: {trailing_zeros(100)}"); print(f"Fib(10): {fib_fast(10)[0]}"); print(f"16 is perfect square: {is_perfect_square(16)}"); print(f"19 is happy: {is_happy(19)}")