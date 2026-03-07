# Time: O(N × M × 4^L), Space: O(L)

def exist(board, word):
    m, n = len(board), len(board[0])
    
    def dfs(i, j, index):
        if index == len(word):
            return True
        if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[index]:
            return False
        
        temp = board[i][j]
        board[i][j] = '#'
        
        found = (dfs(i+1, j, index+1) or
                 dfs(i-1, j, index+1) or
                 dfs(i, j+1, index+1) or
                 dfs(i, j-1, index+1))
        
        board[i][j] = temp
        return found
    
    for i in range(m):
        for j in range(n):
            if dfs(i, j, 0):
                return True
    return False

board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
word = "ABCCED"
print(exist(board, word))
