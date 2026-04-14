// ============================================================
// Solution 1: Brute Force
// ============================================================
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution1 {
public:
    // Brute force: use hash set / nested loops / direct comparison
    // See Solution 2 below for the optimal Trie-based approach
};

// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
#include <string>
#include <unordered_map>
using namespace std;

// Time: O(L) add, O(26^W*L) search | Space: O(N*L)

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};

class WordDictionary {
    TrieNode* root;
    
    bool searchHelper(const string& word, int index, TrieNode* node) {
        if (index == word.size()) return node->isEnd;
        
        char ch = word[index];
        if (ch == '.') {
            for (auto& [c, child] : node->children) {
                if (searchHelper(word, index + 1, child)) return true;
            }
            return false;
        } else {
            if (!node->children[ch]) return false;
            return searchHelper(word, index + 1, node->children[ch]);
        }
    }
    
public:
    WordDictionary() {
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
    }
    
    bool search(string word) {
        return searchHelper(word, 0, root);
    }
};
