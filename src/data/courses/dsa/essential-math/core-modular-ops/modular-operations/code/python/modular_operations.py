MOD=10**9+7
def add(a, b): return ((a%MOD)+(b%MOD))%MOD
def sub(a, b): return ((a%MOD)-(b%MOD)+MOD)%MOD
def mul(a, b): return ((a%MOD)*(b%MOD))%MOD
def pow_mod(a, b): r=1; a%=MOD; [(r:=r*a%MOD if b&1 else r) or (a:=a*a%MOD) or (b:=b>>1) for _ in iter(lambda:b,0)]; return r
print(f"(10+20)%MOD: {add(10,20)}"); print(f"2^10%MOD: {pow_mod(2,10)}")