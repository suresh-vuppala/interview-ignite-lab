// ============================================================
// Solution 1: Sort + HashSet prefix check
// Time: O(N * L²) | Space: O(N * L)
// ============================================================
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution1 {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> built;
        built.insert("");
        string result = "";
        for (auto& w : words) {
            string prefix = w.substr(0, w.size() - 1);
            if (built.count(prefix)) {  // Every prefix must be a word
                built.insert(w);
                if (w.size() > result.size()) result = w;
            }
        }
        return result;  // O(N*L) — HashSet instead of Trie
    }
};

// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution2 {
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
