class Solution {
    // O(1) time (81 cells) — Track seen digits per row, col, box
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