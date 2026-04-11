# ============================================================
# Find Degree
# ============================================================
class Solution:
    def findDegree(self, n, edges):
        degree = [0] * n
        for u, v in edges:
            degree[u] += 1
            degree[v] += 1
        return degree
