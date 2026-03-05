#include <vector>
#include <string>
using namespace std;

class ShortestUniquePrefix {
    struct TrieNode {
        TrieNode* children[26] = {};
        int prefixCount = 0; // Count of words passing through
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
            node->prefixCount++; // Increment count
        }
    }
    
    string findPrefix(string word) {
        TrieNode* node = root;
        string prefix = "";
        
        for (char c : word) {
            int idx = c - 'a';
            prefix += c;
            node = node->children[idx];
            
            if (node->prefixCount == 1) {
                return prefix; // Unique prefix found
            }
        }
        return word; // Entire word is the prefix
    }
    
public:
    vector<string> shortestUniquePrefixes(vector<string>& words) {
        // Build trie with prefix counts
        for (string& word : words) {
            insert(word);
        }
        
        // Find shortest unique prefix for each word
        vector<string> result;
        for (string& word : words) {
            result.push_back(findPrefix(word));
        }
        return result;
    }
};
