# Time: O(N!), Space: O(N)

def solve_n_queens(n):
    result = []
    board = [['.' for _ in range(n)] for _ in range(n)]
    cols = set()
    diag = set()
    anti_diag = set()
    
    def backtrack(row):
        if row == n:
            result.append([''.join(r) for r in board])
            return
        
        for col in range(n):
            if col in cols or (row - col) in diag or (row + col) in anti_diag:
                continue
            
            board[row][col] = 'Q'
            cols.add(col)
            diag.add(row - col)
            anti_diag.add(row + col)
            
            backtrack(row + 1)
            
            board[row][col] = '.'
            cols.remove(col)
            diag.remove(row - col)
            anti_diag.remove(row + col)
    
    backtrack(0)
    return result

print(solve_n_queens(4))
