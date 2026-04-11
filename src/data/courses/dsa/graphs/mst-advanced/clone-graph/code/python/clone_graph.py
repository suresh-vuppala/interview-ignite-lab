class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node: return None
        visited = {}
        def dfs(n):
            if n in visited: return visited[n]
            clone = Node(n.val)
            visited[n] = clone
            clone.neighbors = [dfs(nb) for nb in n.neighbors]
            return clone
        return dfs(node)