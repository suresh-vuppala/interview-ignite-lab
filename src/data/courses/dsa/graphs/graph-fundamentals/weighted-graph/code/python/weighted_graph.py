# ============================================================
# Weighted Graph
# ============================================================
from collections import defaultdict
class Solution:
    def buildWeightedGraph(self, n, edges):
        adj = defaultdict(list)
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))
        return adj
