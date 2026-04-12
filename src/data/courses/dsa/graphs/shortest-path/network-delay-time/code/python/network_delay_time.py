# ============================================================
# Network Delay Time
# ============================================================
import heapq
class Solution:
    def networkDelayTime(self, times, n, k) -> int:
        adj = [[] for _ in range(n+1)]
        for u, v, w in times: adj[u].append((v, w))
        dist = [float('inf')] * (n+1); dist[k] = 0
        heap = [(0, k)]
        while heap:
            d, u = heapq.heappop(heap)
            if d > dist[u]: continue
            for v, w in adj[u]:
                if dist[u]+w < dist[v]: dist[v] = dist[u]+w; heapq.heappush(heap, (dist[v], v))
        max_dist = max(dist[1:])
        return max_dist if max_dist < float('inf') else -1
