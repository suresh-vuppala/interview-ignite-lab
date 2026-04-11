# ============================================================
# Check Bipartite
# ============================================================
from collections import deque
class Solution:
    def isBipartite(self, adj):
        n = len(adj)
        color = [-1] * n
        for i in range(n):
            if color[i] != -1: continue
            queue = deque([i]); color[i] = 0
            while queue:
                node = queue.popleft()
                for nb in adj[node]:
                    if color[nb] == -1:
                        color[nb] = 1 - color[node]
                        queue.append(nb)
                    elif color[nb] == color[node]:
                        return False
        return True
