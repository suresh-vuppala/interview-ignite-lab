# ============================================================
# Kruskal's MST
# ============================================================
class Solution:
    def kruskalMST(self, n, edges):
        parent = list(range(n)); rank = [0]*n
        def find(x):
            if parent[x]!=x: parent[x]=find(parent[x])
            return parent[x]
        def union(x,y):
            rx,ry=find(x),find(y)
            if rx==ry: return False
            if rank[rx]<rank[ry]: rx,ry=ry,rx
            parent[ry]=rx; if rank[rx]==rank[ry]: rank[rx]+=1
            return True
        edges.sort(key=lambda e: e[2])  # Sort by weight
        total = count = 0
        for u, v, w in edges:
            if union(u, v): total += w; count += 1
            if count == n - 1: break
        return total
