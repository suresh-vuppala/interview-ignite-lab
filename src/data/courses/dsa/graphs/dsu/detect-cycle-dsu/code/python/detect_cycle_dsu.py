# ============================================================
# Detect Cycle Using DSU
# ============================================================
class Solution:
    def hasCycle(self, n, edges):
        parent = list(range(n)); rank = [0] * n
        def find(x):
            if parent[x] != x: parent[x] = find(parent[x])
            return parent[x]
        def union(x, y):
            rx, ry = find(x), find(y)
            if rx == ry: return False  # Cycle!
            if rank[rx] < rank[ry]: rx, ry = ry, rx
            parent[ry] = rx
            if rank[rx] == rank[ry]: rank[rx] += 1
            return True
        return any(not union(u, v) for u, v in edges)
