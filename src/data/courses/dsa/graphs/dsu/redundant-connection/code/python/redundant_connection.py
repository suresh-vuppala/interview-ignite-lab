# ============================================================
# Redundant Connection
# ============================================================
class Solution:
    def findRedundantConnection(self, edges):
        n = len(edges)
        parent = list(range(n+1)); rank = [0]*(n+1)
        def find(x):
            if parent[x]!=x: parent[x]=find(parent[x])
            return parent[x]
        def union(x,y):
            rx,ry=find(x),find(y)
            if rx==ry: return False
            if rank[rx]<rank[ry]: rx,ry=ry,rx
            parent[ry]=rx; if rank[rx]==rank[ry]: rank[rx]+=1
            return True
        for u,v in edges:
            if not union(u,v): return [u,v]
