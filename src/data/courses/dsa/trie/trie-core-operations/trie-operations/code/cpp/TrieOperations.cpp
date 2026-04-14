// ============================================================
// Solution 1: Hash Set — Store complete words
// Time: O(N*L) insert, O(L) search, O(N*L) prefix check
// ============================================================
#include <unordered_set>
#include <string>
using namespace std;

class Solution1 {
    unordered_set<string> words;
public:
    void insert(string word) { words.insert(word); }
    bool search(string word) { return words.count(word); }
    bool startsWith(string prefix) {
        for (auto& w : words) // O(N*L) — scan all words!
            if (w.substr(0, prefix.size()) == prefix) return true;
        return false;
    }
};

// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
#include <string>
using namespace std;

class TrieOperations {
    struct TrieNode {
        TrieNode* children[26] = {}; // 26 lowercase letters
        bool isEnd = false; // Marks end of word
    };
    
    TrieNode* root = new TrieNode();
    
public:
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a'; // Convert char to index (0-25)
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode(); // Create new node
            }
            node = node->children[idx]; // Move to child
        }
        node->isEnd = true; // Mark end of word
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false; // Path doesn't exist
            node = node->children[idx];
        }
        return node->isEnd; // Check if it's a complete word
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false; // Path doesn't exist
            node = node->children[idx];
        }
        return true; // Prefix exists (don't check isEnd)
    }
};
