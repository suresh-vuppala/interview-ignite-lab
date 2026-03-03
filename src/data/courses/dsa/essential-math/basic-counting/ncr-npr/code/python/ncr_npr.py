def nCr(n, r): r=min(r,n-r); res=1; [res:=res*(n-i)//(i+1) for i in range(r)]; return res
def nPr(n, r): res=1; [res:=res*(n-i) for i in range(r)]; return res
def pascal(n): c=[[0]*(n+1) for _ in range(n+1)]; [[c[i].__setitem__(0,1)] or [c[i].__setitem__(j,c[i-1][j-1]+c[i-1][j]) for j in range(1,i+1)] for i in range(n+1)]; return c
print(f"C(5,2): {nCr(5,2)}"); print(f"P(5,2): {nPr(5,2)}")