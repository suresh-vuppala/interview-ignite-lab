#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Time: O(N*L) build, O(26^W*N*L) search | Space: O(N*L)

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
    string word;
};

class Solution {
    TrieNode* root;
    
    void dfs(TrieNode* node, const string& pattern, int index, vector<string>& result) {
        if (index == pattern.size()) {
            if (node->isEnd) result.push_back(node->word);
            return;
        }
        
        char ch = pattern[index];
        if (ch == '.') {
            for (auto& [c, child] : node->children) {
                dfs(child, pattern, index + 1, result);
            }
        } else if (ch == '*') {
            dfs(node, pattern, index + 1, result);
            for (auto& [c, child] : node->children) {
                dfs(child, pattern, index, result);
            }
        } else {
            if (node->children[ch]) {
                dfs(node->children[ch], pattern, index + 1, result);
            }
        }
    }
    
public:
    Solution() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch]) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
        node->word = word;
    }
    
    vector<string> search(string pattern) {
        vector<string> result;
        dfs(root, pattern, 0, result);
        return result;
    }
};
