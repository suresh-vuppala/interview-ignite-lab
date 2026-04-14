// ============================================================
// Solution 1: DFS per word — search each word independently
// Time: O(W × M × N × 4^L) | Space: O(L)
// ============================================================
#include <vector>
#include <string>
using namespace std;

class Solution1 {
    int m, n;
    bool dfs(vector<vector<char>>& board, string& word, int i, int r, int c) {
        if (i == (int)word.size()) return true;
        if (r<0||r>=m||c<0||c>=n||board[r][c]!=word[i]) return false;
        char tmp = board[r][c]; board[r][c] = '#';
        bool found = dfs(board,word,i+1,r+1,c) || dfs(board,word,i+1,r-1,c)
                  || dfs(board,word,i+1,r,c+1) || dfs(board,word,i+1,r,c-1);
        board[r][c] = tmp;
        return found;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(); n = board[0].size();
        vector<string> result;
        for (auto& w : words) { // Search EACH word separately — slow!
            bool found = false;
            for (int r = 0; r < m && !found; r++)
                for (int c = 0; c < n && !found; c++)
                    if (dfs(board, w, 0, r, c)) found = true;
            if (found) result.push_back(w);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Trie + single DFS — search all words at once
// Time: O(M × N × 4^L) | Space: O(W × L)
// ============================================================
class Solution2 {
    struct TrieNode {
        TrieNode* ch[26] = {};
        string* word = nullptr; // Store word at end node
    };
    int m, n;
    vector<string> result;
    
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        if (r<0||r>=m||c<0||c>=n||board[r][c]=='#') return;
        char ch = board[r][c];
        TrieNode* next = node->ch[ch-'a'];
        if (!next) return; // No word in trie matches — PRUNE!
        if (next->word) { result.push_back(*next->word); next->word = nullptr; } // Found!
        board[r][c] = '#'; // Mark visited
        dfs(board,r+1,c,next); dfs(board,r-1,c,next);
        dfs(board,r,c+1,next); dfs(board,r,c-1,next);
        board[r][c] = ch; // Unmark
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        // Build trie from all words
        for (auto& w : words) {
            TrieNode* n = root;
            for (char c : w) {
                if (!n->ch[c-'a']) n->ch[c-'a'] = new TrieNode();
                n = n->ch[c-'a'];
            }
            n->word = &w;
        }
        m = board.size(); n = board[0].size();
        // Single DFS guided by trie
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                dfs(board, r, c, root);
        return result;
    }
};
