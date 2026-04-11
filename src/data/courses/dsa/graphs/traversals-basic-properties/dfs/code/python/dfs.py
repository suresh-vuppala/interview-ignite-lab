# ============================================================
# DFS
# ============================================================
class Solution:
    def dfs(self, n, adj, start):
        result, visited = [], [False] * n
        def helper(node):
            visited[node] = True
            result.append(node)
            for nb in adj[node]:
                if not visited[nb]: helper(nb)
        helper(start)
        return result
