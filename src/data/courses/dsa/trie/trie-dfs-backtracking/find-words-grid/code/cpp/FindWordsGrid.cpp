// ============================================================
// Solution 1: DFS per word separately (same as boggle brute)
// Time: O(W * M * N * 4^L) | Space: O(L)
// ============================================================
#include <vector>
#include <string>
using namespace std;

class Solution1 {
    int m, n;
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == (int)word.size()) return true;
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[k]) return false;
        char tmp = board[i][j]; board[i][j] = '#';
        bool found = dfs(board,word,i+1,j,k+1) || dfs(board,word,i-1,j,k+1) ||
                     dfs(board,word,i,j+1,k+1) || dfs(board,word,i,j-1,k+1);
        board[i][j] = tmp;
        return found;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(); n = board[0].size();
        vector<string> result;
        for (auto& w : words) {
            bool found = false;
            for (int i = 0; i < m && !found; i++)
                for (int j = 0; j < n && !found; j++)
                    if (dfs(board, w, i, j, 0)) found = true;
            if (found) result.push_back(w);
        }
        return result;
    }
};

// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
#include <vector>
#include <string>
using namespace std;

class Solution2 {
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };
    
    void insert(TrieNode* root, string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word;
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return;
        
        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";
        }
        
        board[i][j] = '#';
        dfs(board, i + 1, j, node, result);
        dfs(board, i - 1, j, node, result);
        dfs(board, i, j + 1, node, result);
        dfs(board, i, j - 1, node, result);
        board[i][j] = c;
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& word : words) insert(root, word);
        
        vector<string> result;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root, result);
            }
        }
        return result;
    }
};
