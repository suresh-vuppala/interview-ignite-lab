#include <vector>
#include <string>
using namespace std;

bool isValid(vector<string>& board, int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row-1, j = col+1; i >= 0 && j < board.size(); i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}

void backtrack(vector<string>& board, int row, vector<vector<string>>& result) {
    if (row == board.size()) {
        result.push_back(board);
        return;
    }
    for (int col = 0; col < board.size(); col++) {
        if (isValid(board, row, col)) {
            board[row][col] = 'Q';
            backtrack(board, row+1, result);
            board[row][col] = '.';
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    backtrack(board, 0, result);
    return result;
}