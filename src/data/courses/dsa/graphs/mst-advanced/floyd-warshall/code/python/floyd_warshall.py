# ============================================================
# Floyd-Warshall
# ============================================================
class Solution:
    def floydWarshall(self, n, dist):
        INF = float('inf')
        # k MUST be outermost loop
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    if dist[i][k] + dist[k][j] < dist[i][j]:
                        dist[i][j] = dist[i][k] + dist[k][j]
        return dist
