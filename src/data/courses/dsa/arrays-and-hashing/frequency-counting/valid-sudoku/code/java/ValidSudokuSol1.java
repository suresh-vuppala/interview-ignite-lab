class Solution {
    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) { Set<Character> s = new HashSet<>();
            for (int j = 0; j < 9; j++) { if (board[i][j]!='.') if (!s.add(board[i][j])) return false; } }
        for (int j = 0; j < 9; j++) { Set<Character> s = new HashSet<>();
            for (int i = 0; i < 9; i++) { if (board[i][j]!='.') if (!s.add(board[i][j])) return false; } }
        for (int bi=0;bi<3;bi++) for (int bj=0;bj<3;bj++) { Set<Character> s = new HashSet<>();
            for (int i=bi*3;i<bi*3+3;i++) for (int j=bj*3;j<bj*3+3;j++)
                if (board[i][j]!='.') if (!s.add(board[i][j])) return false; }
        return true;
    }
}