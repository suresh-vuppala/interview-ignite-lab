# ============================================================
# Dijkstra's Algorithm
# ============================================================
import heapq

class Solution:
    def dijkstra(self, n, adj, src):
        dist = [float('inf')] * n
        dist[src] = 0
        heap = [(0, src)]  # (distance, node)

        while heap:
            d, u = heapq.heappop(heap)

            if d > dist[u]:
                continue  # Stale entry

            for v, w in adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    heapq.heappush(heap, (dist[v], v))

        return dist
