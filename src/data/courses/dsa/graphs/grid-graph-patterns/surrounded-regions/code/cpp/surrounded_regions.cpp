#include <vector>
#include <queue>
using namespace std;
// ============================================================
// Solution 1: BFS from borders — mark safe, capture rest — O(M*N)
// ============================================================
class Solution1 {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        int dirs[]={0,1,0,-1,0};
        queue<pair<int,int>> q;
        // Mark border-connected O's as safe
        for(int i=0;i<m;i++) for(int j=0;j<n;j++)
            if((i==0||i==m-1||j==0||j==n-1) && board[i][j]=='O') {
                q.push({i,j}); board[i][j]='S';
            }
        while(!q.empty()) {
            auto [r,c]=q.front(); q.pop();
            for(int d=0;d<4;d++) {
                int nr=r+dirs[d],nc=c+dirs[d+1];
                if(nr>=0&&nr<m&&nc>=0&&nc<n&&board[nr][nc]=='O') { board[nr][nc]='S'; q.push({nr,nc}); }
            }
        }
        // Capture remaining O's, restore S's
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
            if(board[i][j]=='O') board[i][j]='X';
            else if(board[i][j]=='S') board[i][j]='O';
        }
    }
};

// ============================================================
// Solution 2: DFS from borders — same logic, recursive — O(M*N)
// ============================================================
class Solution2 {
    void dfs(vector<vector<char>>& b, int i, int j) {
        if(i<0||i>=(int)b.size()||j<0||j>=(int)b[0].size()||b[i][j]!='O') return;
        b[i][j]='S';
        dfs(b,i+1,j); dfs(b,i-1,j); dfs(b,i,j+1); dfs(b,i,j-1);
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(), n=board[0].size();
        for(int i=0;i<m;i++) { dfs(board,i,0); dfs(board,i,n-1); }
        for(int j=0;j<n;j++) { dfs(board,0,j); dfs(board,m-1,j); }
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
            if(board[i][j]=='O') board[i][j]='X';
            else if(board[i][j]=='S') board[i][j]='O';
        }
    }
};
