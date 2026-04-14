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
using namespace std;

class CountDistinctSubstrings {
    struct TrieNode {
        TrieNode* children[26] = {};
    };
    
public:
    int countDistinct(string s) {
        TrieNode* root = new TrieNode();
        int count = 0;
        
        // Insert all substrings
        for (int i = 0; i < s.length(); i++) {
            TrieNode* node = root;
            for (int j = i; j < s.length(); j++) {
                int idx = s[j] - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                    count++; // New unique substring
                }
                node = node->children[idx];
            }
        }
        return count + 1; // +1 for empty string
    }
};
