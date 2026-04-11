# ============================================================
# Eventual Safe States
# ============================================================
class Solution:
    def eventualSafeNodes(self, graph):
        n = len(graph)
        color = [0] * n  # 0=white, 1=gray, 2=black(safe)
        def is_safe(node):
            if color[node] != 0: return color[node] == 2
            color[node] = 1  # Gray
            for nb in graph[node]:
                if not is_safe(nb): return False
            color[node] = 2  # Safe
            return True
        return [i for i in range(n) if is_safe(i)]
