# ============================================================
# Graph Valid Tree
# ============================================================
from collections import deque
class Solution:
    def validTree(self, n, edges):
        if len(edges) != n - 1: return False
        adj = [[] for _ in range(n)]
        for u, v in edges: adj[u].append(v); adj[v].append(u)
        visited = [False] * n
        queue = deque([0]); visited[0] = True; count = 0
        while queue:
            node = queue.popleft(); count += 1
            for nb in adj[node]:
                if not visited[nb]: visited[nb] = True; queue.append(nb)
        return count == n
