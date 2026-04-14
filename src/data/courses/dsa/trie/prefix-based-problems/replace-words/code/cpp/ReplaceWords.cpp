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
#include <sstream>
using namespace std;

class ReplaceWords {
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
        node->isEnd = true; // Mark root word end
    }
    
    string getRoot(string word) {
        TrieNode* node = root;
        string prefix = "";
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) break; // No root found
            prefix += c;
            node = node->children[idx];
            if (node->isEnd) return prefix; // Found shortest root
        }
        return word; // No root found, return original
    }
    
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        // Insert all roots into trie
        for (string& word : dictionary) insert(word);
        
        // Process sentence
        stringstream ss(sentence);
        string word, result = "";
        while (ss >> word) {
            if (!result.empty()) result += " ";
            result += getRoot(word); // Replace with root if exists
        }
        return result;
    }
};
