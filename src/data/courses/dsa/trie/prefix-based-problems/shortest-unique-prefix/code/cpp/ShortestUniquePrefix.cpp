// ============================================================
// Solution 1: For each word, compare against all other words
// Time: O(N² * L) | Space: O(N * L)
// ============================================================
#include <vector>
#include <string>
using namespace std;

class Solution1 {
public:
    vector<string> shortestUniquePrefixes(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= (int)words[i].size(); len++) {
                string prefix = words[i].substr(0, len);
                bool unique = true;
                for (int j = 0; j < n; j++) {
                    if (i != j && words[j].substr(0, len) == prefix)
                        { unique = false; break; }
                }
                if (unique) { result.push_back(prefix); break; }
            }
        }
        return result;  // O(N²*L) — compare each prefix against all words
    }
};

// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
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
