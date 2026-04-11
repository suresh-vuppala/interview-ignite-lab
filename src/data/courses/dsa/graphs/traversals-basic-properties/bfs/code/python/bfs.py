# ============================================================
# BFS
# ============================================================
from collections import deque
class Solution:
    def bfs(self, n, adj, start):
        result, visited = [], [False] * n
        queue = deque([start])
        visited[start] = True
        while queue:
            node = queue.popleft()
            result.append(node)
            for neighbor in adj[node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)
        return result
