#include <vector>
#include <string>
using namespace std;
// ============================================================
// Solution 1: Try all N^N placements, validate — O(N^N * N)
// ============================================================
class Solution1 {
    bool isValid(vector<int>& queens, int row) {
        for (int i = 0; i < row; i++) {
            if (queens[i] == queens[row]) return false;
            if (abs(queens[i] - queens[row]) == abs(i - row)) return false;
        }
        return true;
    }
    void solve(int n, int row, vector<int>& queens, vector<vector<string>>& res) {
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++) board[i][queens[i]] = 'Q';
            res.push_back(board); return;
        }
        for (int col = 0; col < n; col++) {
            queens[row] = col;
            if (isValid(queens, row)) solve(n, row + 1, queens, res);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res; vector<int> queens(n);
        solve(n, 0, queens, res); return res;
    }
};

// ============================================================
// Solution 2: Backtracking + column/diagonal sets — O(N!) pruned
// ============================================================
class Solution2 {
    void bt(int n, int row, vector<bool>& cols, vector<bool>& d1, vector<bool>& d2,
            vector<int>& queens, vector<vector<string>>& res) {
        if (row == n) {
            vector<string> board(n, string(n, '.'));
            for (int i = 0; i < n; i++) board[i][queens[i]] = 'Q';
            res.push_back(board); return;
        }
        for (int col = 0; col < n; col++) {
            if (cols[col] || d1[row-col+n-1] || d2[row+col]) continue; // O(1) check!
            cols[col] = d1[row-col+n-1] = d2[row+col] = true;
            queens[row] = col;
            bt(n, row + 1, cols, d1, d2, queens, res);
            cols[col] = d1[row-col+n-1] = d2[row+col] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res; vector<int> queens(n);
        vector<bool> cols(n,false), d1(2*n,false), d2(2*n,false);
        bt(n, 0, cols, d1, d2, queens, res); return res;
    }
};
