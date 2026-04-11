# ============================================================
# Course Schedule I
# ============================================================
from collections import deque
class Solution:
    def canFinish(self, numCourses, prerequisites) -> bool:
        adj = [[] for _ in range(numCourses)]
        in_deg = [0] * numCourses
        for a, b in prerequisites: adj[b].append(a); in_deg[a] += 1
        queue = deque(i for i in range(numCourses) if in_deg[i] == 0)
        count = 0
        while queue:
            node = queue.popleft(); count += 1
            for nb in adj[node]:
                in_deg[nb] -= 1
                if in_deg[nb] == 0: queue.append(nb)
        return count == numCourses
