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
