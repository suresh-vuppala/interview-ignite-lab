# ============================================================
# Pascal's Triangle
# ============================================================

from typing import List

# ============================================================
# Solution: Row-by-Row Construction (Optimal)
# Time: O(N²) | Space: O(1) extra
# ============================================================
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        result = []

        for i in range(numRows):
            # Start with all 1s
            row = [1] * (i + 1)

            # Fill interior: sum of two elements above
            for j in range(1, i):
                row[j] = result[i - 1][j - 1] + result[i - 1][j]

            result.append(row)

        return result
