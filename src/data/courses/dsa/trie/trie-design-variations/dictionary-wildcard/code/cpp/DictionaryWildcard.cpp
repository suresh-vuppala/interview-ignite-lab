// ============================================================
// Solution 1: Store words in vector, linear scan with matching
// Time: O(N * L) per search | Space: O(N * L)
// ============================================================
#include <string>
#include <vector>
using namespace std;

class Solution1 {
    vector<string> words;
public:
    void addWord(string word) { words.push_back(word); }
    bool search(string pattern) {
        for (auto& w : words) {
            if (w.size() != pattern.size()) continue;
            bool ok = true;
            for (int i = 0; i < (int)w.size(); i++)
                if (pattern[i] != '.' && pattern[i] != w[i]) { ok = false; break; }
            if (ok) return true;
        }
        return false;
    }
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

class Solution2 {
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
