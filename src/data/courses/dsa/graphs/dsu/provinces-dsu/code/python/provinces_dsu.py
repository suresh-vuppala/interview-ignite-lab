# ============================================================
# Provinces DSU
# ============================================================
class Solution:
    def findCircleNum(self, isConnected) -> int:
        n = len(isConnected)
        parent = list(range(n)); rank = [0]*n
        def find(x):
            if parent[x]!=x: parent[x]=find(parent[x])
            return parent[x]
        def union(x,y):
            rx,ry=find(x),find(y)
            if rx==ry: return
            if rank[rx]<rank[ry]: rx,ry=ry,rx
            parent[ry]=rx
            if rank[rx]==rank[ry]: rank[rx]+=1
        for i in range(n):
            for j in range(i+1,n):
                if isConnected[i][j]==1: union(i,j)
        return sum(1 for i in range(n) if find(i)==i)
