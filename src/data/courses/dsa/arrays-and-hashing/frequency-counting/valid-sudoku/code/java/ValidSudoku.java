// ============================================================
// Valid Sudoku
// ============================================================

import java.util.*;

// ============================================================
// Solution 1: Three Separate Passes
// Time: O(1) | Space: O(1)
// ============================================================
class Solution1 {
    public boolean isValidSudoku(char[][] board) {
        // Check rows, columns, and boxes separately
        for (int i = 0; i < 9; i++) {
            Set<Character> row = new HashSet<>(), col = new HashSet<>();
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.' && !row.add(board[i][j])) return false;
                if (board[j][i] != '.' && !col.add(board[j][i])) return false;
            }
        }
        for (int bi = 0; bi < 3; bi++) {
            for (int bj = 0; bj < 3; bj++) {
                Set<Character> box = new HashSet<>();
                for (int i = bi*3; i < bi*3+3; i++)
                    for (int j = bj*3; j < bj*3+3; j++)
                        if (board[i][j] != '.' && !box.add(board[i][j])) return false;
            }
        }
        return true;
    }
}

// ============================================================
// Solution 2: Single Pass with Encoded Set (Optimal)
// Time: O(1) | Space: O(1)
// ============================================================
class Solution2 {
    public boolean isValidSudoku(char[][] board) {
        Set<String> seen = new HashSet<>();

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                char d = board[i][j];

                if (!seen.add(d + " row " + i) ||
                    !seen.add(d + " col " + j) ||
                    !seen.add(d + " box " + i/3 + "-" + j/3))
                    return false;
            }
        }

        return true;
    }
}
