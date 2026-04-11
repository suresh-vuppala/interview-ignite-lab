class Solution {
public:
    // Three passes: check rows, columns, boxes separately
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for (int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                if (seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }
        // Check columns
        for (int j = 0; j < 9; j++) {
            unordered_set<char> seen;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;
                if (seen.count(board[i][j])) return false;
                seen.insert(board[i][j]);
            }
        }
        // Check 3x3 boxes
        for (int bi = 0; bi < 3; bi++) {
            for (int bj = 0; bj < 3; bj++) {
                unordered_set<char> seen;
                for (int i = bi*3; i < bi*3+3; i++)
                    for (int j = bj*3; j < bj*3+3; j++) {
                        if (board[i][j] == '.') continue;
                        if (seen.count(board[i][j])) return false;
                        seen.insert(board[i][j]);
                    }
            }
        }
        return true;
    }
};