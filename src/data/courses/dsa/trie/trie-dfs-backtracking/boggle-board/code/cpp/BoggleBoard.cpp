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
