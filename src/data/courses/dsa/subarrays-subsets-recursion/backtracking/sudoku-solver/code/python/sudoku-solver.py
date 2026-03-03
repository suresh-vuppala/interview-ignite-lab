def solve_sudoku(board):
    def is_valid(row, col, c):
        for i in range(9):
            if board[row][i] == c or board[i][col] == c or                board[3*(row//3)+i//3][3*(col//3)+i%3] == c:
                return False
        return True
    
    def solve():
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    for c in '123456789':
                        if is_valid(i, j, c):
                            board[i][j] = c
                            if solve():
                                return True
                            board[i][j] = '.'
                    return False
        return True
    
    solve()