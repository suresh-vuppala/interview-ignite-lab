# ============================================================
# Shortest Path Weighted
# ============================================================
import heapq
class Solution:
    def shortestPath(self, n, adj, src, dst):
        dist = [float('inf')] * n
        parent = [-1] * n
        dist[src] = 0
        heap = [(0, src)]
        while heap:
            d, u = heapq.heappop(heap)
            if d > dist[u]: continue
            for v, w in adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    parent[v] = u
                    heapq.heappush(heap, (dist[v], v))
        # Reconstruct path
        if dist[dst] == float('inf'): return -1, []
        path = []
        v = dst
        while v != -1: path.append(v); v = parent[v]
        return dist[dst], path[::-1]
