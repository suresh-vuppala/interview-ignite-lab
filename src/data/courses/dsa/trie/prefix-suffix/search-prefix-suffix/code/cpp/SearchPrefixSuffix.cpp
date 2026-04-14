// ============================================================
// Solution 1: Linear scan with prefix+suffix check
// Time: O(N * L) per query | Space: O(N * L)
// ============================================================
#include <vector>
#include <string>
using namespace std;

class Solution1 {
    vector<string> words;
public:
    Solution1(vector<string>& w) : words(w) {}
    int query(string prefix, string suffix) {
        int result = -1;
        for (int i = 0; i < (int)words.size(); i++) {
            string& w = words[i];
            if (w.size() >= prefix.size() && w.size() >= suffix.size() &&
                w.substr(0, prefix.size()) == prefix &&
                w.substr(w.size() - suffix.size()) == suffix)
                result = i;  // Last matching index
        }
        return result;  // O(N*L) per query — no trie
    }
};

// ============================================================
// Solution 2: Optimal (Trie-based)
// ============================================================
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Time: O(N*L) build, O(L+K) query | Space: O(N*L)

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<int> indices;
};

class Solution {
    TrieNode* forwardTrie;
    TrieNode* reverseTrie;
    
    void collectAll(TrieNode* node, vector<int>& result) {
        result.insert(result.end(), node->indices.begin(), node->indices.end());
        for (auto& [ch, child] : node->children) {
            collectAll(child, result);
        }
    }
    
public:
    Solution() {
        forwardTrie = new TrieNode();
        reverseTrie = new TrieNode();
    }
    
    void build(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            // Forward trie
            TrieNode* node = forwardTrie;
            for (char ch : words[i]) {
                if (!node->children[ch]) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }
            node->indices.push_back(i);
            
            // Reverse trie
            node = reverseTrie;
            for (int j = words[i].size() - 1; j >= 0; j--) {
                char ch = words[i][j];
                if (!node->children[ch]) {
                    node->children[ch] = new TrieNode();
                }
                node = node->children[ch];
            }
            node->indices.push_back(i);
        }
    }
    
    vector<int> search(string prefix, string suffix) {
        // Prefix matches
        TrieNode* node = forwardTrie;
        for (char ch : prefix) {
            if (!node->children[ch]) return {};
            node = node->children[ch];
        }
        vector<int> prefixIndices;
        collectAll(node, prefixIndices);
        
        // Suffix matches
        node = reverseTrie;
        for (int i = suffix.size() - 1; i >= 0; i--) {
            if (!node->children[suffix[i]]) return {};
            node = node->children[suffix[i]];
        }
        vector<int> suffixIndices;
        collectAll(node, suffixIndices);
        
        // Intersection
        unordered_set<int> prefixSet(prefixIndices.begin(), prefixIndices.end());
        vector<int> result;
        for (int idx : suffixIndices) {
            if (prefixSet.count(idx)) {
                result.push_back(idx);
            }
        }
        return result;
    }
};
