# ============================================================
# Clone Graph
# ============================================================
class Solution:
    def cloneGraph(self, node):
        if not node: return None
        clone_map = {}
        def dfs(n):
            if n in clone_map: return clone_map[n]
            clone = Node(n.val)
            clone_map[n] = clone
            for nb in n.neighbors: clone.neighbors.append(dfs(nb))
            return clone
        return dfs(node)
