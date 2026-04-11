# ============================================================
# Number of Provinces
# ============================================================
class Solution:
    def findCircleNum(self, isConnected) -> int:
        n, count = len(isConnected), 0
        visited = [False] * n
        def dfs(city):
            visited[city] = True
            for j in range(n):
                if isConnected[city][j] == 1 and not visited[j]: dfs(j)
        for i in range(n):
            if not visited[i]: count += 1; dfs(i)
        return count
