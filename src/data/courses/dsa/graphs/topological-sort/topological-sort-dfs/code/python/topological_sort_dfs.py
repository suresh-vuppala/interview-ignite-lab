# ============================================================
# Topological Sort — DFS
# ============================================================
class Solution:
    def topologicalSort(self, n, adj):
        visited = [False] * n
        stack = []
        def dfs(node):
            visited[node] = True
            for nb in adj[node]:
                if not visited[nb]: dfs(nb)
            stack.append(node)  # Postorder
        for i in range(n):
            if not visited[i]: dfs(i)
        return stack[::-1]  # Reverse postorder = topo order
