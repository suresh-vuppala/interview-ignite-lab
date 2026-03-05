#include <string>
using namespace std;

class CountOperations {
    struct TrieNode {
        TrieNode* children[26] = {}; // 26 lowercase letters
        int wordCount = 0; // Count of words ending here
        int prefixCount = 0; // Count of words passing through
    };
    
    TrieNode* root = new TrieNode();
    
public:
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            node->prefixCount++; // Increment prefix count
        }
        node->wordCount++; // Increment word count at end
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return 0; // Word doesn't exist
            node = node->children[idx];
        }
        return node->wordCount; // Return count of this exact word
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return 0; // Prefix doesn't exist
            node = node->children[idx];
        }
        return node->prefixCount; // Return count of words with this prefix
    }
};
