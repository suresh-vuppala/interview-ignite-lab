# ============================================================
# Count Connected Components
# ============================================================
class Solution:
    def countComponents(self, n, adj):
        visited = [False] * n
        count = 0
        def dfs(node):
            visited[node] = True
            for nb in adj[node]:
                if not visited[nb]: dfs(nb)
        for i in range(n):
            if not visited[i]:
                count += 1; dfs(i)
        return count
