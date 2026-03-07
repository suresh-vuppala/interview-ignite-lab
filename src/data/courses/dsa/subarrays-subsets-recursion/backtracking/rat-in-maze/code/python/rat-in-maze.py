# Time: O(4^(N×M)), Space: O(N×M)

def find_path(maze):
    result = []
    n = len(maze)
    if n == 0 or maze[0][0] == 0 or maze[n-1][n-1] == 0:
        return result
    
    visited = [[False] * n for _ in range(n)]
    
    def backtrack(i, j, path):
        if i == n-1 and j == n-1:
            result.append(path)
            return
        
        visited[i][j] = True
        
        if i+1 < n and maze[i+1][j] == 1 and not visited[i+1][j]:
            backtrack(i+1, j, path + "D")
        if j-1 >= 0 and maze[i][j-1] == 1 and not visited[i][j-1]:
            backtrack(i, j-1, path + "L")
        if j+1 < n and maze[i][j+1] == 1 and not visited[i][j+1]:
            backtrack(i, j+1, path + "R")
        if i-1 >= 0 and maze[i-1][j] == 1 and not visited[i-1][j]:
            backtrack(i-1, j, path + "U")
        
        visited[i][j] = False
    
    backtrack(0, 0, "")
    return result

maze = [[1,0,0,0],[1,1,0,1],[0,1,0,0],[1,1,1,1]]
print(find_path(maze))
