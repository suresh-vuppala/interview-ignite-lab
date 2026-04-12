# ============================================================
# Prim's MST
# ============================================================
import heapq
class Solution:
    def primMST(self, n, adj):
        in_mst = [False] * n
        heap = [(0, 0)]  # (weight, node)
        total = edges = 0
        while heap and edges < n:
            w, u = heapq.heappop(heap)
            if in_mst[u]: continue
            in_mst[u] = True; total += w; edges += 1
            for v, weight in adj[u]:
                if not in_mst[v]: heapq.heappush(heap, (weight, v))
        return total
