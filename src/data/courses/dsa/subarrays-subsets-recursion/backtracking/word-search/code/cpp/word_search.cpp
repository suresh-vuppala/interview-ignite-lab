#include <vector>
#include <string>
using namespace std;
// ============================================================
// Solution 1: Try all starting cells, DFS — O(M*N*4^L)
// ============================================================
class Solution1 {
    int m, n;
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == (int)word.size()) return true;
        if (i<0||i>=m||j<0||j>=n||board[i][j]!=word[k]) return false;
        char tmp = board[i][j]; board[i][j] = '#'; // Mark visited
        bool found = dfs(board,word,i+1,j,k+1) || dfs(board,word,i-1,j,k+1) ||
                     dfs(board,word,i,j+1,k+1) || dfs(board,word,i,j-1,k+1);
        board[i][j] = tmp; // Unmark
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); n = board[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0)) return true;
        return false;
    }
};

// ============================================================
// Solution 2: Pruned DFS — check character frequency first — O(M*N*4^L)
// ============================================================
#include <unordered_map>
class Solution2 {
    int m, n;
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == (int)word.size()) return true;
        if (i<0||i>=m||j<0||j>=n||board[i][j]!=word[k]) return false;
        char tmp = board[i][j]; board[i][j] = '#';
        bool found = dfs(board,word,i+1,j,k+1) || dfs(board,word,i-1,j,k+1) ||
                     dfs(board,word,i,j+1,k+1) || dfs(board,word,i,j-1,k+1);
        board[i][j] = tmp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(); n = board[0].size();
        // Pre-check: board must have all chars in word
        unordered_map<char,int> boardFreq, wordFreq;
        for (auto& row : board) for (char c : row) boardFreq[c]++;
        for (char c : word) wordFreq[c]++;
        for (auto& [c, cnt] : wordFreq)
            if (boardFreq[c] < cnt) return false; // Impossible!
        // Optimization: if last char is rarer, reverse the word
        if (boardFreq[word[0]] > boardFreq[word.back()])
            reverse(word.begin(), word.end());
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (dfs(board, word, i, j, 0)) return true;
        return false;
    }
};
