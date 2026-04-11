# ============================================================
# Valid Sudoku
# ============================================================

from typing import List

# ============================================================
# Solution 1: Three Separate Passes
# Time: O(1) | Space: O(1)
# ============================================================
class Solution1:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Check rows
        for i in range(9):
            seen = set()
            for j in range(9):
                if board[i][j] != '.':
                    if board[i][j] in seen: return False
                    seen.add(board[i][j])

        # Check columns
        for j in range(9):
            seen = set()
            for i in range(9):
                if board[i][j] != '.':
                    if board[i][j] in seen: return False
                    seen.add(board[i][j])

        # Check 3×3 boxes
        for bi in range(3):
            for bj in range(3):
                seen = set()
                for i in range(bi*3, bi*3+3):
                    for j in range(bj*3, bj*3+3):
                        if board[i][j] != '.':
                            if board[i][j] in seen: return False
                            seen.add(board[i][j])

        return True

# ============================================================
# Solution 2: Single Pass with Encoded Set (Optimal)
# Time: O(1) | Space: O(1)
# ============================================================
class Solution2:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        seen = set()

        for i in range(9):
            for j in range(9):
                d = board[i][j]
                if d == '.':
                    continue

                # Encode three constraints as tuples
                row = (d, 'row', i)
                col = (d, 'col', j)
                box = (d, 'box', i // 3, j // 3)

                if row in seen or col in seen or box in seen:
                    return False

                seen.update([row, col, box])

        return True
