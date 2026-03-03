def mex(s): m=0; [m:=m+1 for _ in iter(lambda:m in s,False)]; return m
def grundy(n, moves): return 0 if n==0 else mex({grundy(n-m,moves) for m in moves if n>=m})
print(f"Grundy(5): {grundy(5,[1,2,3])}")