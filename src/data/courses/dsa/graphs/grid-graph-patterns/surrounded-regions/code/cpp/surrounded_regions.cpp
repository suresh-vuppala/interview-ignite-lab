// ============================================================
// Surrounded Regions
// ============================================================
#include <vector>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        // Mark border-connected O's as safe
        for (int i = 0; i < m; i++) { dfs(board,i,0); dfs(board,i,n-1); }
        for (int j = 0; j < n; j++) { dfs(board,0,j); dfs(board,m-1,j); }
        // Capture remaining O's, restore safe
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X'; // Captured
                if (board[i][j] == 'S') board[i][j] = 'O'; // Restored
            }
    }
    void dfs(vector<vector<char>>& b, int i, int j) {
        if (i<0||i>=(int)b.size()||j<0||j>=(int)b[0].size()||b[i][j]!='O') return;
        b[i][j] = 'S'; // Safe
        dfs(b,i+1,j); dfs(b,i-1,j); dfs(b,i,j+1); dfs(b,i,j-1);
    }
};
