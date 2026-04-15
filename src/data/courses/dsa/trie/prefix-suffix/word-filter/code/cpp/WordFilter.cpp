// ============================================================
// Solution 1: Linear scan for prefix+suffix match
// Time: O(N * L) per query | Space: O(N * L)
// ============================================================
#include <vector>
#include <string>
using namespace std;

class Solution1 {
    vector<string> words;
public:
    Solution1(vector<string>& w) : words(w) {}
    int f(string prefix, string suffix) {
        for (int i = words.size() - 1; i >= 0; i--) {
            string& w = words[i];
            if (w.size() >= prefix.size() && w.size() >= suffix.size() &&
                w.substr(0, prefix.size()) == prefix &&
                w.substr(w.size() - suffix.size()) == suffix)
                return i;
        }
        return -1;  // O(N*L) per query
    }
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

class Solution2 {
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
