class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # O(1) time — Track digits per row, col, 3x3 box
        seen = set()
        for i in range(9):
            for j in range(9):
                d = board[i][j]
                if d == '.': continue
                row = (d, 'row', i)
                col = (d, 'col', j)
                box = (d, 'box', i//3, j//3)
                if row in seen or col in seen or box in seen:
                    return False
                seen.update([row, col, box])
        return True