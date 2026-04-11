# ============================================================
# Course Schedule II
# ============================================================
from collections import deque
class Solution:
    def findOrder(self, numCourses, prerequisites):
        adj = [[] for _ in range(numCourses)]
        in_deg = [0] * numCourses
        for a, b in prerequisites: adj[b].append(a); in_deg[a] += 1
        queue = deque(i for i in range(numCourses) if in_deg[i] == 0)
        order = []
        while queue:
            node = queue.popleft(); order.append(node)
            for nb in adj[node]:
                in_deg[nb] -= 1
                if in_deg[nb] == 0: queue.append(nb)
        return order if len(order) == numCourses else []
