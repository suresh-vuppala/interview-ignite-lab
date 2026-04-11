# ============================================================
# Build Graph — Adjacency List
# ============================================================
from collections import defaultdict
class Solution:
    def buildGraph(self, n, edges):
        adj = defaultdict(list)
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)  # Undirected
        return adj
