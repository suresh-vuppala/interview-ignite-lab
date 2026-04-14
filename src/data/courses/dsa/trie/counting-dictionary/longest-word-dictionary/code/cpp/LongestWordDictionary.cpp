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
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class LongestWordDictionary {
    struct TrieNode {
        TrieNode* children[26] = {};
        bool isEnd = false;
    };
    
    void insert(TrieNode* root, string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }
    
    bool canBuild(TrieNode* root, string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            node = node->children[idx];
            if (!node->isEnd) return false; // Each prefix must be a word
        }
        return true;
    }
    
public:
    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (string& word : words) insert(root, word);
        
        string longest = "";
        for (string& word : words) {
            if (canBuild(root, word)) {
                if (word.length() > longest.length() || 
                    (word.length() == longest.length() && word < longest)) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};
