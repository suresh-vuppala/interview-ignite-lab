# ============================================================
# Bellman-Ford
# ============================================================
class Solution:
    def bellmanFord(self, n, edges, src):
        dist = [float('inf')] * n; dist[src] = 0
        for _ in range(n - 1):
            for u, v, w in edges:
                if dist[u] + w < dist[v]: dist[v] = dist[u] + w
        # Negative cycle check
        for u, v, w in edges:
            if dist[u] + w < dist[v]: return None
        return dist
