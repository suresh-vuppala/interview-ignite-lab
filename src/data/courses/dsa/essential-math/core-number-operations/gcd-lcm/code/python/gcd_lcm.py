def gcd(a, b): return a if b==0 else gcd(b, a%b)
def lcm(a, b): return a*b//gcd(a,b)
def coprime(a, b): return gcd(a,b)==1
def ext_gcd(a, b):
    if b==0: return a,1,0
    g,x1,y1=ext_gcd(b,a%b); return g,y1,x1-a//b*y1
print(f"GCD(12,18): {gcd(12,18)}"); print(f"LCM(12,18): {lcm(12,18)}")