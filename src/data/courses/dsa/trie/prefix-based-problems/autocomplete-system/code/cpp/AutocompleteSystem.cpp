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
#include <algorithm>
using namespace std;

class AutocompleteSystem {
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        unordered_map<string, int> sentences; // sentence -> frequency
    };
    
    TrieNode* root = new TrieNode();
    TrieNode* current = root;
    string prefix = "";
    
    void insert(string sentence, int freq) {
        TrieNode* node = root;
        for (char c : sentence) {
            if (!node->children[c]) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->sentences[sentence] += freq; // Add frequency
        }
    }
    
    vector<string> getTop3(unordered_map<string, int>& sentences) {
        vector<pair<string, int>> vec(sentences.begin(), sentences.end());
        // Sort by frequency (desc), then lexicographically (asc)
        sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        });
        
        vector<string> result;
        for (int i = 0; i < min(3, (int)vec.size()); i++) {
            result.push_back(vec[i].first);
        }
        return result;
    }
    
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        // Insert all sentences with frequencies
        for (int i = 0; i < sentences.size(); i++) {
            insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if (c == '#') {
            // Save current sentence
            insert(prefix, 1);
            prefix = "";
            current = root;
            return {};
        }
        
        prefix += c;
        if (!current->children[c]) {
            current->children[c] = new TrieNode();
        }
        current = current->children[c];
        
        // Get top 3 sentences
        return getTop3(current->sentences);
    }
};
