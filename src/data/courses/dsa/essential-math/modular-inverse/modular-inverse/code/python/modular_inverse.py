def ext_gcd(a, b): return (a,1,0) if b==0 else (lambda g,x1,y1: (g,y1,x1-a//b*y1))(*ext_gcd(b,a%b))
def mod_inv_euclid(a, m): g,x,y=ext_gcd(a,m); return (x%m+m)%m if g==1 else -1
def pow_mod(a, b, m): r=1; a%=m; [(r:=r*a%m if b&1 else r) or (a:=a*a%m) or (b:=b>>1) for _ in iter(lambda:b,0)]; return r
def mod_inv_fermat(a, m): return pow_mod(a,m-2,m)
MOD=10**9+7; print(f"Inverse of 3 mod {MOD}: {mod_inv_fermat(3,MOD)}")