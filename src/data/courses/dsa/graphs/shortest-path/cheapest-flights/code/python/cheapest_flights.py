# ============================================================
# Cheapest Flights Within K Stops
# ============================================================
class Solution:
    def findCheapestPrice(self, n, flights, src, dst, k) -> int:
        dist = [float('inf')] * n
        dist[src] = 0
        # Bellman-Ford: k+1 iterations
        for _ in range(k + 1):
            prev = dist[:]  # Use previous round's distances
            for u, v, w in flights:
                if prev[u] + w < dist[v]:
                    dist[v] = prev[u] + w
        return dist[dst] if dist[dst] < float('inf') else -1
