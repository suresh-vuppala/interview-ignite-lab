# ============================================================
# Detect Cycle Directed
# ============================================================
class Solution:
    def hasCycle(self, n, adj):
        color = [0] * n  # 0=white, 1=gray, 2=black
        def dfs(node):
            color[node] = 1  # Gray
            for nb in adj[node]:
                if color[nb] == 1: return True  # Back edge = cycle
                if color[nb] == 0 and dfs(nb): return True
            color[node] = 2  # Black
            return False
        return any(color[i] == 0 and dfs(i) for i in range(n))
