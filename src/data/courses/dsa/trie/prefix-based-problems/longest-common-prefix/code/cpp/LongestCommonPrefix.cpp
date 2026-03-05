#include <vector>
#include <string>
using namespace std;

class LongestCommonPrefix {
    struct TrieNode {
        TrieNode* children[26] = {};
        bool isEnd = false;
    };
    
    TrieNode* root = new TrieNode();
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->isEnd = true; // Mark end of word
    }
    
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        
        // Insert all words into trie
        for (string& word : strs) {
            insert(word);
        }
        
        // Traverse trie to find common prefix
        string prefix = "";
        TrieNode* node = root;
        
        while (true) {
            // Count non-null children
            int childCount = 0;
            int childIdx = -1;
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) {
                    childCount++;
                    childIdx = i;
                }
            }
            
            // Stop if branching or end of word
            if (childCount != 1 || node->isEnd) break;
            
            prefix += (char)('a' + childIdx); // Add character to prefix
            node = node->children[childIdx]; // Move to child
        }
        
        return prefix;
    }
};
