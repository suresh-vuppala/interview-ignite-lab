#include <vector>
using namespace std;
// ============================================================
// Solution 1: Try all empty cells, validate each placement — O(9^81)
// ============================================================
class Solution1 {
    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == ch) return false;
            if (board[i][c] == ch) return false;
            if (board[3*(r/3)+i/3][3*(c/3)+i%3] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false; // No valid digit
                }
        return true; // All filled
    }
public:
    void solveSudoku(vector<vector<char>>& board) { solve(board); }
};

// ============================================================
// Solution 2: Constraint sets (row/col/box bitmasks) — faster pruning
// ============================================================
class Solution2 {
    int row[9]={}, col[9]={}, box[9]={};
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.') {
                    int b = (i/3)*3+j/3;
                    for (int d = 0; d < 9; d++) {
                        int mask = 1 << d;
                        if (row[i]&mask || col[j]&mask || box[b]&mask) continue;
                        row[i]|=mask; col[j]|=mask; box[b]|=mask;
                        board[i][j] = '1' + d;
                        if (solve(board)) return true;
                        board[i][j] = '.';
                        row[i]^=mask; col[j]^=mask; box[b]^=mask;
                    }
                    return false;
                }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;i++) for (int j=0;j<9;j++) if (board[i][j]!='.') {
            int d=board[i][j]-'1', b=(i/3)*3+j/3;
            row[i]|=(1<<d); col[j]|=(1<<d); box[b]|=(1<<d);
        }
        solve(board);
    }
};
