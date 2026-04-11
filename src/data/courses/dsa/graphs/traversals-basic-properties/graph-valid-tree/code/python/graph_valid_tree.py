class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1: return False  # Tree must have n-1 edges
        adj = [[] for _ in range(n)]
        for u, v in edges: adj[u].append(v); adj[v].append(u)
        visited = set([0])
        queue = [0]
        while queue:
            node = queue.pop(0)
            for nb in adj[node]:
                if nb not in visited: visited.add(nb); queue.append(nb)
        return len(visited) == n