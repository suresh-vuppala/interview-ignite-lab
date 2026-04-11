# ============================================================
# Detect Cycle Undirected
# ============================================================
class Solution:
    def hasCycle(self, n, adj):
        visited = [False] * n
        def dfs(node, parent):
            visited[node] = True
            for nb in adj[node]:
                if not visited[nb]:
                    if dfs(nb, node): return True
                elif nb != parent:
                    return True  # Cycle!
            return False
        return any(not visited[i] and dfs(i, -1) for i in range(n))
