# ============================================================
# Kahn's Topological Sort
# ============================================================
from collections import deque
class Solution:
    def topologicalSort(self, n, adj):
        in_deg = [0] * n
        for u in range(n):
            for v in adj[u]: in_deg[v] += 1
        queue = deque(i for i in range(n) if in_deg[i] == 0)
        result = []
        while queue:
            node = queue.popleft()
            result.append(node)
            for nb in adj[node]:
                in_deg[nb] -= 1
                if in_deg[nb] == 0: queue.append(nb)
        return result  # len < n means cycle
