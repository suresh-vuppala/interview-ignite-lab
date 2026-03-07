# Time: O(N log N) preprocess, O(log N) query | Space: O(N log N)

class TreeAncestor:
    def __init__(self, n, parent):
        self.LOG = 20
        self.up = [[-1] * self.LOG for _ in range(n)]
        
        for i in range(n):
            self.up[i][0] = parent[i]
        
        for j in range(1, self.LOG):
            for i in range(n):
                if self.up[i][j-1] != -1:
                    self.up[i][j] = self.up[self.up[i][j-1]][j-1]
    
    def getKthAncestor(self, node, k):
        for i in range(self.LOG):
            if k & (1 << i):
                node = self.up[node][i]
                if node == -1:
                    return -1
        return node
