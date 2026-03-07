// Time: O(N!), Space: O(N)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> cols, diag, antiDiag;
        backtrack(0, n, board, cols, diag, antiDiag, result);
        return result;
    }
    
private:
    void backtrack(int row, int n, vector<string>& board, unordered_set<int>& cols, unordered_set<int>& diag, unordered_set<int>& antiDiag, vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (cols.count(col) || diag.count(row - col) || antiDiag.count(row + col)) continue;
            
            board[row][col] = 'Q';
            cols.insert(col);
            diag.insert(row - col);
            antiDiag.insert(row + col);
            
            backtrack(row + 1, n, board, cols, diag, antiDiag, result);
            
            board[row][col] = '.';
            cols.erase(col);
            diag.erase(row - col);
            antiDiag.erase(row + col);
        }
    }
};

int main() {
    Solution sol;
    vector<vector<string>> result = sol.solveNQueens(4);
    for (auto& solution : result) {
        for (auto& row : solution) cout << row << endl;
        cout << endl;
    }
    return 0;
}
