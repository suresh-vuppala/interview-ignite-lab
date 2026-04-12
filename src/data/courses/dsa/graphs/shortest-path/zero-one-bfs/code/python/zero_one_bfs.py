# ============================================================
# 0-1 BFS
# ============================================================
from collections import deque
class Solution:
    def zeroOneBFS(self, n, adj, src):
        dist = [float('inf')] * n
        dist[src] = 0
        dq = deque([src])
        while dq:
            u = dq.popleft()
            for v, w in adj[u]:
                if dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    if w == 0: dq.appendleft(v)  # Front
                    else: dq.append(v)             # Back
        return dist
