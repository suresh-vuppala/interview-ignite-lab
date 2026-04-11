class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # Three passes: rows, columns, boxes
        for i in range(9):
            if not self.check([board[i][j] for j in range(9)]): return False
            if not self.check([board[j][i] for j in range(9)]): return False
        for bi in range(3):
            for bj in range(3):
                if not self.check([board[bi*3+i][bj*3+j] for i in range(3) for j in range(3)]): return False
        return True
    def check(self, cells):
        nums = [c for c in cells if c != '.']
        return len(nums) == len(set(nums))