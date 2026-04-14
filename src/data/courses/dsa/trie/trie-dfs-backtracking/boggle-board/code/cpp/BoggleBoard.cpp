// ============================================================
// Solution 1: DFS per word separately
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
        for (auto& w : words) {  // DFS per word — redundant grid traversal!
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

class BoggleBoard {
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = ""; // Store word at end
    };
    
    int dirs[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}; // 8 directions
    
    void insert(TrieNode* root, string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->word = word; // Store complete word
    }
    
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
        
        char c = board[i][j];
        if (c == '#' || !node->children[c - 'a']) return; // Visited or no path
        
        node = node->children[c - 'a'];
        if (!node->word.empty()) {
            result.push_back(node->word); // Found word
            node->word = ""; // Avoid duplicates
        }
        
        board[i][j] = '#'; // Mark visited
        for (auto& dir : dirs) { // Explore 8 directions
            dfs(board, i + dir[0], j + dir[1], node, result);
        }
        board[i][j] = c; // Backtrack
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
