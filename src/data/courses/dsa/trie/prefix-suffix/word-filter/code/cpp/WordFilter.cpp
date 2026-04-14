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
#include <unordered_map>
using namespace std;

// Time: O(N*L²) build, O(P+S) query | Space: O(N*L²)

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    int weight = -1;
};

class WordFilter {
    TrieNode* root;
    
    void insert(const string& word, int weight) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children[ch]) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
            node->weight = weight;
        }
    }
    
public:
    WordFilter(vector<string>& words) {
        root = new TrieNode();
        for (int weight = 0; weight < words.size(); weight++) {
            string word = words[weight];
            for (int i = 0; i <= word.size(); i++) {
                string suffix = word.substr(i);
                string key = suffix + "#" + word;
                insert(key, weight);
            }
        }
    }
    
    int f(string prefix, string suffix) {
        TrieNode* node = root;
        string searchKey = suffix + "#" + prefix;
        for (char ch : searchKey) {
            if (!node->children[ch]) return -1;
            node = node->children[ch];
        }
        return node->weight;
    }
};
