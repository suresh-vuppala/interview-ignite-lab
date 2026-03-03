def solve_n_queens(n):
    result = []
    board = [['.'] * n for _ in range(n)]
    
    def is_valid(row, col):
        for i in range(row):
            if board[i][col] == 'Q':
                return False
        i, j = row-1, col-1
        while i >= 0 and j >= 0:
            if board[i][j] == 'Q':
                return False
            i, j = i-1, j-1
        i, j = row-1, col+1
        while i >= 0 and j < n:
            if board[i][j] == 'Q':
                return False
            i, j = i-1, j+1
        return True
    
    def backtrack(row):
        if row == n:
            result.append([''.join(row) for row in board])
            return
        for col in range(n):
            if is_valid(row, col):
                board[row][col] = 'Q'
                backtrack(row+1)
                board[row][col] = '.'
    
    backtrack(0)
    return result